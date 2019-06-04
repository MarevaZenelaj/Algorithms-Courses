#include <iostream>
using namespace std; 


void max_heapify(int array[], int i){
	int largest, temp;
	int size = array.size()
	int left = 2*i;
	int right = 2*i+1;
	if(left <= size && array[left] > array[i])
		largest = left;
	else
		largest = i;
	if(right<= size && array[right] > array[largest])
		largest = right;
	if(largest != i)
		temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;  
	max_heapify(array, largest);
}

void build_max_heapify(int array[]){
	int heap_size = array.size();
	int start = floor(heap_size/2);
	for(int i = start; i > 0; i--){
		max_heapify(array, i);
	}
}

void heapsort(int array[]){
	build_max_heapify(array);
	int start = floor(array.size()/2);
	int temp;
	for(int i = start; i > 1; i--){
		temp = array[1];
		array[1] = array[i];
		array[i] = temp;
		// add heapsize--;
		max_heapify(A,1);
	}
}

int heap_maximum(int array[]){
	return array[0];
}

int heap_extract_max(int array[]){
	if(heap-size[A] < 1)
	     cout << "heap underflow";
     int max  = A[1];
     array[1] = array[heap-size[array]];
     heap-size[array] = heap-size[array] - 1;
     max_heapify(array,1);
     return max;
}



int main(){
	
	return 0;
}