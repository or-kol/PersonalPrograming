import allure
from selenium.webdriver.common.by import By
from pages.base_page import BasePage


class CartPage(BasePage):

    REMOVE_SAUCE_LABS_BACKPACK_BTN = (By.CSS_SELECTOR, "#remove-sauce-labs-backpack")
    REMOVE_SAUCE_LABS_BIKE_LIGHT_BTN = (By.CSS_SELECTOR, "#remove-sauce-labs-bike-light")
    REMOVE_SAUCE_LABS_BOLT_TSHIRT_BTN = (By.CSS_SELECTOR, "#remove-sauce-labs-bolt-t-shirt")
    REMOVE_SAUCE_LABS_FLEECE_JACKET_BTN = (By.CSS_SELECTOR, "#remove-sauce-labs-fleece-jacket")
    REMOVE_SAUCE_LABS_ONESIE_BTN = (By.CSS_SELECTOR, "#remove-sauce-labs-onesie")
    REMOVE_SAUCE_LABS_TSHIRT_BTN = (By.CSS_SELECTOR, "[id^='remove-test']")
    CONTINUE_SHOPPING_BTN = (By.CSS_SELECTOR, "#continue-shopping")
    CHECKOUT_BTN = (By.CSS_SELECTOR, "#checkout")
    CART_LIST = (By.CSS_SELECTOR, ".cart_list>[data-test='inventory-item']")
    CART_BADGE = (By.CSS_SELECTOR, "#shopping_cart_container")
    CART_PAGE_TITLE = (By.CSS_SELECTOR, ".title")

    def __init__(self, driver):
        super().__init__(driver)

    @allure.step("Remove product (product number in DB is : {prod})")
    def remove_item_from_cart(self, prod):
        match prod:
            case 1:
                self.click(self.REMOVE_SAUCE_LABS_BACKPACK_BTN)
            case 2:
                self.click(self.REMOVE_SAUCE_LABS_BIKE_LIGHT_BTN)
            case 3:
                self.click(self.REMOVE_SAUCE_LABS_BOLT_TSHIRT_BTN)
            case 4:
                self.click(self.REMOVE_SAUCE_LABS_FLEECE_JACKET_BTN)
            case 5:
                self.click(self.REMOVE_SAUCE_LABS_ONESIE_BTN)
            case 6:
                self.click(self.REMOVE_SAUCE_LABS_TSHIRT_BTN)
            case _:
                print(f"{prod} is invalid input")

    @allure.step("Go to products list page")
    def go_back_to_prod_list_page(self):
        self.click(self.CONTINUE_SHOPPING_BTN)

    @allure.step("Go to checkout page")
    def go_to_checkout_page(self):
        self.click(self.CHECKOUT_BTN)

    @allure.step("Get items list from cart")
    def get_cart_list(self):
        return self.get_elements_list(self.CART_LIST)

    @allure.step("Get amount of items in cart")
    def get_amount_of_prod_in_cart(self):
        return self.get_text(self.CART_BADGE)

    @allure.step("Get cart page title")
    def get_cart_page_title(self):
        return self.get_text(self.CART_PAGE_TITLE)