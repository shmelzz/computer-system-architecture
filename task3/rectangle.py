import random
from color import *


class Rectangle:
    def __init__(self):
        self.a_x = 0
        self.a_y = 0
        self.b_x = 0
        self.b_y = 0
        self.color = 0

    def input(self, string_array, i):
        if i >= len(string_array) - 4:
            return 0
        self.color = int(string_array[i])
        self.a_x = int(string_array[i + 1])
        self.a_y = int(string_array[i + 2])
        self.b_x = int(string_array[i + 3])
        self.b_y = int(string_array[i + 4])
        i += 5
        return i

    def input_random(self):
        self.color = random.randint(0, 6)
        self.a_x = random.randint(1, 1000)
        self.a_y = random.randint(1, 1000)
        self.b_x = random.randint(1, 1000)
        self.b_y = random.randint(1, 1000)

    def perimeter(self):
        if self.b_x > self.a_x:
            x = self.b_x - self.a_x
        else:
            x = self.a_x - self.b_x

        if self.b_y > self.a_y:
            y = self.b_y - self.a_y
        else:
            y = self.a_y - self.b_y
        return float(2.0 * (abs(x) + abs(y)))

    # переписать вывод (добавить периметр и колор)
    def output(self, stream):
        stream.write("It is RECTANGLE\n")
        stream.write(
            'Angles\' coordinates are: a.X = {0}, a.Y = {1}, b.X = {2}, b.Y = {3},'
            ' color = {4}, perimeter = {5} \n'.format(
                self.a_x, self.a_y, self.b_x, self.b_y, get_color(self.color), self.perimeter()))
