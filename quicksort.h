#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <utility> // for std::pair

// Function to read data from CSV file and populate the vector of pairs
std::vector<std::pair<std::string, double>> readCSV(const std::string& filename);

// Partition part of quicksort
int partition(std::vector<std::pair<std::string, double>>& data, int low, int high);

// Quick sort algorithm to sort vector of pairs by OPS
void quickSort(std::vector<std::pair<std::string, double>>& data, int low, int high);

// Function to print vector of pairs
void printData(const std::vector<std::pair<std::string, double>>& data);
