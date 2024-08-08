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
	#pragma omp parallel firstprivate(rate) private(TID)
	{
			TID = omp_get_thread_num();
			printf("Value for variable rate: %f by thread %d\n",rate, TID);
			#pragma omp barrier
			rate = rand()*1.0/RAND_MAX;
			printf("\nValue for variable rate: %f by thread %d\n",rate, TID);
    }  /*-- End of parallel region --*/


	return(0);
}
