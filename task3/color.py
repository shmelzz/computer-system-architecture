from enum import Enum


class Color(Enum):
    RED = 0
    ORANGE = 1
    YELLOW = 2
    GREEN = 3
    BLUE = 4
    DARK_BLUE = 5
    PURPLE = 6


def get_color(value):
    if value == Color.RED.value:
        return "RED"
    elif value == Color.ORANGE.value:
        return "ORANGE"
    elif value == Color.YELLOW.value:
        return "YELLOW"
    elif value == Color.GREEN.value:
        return "GREEN"
    elif value == Color.BLUE.value:
        return "BLUE"
    elif value == Color.DARK_BLUE.value:
        return "DARK_BLUE"
    else:
        return "PURPLE"
