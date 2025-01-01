from time import sleep
from selenium.webdriver.chrome.webdriver import WebDriver
from selenium.webdriver.support.select import Select

class BasePage:

    def __init__(self, driver):
        self.driver: WebDriver = driver

    def fillText(self, locator, text):
        self.highlight_element(locator, "yellow")
        self.driver.find_element(*locator).clear()
        self.driver.find_element(*locator).send_keys(text)

    def click(self, locator):
        sleep(2)
        self.highlight_element(locator, "yellow")
        self.driver.find_element(*locator).click()

    def getText(self, locator):
        sleep(2)
        self.highlight_element(locator, "red")
        return self.driver.find_element(*locator).text

    def selectOption(self, locator, option):
        self.highlight_element(locator, "yellow")
        select = Select(self.driver.find_element(*locator))
        select.select_by_value(f"{option}")

    def getElementsList(self, locator):
        sleep(2)
        return self.driver.find_elements(*locator)

    def highlight_element(self, locator, color):
        element = self.driver.find_element(*locator)
        original_style = element.get_attribute("style")
        new_style = "background-color: " + color + ";" + original_style

        self.driver.execute_script("arguments[0].setAttribute('style', arguments[1]);", element, new_style)

        self.driver.execute_script("setTimeout(function() {arguments[0].setAttribute('style', arguments[1]);}, 100);"
                                   ,element, original_style)