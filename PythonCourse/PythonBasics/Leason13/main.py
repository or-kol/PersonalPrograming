


def showBalance(balance):
    print(f"Your balance is ${balance:.2f}")


def deposit(balance):
    amount = float(input("Enter deposit ammount: "))
    
    if 0 > amount:
        print("Not a valid amount!")
        return 0
    else:
        return amount


def withdraw(balance):
    amount = float(input("Enter withdraw ammount: "))

    if 0 > amount:
        print("Not a valid amount!")
        return 0
    elif amount > balance:
        print("You don't have enough money!")
        return 0
    else:
        return amount
    

def main():
    balance = 0
    is_running = True

    print("Banking Program")

    while is_running:
        print("1. Show Balance")
        print("2. Deposit")
        print("3. Withdrow")
        print("4. Exit")

        choice = input("Enter your choice (1-4): ")
        
        match choice:
            case "1":
                showBalance(balance)
            case "2":
                balance += deposit(balance)
            case "3":
                balance -= withdraw(balance)
            case "4":
                is_running = False
            case _:
                print("Invalid choice!")
        
        
        print("\n ----------------------- \n")
    
    print("Thank you! Have a nice day!")



if __name__ == "__main__":
    main()




















