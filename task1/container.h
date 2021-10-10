#ifndef DZ1_2_CONTAINER_H
#define DZ1_2_CONTAINER_H

// container.h - содержит тип данных, представляющий простейший контейнер

#include "shape.h"

// Простейший контейнер на основе одномерного массива
struct container {
    enum {
        max_len = 10000
    }; // максимальная длина
    int length; // текущая длина
    shape *cont[max_len];
};

// Инициализация контейнера
void Initialize(container &cont);

// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &cont);

// Ввод содержимого контейнера из указанного потока
void Input(container &cont, FILE *stream);

// Случайный ввод содержимого контейнера
void InputRandom(container &cont, int size);

// Вывод содержимого контейнера в указанный поток
void Output(container &cont, FILE *stream);

void swap(shape *a, shape *b);

int partition(shape *cont[10000], int low, int high);

void SortContainer(container &c, int low, int high);

void quickSort(shape *cont[10000], int low, int high);

#endif //DZ1_2_CONTAINER_H
