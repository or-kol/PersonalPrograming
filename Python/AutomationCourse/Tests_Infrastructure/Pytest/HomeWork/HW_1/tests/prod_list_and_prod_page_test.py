from Pytest.HomeWork.HW_1.pages.cart_page import Cart
from Pytest.HomeWork.HW_1.pages.checkout_page import Checkout
from Pytest.HomeWork.HW_1.pages.complete_purchase_page import CompletePurchase
from Pytest.HomeWork.HW_1.pages.login_page import Login
from Pytest.HomeWork.HW_1.pages.overview_page import Overview
from Pytest.HomeWork.HW_1.pages.prod_list_page import ProductList
from Pytest.HomeWork.HW_1.pages.prod_page import Product

class TestProductPurchase():

    def testTwoProductsPurchase(self):
        login_page = Login(self.driver)
        login_page.fillInfo("standard_user", "secret_sauce")

        prod_list_page = ProductList(self.driver)
        prod_list_page.chooseProd(3)

        prod_page = Product(self.driver)
        prod_page.addToCart()
        prod_page.backToProdListPage()

        prod_list_page.chooseProd(5)

        prod_page.addToCart()
        prod_page.backToProdListPage()

        prod_list_page.goToCart()

        cart_page = Cart(self.driver)
        cart_page.checkout()

        checkout_page = Checkout(self.driver)
        checkout_page.fillInfo("Jhon", "Doe", "555")

        overview_page = Overview(self.driver)
        overview_page.completePurchase()

        complete_page = CompletePurchase(self.driver)
        expected = "Thank you for your order!"
        actual = complete_page.getMsg()

        assert actual == expected, f"Actual result = '{actual}', expected = '{expected}'"