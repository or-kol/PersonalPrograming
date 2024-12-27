from selenium import webdriver
from HomeWork.HW_2.pages.advanced_task_page import AdvancedTask
from HomeWork.HW_2.pages.tasks_page import TasksPage

driver = webdriver.Chrome()
driver.maximize_window()
driver.get("http://www.mytinytodo.net/demo/")

task_page = TasksPage(driver)
task_page.addAdvancedTask("Todo")

advanced_task_page = AdvancedTask(driver)
advanced_task_page.fillAdvancedTask("This is my first task", 1, 2024, 12, 30, "Here you can write your note", "automation")

task_page.addAdvancedTask("Todo")
advanced_task_page.fillAdvancedTask("This is my second task")

input("Enter to close")