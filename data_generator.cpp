#include <iostream> 

using namespace std; 

int main(int argc, char* argv[]) {
  if (argc < 4) {
    cout << R"(USAGE: ./data_generator N MAX_VAL OUTPUT_FILE DISTRIBUTION
            N = number of items
            MAX_VAL = largest possible size of an item
            OUTPUT_FILE = filename to write output to
            DISTRIBUTION = one of (normal, uniform, bimodal)
            )"; 
    return 0; 
  }

  int num_items = stoi(argv[1]); 
  int max_val = stoi(argv[2]); 
  string output_file(argv[3]); 
  string distribution(argv[4]);

}
