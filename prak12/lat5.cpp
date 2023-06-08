#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

void bubbleSortFlag(int arr[], int size) {
    bool swapped;
    for (int i = 0; i < size - 1; ++i) {
        swapped = false;
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void shellSort(int arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int* L = new int[n1];
    int* R = new int[n2];
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[middle + 1 + j];
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;

    int* arr = new int[n];

    srand(time(0));
    for (int i = 0; i < n; ++i)
        arr[i] = rand() % 100;

    auto start = chrono::high_resolution_clock::now();
    insertionSort(arr, n);
    auto end = chrono::high_resolution_clock::now();
    cout << "Waktu running Insertion Sort: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " milidetik" << endl;

    for (int i = 0; i < n; ++i)
        arr[i] = rand() % 100;

    start = chrono::high_resolution_clock::now();
    selectionSort(arr, n);
    end = chrono::high_resolution_clock::now();
    cout << "Waktu running Selection Sort: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " milidetik" << endl;

    for (int i = 0; i < n; ++i)
        arr[i] = rand() % 100;

    start = chrono::high_resolution_clock::now();
    bubbleSort(arr, n);
    end = chrono::high_resolution_clock::now();
    cout << "Waktu running Bubble Sort: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " milidetik" << endl;

    for (int i = 0; i < n; ++i)
        arr[i] = rand() % 100;

    start = chrono::high_resolution_clock::now();
    bubbleSortFlag(arr, n);
    end = chrono::high_resolution_clock::now();
    cout << "Waktu running Bubble Sort (Flag): " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " milidetik" << endl;

    for (int i = 0; i < n; ++i)
        arr[i] = rand() % 100;

    start = chrono::high_resolution_clock::now();
    shellSort(arr, n);
    end = chrono::high_resolution_clock::now();
    cout << "Waktu running Shell Sort : " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " milidetik" << endl;

    for (int i = 0; i < n; ++i)
        arr[i] = rand() % 100;

    start = chrono::high_resolution_clock::now();
    quickSort(arr, 0, n - 1);
    end = chrono::high_resolution_clock::now();
    cout << "Waktu running Quick Sort: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " milidetik" << endl;

    for (int i = 0; i < n; ++i)
        arr[i] = rand() % 100;

    start = chrono::high_resolution_clock::now();
    mergeSort(arr, 0, n - 1);
    end = chrono::high_resolution_clock::now();
    cout << "Waktu running Merge Sort: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " milidetik" << endl;

    delete[] arr;
}
