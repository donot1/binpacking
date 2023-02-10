#include <vector> 
#include <string> 
using namespace std; 

// utils 
vector<int> readFromFile (string file); 
void writeToFile (vector<int> &items, string file); 

vector<int> generateItems(int num_items, int max_val, 
                          string output_file, string distribution); 


// bin packing algorithms 
int firstFit(int binCapacity, vector<int> &items); 
int firstFitDecreasing(int binCapacity, vector<int> &items);
int bestFit(int binCapacity, vector<int> &items);
int bestFitDecreasing(int binCapacity, vector<int> &items); 
int firstFitSegTree(int binCapacity, vector<int> &items);
int firstFitDecreasingSegTree(int binCapacity, vector<int> &items); 
