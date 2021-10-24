#ifndef DZSECOND_RECTANGLE_H
#define DZSECOND_RECTANGLE_H

// rectangle.h - содержит описание прямоугольника  и его интерфейса
#include <fstream>
#include "rnd.h"
#include "shape.h"

// прямоугольник
class Rectangle : public Shape {
private:
  // координаты координаты левого верхнего и правого нижнего углов
  int a_x{}, a_y{}, b_x{}, b_y{};

public:
  // Конструктор
  Rectangle() = default;
  // Деструктор
  ~Rectangle() override = default;
  // Ввод параметров треугольника из файла
  void input(std::ifstream &stream) override;
  // Случайный ввод параметров треугольника
  void inputRandom() override;
  // Вывод параметров треугольника в форматируемый поток
  void output(std::ofstream &stream) override;
  // Вычисление периметра треугольника
  double perimeter() override;
};

#endif // DZSECOND_RECTANGLE_H
