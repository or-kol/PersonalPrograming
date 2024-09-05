
from dog import Dog
from cat import Cat
from car import Car

def main():
    
    animals = [Dog(), Cat(), Car()]

    for animal in animals:
        animal.speak()
        print(animal.alive)

if __name__ == "__main__":
    main()