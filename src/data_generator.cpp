#include <iostream> 
#include <fstream> 
#include <random> 
#include <vector> 
#include "binpacking.h"

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


 vector<int> generateItems (int num_items, int max_val, 
                            string output_file, string distribution) { 
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
    throw(1); 
  }

  
  writeToFile(generated_values, output_file); 
  return generated_values; 
}
