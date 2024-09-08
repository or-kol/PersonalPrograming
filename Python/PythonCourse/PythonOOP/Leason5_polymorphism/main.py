

from circle import Circle
from square import Square
from triangle import Triangle
from pizza import Pizza

def main():
    shapes = [Circle(4), Square(5), Triangle(6, 7), Pizza("Mushrooms", 15)]

    for shape in shapes:
        print(f"area = {shape.area():.2f}cm")


#!!!!
'''
in this example our pizza has 3 forms:
1. pizza
2. circle
3. shape
'''

if __name__ == "__main__":
    main()