from selenium.webdriver.common.by import By
from Pytest.HomeWork.HW_1.pages.base_page import BasePage

class CompletePurchase(BasePage):

    BACK_HOME_BTN = (By.CSS_SELECTOR, "#back-to-products")
    COMPLETE_MSG = (By.CSS_SELECTOR, ".complete-header")

    def __init__(self, driver):
        super().__init__(driver)

    def getMsg(self):
        return self.getText(self.COMPLETE_MSG)

    def backHome(self):
        self.click(self.BACK_HOME_BTN)