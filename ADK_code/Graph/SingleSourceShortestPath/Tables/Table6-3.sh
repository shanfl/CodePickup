#!/bin/bash

# Execute from parent directory
EVAL=../../../bin/eval

OUTPUT=Table6-3.out
rm -f $OUTPUT

NUM_TRIALS=100

# store partial results here...
ACTIVE=/tmp/result.$$

# If non-blank then do Bellman-Ford. Sure? It could take a Loooong time.
DO_BF=""

echo "GRAPH,PQ,DG,optimized,Bellman-Ford" >> $OUTPUT
for i in ../TSP/*.tsp
do
  echo "$i..." 
  echo                   >> $OUTPUT

  # Start off the trial: Dijkstra's algorithm with PQ
  # ------------------------------------------------------
  echo $NUM_TRIALS                                  > $ACTIVE
  T=0
  while [ $T -lt $NUM_TRIALS ]
  do
     ../tsp -f $i |tail -1 | sed 's/secs//'   >> $ACTIVE

     T=$((T+1))
  done
  Z_PQ=`$EVAL < $ACTIVE | cut -f1 -d' '`

  # Start off the trial: Dijkstra's algorithm for DG
  # ------------------------------------------------------
  echo $NUM_TRIALS                                  > $ACTIVE
  T=0
  while [ $T -lt $NUM_TRIALS ]
  do
     ../tspDense -f $i |tail -1 | sed 's/secs//'   >> $ACTIVE

     T=$((T+1))
  done
  Z_DG=`$EVAL < $ACTIVE | cut -f1 -d' '`

  # Start off the trial with optimized dense
  # ------------------------------------------------------
  echo $NUM_TRIALS                                  > $ACTIVE
  T=0
  while [ $T -lt $NUM_TRIALS ]
  do
     ../tsp -d -f $i |tail -1 | sed 's/secs//'>> $ACTIVE

     T=$((T+1))
  done
  Z_RAW=`$EVAL < $ACTIVE | cut -f1 -d' '`

  if [ "x$DO_BF" != "x" ]
  then
    # Start off the trial for Bellman-Ford
    # ------------------------------------------------------
    echo $NUM_TRIALS                                        > $ACTIVE
    T=0
    while [ $T -lt $NUM_TRIALS ]
    do
       ../tspBellmanFord -f $i |tail -1 | sed 's/secs//'>> $ACTIVE
  
       T=$((T+1))
    done
    Z_BF=`$EVAL < $ACTIVE | cut -f1 -d' '`
  fi

  echo "$i,$Z_PQ,$Z_DG,$Z_RAW,$Z_BF"             >> $OUTPUT

done

