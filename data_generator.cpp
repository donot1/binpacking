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


int main(int argc, char* argv[]) {
  if (argc < 4) {
    // cout << "(USAGE: ./data_generator N MAX_VAL OUTPUT_FILE DISTRIBUTION 
    //         N = number of items
    //         MAX_VAL = largest possible size of an item
    //         OUTPUT_FILE = filename to write output to
    //         DISTRIBUTION = one of (binomial, uniform, bimodal)
    //         )"; 
    return 0; 
  }
  
  srand(time(nullptr)); 

  int num_items = stoi(argv[1]); 
  int max_val = stoi(argv[2]); 
  string output_file(argv[3]); 
  string distribution(argv[4]);

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

  
  writeToFile(generated_values, output_file); 
  return 0; 
}
