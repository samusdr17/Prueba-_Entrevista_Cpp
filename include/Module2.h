#pragma once
#include "ModuleBase.h"
#include "SafeQueue.h"
#include "Message.h"
#include <iostream>

class Module2 : public ModuleBase {
private:
    SafeQueue<Message>* input;

public:
    Module2(SafeQueue<Message>* in) : input(in) {}

    void run() override {
        while (running) {
            Message msg = input->pop();

            switch (msg.type) {
                case MessageType::PING:
                    std::cout << "[Module2] Recibido PING: " << msg.payload << "\n";
                    break;

                case MessageType::DATA:
                    std::cout << "[Module2] Procesando DATA: " << msg.payload << "\n";
                    break;

                case MessageType::STOP:
                    std::cout << "[Module2] Recibido STOP. Terminando...\n";
                    running = false;
                    break;

                case MessageType::STATUS:
                    std::cout << "[Module2] Estado solicitado\n";
                    break;
            }
        }
    }
};
