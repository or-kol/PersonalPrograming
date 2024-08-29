
# Q2
numLst2 = []
for num in numLst2:
    print(num)


# Q3
numLst3 = [1, 5, 7, 8, 100]
for num in numLst3[:len(numLst3)//2]:
    print(num)


#Q4
wordsLst = ["hello", "python", "pen", "world of coding"]
for word in wordsLst:
    print(word.upper())


# Q5
for word in wordsLst:
    if len(word) < 4:
        break
    else:
        print(word.upper())


# Q6
myName = "Benjamin Peterson"
print(myName[-5:])

print(myName[:len(myName)//3])

print(myName.count("a"))

print("b" in myName.lower())

myNameLst = myName.split()
print(myNameLst)

myNameLst.reverse()
print(myNameLst)

myNameLst[0] = myNameLst[0].upper()
print(myNameLst[0])

myNameLst[1] = myNameLst[1][:len(myNameLst[1])//2 - 1] + myNameLst[1][len(myNameLst[1])//2:]
print(myNameLst[1])

myNewName = myNameLst[1] + " " + myNameLst[0]
print(myNewName)


# Q7
str7 = "Hello World"
print([charIndex for charIndex, char in enumerate(str7) if char == "o"])


# Q8
import statistics

numLst8 = [8, 1000, -3, 2, 5]
print(sum(numLst8))

print(min(numLst8))

print(max(numLst8))

print(statistics.mean(numLst8))

numLst8.remove(numLst8[int(len(numLst8)/2)])
print(numLst8)

numLst8.sort()
print(numLst8)

for num in range(1, 5):
    print(numLst8)

numLst8.remove(numLst8[0])
print(numLst8)

numLstSmolerAvg = []
for num in numLst8:
    if num < statistics.mean(numLst8):
        numLstSmolerAvg.append(num)
print(numLstSmolerAvg)


# Q9
numLst9 = [1, 5, 7, 8, 100]
largestNum = min(numLst9)
for num in numLst9:
    if num > largestNum:
        largestNum = num

print(largestNum)


# Q10
numLst10 = [ [4, 8, 200], [4, 3000, -1], [5, 87, 12] ]
smallestNum = 999999
for lst in numLst10:
    for num in lst:
        if num < smallestNum:
            smallestNum = num

print(smallestNum)




