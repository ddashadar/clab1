#include <iostream>

void bubbleSort(int array[], int size) {

    // цикл для доступа к каждому элементу массива
    for (int step = 0; step < size; ++step) {
        // цикл для сравнения элементов
        for (int i = 0; i < size - step; ++i) {
            // сравниваем два соседних элемента
            if (array[i] > array[i + 1]) {
                // меняем расположение элементов, если они не в нужном порядке
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

// выводим массив
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << "  " << array[i];
    }
    std::cout << "\n";
}


void countSort(int array[], int size) {
    int output[10]; // выходной массив
    int count[10]; // этот массив используется для хранения количества элементов в массиве
    int max = array[0];

    // находим максимальный элемент массива
    for (int i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }
    // инициализируем количественный массив нулями
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }
    // сохраняем количество каждого элемента
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }
    // находим кумулятивную сумму элементов количественного массива
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    // находим индекс каждого элемента исходного массива в количественном массиве и помещаем элементы в выходной массив
    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }
    // вставляем сохраненные элементы в оригинальный массив
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}


void merge(int arr[], int p, int q, int r) {

    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int l, int r) {
    if (l < r) {
        // делим масиив на части, m iэто точка где массив делится
        int m = l + (r - l) / 2;

        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);

        //объединяем отсортированные части массива
        merge(array, l, m, r);
    }
}


int main() {
    int array1[] = {-2, 45, 0, 11, -9};
    // находим длину массива
    int size1 = sizeof(array1) / sizeof(array1[0]);

    bubbleSort(array1, size1);

    std::cout << "Sorted array: \n";
    printArray(array1, size1);


    int array2[] = {4, 2, 2, 8, 3, 3, 1};
    int size2 = sizeof(array2) / sizeof(array2[0]);

    countSort(array2, size2);

    std::cout << "Sorted array: \n";
    printArray(array2, size2);


    int array3[] = {6, 5, 12, 10, 9, 1};
    int size3 = sizeof(array3) / sizeof(array3[0]);

    mergeSort(array3, 0, size3 - 1);

    std::cout << "Sorted array: \n";
    printArray(array3, size3);
    return 0;
}

