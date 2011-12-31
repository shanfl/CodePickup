#!/bin/sh

Z=1000
NT=100
LOW=4096
HIGH=131072
P="1.0 0.5 0.25 0.0"

REPORT=table5-1.output
rm -f $REPORT

for i in $P
do
  echo "# generated"                >  config.rc
  echo "BINS=../searchInteger"      >> config.rc
  echo "TRIALS=$NT"                 >> config.rc
  echo "LOW=$LOW"                   >> config.rc
  echo "HIGH=$HIGH"                 >> config.rc
  echo "INCREMENT=*2"               >> config.rc
  echo "EXTRAS=-p $i -z $Z"         >> config.rc

  echo "$Z,$T,$i"                   >> $REPORT
  ../../bin/suiteRun.sh config.rc   >> $REPORT
done


