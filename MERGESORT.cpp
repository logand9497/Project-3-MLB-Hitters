#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
using namespace std;

vector<pair<string, double>> readCSV(string fileNAME){
        string fileN = fileNAME;
        ifstream file(fileN); 
        if(!file.is_open()){
            cout << "Error opening file!" << endl;
        }
        string line;
        getline(file,line);
        int i = 1;
        vector<pair<string, double>> rVal;
        while(getline(file, line)){ 
            stringstream ss(line);
            string name;
            getline(ss, name, ',');
            string O;
            getline(ss, O);
            double val = stod(O); 
            rVal.emplace_back(name, val);     
        }   

        return rVal;    

    }


void merge(vector<pair<string,double>>& arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    std::vector<pair<string, double>> L(n1), R(n2);

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].second <= R[j].second) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(vector<pair<string,double>> &rVals, int start, int end){
    if (start < end){
        int middle = (start + end) / 2;

        mergeSort(rVals, middle + 1, end);
        mergeSort(rVals, start, middle);

        merge(rVals,start,middle,end);

    }
}

void printData(const vector<pair<string, double>>& rVal) {
    for (const auto& pair : rVal){
        cout << pair.first << ": " << pair.second << endl;
    }
}