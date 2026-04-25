#pragma once
#include <string>

enum class MessageType {
    PING,
    DATA,
    STOP,
    STATUS
};

struct Message {
    MessageType type;
    std::string payload;
};
