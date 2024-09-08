
from shape import Shape

class Triangle(Shape):
    
    def __init__(self, color, is_filled, width, height):
        super().__init__(color, is_filled)
        self.width = width
        self.height = height
    
    def area(self):
        return (self.width * self.height) / 2

