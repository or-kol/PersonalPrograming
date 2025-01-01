from selenium.webdriver.common.by import By
from Pytest.HomeWork.HW_2.pages.base_page import BasePage

class TasksPage(BasePage):

    TASK_FIELD = (By.CSS_SELECTOR, "#task")
    SEARCH_FIELD = (By.CSS_SELECTOR, "#search")
    AMOUNT_OF_TASKS_FIELD = (By.CSS_SELECTOR, "#total")
    SUBMIT_SIMPLE_TASK_BTN = (By.CSS_SELECTOR, "#newtask_submit")
    CREATE_ADVANCED_TASK_BTN = (By.CSS_SELECTOR, "#newtask_adv>span")
    ADD_LIST_BTN = (By.CSS_SELECTOR, ".mtt-tabs-new-button")
    NEW_LIST_NAME_FIELD = (By.CSS_SELECTOR, "#modalTextInput")
    SUBMIT_NEW_LIST_NAME_BTN = (By.CSS_SELECTOR, "#btnModalOk")
    DELETE_TASK_BTN = (By.CSS_SELECTOR, "#cmenu_delete")
    EDIT_TASK_BTN = (By.CSS_SELECTOR, "#cmenu_edit")
    ALL_TASKS_LIST_BTN = (By.CSS_SELECTOR, "[title='All tasks']")
    TASKS_LIST = (By.CSS_SELECTOR, "#tasklist>li")

    def __init__(self, driver):
        super().__init__(driver)

    def creatNewList(self, list_name):
        self.click(self.ADD_LIST_BTN)
        self.fillText(self.NEW_LIST_NAME_FIELD, list_name)
        self.click(self.SUBMIT_NEW_LIST_NAME_BTN)

    def searchTasks(self, task_name):
        self.fillText(self.SEARCH_FIELD, task_name)

    def searchTasksInList(self, task_name, list_name):
        self.click((By.CSS_SELECTOR, f"[title='{list_name}']"))
        self.searchTasks(task_name)

    def addSimpleTask(self, list_name, head_line):
        self.click((By.CSS_SELECTOR, f"[title='{list_name}']"))
        self.fillText(self.TASK_FIELD, head_line)
        self.click(self.SUBMIT_SIMPLE_TASK_BTN)

    def addAdvancedTask(self, list_name):
        self.click((By.CSS_SELECTOR, f"[title='{list_name}']"))
        self.click(self.CREATE_ADVANCED_TASK_BTN)

    def getAmountOfTasks(self):

        return self.getText(self.AMOUNT_OF_TASKS_FIELD)

    def moveToAllTasksList(self):
        self.click(self.ALL_TASKS_LIST_BTN)

    def getTsakList(self):
        return [task.text for task in self.getElementsList(self.TASKS_LIST)]

