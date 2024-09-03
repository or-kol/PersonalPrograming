
#1:27:14

'''
contents:
string methods
string indexing
format specifiers
'''

'''
name = input("Enter your full name: ")

print(len(name))
print(name.find(' '))
print(name.rfind('o'))
print(name.capitalize())
print(name.upper())
print(name.lower())
print(name.isdigit())
print(name.isalpha())


phone_num = input("Enter our phone number: ")

print(phone_num.count('-'))
print(phone_num.replace('-', ' '))


#exercise 1
user_name = input("Enter your user name: ")

if 12 < len(user_name):
    print("User name can't exceed 12 charachters!")
elif -1 != user_name.find(' '):
    print("User name can't contain spaces!")
elif False == user_name.isalpha():
    print("User name must contain letters only!")
else:
    print("User name approved!")
'''

###################################################################################################

'''
credit_num = "123-456-789"
#[start : end : step]

print(credit_num[0])
print(credit_num[0 : 4])
print(credit_num[4 : ])
print(credit_num[0 : 4 : 2])
print(credit_num[ : 4 : 2])



print(credit_num[-4 : ])
print(credit_num[::-1]) #reverse
'''

###################################################################################################


price1 = 3000000.14159
price2 = -9870.65
price3 = 12000.34

'''
# floating point specifier
print(f"price 1 is: {price1:.2f}")
print(f"price 2 is: {price2:.2f}")
print(f"price 3 is: {price3:.2f}")

#allocate space:
#will allocate the amount of charecters to the output - will add spces to the left of the output.
print(f"price 1 is: {price1:20}")
print(f"price 2 is: {price2:20}")
print(f"price 3 is: {price3:20}") 

#will allocate the amount of charecters to the output - adding < before the number will add spces to the right of the output.
print(f"price 1 is: {price1:<20}")
print(f"price 2 is: {price2:<20}")
print(f"price 3 is: {price3:<20}") 

#will allocate the amount of charecters to the outp - adding a 0 before the number will set all spaces to be zeros.
print(f"price 1 is: {price1:<020}")
print(f"price 2 is: {price2:<020}")
print(f"price 3 is: {price3:<020}") 

#will allocate the amount of charecters to the output - adding ^ before the number will center the number.
print(f"price 1 is: {price1:^20}")
print(f"price 2 is: {price2:^20}")
print(f"price 3 is: {price3:^20}") 

#adding + will add + sign to positive numbers - negative numbers will stay negative.
print(f"price 1 is: {price1:+}")
print(f"price 2 is: {price2:+}")
print(f"price 3 is: {price3:+}") 

#adding , will add , to separate thousends.
print(f"price 1 is: {price1:,}")
print(f"price 2 is: {price2:,}")
print(f"price 3 is: {price3:,}") 

#we can combine these options:
print(f"price 1 is: {price1:+,.2f}")
print(f"price 2 is: {price2:+,.2f}")
print(f"price 3 is: {price3:+,.2f}") 
'''












