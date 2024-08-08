#include <omp.h>
#include <stdio.h>
#include <unistd.h>
void work(int a, int j, int k){sleep(1);}
void main(){
   int j, k, a=3;
   #pragma omp parallel num_threads(4)
   {
      #pragma omp for collapse(2) private(j,k) schedule(static,1) ordered
      for (k=0; k<3; k++)
         for (j=0; j<2; j++){
            #pragma omp ordered
            printf("%d %d %d\n", omp_get_thread_num(), k, j);
            /* end ordered */
            work(a,j,k);
         }
         #pragma omp single
         printf("------------\n");
         #pragma omp for private(k) schedule(static,1) ordered
         for(k=0; k<6; k++){
            #pragma omp ordered
            printf("%d %d %d\n", omp_get_thread_num(), k/2, k%2);
         }
   }
}
//i: k = 0 -- (0, 1,) k = 1 -- (2, 3,) k = 2 ---(4, 5)
