from time import sleep

from selenium import webdriver
from selenium.webdriver.common.by import By

driver = webdriver.Chrome()
driver.maximize_window()


# Home Work:
# https://docs.google.com/document/d/13LEqnGfJJktNbgqAUUOr09TDe6MjY7Zi/edit

'''
# Exercise 1:
driver.get("https://login.salesforce.com/")

driver.find_element(By.CSS_SELECTOR, "#username").send_keys("Or")
driver.find_element(By.CSS_SELECTOR, "#password").send_keys("123456")
driver.find_element(By.CSS_SELECTOR, "#rememberUn").click()
driver.find_element(By.CSS_SELECTOR, "#Login").click()
print(driver.find_element(By.CSS_SELECTOR, "#error").text)

driver.find_element(By.CSS_SELECTOR, "#forgot_password_link").click()
driver.find_element(By.CSS_SELECTOR, "#un").send_keys("Or")
driver.find_element(By.CSS_SELECTOR, "#continue").click()
print(driver.find_element(By.CSS_SELECTOR, ".mb16.error").text)



# Exercise 2:
driver.get("http://www.wix.com/jobs/locations/tel-aviv")
sleep(5)

links_list = driver.find_elements(By.CSS_SELECTOR, "a")

for link in links_list:
    print(link.get_attribute("href"))


showing = ""
total = driver.find_element(By.CSS_SELECTOR, ".rM7ckN.YJEKQk.comp-lr3n08cs1-container.comp-lr3n08cs1.wixui-box>#comp-lr3n08cy10").text
while showing != total:
    driver.find_element(By.CSS_SELECTOR, "#comp-lr3n08d01").click()
    showing = driver.find_element(By.CSS_SELECTOR, ".rM7ckN.YJEKQk.comp-lr3n08cs1-container.comp-lr3n08cs1.wixui-box>#comp-lr3n08cv10").text

jobs_list = driver.find_elements(By.CSS_SELECTOR, ".Mdue19.comp-lr3n08ai6.wixui-repeater>div>div")

print("All jobs:")
print("\n\n".join([job.text for job in jobs_list]))

print("\n-----------------------------------------------------------------------------------------------------\n")

print("All jobs contain the word 'Engineer':")
print("\n\n".join([job.text for job in jobs_list if "Engineer" in job.text]))
'''


# Exercise 3:
driver.get("http://www.wix.com/jobs/locations/tel-aviv")






input("Enter to close browser")