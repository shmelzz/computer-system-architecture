#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

// Ввод фигуры из файла
Shape *Shape::staticInput(std::ifstream &stream) {
  int k;
  stream >> k;
  Shape *shape = nullptr;
  switch (k) {
  case 1:
    shape = new Rectangle;
    break;
  case 2:
    shape = new Triangle;
    break;
  case 3:
    shape = new Circle;
    break;
  default:
    shape = staticInputRandom();
  }
  shape->input(stream);
  return shape;
}

// Случайный ввод фигуры
Shape *Shape::staticInputRandom() {
  int k = rand() % 3 + 1;
  Shape *shape = nullptr;
  switch (k) {
  case 1:
    shape = new Rectangle;
    break;
  case 2:
    shape = new Triangle;
    break;
  case 3:
    shape = new Circle;
    break;
  }
  shape->inputRandom();
  return shape;
}

// Функция получения цвета
std::string Shape::getColor() const {
  switch (color) {
  case BLUE:
    return "BLUE";
  case DARK_BLUE:
    return "DARK_BLUE";
  case GREEN:
    return "GREEN";
  case ORANGE:
    return "ORANGE";
  case PURPLE:
    return "PURPLE";
  case RED:
    return "RED";
  case YELLOW:
    return "YELLOW";
  }
}
