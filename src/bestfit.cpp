#include <iostream> 
#include <fstream> 
#include <string>
#include <vector> 
#include <set> 
#include "binpacking.h"

using namespace std; 

int bestFit (int binCapacity, vector<int> &items) {
  int number_bins = 0; 
  multiset<int> capacities; 
  for (int item : items) {
    auto best_fit = capacities.lower_bound(item); 
    if (best_fit == capacities.end()) {
      number_bins++; 
      capacities.insert(binCapacity-item);
    }
    else {
      capacities.insert(*best_fit - item); 
      capacities.erase(best_fit); 
    }
  }
  return number_bins; 
}

