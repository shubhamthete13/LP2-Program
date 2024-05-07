// Implement Greedy search algorithm for any of the following application:
// I. Selection Sort
#include<iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    int i, j, temp, minIndex;

    for(i = 0; i < n - 1; i++) {
        minIndex = i;
        for(j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    cout << "\nSorted array in ascending order:\n";
    for(i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n\nSorted array in descending order:\n";
    for(i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    selectionSort(arr, n);

    return 0;
}

//Output:
/*Enter the size of the array: 5
Enter the elements of the array:
1
6
2
4
7

Sorted array in ascending order:
1 2 4 6 7

Sorted array in descending order:
7 6 4 2 1
--------------------------------*/
