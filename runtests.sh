#!/bin/bash

OUT=""
counter=1
case $1 in 
	c)
	while [ $counter -le $4 ]
	do
        	res="${counter},$(./EETests $2 $3)"
		OUT+="${res}\n"
        	echo -e $res
		((counter++))
	done
        ;;
        py)
        while [ $counter -le $4 ]
        do
               res="${counter},$(python3 PyTest/p$2.py $3)"
               OUT+="${res}\n"
               echo -e $res
               ((counter++))
        done
        ;;
esac
echo -e $OUT >> out.csv

