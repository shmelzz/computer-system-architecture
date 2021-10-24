#ifndef DZSECOND_RND_H
#define DZSECOND_RND_H

#include <cstdio>
#include <cstdlib>

// Рандомайзер для координат фигур
inline int Random() {
    return rand() % 100 + 1;
}

#endif//DZSECOND_RND_H
