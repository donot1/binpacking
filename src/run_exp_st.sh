#!/bin/bash

for size in 10 100 1000 10000 100000 1000000 10000000 
do 
  for dist in "uniform" "binomial" "bimodal"
  do 
    echo $dist 
    echo $size
    ./exps.o $size 100 100 10 $dist "../segtree_results/${dist}_${size}"
  done
done
