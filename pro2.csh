#!/bin/csh

#number of threads:
foreach t (1 2 3 4 6 8 10 12 14 16)
	echo NUMTHREADS = $t
	#number of subdivision
	foreach s (1 2 3 4)
		echo TYPE = $s
		icpc   -o   prog   pro2.c   -O3   -lm   -openmp  -align  -qopt-report=3  -qopt-report-phase=vec
		./prog $s $t
	end
end
