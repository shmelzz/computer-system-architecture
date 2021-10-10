#ifndef DZ1_2_TRIANGLE_H
#define DZ1_2_TRIANGLE_H

// triangle.h - содержит описание треугольника

#include <stdio.h>
#include <stdlib.h>
#include "random.h"

struct triangle {
    int a_x, a_y, b_x, b_y, c_x, c_y; // координаты углов треугольника
    // значения возможных цветов фигуры
    enum color {
        RED, ORANGE, YELLOW, GREEN, BLUE, DARK_BLUE, PURPLE
    };
    int col;
};

// Ввод параметров треугольника из файла
void Input(triangle &triang, FILE *stream);

// Случайный ввод параметров треугольника
void InputRandom(triangle &triang);

// Вывод параметров треугольника в форматируемый поток
void Output(triangle &triang, FILE *stream);

// Вычисление периметра треугольника
double Perimeter(triangle &triang);

// Получение названия цвета
const char *GetColor(triangle &triang);

#endif //DZ1_2_TRIANGLE_H
