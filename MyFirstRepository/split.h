#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class split{
public:
    split();
    std::vector<std::string> splitLine(const std::string s, char delim);
}; 