import pytest
from pages.cart_page import CartPage
from pages.checkout_page import CheckoutPage
from utils.config_reader import ConfigReader
from utils.general_helpers import GeneralHelp

class TestCartPage:

    product_list = ConfigReader.get_keys("products_list")

    @pytest.mark.parametrize("product", product_list)
    def test_correct_item_added_to_cart(self, product):
        prod_list_page = GeneralHelp.login(self)
        GeneralHelp.add_product_to_cart(self, prod_list_page, product)

        prod_list_page.go_to_cart()

        cart_page = CartPage(self.driver)
        cart_items_list = cart_page.get_cart_list()

        expected_result = product.replace("_position", "").replace("_", " ")
        actual_result = cart_items_list[0].text.lower()

        assert expected_result in actual_result, f"Actual result = '{actual_result}', expected = '{expected_result}'"


    @pytest.mark.parametrize("product", product_list)
    def test_remove_item_from_cart(self, product):
        prod_list_page = GeneralHelp.login(self)
        product_num = GeneralHelp.add_product_to_cart(self, prod_list_page, product)

        prod_list_page.go_to_cart()

        cart_page = CartPage(self.driver)

        expected_num_of_products_in_cart = 1
        actual_num_of_products_in_cart = int(cart_page.get_amount_of_prod_in_cart())

        if actual_num_of_products_in_cart == expected_num_of_products_in_cart:
            cart_page.remove_item_from_cart(product_num)

            expected_result = 0
            actual_result = 0 if cart_page.get_amount_of_prod_in_cart() == '' else int(
                cart_page.get_amount_of_prod_in_cart())

            assert actual_result == expected_result, f"Actual result = '{actual_result}', expected = '{expected_result}'"
        else:
            f"there are {actual_num_of_products_in_cart} in cart, expected {expected_num_of_products_in_cart}"


    def test_go_to_checkout_page(self):
        prod_list_page = GeneralHelp.login(self)
        prod_list_page.go_to_cart()

        cart_page = CartPage(self.driver)
        cart_page.go_to_checkout_page()

        checkout_page = CheckoutPage(self.driver)
        checkout_page.get_checkout_page_title()

        expected_result = "Checkout: Your Information"
        actual_result = checkout_page.get_checkout_page_title()

        assert expected_result in actual_result, f"Actual result = '{actual_result}', expected = '{expected_result}'"


    def test_go_to_prod_list_page(self):
        prod_list_page = GeneralHelp.login(self)
        prod_list_page.go_to_cart()

        cart_page = CartPage(self.driver)
        cart_page.go_back_to_prod_list_page()

        prod_list_page.get_prod_list_page_title()

        expected_result = "Products"
        actual_result = prod_list_page.get_prod_list_page_title()

        assert expected_result in actual_result, f"Actual result = '{actual_result}', expected = '{expected_result}'"