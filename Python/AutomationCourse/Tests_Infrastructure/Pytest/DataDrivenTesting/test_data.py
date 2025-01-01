import pytest
from selenium import webdriver
from selenium.webdriver.common.by import By
from utils.config_reader import ConfigReader

data_list = [(10, 10, 20), (15, -5, 10), (20, 20, 40)]

@pytest.mark.parametrize("a, b, c", data_list)
def test_sum(a, b, c):
    assert a + b == c



users_list = [("gal", "123456", "Login or password is incorrect"),
              ("gal", "111", "Login or password is incorrect"),
              ("admin", "", "Login or password is incorrect")]

@pytest.mark.parametrize("user, password, expected_error", users_list)
def test_login_failed(user, password, expected_error):
    # login (user, password)
    # get error message
    # assert error == expected_error
    print("")
    print(user, password, expected_error)



new_users_list = [("first_name1", "last_name1", "email1"),
                  ("first_name2", "last_name2", "email2"),
                  ("first_name3", "last_name3", "email3")]

@pytest.mark.parametrize("first_name, last_name, email", new_users_list)
def test_data(first_name, last_name, email):
    driver = webdriver.Chrome()
    driver.maximize_window()
    url = f"{ConfigReader.read_config('database', 'url')}"
    driver.get(url)

    driver.find_element(By.CSS_SELECTOR, "#firstname").send_keys(f"{ConfigReader.read_config('database', f'{first_name}')}")
    driver.find_element(By.CSS_SELECTOR, "#lastname").send_keys(f"{ConfigReader.read_config('database', f'{last_name}')}")
    driver.find_element(By.CSS_SELECTOR, "#email").send_keys(f"{ConfigReader.read_config('database', f'{email}')}")

    driver.find_element(By.CSS_SELECTOR, ".btn-next").click()

    expected_result = "What is your automation level? (checkboxes)"
    actual_result = driver.find_element(By.CSS_SELECTOR, "#account>h4").text

    driver.close()

    assert actual_result == expected_result, f"Actual result = '{actual_result}', expected = '{expected_result}'"






