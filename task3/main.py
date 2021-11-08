import sys
from container import *


def error_message_first():
    print("incorrect command line!\n")
    print("  Waited:\n")
    print("     command infile_name outfile_name\n")


def errMessage2(stream):
    stream.write("incorrect qualifier value!\n")
    stream.write("  Waited:\n")
    stream.write("    first line in input_file must be \"file\" or \"random\"\n'")


if __name__ == '__main__':
    if len(sys.argv) != 3:
        error_message_first()
        exit()

    print('==> Start')

    container = Container()
    with open(sys.argv[1], "rt") as input_stream:
        type_in = input_stream.readline()
        input_type = type_in.replace("\n", "")
        if input_type == "file":
            container.fill_container(input_stream.read().replace("\n", " ").split(" "))
        elif input_type == "random":
            number_of_figures = int(input_stream.readline())
            if (number_of_figures < 1) or (number_of_figures > 10000):
                with open(sys.argv[2], "wt") as output_stream:
                    output_stream.write("incorrect number of figures for random = ")
                    output_stream.write(str(number_of_figures))
                    output_stream.write(". Set 0 < number <= 10000")
                    print("Finished, result is in output file\n")
                    exit()

            container.fill_container_random(number_of_figures)
        else:
            with open(sys.argv[2], "wt") as output_stream:
                errMessage2(output_stream)
                print("Finished, result is in output file\n")
                exit()

    with open(sys.argv[2], "wt") as output_stream:
        output_stream.write("Filled container:\n")
        container.output(output_stream)

        container.sortContainer(0, len(container.elements) - 1)
        output_stream.write("\n\nSorted container: \n")
        container.output(output_stream)

    print('==> Finish')
    exit()
