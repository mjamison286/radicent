#include "io.hpp"
#include "log.hpp"

struct IOData
{
    std::string input;
    std::string output;
};

IOData processCLI(int argc, char **argv)
{
    IOData data;

    for(int i = 0; i < argc; i++)
    {
        if(i + 1 != argc)
        {
            std::string arg = argv[i];
            if(arg == "-i")
            {
                data.input = argv[i + 1];
            }
            else if(arg == "-o")
            {
                data.output = argv[i + 1];
            }
        }
    }

    if(data.input == "")
    {
        logFatal("Did not provide an input path.");
    }

    if(data.output == "")
    {
        data.output = data.input;

        logWarning("Output path not received, set path to input.");
    }

    return data;
}

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

    std::string temp;
    std::string content;

    if(!file)
    {
        logFatal("The input file failed to open.");
        return "";
    }

    //logVerbose("The input file opened.");

    while(getline(file, temp))
    {
        content += ("\n" + temp);
    }

    file.close();

    return content;
}