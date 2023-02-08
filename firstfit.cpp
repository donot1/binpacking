#include <iostream> 
#include <fstream> 
#include <string> 
#include <vector>
using namespace std; 

vector<int> readFromFile (string file) {
  ifstream inputFile; 
  inputFile.open(file); 
  vector<int> items; 
  int item; 
  while (inputFile >> item) {
    items.push_back(item); 
  }
  return items; 
}


int firstFit(int binCapacity, vector<int> items) {
    vector<int> bins; 
    bins.push_back(0); 
    for (int i = 0; i < items.size(); i++) {
        int item = items[i]; 
        bool placed = false; 
        for (int j = 0; j < bins.size(); j++) {
        if (bins[j] + item <= binCapacity) {
            bins[j] += item; 
            placed = true; 
            break; 
        }
        }
        if (!placed) {
        bins.push_back(item); 
        }
    }
    return bins.size(); 
}