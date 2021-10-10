#ifndef DZ1_2_RECTANGLE_H
#define DZ1_2_RECTANGLE_H

// rectangle.h - содержит описание прямоугольника  и его интерфейса

#include <stdio.h>
#include <stdlib.h>
#include "random.h"

// прямоугольник
struct rectangle {
    int a_x, a_y, b_x, b_y; // координаты координаты левого верхнего и правого нижнего углов
    // значения возможных цветов фигуры
    enum color {
        RED, ORANGE, YELLOW, GREEN, BLUE, DARK_BLUE, PURPLE
    };
    int col;
};

// Ввод параметров прямоугольника из файла
void Input(rectangle &rect,  FILE *stream);

// Случайный ввод параметров прямоугольника
void InputRandom(rectangle &rect);

// Вывод параметров прямоугольника в форматируемый поток
void Output(rectangle &rect,  FILE *stream);

// Вычисление периметра прямоугольника
double Perimeter(rectangle &rect);

// Получение названия цвета
const char *GetColor(rectangle &rect);

#endif //DZ1_2_RECTANGLE_H
