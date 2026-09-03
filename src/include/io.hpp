#pragma once

#include <string>
#include <iostream>
#include <fstream>

void writeToFile(std::string content, std::string path);

std::string writeToUnknownPath(std::string content);

std::string readFromFile(std::string path);
