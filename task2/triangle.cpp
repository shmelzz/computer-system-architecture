#include "triangle.h"
#include "cmath"

// Ввод треугольника из файла
void Triangle::input(std::ifstream &stream) {
  stream >> color >> a_x >> a_y >> b_x >> b_y >> c_x >> c_y;
}

// Вывод информации о треугольнике
void Triangle::output(std::ofstream &stream) {
  double ab = sqrt(pow(b_x - a_x, 2) + pow(b_y - a_y, 2));
  double bc = sqrt(pow(c_x - b_x, 2) + pow(c_y - b_y, 2));
  double ac = sqrt(pow(c_x - a_x, 2) + pow(c_y - a_y, 2));
  if ((ac >= (ab + bc)) || (ab >= (bc + ac)) || (bc >= (ac + ab))) {
    stream << "It is TRIANGLE" << '\n';
    stream << "But coordinates were incorrect, so it does not exist" << '\n'
           << '\n';
  } else {
    stream << "It is TRIANGLE" << '\n';
    stream << "Angles' coordinates are: a.X = " << a_x << " a.Y = " << a_y
           << ", b.X = " << b_x << ", b.Y = " << b_y << " c.X = " << c_x
           << " c.Y = " << c_y << ", color = " << getColor()
           << ", perimeter = " << perimeter() << '\n'
           << '\n';
  }
}

// Создание рандомного треугольника
void Triangle::inputRandom() {
  color = rand() % 7;
  double ab;
  double bc;
  double ac;
  do {
    a_x = Random();
    a_y = Random();
    b_x = Random();
    b_y = Random();
    c_x = Random();
    c_y = Random();
    ab = sqrt(pow(b_x - a_x, 2) + pow(b_y - a_y, 2));
    bc = sqrt(pow(c_x - b_x, 2) + pow(c_y - b_y, 2));
    ac = sqrt(pow(c_x - a_x, 2) + pow(c_y - a_y, 2));

  } while ((ac >= (ab + bc)) || (ab >= (bc + ac)) || (bc >= (ac + ab)));
}

// Подсчет периметра
double Triangle::perimeter() {
  double ab = sqrt(pow(b_x - a_x, 2) + pow(b_y - a_y, 2));
  double bc = sqrt(pow(c_x - b_x, 2) + pow(c_y - b_y, 2));
  double ac = sqrt(pow(c_x - a_x, 2) + pow(c_y - a_y, 2));
  return ab + ac + bc;
}
