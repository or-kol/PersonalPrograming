from selenium.webdriver.common.by import By
from pages.base_page import BasePage

class OverviewPage(BasePage):

    FINISH_BTN = (By.CSS_SELECTOR, "#finish")
    CANCEL_BTN = (By.CSS_SELECTOR, "#cancel")
    OVERVIEW_PAGE_TITLE = (By.CSS_SELECTOR, ".title")
    PAYMENT_INFO = (By.CSS_SELECTOR, "[data-test='payment-info-value']")
    SHIPPING_INFO = (By.CSS_SELECTOR, "[data-test='shipping-info-value']")
    ITEM_PRICE_INFO = (By.CSS_SELECTOR, ".summary_subtotal_label")
    TAX_INFO = (By.CSS_SELECTOR, ".summary_tax_label")
    TOTAL_PRICE_INFO = (By.CSS_SELECTOR, ".summary_total_label")

    def __init__(self, driver):
        super().__init__(driver)

    def get_overview_page_title(self):
        return self.get_text(self.OVERVIEW_PAGE_TITLE)

    def complete_purchase(self):
        self.click(self.FINISH_BTN)

    def go_back_to_prod_list_page(self):
        self.click(self.CANCEL_BTN)

    def get_payment_info(self):
        return self.get_text(self.PAYMENT_INFO)

    def get_shipping_info(self):
        return self.get_text(self.SHIPPING_INFO)

    def get_net_price(self):
        return self.get_text(self.ITEM_PRICE_INFO)

    def get_tax(self):
        return self.get_text(self.TAX_INFO)

    def get_total_price(self):
        return self.get_text(self.TOTAL_PRICE_INFO)