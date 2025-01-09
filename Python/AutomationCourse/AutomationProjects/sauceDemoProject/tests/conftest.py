import os
import platform
import allure
import pytest
from selenium import webdriver
from selenium.webdriver.common.alert import Alert
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





#allure-results_20250108_094538