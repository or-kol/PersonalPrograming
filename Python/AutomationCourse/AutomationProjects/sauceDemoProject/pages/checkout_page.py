from selenium.webdriver.common.by import By
from pages.base_page import BasePage


class CheckoutPage(BasePage):

    FIRST_NAME_FIELD = (By.CSS_SELECTOR, "#first-name")
    LAST_NAME_FIELD = (By.CSS_SELECTOR, "#last-name")
    ZIP_CODE_FIELD = (By.CSS_SELECTOR, "#postal-code")
    CONTINUE_BTN = (By.CSS_SELECTOR, "#continue")
    CANCEL_BTN = (By.CSS_SELECTOR, "#cancel")
    CHECKOUT_PAGE_TITLE = (By.CSS_SELECTOR, ".title")
    ERROR_MSG = (By.CSS_SELECTOR, "[data-test='error']")

    def __init__(self, driver):
        super().__init__(driver)

    def fill_info(self, first_name, last_name, zip_code):
        self.fill_text(self.FIRST_NAME_FIELD, first_name)
        self.fill_text(self.LAST_NAME_FIELD, last_name)
        self.fill_text(self.ZIP_CODE_FIELD, zip_code)
        self.click(self.CONTINUE_BTN)

    def go_back_to_cart(self):
        self.click(self.CANCEL_BTN)

    def get_checkout_page_title(self):
        return self.get_text(self.CHECKOUT_PAGE_TITLE)

    def get_checkout_error_msg(self):
        return self.get_text(self.ERROR_MSG)