import random
import time

def spinRow(symbols):
    row = []
    symbols = ['🍒', '🍉', '🍋', '🔔', '⭐']
    
    return [random.choice(symbols) for i in range(3)]


def printRow(row):
    print("*************************")
    print(" | ".join(row))
    print("*************************")


def getPayout(bet, row):
    match row:
        case ['🍒', '🍒', '🍒']:
            return bet * 2
        case ['🍉', '🍉', '🍉']:
            return bet * 5
        case ['🍋', '🍋', '🍋']:
            return bet * 10
        case ['🔔', '🔔', '🔔']:
            return bet * 20
        case ['⭐', '⭐', '⭐']:
            return bet * 50
        case _:
            print("Sorry, you lost this round")
            return 0


def main():
    balance = 100
    symbols = ['🍒', '🍉', '🍋', '🔔', '⭐']

    print("*************************")
    print("Wellcom to Python Slots")
    print("symbols:", end=" ")
    for symbol in symbols:
        print(symbol, end=" ")
    print()
    print("*************************")

    while 0 < balance:
        print(f"Current balnce: ${balance}")

        bet = input("Place your bet amount: ")

        if not bet.isdigit():
            print("Please enter a valid number")
            continue
        
        bet = int(bet)

        if bet > balance:
            print("Insufficient funds")
            continue

        if 0 >= bet:
            print("Bet maust be greater than 0")
            continue

        balance -= bet

        row = spinRow(symbols)
        print("Spinning...")
        time.sleep(3)
        printRow(row)

        payout = getPayout(bet, row)

        if 0 < payout:
            print(f"You won ${payout}")
        
        balance += payout

        play_again = input("Do you want to spin again (Y/N): ").upper()

        if 'N' == play_again:
            break
    
    print("*************************")
    print(f"Game Over! Your final balance is ${balance}")
    print("*************************")


if __name__ == "__main__":
    main()







