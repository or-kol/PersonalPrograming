

'''
content:
iterables
'''

'''
nums_list = [1, 2, 3, 4, 5]
nums_tup = (1, 2, 3, 4, 5)
nums_set = {1, 2, 3, 4, 5}

for num in nums_list:
    print(num, end=" ")
print()

for num in nums_tup[::-1]:
    print(num, end=" ")
print()

for num in nums_set: # sets are no reversable!
    print(num, end=" ")


name = "Alexander"

for char in name:
    print(char, end=" ")


my_dict = {"A": 1, "B": 2, "C": 3}

for key in my_dict.keys():
    print(key, end=" ")
print()

for val in my_dict.values():
    print(val, end=" ")
print()

for key, val in my_dict.items():
    print(f"{key}: {val}")
'''

















