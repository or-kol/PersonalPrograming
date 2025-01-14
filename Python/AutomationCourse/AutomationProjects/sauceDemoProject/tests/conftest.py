import os
import platform
import allure
import pytest
from selenium import webdriver
from selenium.webdriver.common.alert import Alert
from pages.login_page import LoginPage
from pages.prod_list_page import ProductsList
from utils.config_reader import ConfigReader

@pytest.fixture(scope="function", autouse=True)
def setup(request):
    global driver
    driver = webdriver.Chrome()
    request.cls.driver = driver
    driver.maximize_window()
    url = ConfigReader.read_config("url_info", "url")
    driver.get(url)
    yield
    driver.quit()

@pytest.fixture(scope="function")
def login_fix():
    login_page = LoginPage(driver)
    user_name = ConfigReader.read_config("login_info", "valid_user_name")
    password = ConfigReader.read_config("login_info", "valid_password")
    login_page.fill_info(user_name, password)
    return ProductsList(driver)

@pytest.fixture(scope="function")
def add_product_to_cart_fix():
    def inner(prod_list_page, product):
        product_num = int(ConfigReader.read_config("products_list", product))
        prod_list_page.quick_add_item_to_cart(product_num)
        return product_num
    return inner

@pytest.fixture
def handle_alerts(request):
    alert = Alert(driver)
    request.cls.alert = alert

def pytest_exception_interact(report):
    if report.failed:
        allure.attach(body=driver.get_screenshot_as_png(), name="screenshot",
                      attachment_type=allure.attachment_type.PNG)

def pytest_sessionfinish() -> None:
    environment_properties = {
        'browser': driver.name,
        'driver_version': driver.capabilities['browserVersion'],
        'os': platform.system(),
        'os_version': platform.version(),
        'python_version': platform.python_version(),
        'selenium_version': webdriver.__version__
    }

    allure_env_path = os.path.join("allure-results", 'environment.properties')

    with open(allure_env_path, 'w') as f:
        data = '\n'.join([f'{variable}={value}' for variable, value in environment_properties.items()])
        f.write(data)
