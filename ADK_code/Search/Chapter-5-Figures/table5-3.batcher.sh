#!/bin/sh

# Things are a bit backwards for searching, I'm afraid...

NT=100
SZ=524288      # must be evenly divisible by all Z
P="1.0 0.0"
Z="4096 8192 16384 32768 65536 131072 262144 524288"

REPORT=table5-3.output
rm -f $REPORT

CONFIG=config5-3.rc
for z in $Z 
do 
  for p in $P
  do
    echo "# generated"                     >  $CONFIG
    echo "BINS=../binarySearchFileInteger" >> $CONFIG
    echo "TRIALS=$NT"                      >> $CONFIG
    echo "LOW=$SZ"                         >> $CONFIG
    echo "HIGH=$SZ"                        >> $CONFIG
    echo "INCREMENT=*2"                    >> $CONFIG
    echo "EXTRAS=-p $p -z $z"              >> $CONFIG
  
    LINE=`../../bin/suiteRun.sh $CONFIG | tail -1`

    echo "$z,$p,$LINE"                     >> $REPORT
  done
done

