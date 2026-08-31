#pragma once

#include "log.hpp"

void logFatal(std::string str)
{
    std::ofstream file("../log.txt");

    file << "FATAL: " << str << std::endl;
    file.close();

    std::cout << "FATAL: " << str << std::endl;

    exit(EXIT_FAILURE);
}

void logWarning(std::string str)
{
    std::ofstream file("../log.txt");

    file << "WARNING: " << str << std::endl;
    file.close();

    std::cout << "WARNING: " << str << std::endl;
}

void logVerbose(std::string str)
{
    std::ofstream file("../log.txt");

    file << "LOG: " << str << std::endl;
    file.close();

    std::cout << "LOG: " << str << std::endl;
}