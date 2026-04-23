#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <random>
#include <chrono>

using namespace std
// =============================================================
// MODULE 1: Genera datos aleatorios (no usa cola)
// =============================================================
class Module1 : public IModule {
public:
    void start() override {
        worker = thread(&Module1::generateLoop, this);
    }

    void join() {
        worker.join();
    }

    void pushData(const vector<uint8_t>&) override {
        // Module1 no recibe datos
    }

private:
    void generateLoop() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 100);

        while (true) {
            int length = dis(gen);
            vector<uint8_t> data(length);

            generate(data.begin(), data.end(), [&]() { return dis(gen); });

            cout << "Module1 - Generated: ";
            for (auto b : data) cout << int(b) << " ";
            cout << endl;

            if (nextModule)
                nextModule->pushData(data);

            this_thread::sleep_for(chrono::seconds(1));
        }
    }

    thread worker;
};