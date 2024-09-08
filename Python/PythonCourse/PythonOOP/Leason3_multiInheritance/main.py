
#nultiple inheritance - a class inherit from multiple class (at the same level - like "fish" example)
#multi level inhertance - a clas inherits the atributes that it's parrent class inherits from thei parrent classes (animal -> prey -> rabbit)

from rabbit import Rabbit
from hawk import Hawk
from fish import Fish

def main():
    
    rabbit = Rabbit("Bugs")
    hawk = Hawk("Tony")
    fish = Fish("Nemo")
    
    rabbit.flee()
    rabbit.eat()
    rabbit.sleep()

    hawk.hunt()
    hawk.eat()
    hawk.sleep()

    fish.hunt()
    fish.flee()
    fish.eat()
    fish.sleep()


if __name__ == "__main__":
    main()