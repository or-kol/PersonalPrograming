from selenium import webdriver
from time import sleep

driver = webdriver.Chrome()

driver.maximize_window()             # Maximize the browser window

driver.get("https://selenium.dev/")  # Navigate to the target URL

driver.get("https://selenium.dev/downloads/")
sleep(5)
driver.back()
sleep(5)
driver.forward()

print(driver.current_url)
print(driver.title)
print(driver.name)

if driver.title == "Downloads | Selenium":
    print("Title test pass")
else:
    print(f"Title test failure! Expected: 'Downloads | Selenium' --> Actual: '{driver.title}'")

input("Enter to close browser")