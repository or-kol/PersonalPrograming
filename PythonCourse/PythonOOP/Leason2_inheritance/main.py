
from dog import Dog
from cat import Cat
from mouse import Mouse


def main():

    dog1 = Dog("Polly")
    cat1 = Cat("Garfield")
    mouse1 = Mouse("Mickey")

    print(dog1.name)
    print(dog1.is_alive)
    dog1.sleep()
    dog1.eat()
    print()

    print(cat1.name)
    print(cat1.is_alive)
    cat1.sleep()
    cat1.eat()
    print()

    print(mouse1.name)
    print(mouse1.is_alive)
    mouse1.sleep()
    mouse1.eat()

    print()
    dog1.speak()
    cat1.speak()
    mouse1.speak()



if __name__ == "__main__":
    main()


