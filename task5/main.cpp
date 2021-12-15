#include <chrono>
#include <iostream>
#include <mutex>
#include <random>
#include <thread>

std::mutex lock_give_variant;
std::mutex lock_get_variant;
std::mutex lock_get_mark;
std::mutex lock_set_mark;
int *marks;
std::mt19937 gen;
int got_marks = 0;
int prepared = 0;
std::vector<int> students_to_get_marks;


// Вывод текущего времени
void printCurrentTime() {
    auto start = std::chrono::system_clock::now();
    std::time_t end_time = std::chrono::system_clock::to_time_t(start);
    std::cout << std::ctime(&end_time);
}

// Метод, который выдает билет на запрос студента
void giveVariant(int number_of_students, int student_index) {
    // В один момент времени билет может выдаваться только одному студенту
    lock_give_variant.lock();
    std::cout << "\nstarted setting variant for student -" << student_index << "- at ";
    printCurrentTime();
    std::this_thread::sleep_for(std::chrono::seconds(gen() % 3));
    int variant = gen() % number_of_students + 1;
    std::cout << "\nvariant for student -" << student_index << "- is " << variant << ". It was set at ";
    printCurrentTime();
    lock_give_variant.unlock();
}

// Метод для выставления оценки на запрос студента
void setMark(int student_index) {
    // В один момент времени оценка может выставляться только одному студенту
    lock_set_mark.lock();
    std::cout << "\nchoosing mark for student -" << student_index << "- at ";
    printCurrentTime();
    std::this_thread::sleep_for(std::chrono::seconds(gen() % 4));
    int mark = gen() % 11;
    marks[student_index] = mark;
    std::cout << "\nmark for student -" << student_index << "- is " << mark << ". It was set at ";
    printCurrentTime();
    ++got_marks;
    lock_set_mark.unlock();
}

// Метод для запроса варианта у преподавателя
void getVariant(int student_index, int number_of_students) {
    // В один момент времени только один студент может тянуть билет
    lock_get_variant.lock();
    std::cout << "\nstudent -" << student_index << "- asked for variant at ";
    printCurrentTime();
    std::thread teacher_to_give_variant(giveVariant, number_of_students, student_index);
    teacher_to_give_variant.join();
    lock_get_variant.unlock();
}

// Метод для запроса оценки у преподавателя
void getMark(int student_index) {
    // В один момент времени только один студент может получать оценку
    lock_get_mark.lock();
    std::cout << "\nstudent -" << student_index << "- answered at ";
    printCurrentTime();
    std::thread teacher_to_set_mark(setMark, student_index);
    teacher_to_set_mark.join();
    lock_get_mark.unlock();
}

// Метод подготовки (сна) студентов
void prepare(int student_index) {
    std::cout << "\nstudent -" << student_index << "- started to prepare at ";
    printCurrentTime();
    std::this_thread::sleep_for(std::chrono::seconds(rand() % 10));
    std::cout << "\nstudent -" << student_index << "- is ready to answer at ";
    printCurrentTime();
    students_to_get_marks.push_back(student_index);
    ++prepared;
}

int main() {
    gen.seed(time(0));
    bool ok_input = false;
    int number_of_students;
    while (!ok_input) {
        std::cout << "\nEnter number of students:";
        std::cin >> number_of_students;
        if (number_of_students > 0) {
            ok_input = true;
        } else {
            std::cout << "Incorrect number, try again.";
        }
    }
    marks = new int[number_of_students]();

    // Запрос и получение билетов
    auto *students_to_get_variants = new std::thread[number_of_students];
    for (int i = 0; i < number_of_students; ++i) {
        students_to_get_variants[i] = std::thread(getVariant, i, number_of_students);
    }

    // Студенты готовятся
    auto *students_to_prepare = new std::thread[number_of_students];
    for (int i = 0; i < number_of_students; ++i) {
        students_to_get_variants[i].join();
        students_to_prepare[i] = std::thread(prepare, i);
    }

    // Ждем пока все студенты подготовятся, студенты занимают очередь на ответ
    while (prepared != number_of_students) {
    }

    // Студенты просят оценки
    auto *students_to_answer = new std::thread[number_of_students];
    for (int i = 0; i < number_of_students; ++i) {
        students_to_answer[i] = std::thread(getMark, students_to_get_marks[i]);
    }

    // Ждем, пока все студенты получат оценки
    while (got_marks != number_of_students) {
    }

    // Вывод результатов экзамена
    std::cout << "\nSo marks are: \n";
    for (int i = 0; i < number_of_students; ++i) {
        std::cout << "Student -" << i << "- : " << marks[i] << '\n';
    }
    return 0;
}
