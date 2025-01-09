from pages.login_page import LoginPage
from pages.prod_list_page import ProductsList
from utils.config_reader import ConfigReader


class GeneralHelp():

    @staticmethod
    def login(self):
        login_page = LoginPage(self.driver)
        user_name = ConfigReader.read_config("login_info", "valid_user_name")
        password = ConfigReader.read_config("login_info", "valid_password")
        login_page.fill_info(user_name, password)
        return ProductsList(self.driver)


    @staticmethod
    def add_product_to_cart(self, prod_list_page, product):
        product_num = int(ConfigReader.read_config("products_list", product))
        prod_list_page.quick_add_item_to_cart(product_num)
        return product_num