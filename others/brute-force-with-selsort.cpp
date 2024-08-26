#include <iostream>
#include <chrono>
using namespace std;

// Fungsi menukar 2 elemen array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi Selection Sort
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }
}

// Fungsi Mencetak Array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Fungsi Input Element Array
void inputArray(int arr[], int size) {
    cout << "Masukkan " << size << " Element Array Tersebut:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

int main() {
    cout << "Selection Sort: Brute Force" << endl;
    int size;
    cout << "Tentukan Ukuran Array: ";
    cin >> size;
    int* arr = new int[size];

    inputArray(arr, size);

    auto start = chrono::high_resolution_clock::now();
    cout << "Array Sebelum di Sortir: ";
    printArray(arr, size);

    selectionSort(arr, size);

    cout << "Array Sesudah di Sortir: ";
    printArray(arr, size);
    auto end = chrono::high_resolution_clock::now();

    delete[] arr;

    chrono::duration<double> cpuTime = end - start;
    cout << "CPU Time: " << cpuTime.count() << " seconds" << endl;

    return 0;
}
