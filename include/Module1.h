#pragma once
#include "SafeQueue.h"
#include "Message.h"
#include <string>

class Module1 {
private:
    SafeQueue<Message>* output;

public:
    Module1(SafeQueue<Message>* out) : output(out) {}

    void sendPing() {
        output->push({ MessageType::PING, "Ping enviado" });
    }

    void sendData(const std::string& data) {
        output->push({ MessageType::DATA, data });
    }

    void sendStop() {
        output->push({ MessageType::STOP, "Detener sistema" });
    }
};
