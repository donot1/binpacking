// #include "functions.h"
#include <iostream>
#include <vector>
#include <fstream> 
#include <string> 
#include <set> 
#include <random> 


using namespace std;



#include <iostream> 
#include <fstream> 
#include <random> 
#include <vector> 


using namespace std; 


template<class Generator, class Distribution>
vector<int> generateRandom(Generator gen, Distribution dist, 
                           int num_values) {
  vector<int> values; 
  for (int i = 0; i < num_values; i++) {
    int val = dist(gen); 
    values.push_back(val); 
  }
  return values; 
}


void writeToFile(vector<int> &values, string file) {
  ofstream output; 
  output.open(file); 
  for (int val : values)
    output << val << " "; 
  output.close(); 
  return; 
}


vector<int> generateItems(int num_items, int max_val, string output_file, string distribution) {

  
  srand(time(nullptr)); 



  default_random_engine generator; 
  vector<int> generated_values;

  if (distribution == "binomial") {
    binomial_distribution<int> dist(max_val, 0.5); 
    generated_values = generateRandom(generator, dist, num_items);  
  }
  else if (distribution == "uniform") {
    uniform_int_distribution<int> dist(1, max_val); 
    generated_values = generateRandom(generator, dist, num_items); 
  }
  else if (distribution == "bimodal") {
    int mode1 = rand() % max_val; 
    int mode2 = rand() % max_val; 
    for (int i = 0; i < num_items; i++) {
      int value = (rand() & 1) ? mode1 : mode2; 
      generated_values.push_back(value); 
    }
  }
  else {
    cout << "INVALID DISTRIBUTION: " << distribution << "\n"; 
  }

  
//   writeToFile(generated_values, output_file); 
  return generated_values; 
}



/*

*/



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
    // cout << "NUMBER BINS: " << bins.size() << '\n'; 
    return bins.size(); 
}

int firstFitDecreasing(int binCapacity, vector<int> items) {
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
    // cout << "NUMBER BINS: " << bins.size() << '\n'; 
    return bins.size(); 
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
//   cout << "NUMBER BINS: " << number_bins << '\n'; 
  return number_bins; 
}

int bestFitDecreasing (vector<int> &items, int bin_size) {
  sort(items.begin(), items.end(), greater<int>()); 
  
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
//   cout << "NUMBER BINS: " << number_bins << '\n'; 
  return number_bins; 
}

int main(int argc, char* argv[]) {
 
    // int bin_size = stoi(argv[1]); 

    // string inputFile = argv[1]; 
    // int bin_size = stoi(argv[2]); 

    int bestFitPerformance = 0;
    int bestFitDecreasingPerformance = 0;
    int firstFitPerformance = 0;
    int firstFitDecreasingPerformance = 0;

    int bin_size = 10;

    for (int i = 0; i < 50; i++) {
        vector<int> items = generateItems(100, 10, "input.txt", "bimodal");
        // vector<int> items = readFromFile("input.txt"); 
        
        bestFitPerformance += bestFit(items, bin_size);
        bestFitDecreasingPerformance += bestFitDecreasing(items, bin_size);
        firstFitPerformance += firstFit(bin_size, items);
        firstFitDecreasingPerformance += firstFitDecreasing(bin_size, items);
    }

    cout << "Best Fit Performance: " << bestFitPerformance/50 << '\n';
    cout << "Best Fit Decreasing Performance: " << bestFitDecreasingPerformance/50 << '\n';
    cout << "First Fit Performance: " << firstFitPerformance/50 << '\n';
    cout << "First Fit Decreasing Performance: " << firstFitDecreasingPerformance/50 << '\n';

    return 0;
}