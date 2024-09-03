

'''
contents:
collections
'''


'''
# LIST
fruits = ["apple", "orange", "bannana", "coconut"]

print(fruits)
print(fruits[0])
print(fruits[ : 3])

for fruit in fruits:
    print(fruit)


print(len(fruits))
print("Apple" in fruits)
print("apple" in fruits)

fruits[0] = "pineapple"

fruits.append("apple")

for fruit in fruits:
    print(fruit)

print()

fruits.remove("apple")
fruits.insert(0, "apple")
fruits.sort()

for fruit in fruits:
    print(fruit)

print()

fruits.reverse()

for fruit in fruits:
    print(fruit)

print()

print(fruits.index("apple"))
print(fruits.count("apple"))
fruits.clear()
print(fruits)



# SETS

fruits = {"apple", "orange", "bannana", "coconut"}

print(len(fruits))
print("Apple" in fruits)
print("apple" in fruits)


fruits.add("Pineapple")
fruits.remove("Pineapple")


fruit = fruits.pop()
print(fruit)


fruits.clear()
print(fruits)



#TUPLE

fruits = ("apple", "orange", "bannana", "coconut")


print(len(fruits))
print("Apple" in fruits)
print("apple" in fruits)

print(fruits.index("orange"))
print(fruits.count("bannana"))


#exercise - shopping cart

foods = []
prices = []
total = 0

while True:
    food = input("Enter a food to buy (q to quit): ")
    if 'q' == food.lower():
        break
    else:
        price = float(input(f"Enter the price of {food}: "))
        foods.append(food)
        prices.append(price)

print()

print("----- Your cart -----")
for i in range(len(foods)):
    print(f"{foods[i]:10} - ${prices[i]:<10}")

print()
print(f"total = ${sum(prices)}")
'''

##############################################################################################################

'''
#fruits =     ["apple", "orange", "bannana", "coconut"]
#vegetables = ["celery", "carrots", "potatoes"]
#meats =      ["chicken", "fish", "turkey"]

groceries = [
    ["apple", "orange", "bannana", "coconut"], 
    ["celery", "carrots", "potatoes"], 
    ["chicken", "fish", "turkey"]
    ]


print(groceries[0]) #fruits list
print(groceries[1]) #vegetables list
print(groceries[2]) #meats list

print(groceries[0][0]) #first element in fruits list
print(groceries[1][0]) #first element in vegetables list
print(groceries[2][0]) #first element in meats list


for list in groceries:
    for food in list:
        print(food, end=", ")
    print()


#exercise - phone key pad

num_pad = (
    (1, 2, 3),
    (4, 5, 6), 
    (7, 8, 9), 
    ('*', 0, '#')
    )

for list in num_pad:
    for num in list:
        print(num, end=" ")
    print()



#exercise - quiz game

questions = ("How many elements are in the periodic table? ",
             "Which animal lays the largest eggs? ",
             "What is the most abundant gas in Earth's atmosphere? ",
             "How many bones are in a human body? ",
             "Which planet in the solar system is the hottest? ")

options = (("A. 116", "B. 117", "C. 118", "D. 119"), 
           ("A. Whale", "B. Crocodile", "C. Elephant", "D. Ostrich"), 
           ("A. Nitrogen", "B. Oxygen", "C. Carbon-Dioxide", "D. Hydrogen"), 
           ("A. 206", "B. 207", "C. 208", "D. 209"), 
           ("A. Mercury", "B. Venus", "C. Earth", "D. Mars"))

answers = ("C", "D", "A", "A", "B")

guesses = []
score = 0
question_num = 0

for question in questions:
    print("-----------------------------------")
    print(question)
    
    for option in options[question_num]:
        print(option)
    
    guess = input("Enter you answer (A, B, C, or D): ").upper()
    guesses.append(guess)

    if answers[question_num] == guesses[question_num]:
        score += 1
        print("CORRECT!!")
    else:
        print("INCORRECT!")
        print(f"{answers[question_num]} is the correct answer")

    question_num += 1

print(f"Your score is {score}/5")


##############################################################################################################

#dictionary

capitals = {"USA": "Washington D.C.", 
            "India": "New Dlhi", 
            "China": "Beijing", 
            "Russia": "Moscow"}


print(capitals.get("USA"))
print(capitals.get("USA"))

capitals.update({"Germany": "Berlin"})
capitals.update({"USA": "Detroit"})

capitals.pop("China")
capitals.popitem()

capitals.clear()


for key in capitals.keys():
    print(key, end=", ")

print()

for value in capitals.values():
    print(value, end=", ")


for key, val in capitals.items():
    print(f"Key = {key}, value = {val}")


#exercise - Concession stand

menu = {"pizza": 3.00,
        "nachos": 4.50,
        "popcorn": 6.00,
        "fries": 2.50,
        "chips": 1.00,
        "pretzel": 3.50,
        "soda": 3.00,
        "lemonade": 4.25}

cart = []
total = 0

print("-------- manu ---------")
for key, val in menu.items():
    print(f"{key:10} = ${val:.2f}")

print("-----------------------")

while True:
    food = input("Selct an Item from the manu (q to quit): ")
    
    if 'q' == food.lower():
        break
    elif food in menu.keys():
        cart.append(food)
    else:
        print(f"{food} is not on the menu")

print("-----------------------")
print("Your order:")
for item in cart:
    total += menu.get(item)
    print(f"{item:10} = ${menu.get(item)}")
print()
print(f"Total = ${total:.2f}")
'''

















