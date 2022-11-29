#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <sstream> //std::stringstream

namespace utils {
    std::string loadFile(std::string filename) {
        std::ifstream inFile;
        inFile.open(filename); //open the input file

        std::stringstream strStream;
        strStream << inFile.rdbuf(); //read the file
        return strStream.str(); //str holds the content of the file
    }
}
