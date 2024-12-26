from time import sleep
from selenium import webdriver
from selenium.webdriver.common.by import By

driver = webdriver.Chrome()
driver.maximize_window()

driver.get("https://www.ebay.com/sch/ebayadvsearch")

'''
driver.find_element(By.CSS_SELECTOR, "#_nkw").send_keys("tent")
driver.find_element(By.CSS_SELECTOR, "#_ex_kw").send_keys("blue, open, small")

# There are two search buttons in this page and their attributes are not unique:
# This is the second search in the bottom of the page:
driver.find_element(By.CSS_SELECTOR, ".adv-form__actions>button").click()

driver.back()

# This is the first search in the top of the page:
driver.find_element(By.CSS_SELECTOR, ".adv-keywords__btn-help>button").click()
'''


# Class exersice:
# Find the following elements in ebay page:
# Sign in, register, Help $ contact, Sell, Watchlist, My ebay, 'bell', 'cart', Home > Buy > Advanced Search

driver.find_element(By.CSS_SELECTOR, "#gh-ug>a").click()
print(("https://www.ebay.com/splashui/captcha" in driver.current_url))

driver.back()
sleep(5)

driver.find_element(By.CSS_SELECTOR, "#gh-ug-flex>a").click()
print(("https://www.ebay.com/splashui/captcha" in driver.current_url))

driver.back()
sleep(5)

driver.find_element(By.CSS_SELECTOR, "#gh-p-3>a").click()
print(("https://www.ebay.com/splashui/captcha" in driver.current_url))

driver.back()
sleep(5)

driver.find_element(By.CSS_SELECTOR, "#gh-p-2>.gh-p").click()
print(("https://www.ebay.com/sl/sell" == driver.current_url))

driver.back()
sleep(5)

driver.find_element(By.CSS_SELECTOR, ".watchlist-menu").click()
print(("https://www.ebay.com/sch/ebayadvsearch" == driver.current_url))

driver.back()
sleep(5)

driver.find_element(By.CSS_SELECTOR, "#gh-eb-My>div>a").click()
print(("https://www.ebay.com/splashui/captcha" in driver.current_url))

driver.back()
sleep(5)

print(driver.find_element(By.CSS_SELECTOR, ".ghn-b>svg>use").get_attribute("xlink:href") == "#gh-icon-notification-evo")

driver.find_element(By.CSS_SELECTOR, "#gh-eb-My>div>a").click()
print(("https://www.ebay.com/splashui/captcha" in driver.current_url))

driver.back()
sleep(5)

print(driver.find_element(By.CSS_SELECTOR, "[aria-current='location']").text == "Advanced search")

input("Enter to close")

