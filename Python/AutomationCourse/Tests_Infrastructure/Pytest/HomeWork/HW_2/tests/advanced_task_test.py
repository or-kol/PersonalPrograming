from time import sleep

from Pytest.HomeWork.HW_2.pages.advanced_task_page import AdvancedTask
from Pytest.HomeWork.HW_2.pages.tasks_page import TasksPage

class TestAdvancedTask:

    def testCreateAdvancedTaskCompleteInfo(self):
        task_page = TasksPage(self.driver)
        task_page.searchTasks("This is my first task")
        expected = int(task_page.getAmountOfTasks()) + 1

        task_page.addAdvancedTask("Todo")

        advanced_task_page = AdvancedTask(self.driver)

        advanced_task_page.fillAdvancedTask("This is my first task", 1, 2024, 12, 30, "Here you can write your note", "automation")

        task_page.moveToAllTasksList()
        task_page.searchTasks("This is my first task")
        actual = int(task_page.getAmountOfTasks())

        assert actual == expected, f"Actual result = '{actual}', expected = '{expected}'"

    def testCreateAdvancedTaskHeadlineOnly(self):
        task_page = TasksPage(self.driver)
        task_page.searchTasks("This is my second task")
        expected = int(task_page.getAmountOfTasks()) + 1

        task_page.addAdvancedTask("Todo")

        advanced_task_page = AdvancedTask(self.driver)
        advanced_task_page.fillAdvancedTask("This is my second task")

        task_page.moveToAllTasksList()
        task_page.searchTasks("This is my second task")
        actual = int(task_page.getAmountOfTasks())

        assert actual == expected, f"Actual result = '{actual}', expected = '{expected}'"
