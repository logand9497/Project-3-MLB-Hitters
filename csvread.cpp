#include "csvread.h"

// Parses CSV file data and creates a vector that holds a vector of strings. Each of the
// string vectors holds the stats for a player's season.
std::vector<std::vector<std::string>> CSVReader::readCSV() {
    std::vector<std::vector<std::string>> data;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return data; // Return empty vector if file cannot be opened
    }

    // Skip the first line (header)
    std::string header;
    std::getline(file, header);

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<std::string> row;
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        data.push_back(row);
    }

    file.close();
    return data;
}
