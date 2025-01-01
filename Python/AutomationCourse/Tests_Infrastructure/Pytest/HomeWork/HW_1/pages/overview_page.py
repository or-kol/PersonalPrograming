from selenium.webdriver.common.by import By
from Pytest.HomeWork.HW_1.pages.base_page import BasePage

class Overview(BasePage):

    FINISH_BTN = (By.CSS_SELECTOR, "#finish")
    CANCEL_BTN = (By.CSS_SELECTOR, "#cancel")

    def __init__(self, driver):
        super().__init__(driver)

    def completePurchase(self):
        self.click(self.FINISH_BTN)

    def backToCheckoutPage(self):
        self.click(self.CANCEL_BTN)