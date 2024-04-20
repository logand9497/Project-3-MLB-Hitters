#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include "quicksort.h"
#include "MERGESORT.cpp"
using namespace std;


int main() {
    // saving data file to variable
    string dataFile = "Data.csv";

    // read CSV to get vector of values
    vector<pair<string, double>> mergeVector = readCSV(dataFile);
    vector<pair<string, double>> quickVector = readCSV(dataFile);

    // intialize mergesort and quicksort
    mergeSort(mergeVector, 0, mergeVector.size() - 1);
    quickSort(quickVector, 0, quickVector.size() - 1);

    // while loop for beginning of user interface
    bool quit = false;
    while (!quit) {
        // Prompt for search for a player or quit
        cout << "Would you like to search for a player? Y/N" << endl;
        char input1;
        cin >> input1;

        if (input1 == 'N') {
            // no to search ends program
            quit = true;
        }
        else if (input1 == 'Y') {
            // prompt for players to compare
            cout << "Please enter a player name and the year you would like to see their score for." << endl;
            cout << "Enter in the format: First Last Year" << endl;
            string player;
            cin >> player;
            cout << endl;

            // begin merge timer
            auto mergeStart = chrono::high_resolution_clock::now();

            // call to find from merge sort
            auto mergeIter = find_if(mergeVector.begin(), mergeVector.end(), [&player](const pair<string, double>& p) { return p.first == player; });

            // end merge timer
            auto mergeEnd = chrono::high_resolution_clock::now();

            // calc timer duration from merge sort
            auto mergeDuration = chrono::duration_cast<std::chrono::microseconds>(mergeEnd - mergeStart);

            // begin quick timer
            auto quickStart = chrono::high_resolution_clock::now();

            // call to find from quick sort
            auto quickIter = find_if(quickVector.begin(), quickVector.end(), [&player](const pair<string, double>& p) { return p.first == player; });

            // end quick timer
            auto quickEnd = chrono::high_resolution_clock::now();

            // calc timer duration from quick sort
            auto quickDuration = chrono::duration_cast<std::chrono::microseconds>(quickEnd - quickStart);

            // output player and the five players on either side
            if (mergeIter != mergeVector.end()) {
                // print the player being searched for
                cout << "Player searched for and their OPS:" << endl;
                cout << mergeIter->first << ", " << mergeIter->second << " OPS" << endl;
                
                // print the five players on either side
                cout << "Closest players using Merge Sort:" << endl;
                auto start = max(mergeVector.begin(), mergeIter - 5);
                auto end = min(mergeVector.end(), mergeIter + 6);
                for (auto it = start; it != end; ++it) {
                    cout << it->first << ", " << it->second << " OPS" << endl;
                }
            }
            else {
                cout << "Player not found using Merge Sort." << endl;
            }
            cout << endl;

            if (quickIter != quickVector.end()) {
                // print the player being searched for
                cout << "Player searched for and their OPS:" << endl;
                cout << quickIter->first << ", " << quickIter->second << " OPS" << endl;
                
                // print the five players on either side
                cout << "Closest players using Quick Sort:" << endl;
                auto start = max(quickVector.begin(), quickIter - 5);
                auto end = min(quickVector.end(), quickIter + 6);
                for (auto it = start; it != end; ++it) {
                    cout << it->first << ", " << it->second << " OPS" << endl;
                }
            }
            else {
                cout << "Player not found using Quick Sort." << endl;
            }
            cout << endl;

            cout << "Merge sort search duration: " << mergeDuration.count() << " microseconds" << endl;
            cout << "Quick sort search duration: " << quickDuration.count() << " microseconds" << endl;
            cout << endl;

        }
        else {
            // any invalid input restarts
            cout << "Invalid input." << endl;
            cout << endl;
        }
    }

    return 0;
}