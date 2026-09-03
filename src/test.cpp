//header files (should not have any std headers, only ones that I make)
#include "io.hpp"
#include "log.hpp"

//global variables
std::string filePath;
std::string outputFilePath;

int main(int argc, char* argv[])
{
    std::cout << "argc: " << argc << std::endl;
    if(argc != 1)
    {
        for(int i = 0; i < argc; i++)
        {
            std::string arg = argv[i];
            if(arg == "-i")
            {
                if(argc - 1 == i)
                {
                    logFatal("There needs to be an input path AFTER the input flag (-i).");
                }

                filePath = argv[i + 1];
            }
            else if(arg == "-o")
            {
                if(argc - 1 == i)
                {
                    logFatal("There needs to be an output path AFTER the output flag (-o).");
                }

                outputFilePath = argv[i + 1];
            }
        }
    }
    else 
    {
        logWarning("Editor opened without file, make sure to save!");
        
        std::string path = writeToUnknownPath("hello");

        std::cout << "The file reads: " << readFromFile(path);

        return 0;
    }

    if(filePath == "")
    {
        logFatal("There is no file path.");
    }

    writeToFile("hello", filePath);

    std::cout << "The file reads: " << readFromFile(filePath) << std::endl;

    return 0;
}