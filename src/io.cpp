#pragma once

#include "io.hpp"
#include "log.hpp"


void writeToFile(std::string content, std::string path)
{
    std::ofstream file(path);

    if(!file)
    {
        logFatal("The output file failed to open.");
    }

    //logVerbose("output filed opened.");

    file << content;

    file.close();
}

std::string writeToUnknownPath(std::string content)
{
    std::cout << "What path do you want the file to be saved to?" << std::endl;
    
    std::string filePath;

    std::cin >> filePath;

    writeToFile(content, filePath);

    return filePath;
}

std::string readFromFile(std::string path)
{
    std::ifstream file(path);

    std::string content;

    if(!file)
    {
        logFatal("The input file failed to open.");
        return "";
    }

    //logVerbose("The input file opened.");

    file >> content;

    file.close();

    return content;
}