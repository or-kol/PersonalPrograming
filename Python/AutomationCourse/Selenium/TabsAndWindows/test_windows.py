from time import sleep
from selenium.webdriver.common.by import By

class TestTabsAndWindows:

    def test_switch_tabs(self):
        original_window = self.driver.current_window_handle
        assert len(self.driver.window_handles) == 1
        self.driver.find_element(By.CSS_SELECTOR, "#content>div>a").click()
        sleep(2)

        for window_handle in self.driver.window_handles:
            if window_handle != original_window:
                self.driver.switch_to.window(window_handle)
                break

        expected_result = "New Window"
        actual_result = self.driver.title

        self.driver.switch_to.window(original_window)

        assert actual_result == expected_result, f"Actual result = '{actual_result}', expected = '{expected_result}'"

    def test_new_tab2(self):
        assert len(self.driver.window_handles) == 2
        self.driver.find_element(By.CSS_SELECTOR, "#content>div>a").click()
        sleep(2)

        self.driver.switch_to.window(self.driver.window_handles[1])

        expected_result = "New Window"
        actual_result = self.driver.title

        assert actual_result == expected_result, f"Actual result = '{actual_result}', expected = '{expected_result}'"

    def test_open_new_tabs_and_window(self):
        self.driver.switch_to.new_window("tab")
        assert len(self.driver.window_handles) == 2
        sleep(10)
        self.driver.switch_to.new_window("window")
        assert len(self.driver.window_handles) == 3
        sleep(10)