#include "split.h"

split::split(){};

std::vector<std::string> split::splitLine(const std::string s, char delim){
        std::stringstream ss(s);
        std::vector<std::string> tokens;
        std::string item;
        while(std::getline(ss, item, delim)) {
            tokens.push_back(item);
        }
        return tokens;
} 