from selenium import webdriver
from Lesson1.pages.wizard1_page import Wizard1

driver = webdriver.Chrome()
driver.maximize_window()
driver.get("https://galmatalon.github.io/tutorials/indexID.html")

page1 = Wizard1(driver)
page1.fillInfo("Or", "Kol", "or@gmail.com")
page1.fillInfo("Or", "Kol", "or")
page1.fillInfo("Orx", "Kol", "or@gmail.com")

input("Enter to close")

