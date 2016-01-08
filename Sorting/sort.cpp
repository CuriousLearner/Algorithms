# include <iostream>

using namespace std;

void bubble_sort(int arr[], int n) {
	int i,k, temp;
	for(k=0; k < n-1; k++) {
		for(i=0; i < n-k-1; i++) {
			if(arr[i] > arr[i+1]) {
				swap(arr[i], arr[i+1]);
			}
		}
	}
}

void selection_sort(int arr[], int n) {
	int i, j, temp, minimum;
	for(i=0; i < n-1; i++) {
		minimum = i;
		for(j=i+1; j < n; j++) {
			if(arr[minimum] > arr[j]) {
				minimum = j;
			}
		}
		swap(arr[i], arr[minimum]);
	}
}

void insertion_sort(int arr[], int n) {
	int i, j, temp;
	for(i=0; i < n; i++) {
		j = i;
		temp = arr[i];
		while(j > 0 && arr[j-1] > temp) {
			arr[j] = arr[j-1];
			j--;
		}
		arr[j] = temp;
	}
}

// Merge Sort Start

void merge(int arr[], int start, int mid, int end) {
	int p = start, q = mid+1, k = 0;
	int aux_arr[end-start+1];

	for(int i=start; i <= end; i++) {
		if(p > mid) {
			aux_arr[k++] = arr[q++];
		}
		else if(q > end) {
			aux_arr[k++] = arr[p++];
		}
		else if(arr[p] < arr[q]) {
			aux_arr[k++] = arr[p++];
		}
		else {
			aux_arr[k++] = arr[q++];
		}
	}
	for(int j=0; j < k; j++) {
		arr[start++] = aux_arr[j];
	}
}

void merge_sort(int arr[], int start, int end) {
	if(start < end) {
		int mid = (start + end) / 2;
		merge_sort(arr, start, mid);
		merge_sort(arr, mid+1, end);

		merge(arr, start, mid, end);
	}
}

// Merge Sort End

// Quick Sort

int partition(int arr[], int start, int end) {
	int i = start + 1;
	int piv = arr[start];
	for(int j=start+1; j <= end; j++) {
		if(arr[j] < piv) {
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[start], arr[i-1]);
	return i-1;
}

void quick_sort(int arr[], int start, int end) {
	if(start < end) {
		int piv_pos = partition(arr, start, end);
		quick_sort(arr, start, piv_pos-1);
		quick_sort(arr, piv_pos+1, end);
	}
}


// Quick Sort End

// Count Sort Start

void counting_sort(int arr[], int aux[], int out[], int n, int max1) {
	int i, j;
	for(i=0; i <= max1; i++) {
		aux[i] = 0;
	}
	for(j=0; j < n; j++) {
		aux[arr[j]]++;
	}
	for(i=1; i <= max1; i++) {
		aux[i] = aux[i] + aux[i-1];
	}
	for(j=n-1; j >= 0; j--) {
		out[aux[arr[j]]-1] = arr[j];
		aux[arr[j]]--;
	}
}

// Count Sort End

int main() {
	int i, n;
	int arr[] = {4,5,2,1,7,6,3,1,98,32,65,34,8};
	n = sizeof(arr)/sizeof(arr[0]);
	bubble_sort(arr, n);
	cout << "Bubble Sort" << endl;
	for(i=0; i < n;i++) {
		cout << arr[i] << endl;
	}
	int a[] = {4,5,2,1,7,6,3,1,98,32,65,34,8};
	selection_sort(a, n);
	cout << "Selection Sort" << endl;
	for(i=0; i < n;i++) {
		cout << a[i] << endl;
	}
	int b[] = {4,5,2,1,7,6,3,1,98,32,65,34,8};
	insertion_sort(b, n);
	cout << "Insertion Sort" << endl;
	for(i=0; i < n;i++) {
		cout << b[i] << endl;
	}
	int c[] = {4,5,2,1,7,6,3,1,98,32,65,34,8};
	merge_sort(c, 0, n-1);
	cout << "Merge Sort" << endl;
	for(i=0; i < n;i++) {
		cout << c[i] << endl;
	}
	int d[] = {4,5,2,1,7,6,3,1,98,32,65,34,8};
	quick_sort(d, 0, n-1);
	cout << "Quick Sort" << endl;
	for(i=0; i < n;i++) {
		cout << d[i] << endl;
	}
	int count_sort_array[] = {6,6,4,3,7,7,6,3,2,3,1,1,8};
	int size = sizeof(count_sort_array)/sizeof(count_sort_array[0]);
	int res_count_sort[size];
	int max1=0;
	for(i=0; i < n; i++) {
		if(count_sort_array[i] > max1)
			max1 = count_sort_array[i];
	}
	int aux[max1];
	counting_sort(count_sort_array, aux, res_count_sort, size, max1);
	cout << "counting sort" << endl;
	for(i=0; i <= n-1;i++) {
		cout << res_count_sort[i] << endl;
	}
}
