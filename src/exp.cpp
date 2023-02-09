#include <functional>
#include <iostream>
#include <fstream> 
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
  double num_bins; 
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
  return {(double)num_bins, exec_time_ms};  
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

TestOutput averageOutputs(vector<TestOutput> &outputs) {
  double total_bins = 0, total_exec_time = 0; 
  for (auto output : outputs) {
    total_bins += output.num_bins;
    total_exec_time += output.exec_time_ms; 
  }
  return {total_bins / outputs.size(), 
          total_exec_time / outputs.size()}; 
}

int main(int argc, char* argv[]) {
  srand(1);

  if (argc < 5) {
    cout << "USAGE: ./exp NUMBER_ITEMS  MAX_ITEM_SIZE  BIN_CAPACITY  NUMBER_TRIALS  DISTRIBUTION  RESULTS_OUTPUT_FILE\n\n";  
    return 0; 
  }

  int num_items = stoi(argv[1]); 
  int max_item_size = stoi(argv[2]);
  int bin_capacity = stoi(argv[3]); 
  int num_trials = stoi(argv[4]); 
  string distribution = argv[5];
  string output_file = argv[6]; 

  
  DataParameters test_params = {num_items, max_item_size, distribution}; 
  auto results = testDistribution(test_params, bin_capacity, num_trials); 

  ofstream resultsFile; 
  resultsFile.open(output_file); 
  for (auto elem : results) {
    resultsFile << "AVERAGE RESULTS FOR ALG: " << elem.first << '\n';
    resultsFile << averageOutputs(elem.second); 
  }
  resultsFile.close(); 
  return 0;
}
