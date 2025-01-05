from selenium.webdriver.common.by import By
from pages.base_page import BasePage


class CompletePurchasePage(BasePage):

    BACK_HOME_BTN = (By.CSS_SELECTOR, "#back-to-products")
    COMPLETE_MSG = (By.CSS_SELECTOR, ".complete-header")

    def __init__(self, driver):
        super().__init__(driver)

    def get_complete_purchase_msg(self):
        return self.get_text(self.COMPLETE_MSG)

    def go_to_prod_list_page(self):
        self.click(self.BACK_HOME_BTN)