#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;


class bGraph{
private:
    map<string, map<string, double>> g;
    map<string, double> LOP;

public:

    bGraph(){
        
    }
    void addVertex(string player, double OPS){
        LOP[player] = OPS;
    }
    void addEdge(string from, string to, double weight){
        g[from][to] = weight;
    }
    double findWeight(string from, string to){
        return g[from][to];
    }
    map<double, string> findSimilar(string from){
        map<double, string> rVals;
        for (auto iter = g[from].begin(); iter != g[from].end(); iter++){
            if (rVals.size() < 10){
                rVals[iter->second] = iter->first;
            }
            else {
                auto newiter = rVals.end();
                newiter--;
                if(abs(newiter->first) > abs(iter->second)){
                    rVals.erase(newiter->first);
                    rVals[iter->second] = iter->first;
                }
            }
        }
        return rVals;
    }
    
};
