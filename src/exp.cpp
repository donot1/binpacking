#include <functional>
#include <iostream>
#include <vector>
#include <string> 
#include <random> 
#include <algorithm> 
#include <chrono> 
#include <map> 
#include <unordered_map> 
#include "binpacking.h" 
using namespace std;

struct PackingAlg {
  function<int(int, vector<int>&)> alg;
  string name; 
}; 

vector<PackingAlg> PACKING_ALGS = 
  { { bestFit, "bestFit" }, 
    { bestFitDecreasing, "bestFitDecreasing" }, 
    { firstFit, "firstFit" } , 
    { firstFitDecreasing, "firstFitDecreasing" } }; 

vector<string> DISTRIBUTIONS = 
  { "uniform", "binomial", "bimodal" }; 

struct TestInput {
  vector<int> items;
  int binCapacity;
};

struct TestOutput {
  int num_bins; 
  double exec_time_ms;
};

ostream& operator<< (ostream& os, const TestOutput& out) {
  os << "BINS : " << out.num_bins << '\n'; 
  os << "EXEC TIME (ms) : " << out.exec_time_ms << '\n'; 
  return os; 
}

struct DataParameters {
  int num_items; 
  int max_item; 
  string distribution; 

  string getFileName(int suffix) {
    return distribution + "_" + to_string(num_items) + "_items_" + to_string(suffix); 
  }
};  

TestOutput runTest(PackingAlg algorithm, TestInput input) {
  auto start = chrono::high_resolution_clock::now();
  int num_bins = algorithm.alg(input.binCapacity, input.items); 
  auto end = chrono::high_resolution_clock::now();

  chrono::duration<double, std::milli> duration_ms = end - start; 
  double exec_time_ms = duration_ms.count(); 
  return {num_bins, exec_time_ms};  
}

map<string, TestOutput> testDataset(DataParameters params, int binCapacity, string output_file)  {
  vector<int> items = generateItems(params.num_items, params.max_item, 
                                    output_file, params.distribution); 
  TestInput input = {items, binCapacity}; 
  
  map<string, TestOutput> results; 
  for (auto alg : PACKING_ALGS) {
    results[alg.name] = runTest(alg, input); 
  }

  return results; 
}

map<string, vector<TestOutput>> testDistribution (DataParameters params, int binCapacity, int numTests) {
  map<string, vector<TestOutput>> combined_results; 
  for (int i = 0; i < numTests; i++) {
    string outputFile = "../data/" + params.getFileName(i); 
    auto test_result = testDataset(params, binCapacity, outputFile); 
    for (auto res : test_result)
      combined_results[res.first].push_back(res.second); 
  }
  return combined_results; 
}

int main(int argc, char* argv[]) {
  srand(1); 
  
  DataParameters test_params = {1000, 100, "uniform"}; 
  auto results = testDistribution(test_params, 100, 10); 
  
  for (auto elem : results) {
    cout << "RESULTS FOR ALG: " << elem.first << '\n'; 
    for (auto x : elem.second) {
      cout << x << '\n'; 
    }
  } 
  return 0;
}
