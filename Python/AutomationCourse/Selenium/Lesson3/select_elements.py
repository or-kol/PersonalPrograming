from time import sleep
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.select import Select

driver = webdriver.Chrome()
driver.maximize_window()

driver.get("https://galmatalon.github.io/tutorials/indexID.html")

driver.find_element(By.ID, "firstname").send_keys("Orx")
driver.find_element(By.ID, "lastname").send_keys("Kol")
driver.find_element(By.ID, "email").send_keys("orkol1988@gmail.com")
driver.find_element(By.ID, "next").click()

driver.find_element(By.ID, "next").click()

driver.find_element(By.ID, "streetname").clear()
driver.find_element(By.ID, "streetname").send_keys("Tzufit")
driver.find_element(By.ID, "streetnumber").send_keys("55")
driver.find_element(By.ID, "city").send_keys("Yarhiv")

dropdown = Select(driver.find_element(By.ID, "country"))
dropdown.select_by_index(0)
sleep(5)
dropdown.select_by_visible_text("Argentina")
sleep(5)
dropdown.select_by_value("Israel")
sleep(5)
driver.find_element(By.ID, "finish").click()

