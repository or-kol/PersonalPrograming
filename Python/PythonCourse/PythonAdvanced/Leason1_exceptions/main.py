


def main():
    
    try:
        num = int(input("Enter a number: "))
        print(1 / num)
    except ZeroDivisionError:
        print("You can't devide by 0!")
    except ValueError:
        print("Enter numbers only!")
    except Exception: #general exception error
        print("something went wrong!")
    finally:
        print("Do some cleanup")



if __name__ == "__main__":
    main()