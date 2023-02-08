#include <iostream> 
#include <fstream> 
#include <string> 
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

int firstFit (vector<int> &items, int bin_size) {
  int number_bins = 0; 
  multiset<int> capacities; 
  for (int item : item
}

int main(int argc, char* argv[]) {
  if (argc < 1) {
    cout << "USAGE: ./firstfit input_file bin_size\n"; 
    cout << "OUTPUT: number_bins\n";
  }

  string inputFile = argv[1]; 
  int bin_size = stoi(argv[2]); 
  vector<int> item_sizes = readFromFile(inputFile); 
  
  return 0; 
}
