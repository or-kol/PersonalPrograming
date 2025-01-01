from selenium.webdriver.common.by import By
from PageObjectModel.pages.base_page import BasePage


class Wizard1(BasePage):

    FIRST_NAME_FIELD = (By.CSS_SELECTOR, "#firstname")
    LAST_NAME_FIELD = (By.CSS_SELECTOR, "#lastname")
    EMAIL_ERROR = (By.CSS_SELECTOR, "#email-error")
    EMAIL_FIELD = (By.CSS_SELECTOR, "#email")
    NEXT_BTN = (By.CSS_SELECTOR, ".btn.btn-next.btn-fill.btn-warning.btn-wd.btn-sm")

    def __init__(self, driver):
        super().__init__(driver)

    def fillInfo(self, first_name, last_name, email):
        self.fillText(self.FIRST_NAME_FIELD, first_name)
        self.fillText(self.LAST_NAME_FIELD, last_name)
        self.fillText(self.EMAIL_FIELD, email)
        self.click(self.NEXT_BTN)

    def nextPage(self):
        self.click(self.NEXT_BTN)

    def getEmailErrorMsg(self):
        return self.getText(self.EMAIL_ERROR)

