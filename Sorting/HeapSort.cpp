# include <iostream>

using namespace std;

void max_heapify(int arr[], int i, int size) {
	int left = (2 * i) + 1;
	int right = (2 * i) + 2;

	int largest;

	if(left < size && arr[left] > arr[i])
		largest = left;
	else
		largest = i;
	if (right < size && arr[right] > arr[largest])
		largest = right;

	if (largest != i) {
		swap(arr[largest], arr[i]);
		max_heapify(arr, largest, size);
	}
}

void build_maxheap(int arr[], int size) {
	for(int i = size/2; i >= 0; i--) {
		max_heapify(arr, i, size);
	}
}


void heap_sort(int arr[], int size) {
	int heap_size = size;
	build_maxheap(arr, size);

	for(int i=size-1; i > 0; i--) {
		swap(arr[0], arr[i]);
		heap_size = heap_size - 1;
		max_heapify(arr, 0, heap_size);
	}
}


int main() {
	int arr[10] = {5, 2, 1, 9, 44, 2, 11, 49, 3, 2};
	/*
						5
					/		\
				2				1
			  /   \           /   \
			9		44 		2		11
		  /   \     /
		49		3	2

	*/
	int size = sizeof(arr)/sizeof(arr[0]);
	cout << "Heap right now is: " << endl;
	for(int i=0; i < size; i++)
		cout << arr[i] << endl;
	heap_sort(arr, size);
	cout << "Heap after heap sort is: " << endl;
	for(int i=0; i < size; i++)
		cout << arr[i] << endl;
	return 0;
}
