
import math
from shape import Shape

class Circle(Shape):
    
    def __init__(self, color, is_filled, radius):
        super().__init__(color, is_filled)
        self.radius = radius
    
    def describe(self):
        print(f"It's a circle with an area of {self.area():.2f} and circumference of {self.circumference():.2f}")
        super().describe()

    def area(self):
        return math.pi * pow(self.radius, 2)
    
    def circumference(self):
        return 2 * math.pi * self.radius


        