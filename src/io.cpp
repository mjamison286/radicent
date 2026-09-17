#include "io.hpp"

void processCLI(int argc, char **argv)
{
    isVerbose = false;

    for(int i = 0; i < argc; i++)
    {
        std::string arg = argv[i];
        if(i + 1 != argc)
        {
            if(arg == "-i")
            {
                inputPath = argv[i + 1];
            }
            else if(arg == "-o")
            {
                outputPath = argv[i + 1];
            }
        }

        if(arg == "-v")
        {
            isVerbose = true;
            logVerbose("Verbose mode set to true.");
        }
    }

    if(inputPath == "")
    {
        inputPath = "./current.txt";

        logWarning("Opened without input path, swapped to default path.");
    }

    if(outputPath == "")
    {
        outputPath = inputPath;

        logWarning("Output path not received, set path to input.");
    }
}

void writeToFile(std::string content, std::string path)
{
    std::ofstream file(path);

    if(!file)
    {
        logFatal("The output file failed to open.");
    }

    if(isVerbose)
    {
        logVerbose("output filed opened.");
    }

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

    std::string temp;
    std::string content;

    if(!file)
    {
        logFatal("The input file failed to open.");
        return "";
    }

    if(isVerbose)
    {
        logVerbose("The input file opened.");
    }

    while(getline(file, temp))
    {
        content += ("\n" + temp);
    }

    file.close();

    return content;
}