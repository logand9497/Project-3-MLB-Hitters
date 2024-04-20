#include <iostream>
#include "MERGESORT.h"
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
using namespace std;

/* void readCSV(vector<pair<string, double>>& rVal, string fileNAME){ // reading file
        string fileN = fileNAME; // file name
        ifstream file(fileN); // opening file
        if(!file.is_open()){ // checking if file is open
            cout << "Error opening file!" << endl;
        }
        string line;
        getline(file,line); // deleting heading
         // data structure to read stuff into
        while(getline(file, line)){  // reading through csv file
            stringstream ss(line);
            string name;
            getline(ss, name, ',');
            string O;
            getline(ss, O);
            double val = stod(O); 
            rVal.emplace_back(name, val); // adding data
        }
    } */


void merge(vector<pair<string,double>>& rVals, int start, int mid, int end){
    int n1 = mid - start + 1; // lengths of two smaller vectors
    int n2 = end - mid;

    std::vector<pair<string, double>> left; // creating copies
    std::vector<pair<string, double>> right;

    for (int i = 0; i < n1; i++){ // adding data to copies
        left.push_back(rVals[start + i]);
    }
    for (int j = 0; j < n2; j++){
        right.push_back(rVals[mid + 1 + j]);
    }

    int i = 0; // adding data back to the main vector
    int j = 0; 
    int k = start;
    while (i < n1 && j < n2) { // while values left in either vector
        if (left[i].second <= right[j].second) { // comparing and adding the smaller one
            rVals[k] = left[i];
            i++;
        } else {
            rVals[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1) { // if values only left in left vector
        rVals[k] = left[i];
        i++;
        k++;
    }
    while (j < n2) { // if values only left in right vector
        rVals[k] = right[j];
        j++;
        k++;
    }
}


void mergeSort(vector<pair<string,double>> &rVals, int start, int end){
    if (start < end){
        int middle = (start + end) / 2; // splitting vector and recursively calling mergeSort

        mergeSort(rVals, middle + 1, end);
        mergeSort(rVals, start, middle);

        merge(rVals,start,middle,end); // combining vectors back together

    }
}

/* void printData(const vector<pair<string, double>>& rVal) {
    for (const auto& pair : rVal){ // going through new vector and printing values
        cout << pair.first << ": " << pair.second << endl;
    }
} */


vector<pair<string,double>> seeOPS(const vector<pair<string, double>>& given, double seeVal) {
    vector<pair<string,double>> rVal; // creating new value
    bool check = false; // exiting if pass all of the same OPS

    for (int i = 0; i < rVal.size(); i++){ // iterating until same OPS
        if (seeVal == given[i].second){
            rVal.push_back(given[i]); // adding to the return vector
            check = true;
        }
        else {
            if (check){
                break;
            }
        }        
    }
    return rVal;
}
