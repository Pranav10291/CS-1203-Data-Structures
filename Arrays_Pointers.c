//Making Arrays, Pointers and the malloc command which allows us to allocate space in the heap
#include <stdio.h>
#include <stdlib.h>

int * generateArray(int n){ // the data type of this function will be an integer pointer, since it is the starting address of the array
  //We are functioning under the assumption n is a positive integer. 
	int * addr; // declaring a new starting address for the array

	addr = malloc( n*sizeof(int) );

	//Validity condition is that memory was allocated successfully, if it fails, we don't run the for loop
	if(addr){ 
		for (int i = 0; i < n; i++){
      addr[i] = i;
    }
	}
	return addr;
}

void printArray(int *a, int n){
	printf("Array = ");
	for (int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}


int main(int argc, char **argv){
	int * a;
	int n = 10;

	a = generateArray(n); // We get the base address of array in a

	printArray(a, n);

	//After using malloc, we need to free the memory to maintain efficiency of the machine
	free(a);
	return 0;
}