from time import sleep
from PageObjectModel.pages.wizard1_page import Wizard1

class TestLoginPage:

    def testNoEmailInput(self):
        global login_page
        login_page = Wizard1(self.driver)
        login_page.fillInfo("Orx", "Kol", "")
        sleep(1)
        actual = login_page.getEmailErrorMsg()
        expected = "This field is required."

        assert actual == expected, f"Actual result = '{actual}', expected = '{expected}'"

    def testInvalidEmailInput(self):
        login_page.fillInfo("Orx", "Kol", "orkol")
        sleep(1)
        actual = login_page.getEmailErrorMsg()
        expected = "Please enter a valid email address."

        assert actual == expected, f"Actual result = '{actual}', expected = '{expected}'"