from selenium.webdriver.common.by import By
from HomeWork.HW_1.pages.base_page import BasePage


class Product(BasePage):

    ADD_TO_CART_BTN = (By.CSS_SELECTOR, "#add-to-cart")
    BACK_TO_PRODUCTS_BTN = (By.CSS_SELECTOR, "#back-to-products")


    def __init__(self, driver):
        super().__init__(driver)

    def addToCart(self):
        self.click(self.ADD_TO_CART_BTN)

    def backToProdListPage(self):
        self.click(self.BACK_TO_PRODUCTS_BTN)