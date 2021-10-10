#ifndef DZ1_2_CIRCLE_H
#define DZ1_2_CIRCLE_H

// circle.h - содержит описание круга  и его интерфейса

#include <stdio.h>
#include <stdlib.h>
#include "random.h"

// круг
struct circle {
    int center_x, center_y, radius; // координаты центра и радиус
    // значения возможных цветов фигуры
    enum color {
        RED, ORANGE, YELLOW, GREEN, BLUE, DARK_BLUE, PURPLE
    };
    int col;
};

// Ввод параметров круга из файла
void Input(circle &circ, FILE *stream);

// Случайный ввод параметров круга
void InputRandom(circle &circ);

// Вывод параметров круга в форматируемый поток
void Output(circle &circ, FILE *stream);

// Вычисление периметра круга
double Perimeter(circle &circ);

// Получение названия цвета
const char *GetColor(circle &circ);

#endif //DZ1_2_CIRCLE_H
