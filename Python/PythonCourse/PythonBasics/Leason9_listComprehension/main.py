


'''
content:
list comprehension
'''

'''
doubles1 = []

for x in range(1, 11):
    doubles1.append(x*2)

print(doubles1)


doubles2 = [y*2 for y in range(1, 11)]

print(doubles2)


triples = [z ** 2 for z in range(1, 11)]
print(triples)



fruits = "apple", "orange", "banana", "coconut"
uper_case_fruits = [fruit.capitalize() for fruit in fruits]

print(uper_case_fruits)



nums = [1, -2, 3, -4, 5, -6]

pos_nums = [num for num in nums if 0 <= num]
neg_nums = [num for num in nums if 0 > num]
even_nums = [num for num in nums if 0 == num % 2]

print(pos_nums)
print(neg_nums)
print(even_nums)



grades = [85, 42, 79, 90, 56, 61, 30]
passing_grades = [grade for grade in grades if 60 <= grade]

print(passing_grades)
'''














