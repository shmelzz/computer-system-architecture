#include "container.h"
#include <algorithm>

// Конструктор
Container::Container() { length = 0; }

// Очистка контейнера от элементов (освобождение памяти)
void Container::clear() {
  for (int i = 0; i < length; i++) {
    delete elements[i];
  }
  length = 0;
}

// Ввод содержимого контейнера из указанного потока
void Container::input(std::ifstream &stream) {
  while (!stream.eof()) {
    if ((elements[length] = Shape::staticInput(stream)) != nullptr) {
      length++;
    }
  }
}

// Случайный ввод содержимого контейнера
void Container::inputRandom(int size) {
  while (length < size) {
    if ((elements[length] = Shape::staticInputRandom()) != nullptr) {
      ++length;
    }
  }
}

// Вывод содержимого контейнера в файл
void Container::output(std::ofstream &stream) {
  stream << "Container contains " << length << " elements." << '\n';
  for (int i = 0; i < length; i++) {
    stream << i + 1 << ": ";
    elements[i]->output(stream);
  }
}

// Деление контейнера на части для сортировки
int Container::partition(int low, int high) {
  double basis_number = elements[high]->perimeter();
  int i = (low - 1);
  for (int j = low; j <= high - 1; j++) {
    if (elements[j]->perimeter() < basis_number) {
      i++;
      std::swap(elements[i], elements[j]);
    }
  }
  std::swap(elements[i + 1], elements[high]);
  return (i + 1);
}

// Применение сортировки к контейнеру
void Container::sortContainer(int low, int high) { quickSort(low, high); }

// QuickSort
void Container::quickSort(int low, int high) {
  if (low < high) {
    int pi = partition(low, high);
    quickSort(low, pi - 1);
    quickSort(pi + 1, high);
  }
}

// Получение кол-ва элементов в контейнере
int Container::getLength() const { return length; }

// Деструктор
Container::~Container() { clear(); }
