#!/bin/bash

bin=orderUp

T=1
while [ $T -lt 200 ]
do
  echo "$T..."
  ./$bin -n $T | grep secs >> report.$bin
  T=$((T+1))
done

