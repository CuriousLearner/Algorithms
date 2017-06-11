/* Sets up entire column and row to 0 of an element if it is 0 */

# include <iostream>

using namespace std;


void resetMatrix(int arr[5][5]) {
    bool rows[5], cols[5];
    memset(rows, true, sizeof rows);
    memset(cols, true, sizeof rows);

    for(int i=0; i < 5; i++) {
        for(int j=0; j < 5; j++) {
            if(arr[i][j] == 0) {
                rows[i] = false;
                cols[j] = false;
            }
        }
    }

    for(int i=0; i < 5; i++) {
        for(int j=0; j < 5; j++) {
            if(!rows[i] || !cols[j])
                arr[i][j] = 0;
        }
    }
} 

void printArray(int arr[5][5]) {
    for(int i=0; i < 5; i++) {
        for(int j=0; j < 5; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}


int main() {
    int a[5][5] = {  
       {0, 1, 2, 3, 48},
       {4, 5, 6, 7, 22},  
       {8, 9, 10, 11, 0},
       {8, 9, 0, 11, 33},
       {8, 9, 10, 11, 8}
    };

    cout << "Array is: " << endl;
    printArray(a);
    resetMatrix(a);
    cout << "After resetMatrix operation, array is: " << endl;
    printArray(a);

    return 0;
}



