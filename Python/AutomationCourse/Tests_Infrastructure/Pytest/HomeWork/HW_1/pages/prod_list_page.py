from selenium.webdriver.common.by import By
from Pytest.HomeWork.HW_1.pages.base_page import BasePage


class ProductList(BasePage):

    SAUCE_LABS_BACKPACK_BTN = (By.CSS_SELECTOR, "#item_4_title_link")
    SAUCE_LABS_BIKE_LIGHT_BTN = (By.CSS_SELECTOR, "#item_0_title_link")
    SAUCE_LABS_BOLT_TSHIRT_BTN = (By.CSS_SELECTOR, "#item_1_title_link")
    SAUCE_LABS_FLEECE_JACKET_BTN = (By.CSS_SELECTOR, "#item_5_title_link")
    SAUCE_LABS_ONESIE_BTN = (By.CSS_SELECTOR, "#item_2_title_link")
    SAUCE_LABS_TSHIRT_BTN = (By.CSS_SELECTOR, "#item_3_title_link")

    def __init__(self, driver):
        super().__init__(driver)

    def chooseProd(self, prod):
        match prod:
            case 1:
                self.click(self.SAUCE_LABS_BACKPACK_BTN)
            case 2:
                self.click(self.SAUCE_LABS_BIKE_LIGHT_BTN)
            case 3:
                self.click(self.SAUCE_LABS_BOLT_TSHIRT_BTN)
            case 4:
                self.click(self.SAUCE_LABS_FLEECE_JACKET_BTN)
            case 5:
                self.click(self.SAUCE_LABS_ONESIE_BTN)
            case 6:
                self.click(self.SAUCE_LABS_TSHIRT_BTN)
            case _:
                print(f"{prod} is invalid input")