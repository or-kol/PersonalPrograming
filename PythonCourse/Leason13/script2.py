from script1 import *

def favoriteDrink(drink):
    print(f"Your favorite drink is {drink}")

def main():
    print("This is script2")
    favoriteFood("Sushi")
    favoriteDrink("Cola")
    print("Goodbye")


if __name__ == "__main__":
    main()