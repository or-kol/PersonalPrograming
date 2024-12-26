from time import sleep
from selenium.webdriver.chrome.webdriver import WebDriver
from selenium.webdriver.common.by import By


class BasePage:

    GO_TO_CART_BTN = (By.CSS_SELECTOR, "#shopping_cart_container")
    MENU_BTN = (By.CSS_SELECTOR, "react-burger-menu-btn")
    LOGOUT_BTN = (By.CSS_SELECTOR, "logout_sidebar_link")

    def __init__(self, driver):
        self.driver: WebDriver = driver

    def fillText(self, locator, text):
        self.driver.find_element(*locator).clear()
        self.driver.find_element(*locator).send_keys(text)

    def click(self, locator):
        sleep(2)
        self.driver.find_element(*locator).click()

    def getText(self, locator):
        return self.driver.find_element(*locator).text

    def goToCart(self):
        self.click(self.GO_TO_CART_BTN)

    def logout(self):
        self.click(self.MENU_BTN)
        self.click(self.LOGOUT_BTN)