import math
import random
from color import *


class Circle:
    def __init__(self):
        self.center_x = 0
        self.center_y = 0
        self.color = 0
        self.radius = 0

    def input(self, string_array, i):
        if i >= len(string_array) - 3:
            return 0
        self.color = int(string_array[i])
        self.center_x = int(string_array[i + 1])
        self.center_y = int(string_array[i + 2])
        self.radius = int(string_array[i + 3])
        i += 4
        return i

    def input_random(self):
        self.color = random.randint(0, 6)
        self.center_x = random.randint(1, 1000)
        self.center_y = random.randint(1, 1000)
        self.radius = random.randint(1, 1000)

    def perimeter(self):
        return float(2.0 * math.pi * self.radius)

    def output(self, stream):
        if self.radius <= 0:
            stream.write("It is CIRCLE\n")
            stream.write("But radius was below zero, so it does not exist\n")
        else:
            stream.write("It is CIRCLE\n")
            stream.write(
                'Center coordinates are: X = {0}, Y = {1}, radius = {2}, color = {3},  perimeter = {4} \n'.format(
                    self.center_x, self.center_y, self.radius, get_color(self.color), self.perimeter()))
