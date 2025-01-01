from selenium.webdriver.common.by import By
from PageObjectModel.HomeWork.HW_1.pages.base_page import BasePage


class Login(BasePage):

    USER_NAME_FIELD = (By.CSS_SELECTOR, "#user-name")
    PASSWORD_FIELD = (By.CSS_SELECTOR, "#password")
    LOGIN_BTN = (By.CSS_SELECTOR, "#login-button")

    def __init__(self, driver):
        super().__init__(driver)

    def fillInfo(self, username, password):
        self.fillText(self.USER_NAME_FIELD, username)
        self.fillText(self.PASSWORD_FIELD, password)
        self.click(self.LOGIN_BTN)
