
from employee import Employee

def main():

    #access static method from the class and not from an instance of that class:
    print(Employee.isValidPosition("Janitor"))



    employee1 = Employee("Eugune", "Manager")
    employee2 = Employee("James", "Cashier")
    employee3 = Employee("Jhon", "Waiter")

    print(employee1.get_info())
    print(Employee.isValidPosition(employee1.position))

    print(employee2.get_info())
    print(Employee.isValidPosition(employee2.position))

    print(employee3.get_info())
    print(Employee.isValidPosition(employee3.position))
if __name__ == "__main__":
    main()