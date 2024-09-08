

'''
content:
variable scope
'''

'''
# local variable

def func1():
    x = 3 #local to func1
    print(x)

def func2():
    x = 6 #local to func2
    print(x)

func1()
func2()



# enclosed

def func3():
    x = 1 #local variable for func3 and enclosed for func4
    def func4():
        x = 5 # local variable func4
        print(x)
    func4()

func3() #will print '5' since local variables have priority over enclosed.


def func5():
    x = 1 #local variable for func5 and enclosed for func6
    def func6():
        print(x)
    func6()

func5() #will print '1' sisce x is enclosed variable for func 6.



# global variable

def func7():
    print(x)

def func8():
    print(x)

x = 6 # global variable

func7() #print 6
func8() #print 6



# built-in
from math import e

def func9():
    print(e)

func9()


# scope resoltion: (LEGB) local -> enclosed -> global -> built-in
#                         1st      2nd         3rd       4th
'''



