#ifndef DZSECOND_CIRCLE_H
#define DZSECOND_CIRCLE_H

#include "rnd.h"
#include "shape.h"
#include <fstream>

// круг
class Circle : public Shape {
private:
  int center_x{}, center_y{}, radius{};

public:
  Circle() = default;
  ~Circle() override = default;
  // Ввод параметров треугольника из файла
  void input(std::ifstream &stream) override;
  // Случайный ввод параметров треугольника
  void inputRandom() override;
  // Вывод параметров треугольника в форматируемый поток
  void output(std::ofstream &stream) override;
  // Вычисление периметра треугольника
  double perimeter() override;
};

#endif // DZSECOND_CIRCLE_H
