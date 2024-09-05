
from circle import Circle
from square import Square
from triangle import Triangle


def main():
    circle = Circle("red", True, 5)
    square = Square("blue", False, 6)
    triangle = Triangle("yellow", True, 7, 8)

    print(circle.color)
    print(circle.is_filled)
    print(circle.radius)
    print(circle.area())
    print(circle.circumference())
    circle.describe()
    print()

    print(square.color)
    print(square.is_filled)
    print(square.width)
    print(square.area())
    print(square.circumference())
    square.describe()
    print()

    print(triangle.color)
    print(triangle.is_filled)
    print(triangle.width)
    print(triangle.height)
    print(triangle.area())
    triangle.describe()
    print()




if __name__ == "__main__":
    main()



