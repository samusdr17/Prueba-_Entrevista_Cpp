#include "Module1.h"
#include "Module2.h"
#include "SafeQueue.h"
#include "Message.h"
#include <thread>
#include <chrono>

int main() {
    SafeQueue<Message> cola;

    Module1 m1(&cola);
    Module2 m2(&cola);

    m2.start();

    m1.sendPing();
    std::this_thread::sleep_for(std::chrono::milliseconds(300));

    m1.sendData("Temperatura: 22.5C");
    std::this_thread::sleep_for(std::chrono::milliseconds(300));

    m1.sendData("Humedad: 45%");
    std::this_thread::sleep_for(std::chrono::milliseconds(300));

    m1.sendStop();

    m2.stop();

    return 0;
}
