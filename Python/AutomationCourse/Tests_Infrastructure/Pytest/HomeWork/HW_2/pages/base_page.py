from time import sleep
from selenium.webdriver.chrome.webdriver import WebDriver
from selenium.webdriver.support.select import Select

class BasePage:

    def __init__(self, driver):
        self.driver: WebDriver = driver

    def fillText(self, locator, text):
        self.driver.find_element(*locator).clear()
        self.driver.find_element(*locator).send_keys(text)

    def click(self, locator):
        sleep(2)
        self.driver.find_element(*locator).click()

    def getText(self, locator):
        sleep(2)
        return self.driver.find_element(*locator).text

    def selectOption(self, locator, option):
        select = Select(self.driver.find_element(*locator))
        select.select_by_value(f"{option}")

    def getElementsList(self, locator):
        sleep(2)
        return self.driver.find_elements(*locator)