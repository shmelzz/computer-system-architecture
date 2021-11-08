import math
import random
from color import *


class Triangle:
    def __init__(self):
        self.a_x = 0
        self.a_y = 0
        self.b_x = 0
        self.b_y = 0
        self.c_x = 0
        self.c_y = 0
        self.color = 0
        self.ab = 0
        self.bc = 0
        self.ac = 0

    def input(self, string_array, i):
        if i >= len(string_array) - 6:
            return 0
        self.color = int(string_array[i])
        self.a_x = int(string_array[i + 1])
        self.a_y = int(string_array[i + 2])
        self.b_x = int(string_array[i + 3])
        self.b_y = int(string_array[i + 4])
        self.c_x = int(string_array[i + 5])
        self.c_y = int(string_array[i + 6])
        i += 7
        return i

    def input_random(self):
        self.color = random.randint(0, 6)
        while True:
            self.a_x = random.randint(1, 1000)
            self.a_y = random.randint(1, 1000)
            self.b_x = random.randint(1, 1000)
            self.b_y = random.randint(1, 1000)
            self.c_x = random.randint(1, 1000)
            self.c_y = random.randint(1, 1000)
            ab, ac, bc = self.calculate_sides()
            if (ac < (ab + bc)) and (ab < (bc + ac)) and (bc < (ac + ab)):
                break

    def calculate_sides(self):
        ab = math.sqrt(pow(self.b_x - self.a_x, 2) + pow(self.b_y - self.a_y, 2))
        bc = math.sqrt(pow(self.c_x - self.b_x, 2) + pow(self.c_y - self.b_y, 2))
        ac = math.sqrt(pow(self.c_x - self.a_x, 2) + pow(self.c_y - self.a_y, 2))
        return ab, ac, bc

    def perimeter(self):
        ab, ac, bc = self.calculate_sides()
        return float(ab + ac + bc)

    # переписать вывод (добавить периметр и колор)
    def output(self, stream):
        ab, ac, bc = self.calculate_sides()
        if ac >= (ab + bc) or ab >= (bc + ac) or bc >= (ac + ab):
            stream.write("It is TRIANGLE\nBut coordinates were incorrect, so it does not exist\n")
        else:
            stream.write("It is TRIANGLE\n")
            stream.write('Angles\' coordinates are: a.X = {0}, a.Y = {1}, b.X = {2}, b.Y = {3}, c.X = {4}, c.Y = {5}, '
                         'color = {6}, perimeter = {7} \n'.format(self.a_x, self.a_y, self.b_x, self.b_y, self.c_x,
                                                                  self.c_y, get_color(self.color), self.perimeter()))
