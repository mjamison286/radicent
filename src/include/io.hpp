#pragma once

#include <string>
#include <iostream>
#include <fstream>

#include "log.hpp"
#include "global.hpp"

void processCLI(int argc, char** argv);

void writeToFile(std::string content, std::string path);

std::string writeToUnknownPath(std::string content);

std::string readFromFile(std::string path);
