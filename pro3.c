#include"stdio.h"
#include"stdlib.h"
#include"omp.h"


#define NUM  0 
struct s

{

         float value;

         int pad[NUM];

} fix1[4];

struct s2

{

         float value;

      

} fix2[4]; 

         

 int main (int argc, char *argv[])
 {
	 int NUMT,type;
	 
	 if(argc == 3)
	 {
		 NUMT = atoi(argv[1]);
		 type = atoi(argv[2]);
	 }
	 else
	 {
		fprintf(stderr,"check entered argument\n"); 
	 }
		printf("\n*****START*****");
         omp_set_num_threads( NUMT );

 

         int someBigNumber = 1000000000;

		 double time0 = omp_get_wtime();
		 if(type== 1)
		 {

         #pragma omp parallel for

         for( int i = 0; i < 4; i++ )

         {

                 for( int j = 0; j < someBigNumber; j++ )

                 {

                          fix1[ i ].value = fix1[ i ].value + 2.;

                 }

         }
		 double time1 = omp_get_wtime();
		fprintf(stdout,"\n TYPE is FIX1 \n NUMPAD IS %d\n AND THREAD IS %d\t",NUM,NUMT); 
		 fprintf( stdout, "performance is  %f\n", ((double)(4.0*someBigNumber))/(1000000.*(time1 - time0) ));
		printf("******END*****");
		}
		 else if(type==2)
		 {

         #pragma omp parallel for

         for( int i = 0; i < 4; i++ )

         {
				 float tmp = fix2[i].value;
                 for( int j = 0; j < someBigNumber; j++ )

                 {

                          tmp = tmp + 2.;

                 }
			fix2[i].value=tmp;
         }
		 double time1 = omp_get_wtime();
		 fprintf(stdout,"\n TYPE is FIX2 \n NUMPAD IS %d\n AND THREAD IS %d\t",NUM,NUMT); 
		 fprintf( stdout, "%f\n", ((double)(4.0*someBigNumber))/(1000000.*(time1 - time0) ));
		 printf("******END*****");
		 }
		 
		 else
		 {
			 fprintf(stderr,"\n Please check your entered argument");
		 }
		 return 0;
 }