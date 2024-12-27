from selenium import webdriver
from HomeWork.HW_2.pages.tasks_page import TasksPage

driver = webdriver.Chrome()
driver.maximize_window()
driver.get("http://www.mytinytodo.net/demo/")

tasks_page = TasksPage(driver)
tasks_page.addSimpleTask("Todo", "New Task")

input("Enter to close")
