#include <bits/stdc++.h> 
#include "binpacking.h" 

using namespace std; 

int main() {
  for (int i = 0; i < 10; i++) {
    int length = rand() % 200;
    int bin_capacity = 100; 
    auto data = generateItems(length, 100, "garbo", "uniform"); 
    
    cout << "SEG TREE: " << firstFitSegTree(bin_capacity, data) << '\n'; 
    cout << "FF: " << firstFit(bin_capacity, data) << '\n'; 
  }
}
