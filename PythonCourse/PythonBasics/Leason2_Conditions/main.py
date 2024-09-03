
'''
contents:
if statements
logical operators
conditional expressions (ternary operator)
'''

'''
age = int(input("Enter your age: "))

if 18 <= age:
    print("You are now signed up")
elif 0 > age:
    print("You havent been born yet")
else:
    print("You must by 18+ to sign up")


responce = input("Would you like some food? (Y/N): ")

if 'Y' == responce:
    print("Have some food!")
else:
    print("No food for you!")



name = input("Enter your name: ")

if "" == name:
    print("You did not type in your name")
else:
    print(f"Hello {name}")



#exercise 1 - caculator
operator = input("Enter an operator (+ - * /): ")
num1 = float(input("Enter first number: "))
num2 = float(input("Enter second number: "))

if '+' == operator:
    print(f"{num1} + {num2} = {round(num1+num2, 2)}")
elif '-' == operator:
    print(f"{num1} - {num2} = {round(num1-num2, 2)}")
elif '*' == operator:
    print(f"{num1} * {num2} = {round(num1*num2, 2)}")
elif '/' == operator:
    if 0 == num2:
        print("Devision By Zero!!")
    else:
        print(f"{num1} / {num2} = {round(num1/num2, 2)}")
else:
    print("Input Error!")


#exercise 2 - weight converter
weight = float(input("Enter your weight: "))
unit = input("Kilograms or Pounds> (K / L): ")

if 'K' == unit:
    weight *= 2.205
    unit = "lbs."
    print(f"Your weight is {round(weight, 2)} {unit}")
elif 'L' == unit:
    weight /= 2.205
    unit = "kgs."
    print(f"Your weight is {round(weight, 2)} {unit}")
else:
    print(f"{unit} is not valid")



#exercise 2 - temperature converter
unit = input("Is this temperature in Celsius or Fahrenheit? (C / F): ")
temperature = float(input("Enter the temperature: "))

if 'C' == unit:
    temperature = (temperature * 9) / 5 + 32
    unit = "Fahrenheit"
    print(f"The temperature is {round(temperature, 1)} {unit}")
elif 'F' == unit:
    temperature = (temperature - 32) * 5 / 9
    unit = "Celsius"
    print(f"The temperature is {round(temperature, 1)} {unit}")
else:
    print(f"{unit} is an invalid unit of measurment!")
'''


#################################################################################################
'''

temperature = 20
is_raining = False
is_sunny = True


if 35 < temperature or 0 > temperature or is_raining:
    print("The outdoor event is cancelled")
else:
    print("The outdoee event is still scheduled")



if 28 <= temperature and is_sunny:
    print("It is hot outside")
    print("It is sunny")
elif 0 >= temperature and is_sunny:
    print("It is cold outside")
    print("It is sunny")
elif 0 < temperature < 28 and is_sunny:
    print("It is warm outside")
    print("It is sunny")

'''


#################################################################################################
'''
num = -2
#print("Positive" if num > 0 else "Negative")

#print("Even" if num % 2 == 0 else "Odd")


a = 6
b = 7
max_num = a if a > b else b
#print(max_num)

age = 18
status = "Adult" if 18 <= age else "Child"
#print(status)


temperature = 15
weather = "Hot" if 20 < temperature else "Cold"
print(weather)
'''












