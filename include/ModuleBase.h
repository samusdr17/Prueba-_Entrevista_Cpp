#pragma once
#include <thread>
#include <atomic>

class ModuleBase {
protected:
    std::thread worker;
    std::atomic<bool> running{false};

public:
    virtual ~ModuleBase() {}

    void start() {
        running = true;
        worker = std::thread(&ModuleBase::run, this);
    }

    void stop() {
        running = false;
        if (worker.joinable()) worker.join();
    }

    virtual void run() = 0;
};
