from random import random
from pages.prod_page import ProductPage
from utils.config_reader import ConfigReader
from utils.general_helpers import GeneralHelp
import random

class TestProductPage:

    product_list = ConfigReader.get_values("products_list")

    def test_add_to_cart(self):
        prod_list_page = GeneralHelp.login(self)
        product_num = int(random.choice(self.product_list))
        prod_list_page.go_to_prod_page(product_num)

        prod_page = ProductPage(self.driver)
        prod_page.add_item_to_cart()

        expected_result = 1
        actual_result = int(prod_page.get_amount_of_prod_in_cart())

        assert actual_result == expected_result, f"Actual result = '{actual_result}', expected = '{expected_result}'"


    def test_remove_from_cart(self):
        prod_list_page = GeneralHelp.login(self)
        product_num = int(random.choice(self.product_list))
        prod_list_page.go_to_prod_page(product_num)

        prod_page = ProductPage(self.driver)
        prod_page.add_item_to_cart()

        if int(prod_page.get_amount_of_prod_in_cart()) == 1:
            prod_page.remove_item_from_cart()
        else:
            print(f"Item was not added to cart")

        expected_result = 0
        actual_result = 0 if prod_page.get_amount_of_prod_in_cart() == '' else int(prod_page.get_amount_of_prod_in_cart())

        assert actual_result == expected_result, f"Actual result = '{actual_result}', expected = '{expected_result}'"


    def test_back_to_products_btn(self):
        prod_list_page = GeneralHelp.login(self)
        product_num = int(random.choice(self.product_list))
        prod_list_page.go_to_prod_page(product_num)

        prod_page = ProductPage(self.driver)
        prod_page.back_to_prod_list_page()

        expected_result = "Products"
        actual_result = prod_list_page.get_prod_list_page_title()

        assert actual_result == expected_result, f"Actual result = '{actual_result}', expected = '{expected_result}'"