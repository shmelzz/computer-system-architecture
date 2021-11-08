from rectangle import *
from triangle import *
from circle import *


class Container:
    def __init__(self):
        self.elements = []

    def fill_container(self, string_array):
        array_length = len(string_array)
        i = 0
        shape_number = 0
        while i < array_length:
            string_key = string_array[i]
            key = int(string_key)
            if key == 1:
                i += 1
                shape = Rectangle()
                i = shape.input(string_array, i)
            elif key == 2:
                i += 1
                shape = Triangle()
                i = shape.input(string_array, i)
            elif key == 3:
                i += 1
                shape = Circle()
                i = shape.input(string_array, i)
            else:
                return shape_number
            if i == 0:
                return shape_number
            shape_number += 1
            self.elements.append(shape)
        return shape_number

    def fill_container_random(self, size):
        while len(self.elements) < size:
            key = random.randint(1, 3)
            if key == 1:
                shape = Rectangle()
                shape.input_random()
            elif key == 2:
                shape = Triangle()
                shape.input_random()
            else:
                shape = Circle()
                shape.input_random()
            self.elements.append(shape)
        pass

    def output(self, stream):
        stream.write('Container contains: {0} elements.\n'.format(len(self.elements)))
        i = 1
        for shape in self.elements:
            stream.write('{0}: '.format(i))
            shape.output(stream)
            stream.write("\n")
            i += 1
        pass

    def partition(self, low, high):
        basis_number = self.elements[high].perimeter()
        i = low - 1
        j = low
        while j <= high - 1:
            if self.elements[j].perimeter() < basis_number:
                i += 1
                temp = self.elements[i]
                self.elements[i] = self.elements[j]
                self.elements[j] = temp
            j += 1
        temp = self.elements[i + 1]
        self.elements[i + 1] = self.elements[high]
        self.elements[high] = temp
        return i + 1

    def quickSort(self, low, high):
        if low < high:
            pi = self.partition(low, high)
            self.quickSort(low, pi - 1)
            self.quickSort(pi + 1, high)

    def sortContainer(self, low, high):
        self.quickSort(low, high)
