from time import sleep

from selenium import webdriver
from selenium.webdriver.common.by import By

driver = webdriver.Chrome()
driver.maximize_window()
driver.get("http://www.mytinytodo.net/demo/")

sleep(2)
task_elements = driver.find_elements(By.CSS_SELECTOR, "#tasklist>li")

print(len(task_elements))

for task in task_elements:
    print(task.text)
    print(" ")


input("close")
