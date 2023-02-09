#include <vector> 
#include <string> 
#include <fstream> 
#include "binpacking.h" 

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

void writeToFile(vector<int> &values, string file) {
  ofstream output;
  output.open(file);
  for (int val : values)
    output << val << " ";
  output.close();
  return;
}

