
# Q2
for num in range(0, 10, 2):
    print(num)

for num in range(10, 0, -2):
    print(num)


# Q3
numLst3 = []
for num in range(0, 10):
    numLst3.append(num)

print(numLst3)


# Q8
print(list(range(200, 1, -1)))


#Q9
print([num for num in range(1, 100) if num % 7 == 0])


numSum9 = 0
while True:
    numInput9 = int(input("Please input number: "))
    if numInput9 >= 0:
        numSum9 += numInput9
    else:
        print(numSum9)
        break


# Q10
import math

numInput10 = int(input("Please input number: "))

print(math.factorial(numInput10)) # Method 1

# Method 2
factorial = 1
for num in range(1, numInput10 + 1):
    factorial *= num

print(factorial)


# Q11
luckyNum = [3, 17, 45, 24, 38]
attempts = 0
pastGuesses = []
while len(luckyNum) > 0:
    if attempts <= 20:
        guess = int(input("Please guess a number between 2-49: "))
        if guess in luckyNum:
            luckyNum.remove(guess)
            attempts += 1
            pastGuesses.append(guess)
        elif guess in pastGuesses:
            break
        else:
            attempts += 1
            pastGuesses.append(guess)
    else:
        luckyNum = [3, 17, 45, 24, 38]
        attempts = 0
        pastGuesses = []

    print(luckyNum)
    print(attempts)
    print(pastGuesses)

if len(luckyNum) == 0:
    print(f"It took you {attempts} attempts to guess all five lucky numbers!!")







