#include "quicksort.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <utility> // for std::pair

// Function to read data from CSV file and populate the vector of pairs
std::vector<std::pair<std::string, double>> readCSV(const std::string& filename) {
    std::vector<std::pair<std::string, double>> data;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return data;
    }

    // Skip the first line (header)
    std::string header;
    std::getline(file, header);

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, OPS_str;
        double OPS;

        // Read name (1st entry)
        std::getline(ss, name, ',');

        // Read OPS (2nd entry)
        std::getline(ss, OPS_str, ',');
        OPS = std::stod(OPS_str);

        // Add pair to vector
        data.emplace_back(name, OPS);
    }

    file.close();
    return data;
}

int partition(std::vector<std::pair<std::string, double>>& data, int low, int high) {
    double pivot = data[high].second;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (data[j].second < pivot) {
            i++;
            std::swap(data[i], data[j]);
        }
    }
    std::swap(data[i + 1], data[high]);
    return i + 1;
}

// Quick sort algorithm to sort the vector of pairs by OPS
void quickSort(std::vector<std::pair<std::string, double>>& data, int low, int high) {
    if (low < high) {
        int pivot = partition(data, low, high);
        quickSort(data, low, pivot - 1);
        quickSort(data, pivot + 1, high);
    }
}

// Iterative quick sort algorithm to sort the vector of pairs by OPS
void quickSortIterative(std::vector<std::pair<std::string, double>>& data, int low, int high) {
    std::vector<std::pair<int, int>> stack;
    stack.push_back(std::make_pair(low, high));

    while (!stack.empty()) {
        std::pair<int, int> range = stack.back();
        stack.pop_back();
        int left = range.first;
        int right = range.second;
        if (left < right) {
            int pivot = partition(data, left, right);
            stack.push_back(std::make_pair(left, pivot - 1));
            stack.push_back(std::make_pair(pivot + 1, right));
        }
    }
}

// Function to print the vector of pairs
void printData(const std::vector<std::pair<std::string, double>>& data) {
    for (const auto& pair : data) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}
