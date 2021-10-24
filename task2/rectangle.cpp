#include "rectangle.h"

// Ввод параметров прямоугольника из файла
void Rectangle::input(std::ifstream &stream) {
  stream >> color >> a_x >> a_y >> b_x >> b_y;
}

// Случайный ввод параметров прямоугольника
void Rectangle::inputRandom() {
  a_x = Random();
  a_y = Random();
  b_x = Random();
  b_y = Random();
  color = rand() % 7;
}

// Вывод параметров прямоугольника
void Rectangle::output(std::ofstream &stream) {
  stream << "It is RECTANGLE" << '\n';
  stream << "Angles' coordinates are: a.X = " << a_x << " a.Y = " << a_y
         << ", b.X = " << b_x << ", b.Y = " << b_y << ", color = " << getColor()
         << ", perimeter = " << perimeter() << '\n'
         << '\n';
}

// Вычисление периметра прямоугольника
double Rectangle::perimeter() {
  int x;
  int y;
  if (b_x > a_x) {
    x = b_x - a_x;
  } else {
    x = a_x - b_x;
  }
  if (b_y > a_y) {
    y = b_y - a_y;
  } else {
    y = a_y - b_y;
  }
  return 2.0 * (abs(x) + abs(y));
}
