from selenium import webdriver
from HomeWork.HW_1.pages.cart_page import Cart
from HomeWork.HW_1.pages.checkout_page import Checkout
from HomeWork.HW_1.pages.complete_purchase_page import CompletePurchase
from HomeWork.HW_1.pages.login_page import Login
from HomeWork.HW_1.pages.overview_page import Overview
from HomeWork.HW_1.pages.prod_list_page import ProductList
from HomeWork.HW_1.pages.prod_page import Product

driver = webdriver.Chrome()
driver.maximize_window()
driver.get("https://www.saucedemo.com/")


login_page = Login(driver)

login_page.fillInfo("standard_user", "secret_sauce")

prod_list_page = ProductList(driver)
prod_list_page.chooseProd(3)

prod_page = Product(driver)
prod_page.addToCart()
prod_page.backToProdListPage()

prod_list_page.chooseProd(5)

prod_page.addToCart()
prod_page.backToProdListPage()

prod_list_page.goToCart()

cart_page = Cart(driver)
cart_page.backToProdListPage()

prod_list_page.chooseProd(2)

prod_page.addToCart()
prod_page.goToCart()

cart_page.removeItem(5)
cart_page.checkout()

checkout_page = Checkout(driver)
checkout_page.fillInfo("Jhon", "Doe", 12345)

overview_page = Overview(driver)
overview_page.completePurchase()

complete_page = CompletePurchase(driver)
print(complete_page.getMsg())
complete_page.backHome()

prod_list_page.logout()


input("Enter to close")