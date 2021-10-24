#ifndef DZSECOND_TRIANGLE_H
#define DZSECOND_TRIANGLE_H

// triangle.h - содержит описание треугольника
#include <fstream>
#include "rnd.h"
#include "shape.h"

class Triangle : public Shape {
private:
  // координаты углов треугольника
  int a_x{}, a_y{}, b_x{}, b_y{}, c_x{}, c_y{};

public:
  // Конструктор
  Triangle() = default;

  // Деструктор
  ~Triangle() override = default;

  // Ввод параметров треугольника из файла
  void input(std::ifstream &stream) override;

  // Случайный ввод параметров треугольника
  void inputRandom() override;

  // Вывод параметров треугольника в форматируемый поток
  void output(std::ofstream &stream) override;

  // Вычисление периметра треугольника
  double perimeter() override;
};

#endif // DZSECOND_TRIANGLE_H
