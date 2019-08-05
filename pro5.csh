#!/bin/csh

echo "---------------Without SIMD-------------------------------------------------"
foreach n (1000 10000 100000 500000 3000000 15000000 64000000)
	echo ""
	foreach t (1 2 4 8)
		icpc -DNUMT=$t -DNUMS=$n -o pro5 pro5.cpp -lm --openmp -align -qopt-report=3 -qopt-report-phase=vec -no-vec
		./pro5
	end
end

echo "-----------------------------------With--SIMD-------------------------------"

foreach n (1000 10000 100000 500000 3000000 15000000 64000000)
	echo ""
	foreach t (1 2 4 8)
		icpc -DNUMT=$t -DNUMS=$n -o pro5 pro5_1.cpp -lm --openmp -align -qopt-report=3 -qopt-report-phase=vec
		./pro5
	end
end

