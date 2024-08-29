import random

'''
contents:
collections
'''

'''
cube_num = random.randint(1, 20)
print(cube_num)

f_num = random.random()
print(f"{f_num:.2f}")

cards = ["2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Quin", "King", "A", "Joker"]
random.shuffle(cards)
print(cards)


#exercise - number guessing game
low = 1
high = 100
guesses = 0
answer = random.randint(low, high)
is_running = True

print("Python number guessing game")
while is_running:
    guess = input(f"Enter a number between {low}-{high}: ")

    if guess.isdigit():
        guess = int(guess)
        guesses += 1

        if not low <= guess <= high:
            print("Guess is out of range!")
        elif guess < answer:
            print("Too low!")
        elif guess > answer:
            print("Too high!")
        else:
            print(f"congratulations! {guess} is the lucky number!")
            print(f"Number of guesse: {guesses}")
            is_running = False
    else:
        print("You entered an invalid value")
    


options = ("rock", "paper", "scissors")
player = None

print("Wellcome to Rock, Paper, Scissors game!")
while 'q' != player:
    player = input("Please choose rock, paper or scissors: ").lower()
    computer = random.choice(options)

    if 'q' == player:
        break
    
    print("----------------------------")
    print(f"player: {player}")
    print(f"computer: {computer}")
    print()

    if player not in options:
        print("You chose an invalid input - try again!")
        continue
    
    if player == computer:
        print("It's a tie!!")
    elif ("rock" == player and "scissors" == computer) or ("scissors" == player and "paper" == computer) or ("paper" == player and "rock" == computer):
        print("Congratulations!! You won")
    else:
        print("You lost!!")
    
    print("----------------------------")

'''
















