#include <omp.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int
main()
{
	float * C = new float[NUMS];//input numebr to find the square root 
	omp_set_num_threads( NUMT );//set number of threads
	double time1 = omp_get_wtime();

	#pragma omp parallel for simd //With SIMD 
	for (int i = 0; i < NUMS; i++)
	{
		C[i] = sqrt( i );
	}

	double time2 = omp_get_wtime();
	double performance2 = (double)NUMS / (time2 - time1) / 1000000.; //mega multiples
	printf("Numbers: %d \t , Performance : %8.2lf\n", NUMS, performance2); //performance


}

