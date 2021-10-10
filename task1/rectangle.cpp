#include "rectangle.h"

// Ввод параметров прямоугольника из файла
void Input(rectangle &rect, FILE *stream) {
    fscanf(stream, "%d %d %d %d %d", &rect.col, &rect.a_x, &rect.a_y, &rect.b_x, &rect.b_y);
}

// Случайный ввод параметров прямоугольника
void InputRandom(rectangle &rect) {
    rect.a_x = Random();
    rect.a_y = Random();
    rect.b_x = Random();
    rect.b_y = Random();
    rect.col = rand() % 7;
}

// Получение цвета
const char *GetColor(rectangle &rect) {
    switch (rect.col) {
        case rectangle::BLUE:
            return "BLUE";
        case rectangle::DARK_BLUE:
            return "DARK_BLUE";
        case rectangle::GREEN:
            return "GREEN";
        case rectangle::ORANGE:
            return "ORANGE";
        case rectangle::PURPLE:
            return "PURPLE";
        case rectangle::RED:
            return "RED";
        case rectangle::YELLOW:
            return "YELLOW";
    }
}

// Вывод параметров прямоугольника в форматируемый поток
void Output(rectangle &rect, FILE *stream) {
    fprintf(stream, "%s\n", "It is RECTANGLE");
    fprintf(stream, "%s%d%s%d%s%d%s%d%s%s%s%f\n\n",
            "Angles' coordinates are: a.X = ", rect.a_x,
            " a.Y = ", rect.a_y, ", b.X = ", rect.b_x,
            ", b.Y = ", rect.b_y, ", color = ", GetColor(rect),
            ", perimeter = ", Perimeter(rect));
}

// Вычисление периметра прямоугольника
double Perimeter(rectangle &rect) {
    int x;
    int y;
    if (rect.b_x > rect.a_x) {
        x = rect.b_x - rect.a_x;
    } else {
        x = rect.a_x - rect.b_x;
    }
    if (rect.b_y > rect.a_y) {
        y = rect.b_y - rect.a_y;
    } else {
        y = rect.a_y - rect.b_y;
    }
    return 2.0 * (abs(x) + abs(y));
}
