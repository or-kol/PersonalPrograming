from selenium import webdriver
from HomeWork.HW_1.pages.login_page import Login
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


input("Enter to close")