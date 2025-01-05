import pytest
from pages.prod_page import ProductPage
from utils.config_reader import ConfigReader
from utils.general_helpers import GeneralHelp

class TestProductPage:

    product_list = ConfigReader.get_keys("products_list")

    @pytest.mark.parametrize("product", product_list)
    def test_add_to_cart(self, product):
        prod_list_page = GeneralHelp.login(self)
        product_num = int(ConfigReader.read_config("products_list", product))
        prod_list_page.go_to_prod_page(product_num)

        prod_page = ProductPage(self.driver)
        prod_page.add_item_to_cart()

        expected_result = 1
        actual_result = prod_page.get_amount_of_prod_in_cart()

        assert actual_result == expected_result, f"Actual result = '{actual_result}', expected = '{expected_result}'"