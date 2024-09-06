


class Rectangle:

    def __init__(self, width, height):
        self._width = width #the '_' before the property name tells others that it should not be accessed directly (we can access it is using '_width', but we shouldn't)
        self._height = height

    @property
    def width(self):
        return f"{self._width:.2f}cm"

    @property
    def height(self):
        return f"{self._height:.2f}cm"
    
    @width.setter
    def width(self, new_width):
        if 0 < new_width:
            self._width = new_width
        else:
            print("Width mast be greater than 0")

    @height.setter
    def height(self, new_height):
        if 0 < new_height:
            self._height = new_height
        else:
            print("Height mast be greater than 0")
    

    @width.deleter
    def width(self):
        del self._width
        print("Width has been deleted")

    @height.deleter
    def height(self):
        del self._height
        print("Height has been deleted")





