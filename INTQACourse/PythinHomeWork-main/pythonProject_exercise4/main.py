import math
import random

# Q2
def function2():
    pass


# Q3
def function3a(x = 3):
    pass


def function3b(x, y, z = 3):
    pass


# Q3
def function3():
    return True


# Q4
def function4(x = 5):
    return 5


# Q5 - see question 4


# Q6 - what does "empty" means?


# Q7
num6 = random.randint(0, 100)


# Q8
def sircleArea(rad):
    return math.pi * rad ** 2


# Q9
def add(x = 0, y = 0):
    return x + y


def sub(x = 0, y = 0):
    return x - y


def mul(x = 0, y = 0):
    return x * y


def div(x = 0, y = 0):
    return x / y


userInput1 = int(input("Please input first number: "))
userInput2 = int(input("Please input second number: "))

print(add(userInput1, userInput2))
print(sub(userInput1, userInput2))
print(mul(userInput1, userInput2))
print(div(userInput1, userInput2))


# Q10
def getInRange(min, max):
    while True:
        userInput10 = int(input("Please input number: "))
        if min <= userInput10 <= max:
            return userInput10


print(getInRange(10, 100))


#Q10
def getLowest(x, y, z):
    if x > y and x > z:
        print(f"{x} is the largest number")
    elif y > z:
        print(f"{y} is the largest number")
    else:
        print(f"{z} is the largest number")


getLowest(1, 2, 3)
getLowest(1, 3, 2)
getLowest(3, 2, 1)
getLowest(2, 3, 1)
getLowest(2, 1, 3)
getLowest(3, 1, 2)










