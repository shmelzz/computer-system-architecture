// main.cpp - содержит главную функцию

#include <stdio.h>
#include <stdlib.h> // для функций rand() и srand()
#include <time.h>   // для функции time()
#include "string.h"
#include "container.h"

// Вывод ошибки при неправильных аргументах
void error_message_first() {
    printf("%s\n", "incorrect command line!");
    printf("%s\n", "  Waited:");
    printf("%s\n", "     command infile_name outfile_name");
}

// Вывод ошибки при выборе неправильного типа ввода данных
void errMessage2(FILE *stream) {
    fprintf(stream, "%s\n", "incorrect qualifier value!");
    fprintf(stream, "%s\n", "  Waited:");
    fprintf(stream, "%s\n", "    first line in input_file must be \"file\" or \"random\"");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        error_message_first();
        return 1;
    }

    printf("%s\n", "Start");
    container cont;
    Initialize(cont);
    FILE *input_stream = fopen(argv[1], "r");
    char *input_type;
    char str[250];
    input_type = fgets(str, 250, input_stream);
    printf("%s %s", "input type =", input_type);
    if (strstr(input_type, "file") != NULL) {
        Input(cont, input_stream);
    } else if (strstr(input_type, "random") != NULL) {
        int number_of_figures;
        fscanf(input_stream, "%d", &number_of_figures);
        if ((number_of_figures < 1) || (number_of_figures > 10000)) {
            FILE *stream_first = fopen(argv[2], "w");
            fprintf(stream_first, "%s%d%s\n", "incorrect number of figures for random = ", number_of_figures,
                    ". Set 0 < number <= 10000");
            printf("%s\n", "Finished, result is in output file");
            return 3;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел
        InputRandom(cont, number_of_figures);
    } else {
        FILE *stream_first = fopen(argv[2], "w");
        errMessage2(stream_first);
        printf("%s\n", "Finished, result is in output file");
        return 2;
    }

    // Вывод содержимого контейнера в файл
    FILE *stream_out = fopen(argv[2], "w");
    fprintf(stream_out, "%s\n", "Filled container:");
    Output(cont, stream_out);

    SortContainer(cont, 0, cont.length - 1);

    fprintf(stream_out, "\n\n%s\n", "Sorted container: ");
    Output(cont, stream_out);
    fclose(stream_out);

    Clear(cont);
    printf("%s\n", "Finished, result is in output file");
    return 0;
}
