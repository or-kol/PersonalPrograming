import time


'''
content:
functions
arguments
'''


'''
# positional arguments
def singHappyBirthday(name, age):
    print(f"Happy birthday to {name}!")
    print(f"You are {age} years old!")
    print("Happy birthday to you!")
    print()


singHappyBirthday("Or", 20)
singHappyBirthday("Bro", 30)
singHappyBirthday("Joe", 40)


def displayInvoice(user_name, amount, due_date):
    print(f"Hello {user_name}")
    print(f"Your bill of ${amount:.2f} is due: {due_date}")

displayInvoice("Or", 18.659885, "01/01")



def add(x, y):
    return x + y

def subtract(x, y):
    return x - y

def multiply(x, y):
    return x * y

def divide(x, y):
    return x / y

print(add(1, 2))
print(subtract(1, 2))
print(multiply(1, 2))
print(divide(1, 2))


def createFullName(f_name, l_name):
    return f_name + " " + l_name

f_name = input("Please enter your first name: ").capitalize()
l_name = input("Please enter your last name: ").capitalize()

full_name = createFullName(f_name, l_name)
print(full_name)
'''


##############################################################################################


# default arguments

'''
def netPrice(price, discount = 0, tax = 0.05):
    return price * (1 - discount) * (1 + tax)

print(netPrice(500))
print(netPrice(500, 0.1))
print(netPrice(500, 0.1, 0))



def count(end, start = 0):
    for x in range(start, end + 1):
        print(x)
        time.sleep(1)
    
    print("Done")

count(10)
count(30, 15)
'''


##############################################################################################


# keyword arguments
'''
def hello(greet, title, first, last):
    print(f"{greet} {title} {first} {last}")

hello("Hello", last = "Kol", first = "Or", title = "Mr.")



for x in range(1, 11):
    print(x, end = " ")



def getPhoneNum(country, area, first, last):
    return f"{country}-{area}-{first}-{last}"

phone_num = getPhoneNum(country=1, area=123, first=456, last=7890)

print(phone_num)
'''


##############################################################################################


# arbitrary arguments

# *args
'''
def add(*nums):
    return sum(nums)

print(add())
print(add(1, 2))
print(add(1, 2, 3))
print(add(1, 2, 3, 4))



def displayName(*names):
    for name in names:
        print(name.capitalize(), end = " ")

displayName("or", "polly", "kol")
'''


# *kwargs
'''
def print_address(**kwargs):
    for key, val in kwargs.items():
        print(f"{key:6}: {val}")


print_address(street="123 Fake St.", 
              apt="100",
              city="Detroit", 
              state="Michigan", 
              zip="54321")



def shippingLable(*args, **kwargs):
    for name in args:
        print(name, end=" ")

    print()

    if "apt" in kwargs:
        print(f"{kwargs.get('street')} {kwargs.get('apt')}")
    else:
        print(f"{kwargs.get('street')}")
    
    print(f"{kwargs.get('city')} {kwargs.get('state')} {kwargs.get('zip')}")


shippingLable("Dr.", "Jhon", "Stinson", "III",
              street="123 Fake St.", 
              apt="100",
              city="Detroit", 
              state="Michigan", 
              zip="54321")
'''







