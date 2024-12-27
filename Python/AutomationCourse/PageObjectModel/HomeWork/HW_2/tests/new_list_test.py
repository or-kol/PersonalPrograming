from selenium import webdriver
from HomeWork.HW_2.pages.tasks_page import TasksPage

driver = webdriver.Chrome()
driver.maximize_window()
driver.get("http://www.mytinytodo.net/demo/")

tasks_page = TasksPage(driver)
tasks_page.creatNewList("New Tasks List")
tasks_page.addSimpleTask("New Tasks List", "New Task1")
tasks_page.addSimpleTask("New Tasks List", "New Task2")

print(f"New Tasks List contain {tasks_page.getAmountOfTasks()} tasks")

input("Enter to close")
