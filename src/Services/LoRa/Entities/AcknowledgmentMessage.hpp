#pragma once

#include <string>

struct AcknowledgmentMessage
{
    std::string MessageId;
    std::string ReceiverId;
    std::string SenderId;
    int Timestamp;
};