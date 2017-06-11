# include <iostream>

using namespace std;

void printMaxContiguousArray(int arr[], int size) {
	int max_ending_here = 0;
	int max_so_far = 0;
	int start, end, s;

	for (int i=0; i < size; i++) {
		max_ending_here += arr[i];

		if (max_ending_here < 0) {
			max_ending_here = 0;
			s = i + 1;
		}

		else if (max_ending_here > max_so_far) {
			max_so_far = max_ending_here;
			start = s;
			end = i;
		}
	}

	cout << "Subarray sum " << max_so_far << endl;
	cout << "Start index: " << start << " End index: " << end; 
}

int main() {
	int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int size = sizeof(arr)/sizeof(arr[0]);
	printMaxContiguousArray(arr, size);
	return 0;
}
