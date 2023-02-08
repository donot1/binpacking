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
    sort(items.begin(), items.end(), greater<int>()); 

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
    cout << "NUMBER BINS: " << bins.size() << '\n'; 
    return bins.size(); 
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
  int x = firstFit(bin_size, item_sizes); 
  cout << x << '\n'; 

  return 0; 
}