#!/bin/bash

for size in 100000 
do 
  for dist in "uniform" "binomial" "bimodal"
  do 
    echo $dist 
    echo $size
    ./exp.o $size 100 100 10 $dist "../results/${dist}_${size}"
  done
done
