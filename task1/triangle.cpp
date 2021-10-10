#include "triangle.h"
#include "math.h"

// Ввод треугольника из файла
void Input(triangle &triang, FILE *stream) {
    fscanf(stream, "%d %d %d %d %d %d %d", &triang.col, &triang.a_x,
           &triang.a_y, &triang.b_x, &triang.b_y, &triang.c_x, &triang.c_y);
}

void InputRandom(triangle &triang) {
    triang.col = (rand() % 7);
    double ab;
    double bc;
    double ac;
    do {
        triang.a_x = Random();
        triang.a_y = Random();
        triang.b_x = Random();
        triang.b_y = Random();
        triang.c_x = Random();
        triang.c_y = Random();
        ab = sqrt(pow(triang.b_x - triang.a_x, 2) + pow(triang.b_y - triang.a_y, 2));
        bc = sqrt(pow(triang.c_x - triang.b_x, 2) + pow(triang.c_y - triang.b_y, 2));
        ac = sqrt(pow(triang.c_x - triang.a_x, 2) + pow(triang.c_y - triang.a_y, 2));

    } while ((ac >= (ab + bc)) || (ab >= (bc + ac)) || (bc >= (ac + ab)));
}

const char *GetColor(triangle &triang) {
    switch (triang.col) {
        case triangle::BLUE:
            return "BLUE";
        case triangle::DARK_BLUE:
            return "DARK_BLUE";
        case triangle::GREEN:
            return "GREEN";
        case triangle::ORANGE:
            return "ORANGE";
        case triangle::PURPLE:
            return "PURPLE";
        case triangle::RED:
            return "RED";
        case triangle::YELLOW:
            return "YELLOW";
    }
}

// Вывод информации о треугольнике
void Output(triangle &triang, FILE *stream) {
    double ab = sqrt(pow(triang.b_x - triang.a_x, 2) + pow(triang.b_y - triang.a_y, 2));
    double bc = sqrt(pow(triang.c_x - triang.b_x, 2) + pow(triang.c_y - triang.b_y, 2));
    double ac = sqrt(pow(triang.c_x - triang.a_x, 2) + pow(triang.c_y - triang.a_y, 2));
    if ((ac >= (ab + bc)) || (ab >= (bc + ac)) || (bc >= (ac + ab))) {
        fprintf(stream, "%s\n", "It is TRIANGLE");
        fprintf(stream, "%s\n\n", "But coordinates were incorrect, so it does not exist");
    } else {
        fprintf(stream, "%s\n", "It is TRIANGLE");
        fprintf(stream, "%s%d%s%d%s%d%s%d%s%d%s%d%s%s%s%f\n\n",
                "Angles' coordinates are: a.X = ", triang.a_x, " a.Y = ", triang.a_y,
                ", b.X = ", triang.b_x, ", b.Y = ", triang.b_y, " c.X = ", triang.c_x, " c.Y = ", triang.c_y,
                ", color = ", GetColor(triang), ", perimeter = ", Perimeter(triang));
    }
}

// Подсчет периметра
double Perimeter(triangle &triang) {
    double ab = sqrt(pow(triang.b_x - triang.a_x, 2) + pow(triang.b_y - triang.a_y, 2));
    double bc = sqrt(pow(triang.c_x - triang.b_x, 2) + pow(triang.c_y - triang.b_y, 2));
    double ac = sqrt(pow(triang.c_x - triang.a_x, 2) + pow(triang.c_y - triang.a_y, 2));
    return ab + ac + bc;
}
