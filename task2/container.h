#ifndef DZSECOND_CONTAINER_H
#define DZSECOND_CONTAINER_H

// container.h - содержит тип данных, представляющий простейший контейнер

#include "shape.h"

// контейнер на основе одномерного массива
class Container {
private:
    void clear();// Очистка контейнера от данных
    int length;  // текущая длина
    Shape *elements[10000];

public:
    Container();
    ~Container();
    // Ввод содержимого контейнера из указанного потока
    void input(std::ifstream &stream);
    // Случайный ввод содержимого контейнера
    void inputRandom(int size);
    // Вывод содержимого контейнера в указанный поток
    void output(std::ofstream &stream);

    int partition(int low, int high);

    void sortContainer(int low, int high);

    void quickSort(int low, int high);

    int getLength() const;
};

#endif//DZSECOND_CONTAINER_H
