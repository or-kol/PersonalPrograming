


class Student:

    count = 0
    sum_gpa = 0

    def __init__(self, name, gpa):
        self.name = name
        self.gpa = gpa
        Student.count += 1
        Student.sum_gpa += gpa
    
    #instance method
    def getInfo(self):
        return f"{self.name}: {self.gpa}"
    

    @classmethod
    def getCount(cls):
        return f"Total number of students: {cls.count}"
    
    @classmethod
    def avgGpa(cls):
        if 0 == cls.count:
            return 0
        else:
            return f"Average GPA: {cls.sum_gpa / cls.count:.2f}"

