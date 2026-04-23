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
// MODULE 2: Filtra números impares
// =============================================================
class Module2 : public ModuleBase {
protected:
    vector<uint8_t> processData(const vector<uint8_t>& data) override {
        cout << "Module2 - Filtering..." << endl;

        vector<uint8_t> filtered;
        for (auto b : data)
            if (b % 2 != 0)
                filtered.push_back(b);

        cout << "Filtered (odd): ";
        for (auto b : filtered) cout << int(b) << " ";
        cout << endl;

        return filtered;
    }
};
