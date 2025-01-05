import pytest
from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.alert import Alert
from utils.config_reader import ConfigReader


@pytest.fixture(scope="function", autouse=True)
def setup(request):
    global driver
    options = Options()
    options.add_experimental_option("detach", True)
    driver = webdriver.Chrome(options=options)
    request.cls.driver = driver
    driver.maximize_window()
    url = ConfigReader.read_config("url_info", "url")
    driver.get(url)
    yield
    driver.quit()

@pytest.fixture
def handleAlerts(request):
    alert = Alert(driver)
    request.cls.alert = alert