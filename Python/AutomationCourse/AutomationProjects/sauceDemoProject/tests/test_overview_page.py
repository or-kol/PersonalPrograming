import pytest
from pages.cart_page import CartPage
from pages.checkout_page import CheckoutPage
from pages.complete_purchase_page import CompletePurchasePage
from pages.overview_page import OverviewPage
from pages.prod_list_page import ProductsList
from utils.config_reader import ConfigReader
from utils.general_helpers import GeneralHelp


class TestOverviewPage:

    product_list = ConfigReader.get_keys("products_list")

    def get_to_overview_page(self, product):
        first_name = ConfigReader.read_config("checkout_data", "first_name5")
        last_name = ConfigReader.read_config("checkout_data", "last_name5")
        zip = ConfigReader.read_config("checkout_data", "zip5")

        prod_list_page = GeneralHelp.login(self)
        GeneralHelp.add_product_to_cart(self, prod_list_page, product)
        prod_list_page.go_to_cart()

        cart_page = CartPage(self.driver)
        cart_page.go_to_checkout_page()

        checkout_page = CheckoutPage(self.driver)
        checkout_page.fill_info(first_name, last_name, zip)

        return OverviewPage(self.driver)


    def test_verify_payment_info(self):
        payment_info = ConfigReader.read_config("overview_page_data", "payment_info")
        overview_page = self.get_to_overview_page("Sauce_Labs_Onesie_position")

        expected_result = payment_info
        actual_result = overview_page.get_payment_info()

        assert actual_result == expected_result, f"Actual result = '{actual_result}', expected = '{expected_result}'"


    def test_verify_shipping_info(self):
        shipping_info = ConfigReader.read_config("overview_page_data", "shipping_info")
        overview_page = self.get_to_overview_page("Sauce_Labs_Onesie_position")

        expected_result = shipping_info
        actual_result = overview_page.get_shipping_info()

        assert actual_result == expected_result, f"Actual result = '{actual_result}', expected = '{expected_result}'"


    @pytest.mark.parametrize("product", product_list)
    def test_verify_net_price_info(self, product):
        item_net_price = ConfigReader.read_config("overview_page_data", product.replace("_position", "_price"))

        overview_page = self.get_to_overview_page(product)

        expected_result = f"Item total: ${item_net_price}"
        actual_result = overview_page.get_net_price()

        assert actual_result == expected_result, f"Actual result = '{actual_result}', expected = '{expected_result}'"


    @pytest.mark.parametrize("product", product_list)
    def test_verify_tax_info(self, product):
        item_net_price = float(ConfigReader.read_config("overview_page_data", product.replace("_position", "_price")))
        item_tax = round(item_net_price * 0.08, 2)

        overview_page = self.get_to_overview_page(product)

        expected_result = f"Tax: ${item_tax:.2f}"
        actual_result = overview_page.get_tax()

        assert actual_result == expected_result, f"Actual result = '{actual_result}', expected = '{expected_result}'"


    @pytest.mark.parametrize("product", product_list)
    def test_verify_total_price_info(self, product):
        item_net_price = float(ConfigReader.read_config("overview_page_data", product.replace("_position", "_price")))
        total_item_price = round(item_net_price * 1.08, 2)

        overview_page = self.get_to_overview_page(product)

        expected_result = f"Total: ${total_item_price:.2f}"
        actual_result = overview_page.get_total_price()

        assert actual_result == expected_result, f"Actual result = '{actual_result}', expected = '{expected_result}'"


    def test_cencel_btn(self):
        overview_page = self.get_to_overview_page("Sauce_Labs_Onesie_position")
        overview_page.go_back_to_prod_list_page()

        prod_list_page = ProductsList(self.driver)

        expected_result = "Products"
        actual_result = prod_list_page.get_prod_list_page_title()

        assert actual_result == expected_result, f"Actual result = '{actual_result}', expected = '{expected_result}'"


    def test_finish_btn(self):
        overview_page = self.get_to_overview_page("Sauce_Labs_Onesie_position")
        overview_page.complete_purchase()

        complete_purchase_page = CompletePurchasePage(self.driver)

        expected_result = "Thank you for your order!"
        actual_result = complete_purchase_page.get_complete_purchase_msg()

        assert actual_result == expected_result, f"Actual result = '{actual_result}', expected = '{expected_result}'"