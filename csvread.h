#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class CSVReader {
private:
    std::string filename;
    std::vector<std::vector<std::string>> data;

public:
    CSVReader(const std::string &filename) : filename(filename) {};

    // Parses CSV file data and creates a vector that holds a vector of strings. Each of the
    // string vectors holds the stats for a player's season.
    std::vector<std::vector<std::string>> readCSV();
};