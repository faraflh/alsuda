#include <iostream>
#include <cstdlib>

using namespace std;

void InsertionSortAscending(int data[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = data[i];
        j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

void InsertionSortDescending(int data[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = data[i];
        j = i - 1;
        while (j >= 0 && data[j] < key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

void SelectionSortAscending(int data[], int n) {
    int i, j, temp, min, min_id;
    i = 0;
    while (i < n - 1) {
        min_id = i;
        min = data[i];
        for (j = i + 1; j < n; j++)
            if (data[j] < min) {
                min = data[j];
                min_id = j;
            }
        temp = data[min_id];
        data[min_id] = data[i];
        data[i] = temp;
        i++;
    }
}

void SelectionSortDescending(int data[], int n) {
    int i, j, temp, max, max_id;
    i = 0;
    while (i < n - 1) {
        max_id = i;
        max = data[i];
        for (j = i + 1; j < n; j++)
            if (data[j] > max) {
                max = data[j];
                max_id = j;
            }
        temp = data[max_id];
        data[max_id] = data[i];
        data[i] = temp;
        i++;
    }
}

void BubbleSortAscending(int data[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (data[i] > data[j]) {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

void BubbleSortDescending(int data[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (data[i] < data[j]) {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

void BubbleSortFlagAscending(int data[], int n) {
    int i = 0, j, temp;
    bool did_swap = true;
    while (i < n - 1 && did_swap) {
        for (j = 0; j < n - i - 1; j++) {
            did_swap = false;
            if (data[j] > data[j + 1]) {
                temp = data[j + 1];
                data[j + 1] = data[j];
                data[j] = temp;
                did_swap = true;
            }
        }
        i++;
    }
}

void BubbleSortFlagDescending(int data[], int n) {
    int i = 0, j, temp;
    bool did_swap = true;
    while (i < n - 1 && did_swap) {
        for (j = 0; j < n - i - 1; j++) {
            did_swap = false;
            if (data[j] > data[j + 1]) {
                temp = data[j + 1];
                data[j + 1] = data[j];
                data[j] = temp;
                did_swap = true;
            }
        }
        i++;
    }
}

void ShellSortAscending(int data[], int n) {
    int i, jarak, temp;
    bool did_swap = true;
    jarak = n;
    while (jarak > 1) {
        jarak = jarak / 2;
        did_swap = true;
        while (did_swap) {
            did_swap = false;
            i = 0;
            while (i < (n - jarak)) {
                if (data[i] > data[i + jarak]) {
                    temp = data[i];
                    data[i] = data[i + jarak];
                    data[i + jarak] = temp;
                    did_swap = true;
                }
                i++;
            }
        }
    }
}

void ShellSortDescending(int data[], int n) {
    int i, jarak, temp;
    bool did_swap = true;
    jarak = n;
    while (jarak > 1) {
        jarak = jarak / 2;
        did_swap = true;
        while (did_swap) {
            did_swap = false;
            i = 0;
            while (i < (n - jarak)) {
                if (data[i] < data[i + jarak]) {
                    temp = data[i];
                    data[i] = data[i + jarak];
                    data[i + jarak] = temp;
                    did_swap = true;
                }
                i++;
            }
        }
    }
}

void QuickSortAscending(int data[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = data[(left + right) / 2];
    while (i <= j) {
        while (data[i] < pivot)
            i++;
        while (data[j] > pivot)
            j--;
        if (i < j) {
            tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
            i++;
            j--;
        };
    };
    if (right < i)
        QuickSortAscending(data, left, i);
    if (j < left)
        QuickSortAscending(data, j, right);
}

void QuickSortDescending(int data[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = data[(left + right) / 2];
    while (i < j) {
        while (data[i] > pivot)
            i++;
        while (data[j] < pivot)
            j--;
        if (i <= j) {
            tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
            i++;
            j--;
        };
    };
    if (left < j)
        QuickSortDescending(data, left, j);
    if (i < right)
        QuickSortDescending(data, i, right);
}

void MergeA(int data[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = data[l + i];
    for (j = 0; j < n2; j++)
        R[j] = data[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            data[k] = L[i];
            i++;
        } else {
            data[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        data[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        data[k] = R[j];
        j++;
        k++;
    }
}

void MergeSortAscending(int data[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        MergeSortAscending(data, l, m);
        MergeSortAscending(data, m + 1, r);
        MergeA(data, l, m, r);
    }
}

void MergeD(int data[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = data[l + i];
    for (j = 0; j < n2; j++)
        R[j] = data[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            data[k] = L[i];
            i++;
        } else {
            data[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        data[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        data[k] = R[j];
        j++;
        k++;
    }
}

void MergeSortDescending(int data[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        MergeSortDescending(data, l, m);
        MergeSortDescending(data, m + 1, r);
        MergeD(data, l, m, r);
    }
}

int main() {
    int length;
    cout << "		Algoritma Pengurutan	" << endl;
    cout << "-----------------------------" << endl;
    cout << "Input Jumlah Elemen Array : ";
    cin >> length;
    int data[length];
    for (int i = 0; i < length; i++) {
        cout << "Nilai Elemen ke-" << i << " = ";
        cin >> data[i];
    }
    cout << endl;

    system("cls");
    char pilihan;
    cout << "---------------------------" << endl;
    cout << "|| Menu	||\n";
    cout << "----------------------------" << endl;
    cout << "\n1. Insertion Sort";
    cout << "\n2. Selection Sort";
    cout << "\n3. Bubble Sort";
    cout << "\n4. Bubble Sort dengan Flag";
    cout << "\n5. Shell Sort";
    cout << "\n6. Quick Sort";
    cout << "\n7. Merge Sort";
    cout << "\nMasukkan Pilihan : ";
    cin >> pilihan;
    if (pilihan == '1') {
        system("cls");
        char pilihan2;
        cout << "-- Insertion Sort --";
        cout << "\n1. Ascending";
        cout << "\n2. Descending";
        cout << "\nMasukkan Pilihan : ";
        cin >> pilihan2;
        if (pilihan2 == '1') {
            cout << "\nData Belum Terurut : " << endl;
            for (int i = 0; i < length; i++) {
                cout << data[i] << " ";
            }
            cout << endl;

            InsertionSortAscending(data, length);
            cout << "\nData Sudah Terurut Secara Ascending :" << endl;
            for (int i = 0; i < length; i++) {
                cout << data[i] << " ";
            }
            cout << endl;
        }
        if (pilihan2 == '2') {
            cout << "\nData Belum Terurut : " << endl;
            for (int i = 0; i < length; i++) {
                cout << data[i] << " ";
            }
            cout << endl;
            InsertionSortDescending(data, length);
        }

            int length;
            cout << "		Algoritma Pengurutan	\n";
            cout << "------------------------------\n";
            cout << "Input Jumlah Elemen Array : ";
            cin >> length;
            int data[length];
            for (int i = 0; i < length; i++) {
                cout << "Nilai Elemen ke-" << i << " = ";
                cin >> data[i];
            }
            cout << endl;

            system("cls");
            char pilihan;
            cout << "---------------------------\n";
            cout << "|| Menu	||\n";
            cout << "-----------------------";
            cout << "\n1. Insertion Sort";
            cout << "\n2. Selection Sort";
            cout << "\n3. Bubble Sort";
            cout << "\n4. Bubble Sort dengan Flag";
            cout << "\n5. Shell Sort";
            cout << "\n6. Quick Sort";
            cout << "\n7. Merge Sort";
            cout << "\nMasukkan Pilihan : ";
            cin >> pilihan;
            if (pilihan == '1') {
                system("cls");
                char pilihan2;
                cout << "-- Insertion Sort --";
                cout << "\n1. Ascending";
                cout << "\n2. Descending";
                cout << "\nMasukkan Pilihan : ";
                cin >> pilihan2;
                if (pilihan2 == '1') {
                    cout << "\nData Belum Terurut : " << endl;
                    for (int i = 0; i < length; i++) {
                        cout << data[i] << " ";
                    }
                    cout << endl;

                    InsertionSortAscending(data, length);
                    cout << "\nData Sudah Terurut Secara Ascending :" << endl;
                    for (int i = 0; i < length; i++) {
                        cout << data[i] << " ";
                    }
                    cout << endl;
                }
                if (pilihan2 == '2') {
                    cout << "\nData Belum Terurut : " << endl;
                    for (int i = 0; i < length; i++) {
                        cout << data[i] << " ";
                    }
                    cout << endl;
                    InsertionSortDescending(data, length);
                    cout << "\nData Sudah Terurut Secara Descending :" << endl;
                    for (int i = 0; i < length; i++) {
                        cout << data[i] << " ";
                    }
                    cout << endl;
                }
            }

            if (pilihan == '2') {
                system("cls");
                char pilihan2;
                cout << "-- Selection Sort --";
                cout << "\n1. Ascending";
                cout << "\n2. Descending";
                cout << "\nMasukkan Pilihan : ";
                cin >> pilihan2;
                if (pilihan2 == '1') {
                    cout << "\nData Belum Terurut :" << endl;
                    for (int i = 0; i < length; i++) {
                        cout << data[i] << " ";
                    }
                    cout << endl;
                    SelectionSortAscending(data, length);
                    cout << "\nData Sudah Terurut Secara Ascending :" << endl;
                    for (int i = 0; i < length; i++) {
                        cout << data[i] << " ";
                    }
                    cout << endl;
                }
                if (pilihan2 == '2') {
                    cout << "\nData Belum Terurut : " << endl;
                    for (int i = 0; i < length; i++) {
                        cout << data[i] << " ";
                    }
                    cout << endl;
                    SelectionSortDescending(data, length);
                    cout << "\nData Sudah Terurut Secara Descending :" << endl;
                    for (int i = 0; i < length; i++) {
                        cout << data[i] << " ";
                    }
                    cout << endl;
                }
            }

            if (pilihan == '3') {
                system("cls");
                char pilihan2;
                cout << "-- Bubble Sort --";
                cout << "\n1. Ascending";
                cout << "\n2. Descending";
                cout << "\nMasukkan Pilihan : ";
                cin >> pilihan2;
                if (pilihan2 == '1') {
                    cout << "\nData Belum Terurut : " << endl;
                    for (int i = 0; i < length; i++) {
                        cout << data[i] << " ";
                    }
                    cout << endl;
                    BubbleSortAscending(data, length);
                    cout << "\nData Sudah Terurut Secara Ascending :" << endl;
                    for (int i = 0; i < length; i++) {
                        cout << data[i] << " ";
                    }
                    cout << endl;
                }
                if (pilihan2 == '2') {
                    cout << "\nData Belum Terurut : " << endl;
                    for (int i = 0; i < length; i++) {
                        cout << data[i] << " ";
                    }
                    cout << endl;
                    BubbleSortDescending(data, length);
                    cout << "\nData Sudah Terurut Secara Descending :" << endl;
                    for (int i = 0; i < length; i++) {
                        cout << data[i] << " ";
                    }
                    cout << endl;
                }
            }

            if (pilihan == '4') {
                system("cls");
                char pilihan2;
                cout << "-- Bubble Sort dengan Flag --";
                cout << "\n1. Ascending";
                cout << "\n2. Descending";
                cout << "\nMasukkan Pilihan : ";
                cin >> pilihan2;
                if (pilihan2 == '1') {
                    cout << "\nData Belum Terurut :" << endl;
                    for (int i = 0; i < length; i++) {
                        cout << data[i] << " ";
                    }
                    cout << endl;
                    BubbleSortFlagAscending(data, length);
                    cout << "\nData Sudah Terurut Secara Ascending :" << endl;
                    for (int i = 0; i < length; i++) {
                        cout << data[i] << " ";
                    }
                    cout << endl;
                }
                if (pilihan2 == '2') {
                    cout << "\nData Belum Terurut :" << endl;
                    for (int i = 0; i < length; i++) {
                        cout << data[i] << " ";
                    }
                    cout << endl;
                    BubbleSortFlagDescending(data, length);
                    cout << "\nData Sudah Terurut Secara Descending :" << endl;
                    for (int i = 0; i < length; i++) {
                        cout << data[i] << " ";
                    }
                    cout << endl;
                }
            }

            if (pilihan == '5') {
                system("cls");
                char pilihan2;
                cout << "-- Shell Sort --";
                cout << "\n1. Ascending";
                cout << "\n2. Descending";
                cout << "\nMasukkan Pilihan : ";
                cin >> pilihan2;
                if (pilihan2 == '1') {
                    cout << "\nData Belum Terurut :" << endl;
                    for (int i = 0; i < length; i++) {
                        cout << data[i] << " ";
                    }
                    cout << endl;
                    ShellSortAscending(data, length);
                    cout << "\nData Sudah Terurut Secara Ascending :" << endl;
                    for (int i = 0; i < length; i++) {
                        cout << data[i] << " ";
                    }
                    cout << endl;
                }
                if (pilihan2 == '2') {
                    cout << "\nData Belum Terurut :" << endl;
                    for (int i = 0; i < length; i++) {
                        cout << data[i] << " ";
                    }
                    cout << endl;
                    ShellSortDescending(data, length);
                    cout << "\nData Sudah Terurut Secara Descending :" << endl;
                    for (int i = 0; i < length; i++) {
                        cout << data[i] << " ";
                    }
                    cout << endl;
                }
            }

            if (pilihan == '6') {
                system("cls");
                char pilihan2;
                cout << "-- Quick Sort --";
                cout << "\n1. Ascending";
                cout << "\n2. Descending";
                cout << "\nMasukkan Pilihan : ";
                cin >> pilihan2;
                if (pilihan2 == '1') {
                    cout << "\nData Belum Terurut :" << endl;
                    for (int i = 0; i < length; i++) {
                        cout << data[i] << " ";
                    }
                    cout << endl;
                    QuickSortAscending(data, 0, length - 1);
                    cout << "\nData Sudah Terurut Secara Ascending :" << endl;
                    for (int i = 0; i < length; i++) {
                        cout << data[i] << " ";
                    }
                    cout << endl;
                }
                if (pilihan2 == '2') {
                    cout << "\nData Belum Terurut :" << endl;
                    for (int i = 0; i < length; i++) {
                        cout << data[i] << " ";
                    }
                    cout << endl;
                    QuickSortDescending(data, 0, length - 1);
                    cout << "\nData Sudah Terurut Secara Descending :" << endl;
                    for (int i = 0; i < length; i++) {
                        cout << data[i] << " ";
                    }
                    cout << endl;
                }

                if (pilihan == '7') {
                    system("cls");
                    char pilihan2;
                    cout << "-- Merge Sort --";
                    cout << "\n1. Ascending";
                    cout << "\n2. Descending";
                    cout << "\nMasukkan Pilihan : ";
                    cin >> pilihan2;
                    if (pilihan2 == '1') {
                        cout << "\nData Belum Terurut :" << endl;
                        for (int i = 0; i < length; i++) {
                            cout << data[i] << " ";
                        }
                        cout << endl;
                        MergeSortAscending(data, 0, length - 1);
                        cout << "\nData Sudah Terurut Secara Ascending :" << endl;
                        for (int i = 0; i < length; i++) {
                            cout << data[i] << " ";
                        }
                        cout << endl;
                    }
                }
                if (pilihan2 == '2') {
                    cout << "\nData Belum Terurut :" << endl;
                    for (int i = 0; i < length; i++) {
                        cout << data[i] << " ";
                    }
                    cout << endl;
                    MergeSortDescending(data, 0, length - 1);
                    cout << "\nData Sudah Terurut Secara Descending :" << endl;
                    for (int i = 0; i < length; i++) {
                        cout << data[i] << " ";
                    }
                    cout << endl;
                }
            }
        }
    }

