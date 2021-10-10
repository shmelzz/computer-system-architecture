#ifndef DZ1_2_SHAPE_H
#define DZ1_2_SHAPE_H
// shape.h - содержит описание обобщающей геометрической фигуры

#include "rectangle.h"
#include "triangle.h"
#include "circle.h"

// структура, обобщающая все имеющиеся фигуры
struct shape {
    // значения ключей для каждой из фигур
    enum key {
        RECTANGLE, TRIANGLE, CIRCLE
    };
    key k; // ключ
    // используемые альтернативы
    union {
        rectangle r;
        triangle t;
        circle c;
    };
};

// Ввод обобщенной фигуры
shape *Input(FILE *stream, int k);

// Случайный ввод обобщенной фигуры
shape *InputRandom();

// Вывод обобщенной фигуры
void Output(shape &s, FILE *stream);

// Вычисление периметра обобщенной фигуры
double Perimeter(shape &s);

#endif //DZ1_2_SHAPE_H
