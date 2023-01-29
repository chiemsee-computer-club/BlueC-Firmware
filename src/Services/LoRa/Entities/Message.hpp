#pragma once

#include <string>

struct Message
{
    std::string Id;
    std::string Message;
    std::string SenderId;
    std::string ReceiverId;
    int Timestamp;
};