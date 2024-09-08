
from rectangle import Rectangle

def main():
    
    rectangle = Rectangle(3, 4)

    #print(rectangle._width) #it should not be accessed directly (we can access it is using '_width', but we shouldn't)

    rectangle.width = 0
    rectangle.height = -1
    print(rectangle.width)
    print(rectangle.height)

    rectangle.width = 5
    rectangle.height = 6
    print(rectangle.width)
    print(rectangle.height)

    del rectangle.width
    del rectangle.height
    

    

if __name__ == "__main__":
    main()