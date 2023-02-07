#include <iostream> 
using namespace std; 

int main(int argc, char* argv[]) {
  if (argc < 1) {
    cout << "USAGE: ./firstfit input_file\n"; 
    cout << "OUTPUT: number_bins\n";
  }
  return 0; 
}
