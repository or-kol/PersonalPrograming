import random
from selenium import webdriver
from Lesson1.pages.wizard1_page import Wizard1
from Lesson1.pages.wizard2_page import Wizard2
from Lesson1.pages.wizard3_page import Wizard3

driver = webdriver.Chrome()
driver.maximize_window()
driver.get("https://galmatalon.github.io/tutorials/indexID.html")


page1 = Wizard1(driver)
page1.fillInfo("Orx", "Kol", "or@gmail.com")


page2 = Wizard2(driver)
valid_level = ['Beginner', 'Intermediate', 'Advanced', '']
option = random.choices(valid_level)[0]
print(option)
page2.selectLevel(option)

page3 = Wizard3(driver)
page3.fillInfo("street", 555, "Tel Aviv", "Italy")

print(page3.getMsg())


input("Enter to close")

