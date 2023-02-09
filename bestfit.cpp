#include <iostream> 
#include <fstream> 
#include <string>
#include <vector> 
#include <set> 

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

int bestFit (vector<int> &items, int bin_size) {
  int number_bins = 0; 
  multiset<int> capacities; 
  for (int item : items) {
    // look for the lowest capacity that is greater than item
    auto best_fit = capacities.lower_bound(item); 
    if (best_fit == capacities.end()) {
      number_bins++; 
      capacities.insert(bin_size-item);
    }
    else {
      capacities.insert(*best_fit - item); 
      capacities.erase(best_fit); 
    }
  }
  cout << "NUMBER BINS: " << number_bins << '\n'; 
  return number_bins; 
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    cout << "USAGE: ./firstfit input_file bin_size\n"; 
    cout << "OUTPUT: number_bins\n";
    return 0; 
  }

  string inputFile = argv[1]; 
  int bin_size = stoi(argv[2]); 
  vector<int> item_sizes = readFromFile(inputFile); 
  bestFit(item_sizes, bin_size);  
  return 0; 
}
