from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.select import Select
from time import sleep

driver = webdriver.Chrome()
driver.maximize_window()
driver.get("https://galmatalon.github.io/tutorials/indexNoID.html")

# Page 1
driver.find_element(By.CSS_SELECTOR, "#firstname").send_keys("Or")
driver.find_element(By.CSS_SELECTOR, "#lastname").send_keys("Kol")
driver.find_element(By.CSS_SELECTOR, "#email").send_keys("orkol1988@gmail.com")
sleep(5)
driver.find_element(By.CSS_SELECTOR, ".btn.btn-next.btn-fill.btn-warning.btn-wd.btn-sm").click()

first_name_error_text = driver.find_element(By.CSS_SELECTOR, "#firstname-error").text
if first_name_error_text:
    driver.find_element(By.CSS_SELECTOR, "#firstname").clear()
    driver.find_element(By.CSS_SELECTOR, "#firstname").send_keys("Orx")
    driver.find_element(By.CSS_SELECTOR, ".btn.btn-next.btn-fill.btn-warning.btn-wd.btn-sm").click()


# Page 2
driver.find_element(By.CSS_SELECTOR, ".fa-child").click()
sleep(5)
driver.find_element(By.CSS_SELECTOR, ".btn-next").click()     # It's better to use minimum number of classes
                                                                    # (less likely it will be changed or deleted).

# Page 3
street_name_initial = driver.find_element(By.CSS_SELECTOR, "[name='streetname']").get_attribute("value")
print(street_name_initial)
if street_name_initial:
    driver.find_element(By.CSS_SELECTOR, "[name='streetname']").clear()

driver.find_element(By.CSS_SELECTOR, "[name='streetname']").send_keys("Tzufit")
driver.find_element(By.CSS_SELECTOR, "[name='streetnumber']").send_keys("55")
driver.find_element(By.CSS_SELECTOR, "[name='city']").send_keys("Yarhiv")

select = Select(driver.find_element(By.CSS_SELECTOR, "#country"))
select.select_by_value("Israel")
sleep(5)
driver.find_element(By.CSS_SELECTOR, "#finish").click()

e2e_test_text = driver.find_element(By.CSS_SELECTOR, ".cta-title").text
if e2e_test_text == "Congratulations!":
    print("E2E test success")
else:
    print("E2E test failure")

input("Enter to close browser")