
from car import Car
from student import Student


def main():  
    '''
    car1 = Car("Mustang", 2024, "Red", False)

    print(car1.color)
    print(car1.model)
    print(car1.year)
    print(car1.for_sale)

    car1.drive()
    

    car2 = Car("Corvette", 2025, "Blue", True)
    print(car2.color)
    print(car2.model)
    print(car2.year)
    print(car2.for_sale)

    car2.stop()

    car1.describe()
    car2.describe()
    '''

    ###########################################################################

    # class variables

    student1 = Student("Or Kol", 36)
    print(student1.name)
    print(student1.age)
    print(Student.class_year) # it's good practice to access class var with the calss name and not the instance name.
    print(Student.num_of_students)

    student2 = Student("Israel Israeli", 25)
    print(student2.name)
    print(student2.age)
    print(Student.class_year)
    print(Student.num_of_students)

    print(f"My graduating class of {Student.class_year} has {Student.num_of_students} students")




if __name__ == "__main__":
    main()







