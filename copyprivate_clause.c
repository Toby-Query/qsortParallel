#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define TRUE  1
#define FALSE 0

int main()
{
	int TID;
	float rate=1.2;
	omp_set_num_threads(4);
	#pragma omp parallel private(rate,TID)
	{
			TID = omp_get_thread_num();
			#pragma omp single copyprivate(rate)
			{
				rate = rand()*1.0/RAND_MAX;
			}
			printf("Value for variable rate: %f by thread %d\n",rate, TID);
    }  /*-- End of parallel region --*/
	return(0);
}
