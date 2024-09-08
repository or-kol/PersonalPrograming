
import math
from shape import Shape

class Circle(Shape):
    
    def __init__(self, radius):
        self.radius = radius

    def area(self):
        return math.pi * pow(self.radius, 2)
    
    def circumference(self):
        return 2 * math.pi * self.radius


        