
#example for this topic: https://www.youtube.com/watch?v=r7Dtus7N4pI

def addSprinkles(func):
    def wrapper(*args, **kwargs):
        print("You added sprinkles")
        func(*args, **kwargs)
    return wrapper

def addFudge(func):
    def wrapper(*args, **kwargs):
        print("You added fudge")
        func(*args, **kwargs)
    return wrapper


@addSprinkles
@addFudge
def getIceCream(flavor):
    print(f"Here is your {flavor} ice cream")


def main():
    
    getIceCream("Vanila")


if __name__ == "__main__":
    main()