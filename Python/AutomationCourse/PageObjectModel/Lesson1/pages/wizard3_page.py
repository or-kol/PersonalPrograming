from tkinter import Scale

from selenium.webdriver.common.by import By
from Lesson1.pages.base_page import BasePage

class Wizard3(BasePage):

    STREET_NAME_FIELD = (By.CSS_SELECTOR, "#streetname")
    STREET_NUM_FIELD = (By.CSS_SELECTOR, "#streetnumber")
    CITY_FIELD = (By.CSS_SELECTOR, "#city")
    COUNTRY_FIELD = (By.CSS_SELECTOR, "#country")
    BACK_BTN = (By.CSS_SELECTOR, ".btn.btn-previous.btn-fill.btn-default.btn-wd.btn-sm")
    FINISH_BTN = (By.CSS_SELECTOR, "#finish")
    MSG_LABEL = (By.CSS_SELECTOR, ".cta-title")

    def __init__(self, driver):
        super().__init__(driver)

    def backPage(self):
        self.click(self.BACK_BTN)

    def fillInfo(self, street_name, street_num, city, country):
        self.fillText(self.STREET_NAME_FIELD, street_name)
        self.fillText(self.STREET_NUM_FIELD, street_num)
        self.fillText(self.CITY_FIELD, city)
        self.selectOption(self.COUNTRY_FIELD, country)
        self.click(self.FINISH_BTN)

    def getMsg(self):
        return self.getText(self.MSG_LABEL)


