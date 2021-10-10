// shape.cpp - содержит процедуры связанные с обработкой обобщенной фигуры и создания произвольной фигуры

#include "shape.h"
#include <stdio.h>
#include <stdlib.h>

// Ввод параметров обобщенной фигуры из файла
shape *Input(FILE *stream, int k) {
    shape *sp;
    switch (k) {
        case 1:
            sp = new shape;
            sp->k = shape::RECTANGLE;
            Input(sp->r, stream);
            return sp;
        case 2:
            sp = new shape;
            sp->k = shape::TRIANGLE;
            Input(sp->t, stream);
            return sp;
        case 3:
            sp = new shape;
            sp->k = shape::CIRCLE;
            Input(sp->c, stream);
            return sp;
        default:
            return nullptr;
    }
}

// Случайный ввод обобщенной фигуры
shape *InputRandom() {
    shape *sp;
    int k = rand() % 3 + 1;
    switch (k) {
        case 1:
            sp = new shape;
            sp->k = shape::RECTANGLE;
            InputRandom(sp->r);
            return sp;
        case 2:
            sp = new shape;
            sp->k = shape::TRIANGLE;
            InputRandom(sp->t);
            return sp;
        case 3:
            sp = new shape;
            sp->k = shape::CIRCLE;
            InputRandom(sp->c);
            return sp;
        default:
            return nullptr;
    }
}

// Вывод параметров текущей фигуры в поток
void Output(shape &s, FILE *stream) {
    switch (s.k) {
        case shape::RECTANGLE:
            Output(s.r, stream);
            break;
        case shape::TRIANGLE:
            Output(s.t, stream);
            break;
        case shape::CIRCLE:
            Output(s.c, stream);
            break;
        default:
            fprintf(stream, "%s\n", "Incorrect figure!");
            break;
    }
}

// Вычисление периметра фигуры
double Perimeter(shape &figure) {
    switch (figure.k) {
        case shape::RECTANGLE:
            return Perimeter(figure.r);
        case shape::TRIANGLE:
            return Perimeter(figure.t);
        case shape::CIRCLE:
            return Perimeter(figure.c);
        default:
            return 0.0;
    }
}
