
from student import Student

def main():
    
    print(Student.getCount())

    student1 = Student("Mike", 80)
    print(Student.avgGpa())
    student2 = Student("Jake", 75)
    print(Student.getCount())
    print(Student.avgGpa())
    student3 = Student("Toni", 90)
    print(Student.getCount())
    print(Student.avgGpa())

    print(student1.getInfo())
    
    print(student2.getInfo())
    
    print(student3.getInfo())
    



if __name__ == "__main__":
    main()





