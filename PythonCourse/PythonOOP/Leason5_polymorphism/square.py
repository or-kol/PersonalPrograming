
from shape import Shape

class Square(Shape):
    
    def __init__(self, side):
        self.side = side
    
    def area (self):
        return pow(self.side, 2)
    
    def circumference(self):
        return self.side * 4