import allure
from selenium.webdriver.common.by import By
from pages.base_page import BasePage

class ProductPage(BasePage):

    ADD_TO_CART_BTN = (By.CSS_SELECTOR, "#add-to-cart")
    REMOVE_FROM_CART_BTN = (By.CSS_SELECTOR, "#remove")
    BACK_TO_PRODUCTS_LIST_PAGE_BTN = (By.CSS_SELECTOR, "#back-to-products")
    PRODUCTS_NAME = (By.CSS_SELECTOR, ".inventory_details_name")
    CART_BADGE = (By.CSS_SELECTOR, "#shopping_cart_container")

    def __init__(self, driver):
        super().__init__(driver)

    @allure.step("Add product to cart from product page")
    def add_item_to_cart(self):
        self.click(self.ADD_TO_CART_BTN)

    @allure.step("Remove product from cart from product page")
    def remove_item_from_cart(self):
        self.click(self.REMOVE_FROM_CART_BTN)

    @allure.step("Go to products list page")
    def back_to_prod_list_page(self):
        self.click(self.BACK_TO_PRODUCTS_LIST_PAGE_BTN)

    @allure.step("Get the name of the product in the page")
    def get_product_name(self):
        return self.get_text(self.PRODUCTS_NAME)

    @allure.step("Get amount of products in cart")
    def get_amount_of_prod_in_cart(self):
        return self.get_text(self.CART_BADGE)