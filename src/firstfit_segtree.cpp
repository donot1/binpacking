#include <iostream> 
#include <fstream> 
#include <string> 
#include <vector>
#include "binpacking.h"
using namespace std; 

struct SegmentTree {
  vector<int> tree; 
  int bin_count; 
  int bin_capacity; 
  int tree_size; 
    
  int computeSize (int n) {
    int i = 1; 
    while (i < n) i *= 2; 
    return i; 
  }
  
  void updateBin(int index, int item_size) {
    index += tree_size; 
    if (tree[index] == bin_capacity) 
      bin_count++;
    tree[index] -= item_size;
    for (index /= 2; index >= 1; index /= 2)
      tree[index] = max(tree[2*index], tree[2*index+1]); 
    return; 
  }

  int findBin(int item_size) {
    int curr = 1; 
    while (curr < tree_size) {
      if (tree[curr*2] >= item_size)
        curr = curr*2; 
      else 
        curr = curr*2 + 1; 
    }
    return curr - tree_size; 
  }

  void placeItem(int item_size) {
    int bin = findBin(item_size); 
    updateBin(bin, item_size); 
  }

  SegmentTree(const vector<int> &items, int bin_size) : 
              bin_capacity(bin_size), 
              bin_count(0),
              tree_size(computeSize(items.size())) {
    tree = vector<int>(2*tree_size, bin_size); 
  }
}; 

int firstFitSegTree(int binCapacity, vector<int> &items) {
  SegmentTree segTree(items, binCapacity); 
  for (auto item : items) {
    segTree.placeItem(item); 
  }
  return segTree.bin_count; 
}
