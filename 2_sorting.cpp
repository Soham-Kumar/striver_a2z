#include <bits/stdc++.h>
using namespace std;

// ---------------------- Selection Sort ----------------------
int* selectionSort(int *arr, int lenarr) {
    int* sortedArr = new int[lenarr];
    memcpy(sortedArr, arr, lenarr * sizeof(int));
    
    for (int i = 0; i < lenarr; i++) {
        for (int j = i + 1; j < lenarr; j++) {
            if (sortedArr[i] > sortedArr[j]) {
                swap(sortedArr[i], sortedArr[j]);
            }
        }
    }
    return sortedArr;
}



// ---------------------- Bubble Sort ----------------------
int* bubbleSort(int *arr, int lenarr){
    
    int* sorteddArray = new int[lenarr];
    memcpy(sorteddArray, arr, lenarr * sizeof(int));
    bool unsorted = true;

    while(unsorted){
        for(int i = 0; i<lenarr-1; i++){
            if(i==0){
                unsorted = false;
            }
            if(sorteddArray[i] > sorteddArray[i+1]){
                swap(sorteddArray[i], sorteddArray[i+1]);
                unsorted = true;
            }
        }
    }

    return sorteddArray;
}


// ---------------------- Insertion Sort ----------------------
int* insertionSort(int *arr, int lenarr){
    
    int* sortedArray = new int[lenarr];
    memcpy(sortedArray, arr, lenarr * sizeof(int));

    for(int i = 0; i<lenarr; i++){
        for(int j = i+1; j<lenarr; j++){
            for(int k = i; k >= 0; k--){
                if(sortedArray[j] < sortedArray[k]){
                    swap(sortedArray[j], sortedArray[k]);
                }
            }
        }
    }

    return sortedArray;
    
}

// Better version of Insertion Sort
int* insertionSortBetter(int* arr, int lenarr){
    int* sortedArray = new int[lenarr];
    memcpy(sortedArray, arr, lenarr * sizeof(int));

    for (int i = 1; i < lenarr; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    return sortedArray;
}



// ---------------------- Merge Sort ----------------------
int* merge(int* left, int lenLeft, int* right, int lenRight) {
    int* result = (int*)malloc((lenLeft + lenRight) * sizeof(int));
    int i = 0, j = 0, k = 0;

    while (i < lenLeft && j < lenRight) {
        if (left[i] < right[j]) {
            result[k++] = left[i++];
        } else {
            result[k++] = right[j++];
        }
    }

    while (i < lenLeft) {
        result[k++] = left[i++];
    }

    while (j < lenRight) {
        result[k++] = right[j++];
    }

    return result;
}

int* mergeSort(int* arr, int lenarr) {
    if (lenarr <= 1) {
        return arr;  // if array has 0 or 1 elements
    }

    int mid = lenarr / 2;
    int* leftHalf = (int*)malloc(mid * sizeof(int));
    int* rightHalf = (int*)malloc((lenarr - mid) * sizeof(int));

    for (int i = 0; i < mid; i++) {
        leftHalf[i] = arr[i];
    }
    for (int i = mid; i < lenarr; i++) {
        rightHalf[i - mid] = arr[i];
    }

    int* sortedLeft = mergeSort(leftHalf, mid);
    int* sortedRight = mergeSort(rightHalf, lenarr - mid);

    int* sortedArr = merge(sortedLeft, mid, sortedRight, lenarr - mid);

    free(leftHalf);
    free(rightHalf);

    return sortedArr;
}




// ---------------------- Quick Sort ----------------------
// 
int* quickSort(int* arr, int lenarr) {
    if (lenarr <= 1) {
        return arr;
    }

    int pivot = 
    return arr;
}



// Function to print the array
void printArray(int *arr, int lenarr) {
    for (int i = 0; i < lenarr; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[10] = {24, 27, 43, 12, 32, 16, 18, 32, 2, 8};
    int lenarr = sizeof(arr) / sizeof(int);
    cout << "Length of given array is " << lenarr << endl;

    int* sortedArr = selectionSort(arr, lenarr);
    cout << "Selection Sort: ";
    printArray(sortedArr, lenarr);
    delete[] sortedArr;

    sortedArr = bubbleSort(arr, lenarr);
    cout<<"Bubble Sort: ";
    printArray(sortedArr, lenarr);
    delete[] sortedArr;

    sortedArr = insertionSort(arr, lenarr);
    cout<<"Insertion Sort: ";
    printArray(sortedArr, lenarr);
    delete[] sortedArr;

    sortedArr = mergeSort(arr, lenarr);
    cout<<"Merge Sort: ";
    printArray(sortedArr, lenarr);
    delete[] sortedArr;

    sortedArr = quickSort(arr, lenarr);
    cout<<"Quick Sort: ";
    printArray(sortedArr, lenarr);
    delete[] sortedArr;
    

    return 0;
}
