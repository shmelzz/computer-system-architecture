// container.cpp - содержит функции обработки контейнера
#include "container.h"
#include <stdio.h>

// Инициализация контейнера
void Initialize(container &cont) {
    cont.length = 0;
}

// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &cont) {
    for (int i = 0; i < cont.length; i++) {
        delete cont.cont[i];
    }
    cont.length = 0;
}

// Ввод содержимого контейнера из указанного потока
void Input(container &cont, FILE *stream) {
    int k;
    while (fscanf(stream, "%d", &k) != EOF) {
        if ((cont.cont[cont.length] = Input(stream, k)) != nullptr) {
            cont.length++;
        }
    }
}

// Случайный ввод содержимого контейнера
void InputRandom(container &cont, int size) {
    while (cont.length < size) {
        if ((cont.cont[cont.length] = InputRandom()) != nullptr) {
            cont.length++;
        }
    }
}

// Вывод содержимого контейнера в файл
void Output(container &cont, FILE *stream) {
    fprintf(stream, "%s%d%s\n", "Container contains ", cont.length, " elements.");
    for (int i = 0; i < cont.length; i++) {
        fprintf(stream, "%d%s", i + 1, ": ");
        Output(*(cont.cont[i]), stream);
    }
}

// Поменять местами элементы контейнера
void swap(shape *a, shape *b) {
    shape t = *a;
    *a = *b;
    *b = t;
}

// Деление контейнера для сортировки
int partition(shape **cont, int low, int high) {
    shape basis = *cont[high];
    double basis_number = Perimeter(basis);
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (Perimeter(*cont[j]) < basis_number) {
            i++;
            swap(cont[i], cont[j]);
        }
    }
    swap(cont[i + 1], cont[high]);
    return (i + 1);
}

// QuickSort
void quickSort(shape **cont, int low, int high) {
    if (low < high) {
        int pi = partition(cont, low, high);
        quickSort(cont, low, pi - 1);
        quickSort(cont, pi + 1, high);
    }
}

// Применение сортировки к контейнеру
void SortContainer(container &c, int low, int high) {
    quickSort(c.cont, low, high);
}
