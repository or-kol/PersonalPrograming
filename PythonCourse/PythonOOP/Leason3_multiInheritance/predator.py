
from animal import Animal

class Predator(Animal):
    
    def hunt(self):
        print(f"{self.name} is hunting")