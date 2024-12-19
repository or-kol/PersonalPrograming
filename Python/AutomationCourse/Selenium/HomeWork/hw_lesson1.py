from time import sleep
from selenium import webdriver
from selenium.webdriver.common.by import By

driver = webdriver.Chrome()
driver.maximize_window()

# Home Work:
# https://docs.google.com/document/d/1oR6Co-KDMVV7EQ20KV0GuVXXd0yWx7sV/edit?usp=sharing&ouid=105968411837263593065&rtpof=true&sd=true

# Exercise 1:
driver.get("https://prd.canvusapps.com/signup")

driver.find_element(By.CSS_SELECTOR, "#user_name").send_keys("Or Kol")
driver.find_element(By.CSS_SELECTOR, "#user_email").send_keys("OrKol@gmail.com")
driver.find_element(By.CSS_SELECTOR, "#user_password").send_keys("123456")
driver.find_element(By.CSS_SELECTOR, "#user_password_confirmation").send_keys("123456")
driver.find_element(By.CSS_SELECTOR, "#company_name").send_keys("Or Kol")
driver.find_element(By.CSS_SELECTOR, ".submit").click()

print(driver.find_element(By.CSS_SELECTOR, ".alert-error").text)



# Exercise 2:
driver.get("https://login.salesforce.com/")

driver.find_element(By.CSS_SELECTOR, "#forgot_password_link").click()

if "Forgot Your Password" in driver.title:
    driver.find_element(By.CSS_SELECTOR, "#un").send_keys("OrKol")
    driver.find_element(By.CSS_SELECTOR, "#continue").click()
    print(driver.find_element(By.CSS_SELECTOR, ".error").text)



# Exercise 3:
driver.get("http://www.ebay.com/sch/ebayadvsearch")

driver.find_element(By.CSS_SELECTOR, "#_nkw").send_keys("tent")
driver.find_element(By.CSS_SELECTOR, "#_ex_kw").send_keys("blue, open, small")
driver.find_element(By.CSS_SELECTOR, "[data-marko*='s0-1-17-12']").click()
driver.back()
driver.find_element(By.CSS_SELECTOR, "[data-marko*='s0-1-17-4[0]-9']").click()



# Exercise 4:
driver.get("https://www.espn.com/")

print("1st element:")
print(driver.find_element(By.CSS_SELECTOR, ".menu-nfl").text)
print(driver.find_element(By.CSS_SELECTOR, ".menu-nfl").get_attribute("id"))
print(driver.find_element(By.CSS_SELECTOR, ".menu-nfl").tag_name)
print(driver.find_element(By.CSS_SELECTOR, ".menu-nfl").is_displayed())
print(driver.find_element(By.CSS_SELECTOR, ".menu-nfl").is_enabled())

print("\n2nd element:")
print(driver.find_element(By.CSS_SELECTOR, "[name='&lpos=customize:espn:oneid:module:login']").text)
print(driver.find_element(By.CSS_SELECTOR, "[name='&lpos=customize:espn:oneid:module:login']").get_attribute("id"))
print(driver.find_element(By.CSS_SELECTOR, "[name='&lpos=customize:espn:oneid:module:login']").tag_name)
print(driver.find_element(By.CSS_SELECTOR, "[name='&lpos=customize:espn:oneid:module:login']").is_displayed())
print(driver.find_element(By.CSS_SELECTOR, "[name='&lpos=customize:espn:oneid:module:login']").is_enabled())

print("\n3rd element:")
print(driver.find_element(By.CSS_SELECTOR, ".button--eplus").text)
print(driver.find_element(By.CSS_SELECTOR, ".button--eplus").get_attribute("id"))
print(driver.find_element(By.CSS_SELECTOR, ".button--eplus").tag_name)
print(driver.find_element(By.CSS_SELECTOR, ".button--eplus").is_displayed())
print(driver.find_element(By.CSS_SELECTOR, ".button--eplus").is_enabled())



# Exercise 5:
driver.get("https://login.salesforce.com/")
driver.find_element(By.CSS_SELECTOR, "#username").send_keys("Or Kol")
driver.find_element(By.CSS_SELECTOR, "#password").send_keys("123456")
driver.find_element(By.CSS_SELECTOR, "#rememberUn").click()
sleep(5)

check_box_status = driver.find_element(By.CSS_SELECTOR, "#rememberUn")
if check_box_status.is_selected():
    driver.find_element(By.CSS_SELECTOR, "#Login").click()



# Exercise 5:
driver.get("https://www.selenium.dev/")
selenium_title = driver.title
print("Yes!" if selenium_title == "selenium web site" or "Selenium" in selenium_title else "No!")

driver.get("https://www.google.com")
google_title = driver.title
print("Yes!" if google_title == "Google" or "google" in google_title else "No!")

driver.back()
back_title = driver.title
print("Yes!" if selenium_title == "selenium web site" or "Selenium" in selenium_title else "No!")

input("Enter to close browser")




