from time import sleep

from Pytest.HomeWork.HW_2.pages.tasks_page import TasksPage

class TestTasksPage:

    def testCreatesimpleTask(self):
        global tasks_page
        tasks_page = TasksPage(self.driver)

        tasks_page.searchTasks("New Task")
        expected = int(tasks_page.getAmountOfTasks()) + 1

        tasks_page.addSimpleTask("Todo", "New Task")

        tasks_page.moveToAllTasksList()
        tasks_page.searchTasks("New Task")
        actual = int(tasks_page.getAmountOfTasks())

        assert actual == expected, f"Actual result = '{actual}', expected = '{expected}'"

    def testCreatNewListAndAddTwoTasks(self):
        tasks_page.creatNewList("New Tasks List")

        tasks_page.addSimpleTask("New Tasks List", "New Task1")
        tasks_page.addSimpleTask("New Tasks List", "New Task2")

        expected = 2
        actual = int(tasks_page.getAmountOfTasks())

        assert actual == expected, f"Actual result = '{actual}', expected = '{expected}'"

    def testTaskSearch(self):
        tasks_page.moveToAllTasksList()
        tasks_page.searchTasks("task")
        task_elements = tasks_page.getTsakList()

        for task in task_elements:
            assert "task" in task.lower(), f"'Task' does not exist in '{task}'"



