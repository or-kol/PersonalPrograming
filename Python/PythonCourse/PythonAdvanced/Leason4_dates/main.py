
import datetime
import time
import pygame


def setAlarm(alarm_time):
    print(f"Alarm set for {alarm_time}")
    sound_file = r"PythonCourse\PythonAdvanced\Leason4_dates\Babe_I'm_Gonna_Leave_You_Live.mp3"
    is_running = True

    while is_running:
        current_time = datetime.datetime.now().strftime("%H:%M:%S")

        print(current_time)
        time.sleep(1)
        
        if current_time == alarm_time:
            print("Wake Up!!")
            pygame.mixer.init()
            pygame.mixer.music.load(sound_file)
            pygame.mixer.music.play()
            while pygame.mixer.music.get_busy():
                time.sleep(1)
            is_running = False



def main():
    '''
    date = datetime.date(2025, 1, 2)
    print(date)

    today = datetime.date.today()
    print(today)


    time = datetime.time(12, 30, 0)
    print(time)

    now1 = datetime.datetime.now()
    print(now1)

    now2 = datetime.datetime.now().strftime("%H:%M:%S %d-%m-%Y")
    print(now2)
    


    #target_datetime = datetime.datetime(2030, 1 , 2 , 12 , 30, 1)
    target_datetime = datetime.datetime(2020, 1 , 2 , 12 , 30, 1)
    current_datetime = datetime.datetime.now()

    if target_datetime < current_datetime:
        print("Tatget date has passed")
    else:
        print("Target date has not passed")
    '''

    #exercise - alarm clock

    alarm_time = input("Enter the alarm time (HH:MM:SS): ")
    setAlarm(alarm_time)



if __name__ == "__main__":
    main()