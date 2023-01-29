#include "Logger.hpp"

std::list<LoggerBackend*> Logger::_backends = {};

void Logger::AddBackend(LoggerBackend* backend)
{
    _backends.push_back(backend);
}

void Logger::Debug(String value)
{
    for(const auto& backend : _backends)
    {
        backend->WriteLine("[DEBUG] " + value);
    }
}
