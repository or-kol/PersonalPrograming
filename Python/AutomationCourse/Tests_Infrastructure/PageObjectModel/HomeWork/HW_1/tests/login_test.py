from selenium import webdriver
from PageObjectModel.HomeWork.HW_1.pages.login_page import Login


driver = webdriver.Chrome()
driver.maximize_window()
driver.get("https://www.saucedemo.com/")

login_page = Login(driver)
login_page.fillInfo("standard_user", "secret_sauce")

input("Enter to close")