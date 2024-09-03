import math


'''
content:
variables
print
user input
math operation
math functions
'''



# python program
# print("Hello World")

# strings
name = "Or"

# print(f"Hello {first_name}")


# integers
age = 36

# print(f"I am {age} years old")


# floats
gpa = 3.2

#print(f"the gpa is {gpa}")

# boolean

is_student = True

'''
if is_student:
    print(f"You are a students")
else:
    print(f"You are not a students")
'''

#################################################################################################################

'''
print(type(name))
print(type(age))
print(type(gpa))
print(type(is_student))

gpa = int(gpa)

print(type(gpa))

print(f"the gpa is {gpa}")
'''

#################################################################################################################

'''
user_name = input("What is your name?: ")
user_age = int(input("How old are you?: "))

user_age += 1

print(f"Hello {user_name}!")
print(f"you are {user_age} years old!")


# exercise 1
length = float(input("Enter rectangle length: "))
width = float(input("Enter rectangle width: "))
area = length * width

print(f"Rectangle area is {area} cm")



# exercise 2
item = input("What item whould you like to buy?: ")
price = float(input("What is the price?: "))
quantity = int(input("How many would you like to but?: "))

total = price * quantity

print(f"{quantity} {item} cost ${total}")
'''

#################################################################################################################


'''
x = 3.14
y = -4
z = 5

resultx = round(x)
resulty = abs(y)
resultpow = pow(z, 2)
resultmax = max(x, y, z)
resultmin = min(x, y, z)

print(resultx)
print(resulty)
print(resultpow)
print(resultmax)
print(resultmin)


print(math.pi)
print(math.e)
print(math.sqrt(9))
print(math.ceil(3.5))
print(math.floor(3.5))


#exercise 1
radius = float(input("Enter the radius of a circle: "))

circumference = 2 * math.pi *radius

print(f"the circumference of the circle is {round(circumference, 2)}")


#exercise 2
radius = float(input("Enter the radius of a circle: "))

area = math.pi * pow(radius, 2)
print(f"The area of the circle is {round(area, 2)}")


#exercise 3
a = float(input("Enter side a: "))
b = float(input("Enter side b: "))
c = math.sqrt(pow(a, 2) + pow(b, 2))

print(f"Side c = {c}")
'''

