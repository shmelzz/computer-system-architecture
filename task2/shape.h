#ifndef DZSECOND_SHAPE_H
#define DZSECOND_SHAPE_H

// shape.h - содержит описание обобщающей геометрической фигуры
#include "rnd.h"
#include <fstream>

class Shape {
protected:
  int color{};
  enum color { RED, ORANGE, YELLOW, GREEN, BLUE, DARK_BLUE, PURPLE };

public:
  virtual ~Shape() = default;

  // Ввод обобщенной фигуры
  static Shape *staticInput(std::ifstream &stream);

  // Случайный ввод обобщенной фигуры
  virtual void input(std::ifstream &stream) = 0;

  static Shape *staticInputRandom();

  // Виртуальный метод ввода случайной фигуры
  virtual void inputRandom() = 0;

  // Вывод обобщенной фигуры
  virtual void output(std::ofstream &stream) = 0;

  // Вычисление периметра обобщенной фигуры
  virtual double perimeter() = 0;

  // Получение цвета фигуры
  std::string getColor() const;
};

#endif // DZSECOND_SHAPE_H
