import pytest
from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.alert import Alert

@pytest.fixture(scope="class", autouse=True)
def setup(request):
    global driver
    options = Options()
    options.add_experimental_option("detach", True)
    driver = webdriver.Chrome(options=options)
    request.cls.driver = driver
    driver.maximize_window()
    driver.get("https://the-internet.herokuapp.com/windows")

    yield
    driver.quit()

@pytest.fixture
def handleAlerts(request):
    alert = Alert(driver)
    request.cls.alert = alert

