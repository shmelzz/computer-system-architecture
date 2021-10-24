// main.cpp - содержит главную функцию

#include "container.h"
#include <chrono>
#include <cstdlib> // для функций rand() и srand()
#include <ctime>   // для функции time()
#include <iostream>
#include <string>

// Вывод ошибки при неправильных аргументах
void error_message_first() {
  std::cout << "incorrect command line!" << '\n';
  std::cout << "  Waited:" << '\n';
  std::cout << "     command infile_name outfile_name" << '\n';
}

// Вывод ошибки при выборе неправильного типа ввода данных
void errMessage2(std::ofstream &stream) {
  stream << "incorrect qualifier value!" << '\n';
  stream << "  Waited:" << '\n';
  stream << R"(    first line in input_file must be "file" or "random")"
         << '\n';
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    error_message_first();
    return 1;
  }

  std::cout << "Start" << '\n';
  Container *container = new Container();
  std::ifstream input_stream(argv[1]);
  std::string input_type;
  input_stream >> input_type;
  std::cout << "input type = " << input_type << '\n';
  if (input_type == "file") {
    container->input(input_stream);
  } else if (input_type == "random") {
    int number_of_figures;
    input_stream >> number_of_figures;
    if ((number_of_figures < 1) || (number_of_figures > 10000)) {
      std::ofstream stream_out(argv[2]);
      stream_out << "incorrect number of figures for random = "
                 << number_of_figures << ". Set 0 < number <= 10000";
      std::cout << "Finished, result is in output file" << '\n';
      return 3;
    }
    // системные часы в качестве инициализатора
    srand(static_cast<unsigned int>(time(0)));
    // Заполнение контейнера генератором случайных чисел
    container->inputRandom(number_of_figures);
  } else {
    std::ofstream stream_out(argv[2]);
    errMessage2(stream_out);
    std::cout << "Finished, result is in output file" << '\n';
    return 2;
  }

  // Вывод содержимого контейнера в файл
  std::ofstream stream_out(argv[2]);
  stream_out << "Filled container:" << '\n';
  container->output(stream_out);

  // Сортировка
  container->sortContainer(0, container->getLength() - 1);
  stream_out << "\n\n"
             << "Sorted container: " << '\n';
  container->output(stream_out);
  stream_out.close();
  std::cout << "Finished, result is in output file" << '\n';
  delete container;
  return 0;
}
