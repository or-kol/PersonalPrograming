from pages.cart_page import CartPage
from pages.checkout_page import CheckoutPage
from pages.complete_purchase_page import CompletePurchasePage
from pages.overview_page import OverviewPage
from pages.prod_list_page import ProductsList
from utils.config_reader import ConfigReader
from utils.general_helpers import GeneralHelp


class TestCompletePurchasePage:

    def get_to_copmlete_purchase_page(self, product):
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

        overview_page = OverviewPage(self.driver)
        overview_page.complete_purchase()

        return CompletePurchasePage(self.driver)


    def test_back_home_btn(self):
        overview_page = self.get_to_copmlete_purchase_page("Sauce_Labs_Onesie_position")
        overview_page.go_to_prod_list_page()

        prod_list_page = ProductsList(self.driver)
        expected_result = "Products"
        actual_result = prod_list_page.get_prod_list_page_title()

        assert actual_result == expected_result, f"Actual result = '{actual_result}', expected = '{expected_result}'"