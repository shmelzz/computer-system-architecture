#include "circle.h"

// Ввод данных круга из файла
void Input(circle &circ, FILE *stream) {
    fscanf(stream, "%d %d %d %d", &circ.col, &circ.center_x, &circ.center_y, &circ.radius);
}

// Формирование случайного круга
void InputRandom(circle &circ) {
    circ.center_x = Random();
    circ.center_y = Random();
    circ.radius = Random();
    circ.col = rand() % 7;
}

const char *GetColor(circle &circ) {
    switch (circ.col) {
        case circle::BLUE:
            return "BLUE";
        case circle::DARK_BLUE:
            return "DARK_BLUE";
        case circle::GREEN:
            return "GREEN";
        case circle::ORANGE:
            return "ORANGE";
        case circle::PURPLE:
            return "PURPLE";
        case circle::RED:
            return "RED";
        case circle::YELLOW:
            return "YELLOW";
    }
}

// Вывод информации о круге в файл
void Output(circle &circ, FILE *stream) {
    if (circ.radius <= 0) {
        fprintf(stream, "%s\n", "It is CIRCLE");
        fprintf(stream, "%s\n\n", "But radius was below zero, so it does not exist");
    } else {
        fprintf(stream, "%s\n", "It is CIRCLE");
        fprintf(stream, "%s%d%s%d%s%d%s%s%s%f\n\n", "Center coordinates are: X = ", circ.center_x,
                " Y = ", circ.center_y, ", radius = ", circ.radius,
                ", color = ", GetColor(circ), ", perimeter = ", Perimeter(circ));
    }
}

// Вычисление периметра круга
double Perimeter(circle &circ) {
    const double PI = 3.14159265;
    return 2.0 * PI * circ.radius;
}
