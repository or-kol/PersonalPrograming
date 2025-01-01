import pytest
from selenium.webdriver.common.by import By

@pytest.mark.usefixtures("handleAlerts")
class TestAlerts:

    def testAlert(self):
        self.driver.find_element(By.CSS_SELECTOR, "#content>div>ul>li:nth-child(1)>button").click()
        self.alert.accept()

        expected_result = "You successfully clicked an alert"
        actual_result = self.driver.find_element(By.CSS_SELECTOR, "#result").text

        assert actual_result == expected_result, f"Actual result = '{actual_result}', expected = '{expected_result}'"

    def testConfirmAccept(self):
        self.driver.find_element(By.CSS_SELECTOR, "#content>div>ul>li:nth-child(2)>button").click()
        self.alert.accept()

        expected_result = "You clicked: Ok"
        actual_result = self.driver.find_element(By.CSS_SELECTOR, "#result").text

        assert actual_result == expected_result, f"Actual result = '{actual_result}', expected = '{expected_result}'"

    def testConfirmCancel(self):
        self.driver.find_element(By.CSS_SELECTOR, "#content>div>ul>li:nth-child(2)>button").click()
        self.alert.dismiss()

        expected_result = "You clicked: Cancel"
        actual_result = self.driver.find_element(By.CSS_SELECTOR, "#result").text

        assert actual_result == expected_result, f"Actual result = '{actual_result}', expected = '{expected_result}'"

    def testPromptAlert(self):
        self.driver.find_element(By.CSS_SELECTOR, "#content>div>ul>li:nth-child(3)>button").click()
        self.alert.send_keys("Hi JS prompt")
        self.alert.accept()

        expected_result = "You entered: Hi JS prompt"
        actual_result = self.driver.find_element(By.CSS_SELECTOR, "#result").text

        assert actual_result == expected_result, f"Actual result = '{actual_result}', expected = '{expected_result}'"