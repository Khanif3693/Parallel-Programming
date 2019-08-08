#!/bin/sh


for i in 1 2
	do
	echo TYPE = $i
	for t in 1 2 4
		do 
		echo NUMBER OF THREADS = $t
		for p in 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
			do
			echo NUM = $p
			g++ -DNUM=$p pro3.c -o prog -lm -fopenmp
			./prog $t $i
			done
		done
	done
	