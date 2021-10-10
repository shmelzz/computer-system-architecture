#ifndef DZ1_2_RANDOM_H
#define DZ1_2_RANDOM_H

#include <stdio.h>
#include <stdlib.h>

// Рандомайзер для координат фигур
inline int Random() {
    return rand() % 100 + 1;
}

#endif //DZ1_2_RANDOM_H
