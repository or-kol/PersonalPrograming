from selenium.webdriver.common.by import By
from PageObjectModel.HomeWork.HW_1.pages.base_page import BasePage

class Cart(BasePage):

    REMOVE_SAUCE_LABS_BACKPACK_BTN = (By.CSS_SELECTOR, "#remove-sauce-labs-backpack")
    REMOVE_SAUCE_LABS_BIKE_LIGHT_BTN = (By.CSS_SELECTOR, "#remove-sauce-labs-bike-light")
    REMOVE_SAUCE_LABS_BOLT_TSHIRT_BTN = (By.CSS_SELECTOR, "#remove-sauce-labs-bolt-t-shirt")
    REMOVE_SAUCE_LABS_FLEECE_JACKET_BTN = (By.CSS_SELECTOR, "#remove-sauce-labs-fleece-jacket")
    REMOVE_SAUCE_LABS_ONESIE_BTN = (By.CSS_SELECTOR, "#remove-sauce-labs-onesie")
    REMOVE_SAUCE_LABS_TSHIRT_BTN = (By.CSS_SELECTOR, "#remove-test.allthethings()-t-shirt-(red)")
    CONTINUE_SHOPPING_BTN = (By.CSS_SELECTOR, "#continue-shopping")
    CHECKOUT_BTN = (By.CSS_SELECTOR, "#checkout")

    def __init__(self, driver):
        super().__init__(driver)

    def removeItem(self, prod):
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

    def backToProdListPage(self):
        self.click(self.CONTINUE_SHOPPING_BTN)

    def checkout(self):
        self.click(self.CHECKOUT_BTN)
