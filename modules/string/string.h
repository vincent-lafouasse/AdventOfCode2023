#pragma once

#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> split(std::ifstream& stream, char sep);
std::vector<std::string> split(const std::string& s, char sep);
