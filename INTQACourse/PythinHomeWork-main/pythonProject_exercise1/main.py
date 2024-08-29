
# Q1 - "Input" is a command for user input. the type of the input is string.
userName = input("Please enter your name: ")
print(type(userName))


# Q2 - Casting:
#Option 1:
inputNum = input("Please input a number: ")
print(type(inputNum))

inputNum = int(inputNum)
print(type(inputNum))

inputNum = float(inputNum)
print(type(inputNum))

#Option 2:
inputNumInt = int(input("Please input a number: "))
print(type(inputNumInt))

inputNumfloat = float(input("Please input a number: "))
print(type(inputNumfloat))


# Q3
ranString = "What is your name ?"
ranStringLst = ranString.split() # Split by space
print(type(ranStringLst))
print(ranStringLst)

ranString3 = "taramasalata"
ranStringLst3 = ranString3.split("a") # Split by the letter "a"
print(ranStringLst3)


# Q4
x = 1
y = 2
z = x + y
print("{} + {} = {}".format(x, y, z))
# or
print("{} + {} = {}".format(x, y, x+y))


# Q5 - check if the value exist in the list.
numLst5 = [1, 2, 3, 4, 5, 5, 6, 7, 8]
print(1 in numLst5)


# Q6
num6 = int(input("Please enter a number: "))
if num6 < 0:
    print(f"Tne number {num6} is negative!")
elif num6 == 0:
    print(f"Tne number you entered is {num6}!")
else:
    print(f"Tne number {num6} is positive!")


# Q7 - Indentation.


# Q8
x8 = input("Please input first number: ")
y8 = input("Please input second number: ")

if x8 > y8:
    print(f"The larger number is {x8}")
else:
    print(f"The larger number is {y8}")


# Q9
x9 = input("Please input first number: ")
y9 = input("Please input second number: ")
z9 = input("Please input third number: ")

if x9 > y9 and x9 > z9:
    print(f"The larger number is {x9}")
elif y9 > z9:
    print(f"The larger number is {y9}")
else:
    print(f"The larger number is {z9}")


# Q10
mathOperation = input("Please input mathematical operation (ie: 1 + 1 = 2, 1 - 1 = 0 etc.): ")

mathOperationLst = mathOperation.split()
numLst10 = []
charLst10 = []

for num in range(len(mathOperationLst)):
    if num % 2 == 0:
        numLst10.append(int(mathOperationLst[num]))
    else:
        charLst10.append(mathOperationLst[num])

print(numLst10)
print(charLst10)

if charLst10[0] == "+":
    if numLst10[0] + numLst10[1] == numLst10[2]:
        print(True)
    else:
        print(False)
elif charLst10[0] == "-":
    if numLst10[0] - numLst10[1] == numLst10[2]:
        print(True)
    else:
        print(False)
elif charLst10[0] == "*":
    if numLst10[0] * numLst10[1] == numLst10[2]:
        print(True)
    else:
        print(False)
elif charLst10[0] == "/":
    if numLst10[1] == 0:
        print(f"Error - can't divide by {numLst10[1]}")
    else:
        if numLst10[0] / numLst10[1] == numLst10[2]:
            print(True)
        else:
            print(False)











