#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <random>
#include <chrono>

using namespace std;

class IModule {
public:
    virtual void pushData(const vector<uint8_t>& data) = 0;
    virtual void start() = 0;
    virtual ~IModule() = default;

    void setNext(IModule* next) { nextModule = next; }

protected:
    IModule* nextModule = nullptr;
};

