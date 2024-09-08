
from shape import Shape

class Square(Shape):
    
    def __init__(self, color, is_filled, width):
        super().__init__(color, is_filled)
        self.width = width
    
    def area (self):
        return pow(self.width, 2)
    
    def circumference(self):
        return self.width * 4