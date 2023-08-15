#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define Max_Arr 100000

int array[Max_Arr];

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
///////////////////////////////////////////////////////////////////////////////////////////
int pivot_place (int array[], int low, int high){
	int pivot = array[high]; 
	int i = (low - 1); 
	for (int j = low; j <= high- 1; j++){
		if (array[j] <= pivot){
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}
///////////////////////////////////////////////////////////////////////////////////////////
void quickSort(int array[], int low, int high){
	if (low < high){
		int pi = pivot_place(array, low, high);
		#pragma omp task firstprivate(array,low,pi)
		{
			quickSort(array,low, pi - 1);

		}


		{
			quickSort(array, pi + 1, high);

		}


	}
}
///////////////////////////////////////////////////////////////////////////////////////////
void display(int array[], int size){
	int i;
	for (i=0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
}
///////////////////////////////////////////////////////////////////////////////////////////
int main(){
	double start_time, total_time;
	for( int i = 0; i < Max_Arr-1; i++ ){
       array[i] = rand() % 1000 +1;
    }
	int n = sizeof(array)/sizeof(array[0]);

omp_set_num_threads(8);
start_time = omp_get_wtime();
#pragma omp parallel
 {

 int thread_id = omp_get_thread_num();
    int num_threads = omp_get_num_threads();

#pragma omp single nowait


	 quickSort(array, 0, n-1);


}

	total_time = omp_get_wtime() - start_time;
	printf("\n Execution time was %lf seconds\n ",total_time);

  printf("\n");
	return 0;
}
