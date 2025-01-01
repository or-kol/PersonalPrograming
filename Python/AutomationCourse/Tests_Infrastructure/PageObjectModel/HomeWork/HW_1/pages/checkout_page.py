from selenium.webdriver.common.by import By
from PageObjectModel.HomeWork.HW_1.pages.base_page import BasePage


class Checkout(BasePage):

    FIRST_NAME_FIELD = (By.CSS_SELECTOR, "#first-name")
    LAST_NAME_FIELD = (By.CSS_SELECTOR, "#last-name")
    ZIP_CODE_FIELD = (By.CSS_SELECTOR, "#postal-code")
    CONTINUE_BTN = (By.CSS_SELECTOR, "#continue")
    CANCEL_BTN = (By.CSS_SELECTOR, "#cancel")

    def __init__(self, driver):
        super().__init__(driver)

    def fillInfo(self, first_name, last_name, zip_code):
        self.fillText(self.FIRST_NAME_FIELD, first_name)
        self.fillText(self.LAST_NAME_FIELD, last_name)
        self.fillText(self.ZIP_CODE_FIELD, zip_code)
        self.click(self.CONTINUE_BTN)

    def backToCart(self):
        self.click(self.CANCEL_BTN)