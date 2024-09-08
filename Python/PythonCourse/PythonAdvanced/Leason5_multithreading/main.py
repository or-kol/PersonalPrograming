


import threading
import time

def walkDog(name):
    time.sleep(8)
    print(f"You finished walking {name}")

def takeOutTrash():
    time.sleep(2)
    print("You took out the trash")

def getMail():
    time.sleep(4)
    print("You got the mail")

def main():
    
    '''
    walkDog()
    takeOutTrash()
    getMail()
    '''

    chore1 = threading.Thread(target=walkDog, args=("Polly",))
    chore1.start()

    chore2 = threading.Thread(target=takeOutTrash)
    chore2.start()

    chore3 = threading.Thread(target=getMail)
    chore3.start()

    chore1.join()
    chore2.join()
    chore2.join()
    # without the join mathod the print will be executed before the chores are completed.
    print("All chores are compete!")



if __name__ == "__main__":
    main()