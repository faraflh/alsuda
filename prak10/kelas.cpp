void BubbleSortFlag(int arr[]) {
    int i = 0, j, temp;
    bool did_swap = true;
    while (i < MAX - 1 && did_swap) {
        for (j = 0; j < MAX - i - 1; j++) {
            did_swap = false;
            if (arr[j] > arr[j + 1]) {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                did_swap = true;
            }
        }
        i++;
    }
}

void BubbleSort(int arr[]) {
    int i, j, temp;
    for (i = 0; i < MAX - 1; i++) {
        for (j = 0; j < MAX - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void ShellSort(int arr[]) {
    int i, jarak, temp;
    bool did_swap = true;
    jarak = MAX;
    while (jarak > 1) {
        jarak = jarak / 2;
        did_swap = true;
        while (did_swap) {
            did_swap = false;
            i = 0;
            while (i < (MAX - jarak)) {
                if (arr[i] > arr[i + jarak]) {
                    temp = arr[i];
                    arr[i] = arr[i + jarak];
                    arr[i + jarak] = temp;
                    did_swap = true;
                }
                i++;
            }
        }
    }
}