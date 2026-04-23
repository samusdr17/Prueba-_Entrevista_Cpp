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
// MODULE 3: Guarda datos
// =============================================================
class Module3 : public ModuleBase {
protected:
    vector<uint8_t> processData(const vector<uint8_t>& data) override {
        cout << "Module3 - Saving data... size = " << data.size() << endl;
        cout << "----------------------------------------" << endl;

        return {}; // Último módulo no pasa nada
    }
};

