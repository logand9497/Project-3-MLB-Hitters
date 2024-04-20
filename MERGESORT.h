#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
using namespace std;

void merge(vector<pair<string, double>>& rVals, int start, int mid, int end);

void mergeSort(vector<pair<string, double>>& rVals, int start, int end);

void printData(const vector<pair<string, double>>& rVal);

vector<pair<string, double>> seeOPS(const vector<pair<string, double>>& given, double seeVal);