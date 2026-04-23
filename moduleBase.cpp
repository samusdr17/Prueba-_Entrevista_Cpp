#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <random>
#include <chrono>

using namespace std;

// =============================================================
// MODULE BASE: Cola + hilo + condition_variable
// =============================================================
class ModuleBase : public IModule {
public:
    void start() override {
        worker = thread(&ModuleBase::processLoop, this);
    }

    void join() {
        worker.join();
    }

    void pushData(const vector<uint8_t>& data) override {
        {
            lock_guard<mutex> lock(mtx);
            queueData.push(data);
        }
        cv.notify_one();
    }

protected:
    virtual vector<uint8_t> processData(const vector<uint8_t>& data) = 0;

private:
    void processLoop() {
        while (true) {
            vector<uint8_t> data;

            {
                unique_lock<mutex> lock(mtx);
                cv.wait(lock, [&]() { return !queueData.empty(); });

                data = queueData.front();
                queueData.pop();
            }

            vector<uint8_t> result = processData(data);

            if (nextModule)
                nextModule->pushData(result);
        }
    }

    queue<vector<uint8_t>> queueData;
    mutex mtx;
    condition_variable cv;
    thread worker;
};