from queue import PriorityQueue

from selenium.webdriver.chrome.webdriver import WebDriver
from selenium.webdriver.common.by import By
from PageObjectModel.pages.base_page import BasePage

class Wizard2(BasePage):

    BEGINNER_BTN = (By.CSS_SELECTOR, "#Beginner")
    INTERMEDIATE_BTN = (By.CSS_SELECTOR, "#Intermediate")
    ADVANCED_BTN = (By.CSS_SELECTOR, "#Advanced")
    PREVIOUS_BTN = (By.CSS_SELECTOR, ".btn.btn-previous.btn-fill.btn-default.btn-wd.btn-sm")
    NEXT_BTN = (By.CSS_SELECTOR, ".btn.btn-next.btn-fill.btn-warning.btn-wd.btn-sm")

    def __init__(self, driver):
        super().__init__(driver)

    def backPage(self):
        self.click(self.PREVIOUS_BTN)

    def selectLevel(self, level):
        match level:
            case "Beginner":
                self.click(self.BEGINNER_BTN)
            case "Intermediate":
                self.click(self.INTERMEDIATE_BTN)
            case "Advanced":
                self.click(self.ADVANCED_BTN)
            case _:
                print("Choose nothing")

        #next
        self.click(self.NEXT_BTN)

