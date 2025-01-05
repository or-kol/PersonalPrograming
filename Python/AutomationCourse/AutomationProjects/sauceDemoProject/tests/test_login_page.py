from pages.login_page import LoginPage
from pages.prod_list_page import ProductsList
from utils.config_reader import ConfigReader

class TestLoginPage:

    def test_valid_login(self):
        login_page = LoginPage(self.driver)
        user_name = ConfigReader.read_config("login_info", "valid_user_name")
        password = ConfigReader.read_config("login_info", "password")
        login_page.fill_info(user_name, password)

        prod_list_page = ProductsList(self.driver)
        expected_result = "Products"
        actual_result = prod_list_page.get_prod_list_page_title()

        assert actual_result == expected_result, f"Actual result = '{actual_result}', expected = '{expected_result}'"


    def test_locked_user_login(self):
        login_page = LoginPage(self.driver)
        user_name = ConfigReader.read_config("login_info", "locked_out_user_name")
        password = ConfigReader.read_config("login_info", "password")
        login_page.fill_info(user_name, password)

        expected_result = "Epic sadface: Sorry, this user has been locked out."
        actual_result = login_page.get_error_msg()

        assert actual_result == expected_result, f"Actual result = '{actual_result}', expected = '{expected_result}'"
