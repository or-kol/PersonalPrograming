import allure
from selenium.webdriver.common.by import By
from pages.base_page import BasePage


class LoginPage(BasePage):

    USER_NAME_FIELD = (By.CSS_SELECTOR, "#user-name")
    PASSWORD_FIELD = (By.CSS_SELECTOR, "#password")
    LOGIN_BTN = (By.CSS_SELECTOR, "#login-button")
    ERROR_MSG = (By.CSS_SELECTOR, ".error-message-container")

    def __init__(self, driver):
        super().__init__(driver)

    @allure.step("Login with Username: {username} and Password: {password}")
    def fill_info(self, username, password):
        self.fill_text(self.USER_NAME_FIELD, username)
        self.fill_text(self.PASSWORD_FIELD, password)
        self.click(self.LOGIN_BTN)

    @allure.step("Get error message")
    def get_error_msg(self):
        return self.get_text(self.ERROR_MSG)


