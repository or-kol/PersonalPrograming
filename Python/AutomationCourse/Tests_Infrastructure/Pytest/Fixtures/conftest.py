import pytest
from selenium import webdriver
from selenium.webdriver.chrome.options import Options

@pytest.fixture(scope="class", autouse=True)
def setup(request):
    global driver
    options = Options()
    options.add_experimental_option("detach", True)
    driver = webdriver.Chrome(options=options)
    request.cls.driver = driver
    driver.maximize_window()
    driver.get("https://galmatalon.github.io/tutorials/indexID.html")
    yield
    driver.quit()

