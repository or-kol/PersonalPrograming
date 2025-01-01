from time import sleep

from selenium.webdriver.common.by import By
from PageObjectModel.pages.base_page import BasePage

class AdvancedTask(BasePage):

    BACK_BTN = (By.CSS_SELECTOR, ".page-title.mtt-inadd>.mtt-back-button")
    PRIORITY_BTN = (By.CSS_SELECTOR, "[name='prio']")
    DUE_DATE_BTN = (By.CSS_SELECTOR, ".ui-datepicker-trigger")
    DUE_DATE_MONTH_LIST = (By.CSS_SELECTOR, ".ui-datepicker-month")
    DUE_DATE_YEAR_LIST = (By.CSS_SELECTOR, ".ui-datepicker-year")
    TASK_HEADLINE_FIELD = (By.CSS_SELECTOR, "#taskedit_form>div>div:nth-child(3)>input")
    TASK_NOTE_FIELD = (By.CSS_SELECTOR, "#taskedit_form>div>div:nth-child(4)>textarea")
    TASK_TAGS_FIELD = (By.CSS_SELECTOR, "#edittags")
    SAVE_TASK_BTN = (By.CSS_SELECTOR, ".form-row.form-bottom-buttons>button:nth-child(1)")
    CANCEL_TASK_BTN = (By.CSS_SELECTOR, ".form-row.form-bottom-buttons>button:nth-child(2)")
    SHOW_ALL_TAGS_BTN = (By.CSS_SELECTOR, "#alltags_show")
    HIDE_ALL_TAGS_BTN = (By.CSS_SELECTOR, "#alltags_hide")

    def __init__(self, driver):
        super().__init__(driver)

    def backToTasksPage(self):
        self.click(self.BACK_BTN)

    def fillAdvancedTask(self, headline, priority = 0, year: int = 0, month: int = 0, day: int = 0, note = "", tags = ""):
        self.fillText(self.TASK_HEADLINE_FIELD, headline)
        self.selectOption(self.PRIORITY_BTN, priority)

        try:
            self.click(self.DUE_DATE_BTN)
            self.selectOption(self.DUE_DATE_MONTH_LIST, month-1)
            self.selectOption(self.DUE_DATE_YEAR_LIST, year)
            self.click((By.CSS_SELECTOR, f"[data-date='{day}']"))
        except Exception as e:
            print(e)
        finally:
            self.fillText(self.TASK_NOTE_FIELD, note)
            self.fillText(self.TASK_TAGS_FIELD, tags)
            self.click(self.SAVE_TASK_BTN)

    def selectTagFromTagsList(self, tag):
        self.click(self.SHOW_ALL_TAGS_BTN)
        self.click((By.CSS_SELECTOR, f"#alltags>[data-tag='{tag}']"))
        self.click(self.HIDE_ALL_TAGS_BTN)

    def cancelTask(self):
        self.click(self.CANCEL_TASK_BTN)



