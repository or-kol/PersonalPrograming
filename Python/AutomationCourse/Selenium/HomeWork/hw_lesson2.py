import random
import string
from time import sleep
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.options import Options

chrome_options = Options()
chrome_options.add_argument("--disable-notifications")
chrome_options.add_argument("--disable-blink-features=AutomationControlled")
chrome_options.add_argument("user-agent=Your User Agent Here")

driver = webdriver.Chrome(options=chrome_options)
driver.maximize_window()

# Home Work:
# https://docs.google.com/document/d/1JGQYxI18oRSe2Coqy757cloH2yiOPaz5/edit


# Exercise 1:
driver.get("https://prd.canvusapps.com/signup")

driver.find_element(By.CSS_SELECTOR, "#user_email").send_keys("".join(random.choices(string.ascii_lowercase, k=8)) + "@gmail.com")
driver.find_element(By.CSS_SELECTOR, "#user_name").send_keys("".join(random.choices(string.ascii_lowercase, k=8)))
driver.find_element(By.CSS_SELECTOR, "#user_password").send_keys("123456")
driver.find_element(By.CSS_SELECTOR, "#user_password_confirmation").send_keys("654321")
driver.find_element(By.CSS_SELECTOR, "#company_name").send_keys("".join(random.choices(string.ascii_lowercase, k=8)))

driver.find_element(By.CSS_SELECTOR, ".submit.btn.btn-primary").click()

print(driver.find_element(By.CSS_SELECTOR, ".alert.alert-error.alert-block.error").text)
print(driver.find_element(By.CSS_SELECTOR, "#reg-form>div.control-group.error>div>span").text)

driver.find_element(By.CSS_SELECTOR, ".span6.text-right>small>a").click()
driver.find_element(By.CSS_SELECTOR, ".form-vertical.well>fieldset>p>a").click()

print(driver.title)
if "password_resets" in driver.current_url:
    driver.find_element(By.CSS_SELECTOR, "#email").send_keys("ok@gmail.com")
    driver.find_element(By.CSS_SELECTOR, "[name='commit']").click()



# Exercise 2:
driver.get("https://www.w3schools.com/")

links_list = driver.find_elements(By.CSS_SELECTOR, "a")

#for link in links_list:
#    print(link.get_attribute("href"))

for link in links_list:
    if "video" in link.get_attribute("href"):
        print(link.get_attribute("href"))



# Exercise 3:
driver.get("http://www.echoecho.com/htmlforms10.htm")

driver.find_element(By.CSS_SELECTOR, "input[type=radio]:nth-child(2)").click()

driver.find_element(By.CSS_SELECTOR, "body>div:nth-child(2)>table:nth-child(14)>tbody>tr>td.main>table>tbody>tr>td>div>span>form>table:nth-child(38)>tbody>tr>td>table>tbody>tr>td>input[value='Milk']").click()
driver.find_element(By.CSS_SELECTOR, "body>div:nth-child(2)>table:nth-child(14)>tbody>tr>td.main>table>tbody>tr>td>div>span>form>table:nth-child(38)>tbody>tr>td>table>tbody>tr>td>input[value='Water']").click()



# Exercise 4:
driver.get("https://whatismyipaddress.com/")
sleep(5)
ip_adrs = driver.find_element(By.CSS_SELECTOR, "#ipv4>a").text

driver.get("https://apps.db.ripe.net/db-web-ui/query")
sleep(5)
driver.find_element(By.CSS_SELECTOR, "#queryStringInput").send_keys(f"{ip_adrs}\n")
sleep(10)
element_list = driver.find_elements(By.CSS_SELECTOR, "#resultsSection>div>div:nth-child(3)>div>lookup>div>whois-object-viewer>pre>ul")

for element in element_list:
    print(element.text)



# Exercise 4:
driver.get("https://www.amazon.com/")

driver.find_element(By.CSS_SELECTOR, "#twotabsearchtextbox").send_keys("tent\n")

for idx in range(0, 10):
    sleep(3)
    page_results_list = driver.find_elements(By.CSS_SELECTOR, "[data-component-type='s-search-result']")
    for result in page_results_list:
        print(result.text)
        print()
    sleep(10)
    driver.find_element(By.CSS_SELECTOR, "[aria-label^='Go to next page']").click()

input("Enter to close browser")