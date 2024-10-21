// insertion_sort.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
using namespace std;

// Funkce pro provedení Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Posuneme prvky arr[0..i-1], které jsou větší než key, o jedno místo vpřed
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

// Funkce pro výpis pole
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = { 12, 11, 13, 5, 6 };  // Ukázkové pole
    int n = sizeof(arr) / sizeof(arr[0]); // Velikost pole

    cout << "Původní pole: ";
    printArray(arr, n);

    insertionSort(arr, n);

    cout << "Seřazené pole: ";
    printArray(arr, n);

    return 0;
}
