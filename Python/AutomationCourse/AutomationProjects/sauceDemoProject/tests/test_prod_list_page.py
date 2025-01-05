import pytest
from pages.cart_page import CartPage
from pages.prod_page import ProductPage
from utils.config_reader import ConfigReader
from utils.general_helpers import GeneralHelp

class TestProductsList:
    
    product_list = ConfigReader.get_keys("products_list")

    @pytest.mark.parametrize("product", product_list)
    def test_go_to_product_page(self, product):
        prod_list_page = GeneralHelp.login(self)
        product_num = int(ConfigReader.read_config("products_list", product))
        prod_list_page.go_to_prod_page(product_num)

        prod_page = ProductPage(self.driver)
        expected_result = product.replace("_position", "").replace("_", " ")
        actual_result = prod_page.get_product_name().lower()

        assert expected_result in actual_result, f"Actual result = '{actual_result}', expected = '{expected_result}'"


    def test_go_to_cart_page(self):
        prod_list_page = GeneralHelp.login(self)
        prod_list_page.go_to_cart()

        cart_page = CartPage(self.driver)

        expected_result = "Your Cart"
        actual_result = cart_page.get_cart_page_title()
        assert expected_result in actual_result, f"Actual result = '{actual_result}', expected = '{expected_result}'"


    @pytest.mark.parametrize("product", product_list)
    def test_quick_add_to_cart(self, product):
        prod_list_page = GeneralHelp.login(self)
        product_num = int(ConfigReader.read_config("products_list", product))
        prod_list_page.quick_add_item_to_cart(product_num)

        expected_result = 1
        actual_result = int(prod_list_page.get_amount_of_prod_in_cart())

        assert actual_result == expected_result, f"Actual result = '{actual_result}', expected = '{expected_result}'"


    @pytest.mark.parametrize("product", product_list)
    def test_quick_remove_from_cart(self, product):
        prod_list_page = GeneralHelp.login(self)
        product_num = int(ConfigReader.read_config("products_list", product))
        prod_list_page.quick_add_item_to_cart(product_num)
        expected_num_of_products_in_cart = 1
        actual_num_of_products_in_cart = int(prod_list_page.get_amount_of_prod_in_cart())

        if actual_num_of_products_in_cart == expected_num_of_products_in_cart:
            prod_list_page.quick_remove_item_from_cart(product_num)

            expected_result = 0
            actual_result = 0 if prod_list_page.get_amount_of_prod_in_cart() == '' else int(prod_list_page.get_amount_of_prod_in_cart())

            assert actual_result == expected_result, f"Actual result = '{actual_result}', expected = '{expected_result}'"
        else:
            f"there are {actual_num_of_products_in_cart} in cart, expected {expected_num_of_products_in_cart}"


    sort_options = ConfigReader.get_values("product_sort_options")
    @pytest.mark.parametrize("sort", sort_options)
    def test_product_sort(self, sort):
        prod_list_page = GeneralHelp.login(self)
        prod_list_page.sort_products(sort)

        expected_products1_4_6 = []
        match sort:
            case "az":
                expected_products1_4_6 = [self.product_list[0].replace("_position", "").replace("_", " "),
                                          self.product_list[3].replace("_position", "").replace("_", " "),
                                          self.product_list[5].replace("_position", "").replace("_", " ")]
            case "za":
                expected_products1_4_6 = [self.product_list[5].replace("_position", "").replace("_", " "),
                                          self.product_list[2].replace("_position", "").replace("_", " "),
                                          self.product_list[0].replace("_position", "").replace("_", " ")]
            case "lohi":
                expected_products1_4_6 = [self.product_list[4].replace("_position", "").replace("_", " "),
                                          self.product_list[5].replace("_position", "").replace("_", " "),
                                          self.product_list[3].replace("_position", "").replace("_", " ")]
            case "hilo":
                expected_products1_4_6 = [self.product_list[3].replace("_position", "").replace("_", " "),
                                          self.product_list[5].replace("_position", "").replace("_", " "),
                                          self.product_list[4].replace("_position", "").replace("_", " ")]
            case _:
                print(f"{sort} is invalid sorting option")

        actual_products1_4_6 = [prod_list_page.get_nth_product_in_page(1).lower(),
                                prod_list_page.get_nth_product_in_page(4).lower(),
                                prod_list_page.get_nth_product_in_page(6).lower()]

        for idx in range(3):
            assert expected_products1_4_6[idx] in actual_products1_4_6[idx], \
                f"Actual result = '{actual_products1_4_6}', expected = '{expected_products1_4_6}'"
