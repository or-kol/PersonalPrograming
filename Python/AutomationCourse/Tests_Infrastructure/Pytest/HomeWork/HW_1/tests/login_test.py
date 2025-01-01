from Pytest.HomeWork.HW_1.pages.login_page import Login

class TestLoginPage():

    def testValidLogin(self):
        login_page = Login(self.driver)
        login_page.fillInfo("standard_user", "secret_sauce")
        expected = "Swag Labs"
        actual = login_page.getPageTitle()

        assert actual == expected, f"Actual result = '{actual}', expected = '{expected}'"

    def testLockedOutUserLogin(self):
        login_page = Login(self.driver)
        login_page.fillInfo("locked_out_user", "secret_sauce")
        expected = "Epic sadface: Sorry, this user has been locked out."
        actual = login_page.getErrorMsg()

        assert actual == expected, f"Actual result = '{actual}', expected = '{expected}'"