#!/bin/sh

# A single script to be able to run just the 1048576 on binarySearch
# for p=0.0

NT=100
SZ=100000
P="0.0"
Z="1048576"

REPORT=table5-2.output
#rm $REPORT

CONFIG=config5-2.rc
for z in $Z 
do 
  for p in $P
  do
    echo "# generated"                  >  $CONFIG
    echo "BINS=../binarySearchInteger"  >> $CONFIG
    echo "TRIALS=$NT"                   >> $CONFIG
    echo "LOW=$SZ"                      >> $CONFIG
    echo "HIGH=$SZ"                     >> $CONFIG
    echo "INCREMENT=*2"                 >> $CONFIG
    echo "EXTRAS=-p $p -z $z"           >> $CONFIG
  
    LINE=`../../bin/suiteRun.sh $CONFIG | tail -1`

    echo "$z,$p,$LINE"                  >> $REPORT
  done
done

