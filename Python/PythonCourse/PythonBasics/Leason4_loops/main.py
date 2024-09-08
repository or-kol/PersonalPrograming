import time


'''
contents:
while loop
for loops
nested loop
'''

'''
name = input("Enter your name: ")

while ("" == name):
    print("You didn't enter your name!")
    name = input("Enter your name: ")

print(f"Hello {name}")



age = int(input("Enter your age: "))

while 0 > age:
    print("Age can't be negative!")
    age = int(input("Enter your age: "))

print(f"you are {age} years old!")


food = input("Enter a food you like (q to quit): ")

while 'q' != food:
    print(f"You like {food}")
    food = input("Enter another food you like (q to quit): ")

print("Bye")



num = int(input("Enter a number betwween 1-10: "))

while 1 > num or 10 < num:
    print("You entered and invalid number!")
    num = int(input("Enter a number betwween 1-10: "))

print(f"number = {num}")


# excersise compound interest calculator
principle = 0
rate = 0
time = 0

while True:
    principle = float(input("Enter the principle amount: "))
    if 0 > principle:
        print("principle can't be less than 0!")
    else:
        break


while True:
    rate = float(input("Enter the interest rate: "))
    if 0 > rate:
        print("interest rate can't be less than 0!")
    else:
        break


while True:
    time = int(input("Enter the time in years: "))
    if 0 > time:
        print("time can't be less than 0!")
    else:
        break

total = principle * pow((1 + rate / 100), time)

print(f"Balance after {time} years: {total:.2f}")
'''


#######################################################################################################################

'''
for i in range(1, 11):
    print(i)

for i in reveresed(range(1, 11)):
    print(i)
    
for i in range(10, 0, -1):
    print(i)

credit_num = "1234-5678-1346-3579"

for i in credit_num:
    print(i)

for i in range(1, 21):
    if 13 == i:
        continue
    else:
        print(i)


#exercise - countdown clock
my_time = int(input("Enter the time in seconds: "))

for i in range(my_time, 0, -1):
    seconds = i % 60
    minutes = int(i / 60) % 60
    hours = int(i / 3600)
    print(f"{hours:02}:{minutes:02}:{seconds:02}")
    time.sleep(1)

print("Time's up!")
'''

#######################################################################################################################

'''
for i1 in range(3):
    for i2 in range(1, 10):
        print(i2, end = "")
    print()


#exercise - print rectangle
rows = int(input("Enter number of rows: "))
columns = int(input("Enter number of columns: "))
symbol = input("Enter a symbol to use: ")

for i1 in range(rows):
    for i2 in range(columns):
        print(symbol, end = "")
    print()
'''






















