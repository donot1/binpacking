#include <functional>
#include <iostream>
#include <vector>
#include <string> 
#include <random> 
#include <algorithm> 
#include <chrono> 
#include "binpacking.h" 
using namespace std;

typedef function<int(int, vector<int>&)> PackingAlg; 

vector<PackingAlg> PACKING_ALGS = 
  { bestFit, bestFitDecreasing, 
    firstFit, firstFitDecreasing }; 

struct TestInput {
  vector<int> items; 
  int binCapacity; 
}; 

pair<int, double> runTest(PackingAlg alg, TestInput input) {
  auto start = chrono::high_resolution_clock::now();
  int num_bins = alg(input.binCapacity, input.items); 
  auto end = chrono::high_resolution_clock::now();

  chrono::duration<double, std::milli> duration_ms = end - start; 
  double exec_time_ms = duration_ms.count(); 
  return {num_bins, exec_time_ms};  
}


int main(int argc, char* argv[]) {

  return 0;
}
