#include "circle.h"

void Circle::input(std::ifstream &stream) {
  stream >> color >> center_x >> center_y >> radius;
}
void Circle::inputRandom() {
  center_x = Random();
  center_y = Random();
  radius = Random();
  color = rand() % 7;
}
void Circle::output(std::ofstream &stream) {
  if (radius <= 0) {
    stream << "It is CIRCLE" << '\n';
    stream << "But radius was below zero, so it does not exist" << '\n' << '\n';
  } else {
    stream << "It is CIRCLE" << '\n';
    stream << "Center coordinates are: X = " << center_x << " Y = " << center_y
           << ", radius = " << radius << ", color = " << getColor()
           << ", perimeter = " << perimeter() << '\n'
           << '\n';
  }
}
double Circle::perimeter() {
  const double PI = 3.14159265;
  return 2.0 * PI * radius;
}
