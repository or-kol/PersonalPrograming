



'''
content:
match case (switch)
'''


'''
def dayOfWeek(day):
    match day:
        case 1:
            return "It's Sunday"
        case 2:
            return "It's Monday"
        case 3:
            return "It's Tuesday"
        case 4:
            return "It's Wednesday"
        case 5:
            return "It's Thursday"
        case 6:
            return "It's Friday"
        case 7:
            return "It's Saturday"
        case _:
            return "Not a valid day"

print(dayOfWeek(1))
print(dayOfWeek(3))
print(dayOfWeek(9))



def isWeekend(day):
    match day:
        case "Saturday" | "Sunday":
            return True
        case "Monday" | "Tuesday" | "Wednesday" | "Thursday" | "Friday":
            return False
        case _:
            return "Not a valid day"


print(isWeekend("Sunday"))
print(isWeekend("Monday"))
print(isWeekend("Thursday"))
print(isWeekend("Saturday"))
print(isWeekend("saturday"))
'''








