

class Employee:

    def __init__(self, name, position):
        self.name = name
        self.position = position
    

    def get_info(self):
        return f"{self.name} -> {self.position}"
    

    @staticmethod
    def isValidPosition(position):
        valid_positions = ["Manager", "Cashier", "Cook", "Janitor"]

        return position in valid_positions
