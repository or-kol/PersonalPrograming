import logging
from selenium.webdriver.chrome.webdriver import WebDriver
from selenium.webdriver.support.select import Select
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.common.exceptions import TimeoutException, NoSuchElementException

# Setup logging
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')
logger = logging.getLogger(__name__)

class BasePage:

    TIMEOUT = 10

    def __init__(self, driver):
        self.driver: WebDriver = driver

    def fill_text(self, locator, text):
        try:
            logger.info(f"Filling text for element located by {locator}")
            self.highlight_element(locator, "yellow")
            element = self.driver.find_element(*locator)
            element.clear()
            element.send_keys(text)
        except NoSuchElementException as e:
            logger.error(f"Element not found: {locator}. Error: {e}")
            raise
        except Exception as e:
            logger.error(f"Failed to fill text for {locator}. Error: {e}")
            raise

    def click(self, locator):
        try:
            logger.info(f"Clicking on element located by {locator}")
            WebDriverWait(self.driver, self.TIMEOUT).until(EC.element_to_be_clickable(locator))
            self.highlight_element(locator, "yellow")
            self.driver.find_element(*locator).click()
        except TimeoutException as e:
            logger.error(f"Element not clickable within {self.TIMEOUT} seconds: {locator}. Error: {e}")
            raise
        except NoSuchElementException as e:
            logger.error(f"Element not found: {locator}. Error: {e}")
            raise
        except Exception as e:
            logger.error(f"Failed to click on element {locator}. Error: {e}")
            raise

    def get_text(self, locator):
        try:
            logger.info(f"Getting text from element located by {locator}")
            WebDriverWait(self.driver, self.TIMEOUT).until(EC.presence_of_element_located(locator))
            self.highlight_element(locator, "red")
            return self.driver.find_element(*locator).text
        except TimeoutException as e:
            logger.error(f"Element not found within {self.TIMEOUT} seconds: {locator}. Error: {e}")
            raise
        except NoSuchElementException as e:
            logger.error(f"Element not found: {locator}. Error: {e}")
            raise
        except Exception as e:
            logger.error(f"Failed to get text from {locator}. Error: {e}")
            raise

    def select_option(self, locator, option):
        try:
            logger.info(f"Selecting option '{option}' from dropdown located by {locator}")
            self.highlight_element(locator, "yellow")
            select = Select(self.driver.find_element(*locator))
            select.select_by_value(f"{option}")
        except NoSuchElementException as e:
            logger.error(f"Element not found: {locator}. Error: {e}")
            raise
        except Exception as e:
            logger.error(f"Failed to select option '{option}' from {locator}. Error: {e}")
            raise

    def get_elements_list(self, locator):
        try:
            logger.info(f"Getting list of elements located by {locator}")
            WebDriverWait(self.driver, self.TIMEOUT).until(EC.presence_of_all_elements_located(locator))
            return self.driver.find_elements(*locator)
        except TimeoutException as e:
            logger.error(f"Elements not found within {self.TIMEOUT} seconds: {locator}. Error: {e}")
            raise
        except Exception as e:
            logger.error(f"Failed to get elements list for {locator}. Error: {e}")
            raise

    def highlight_element(self, locator, color):
        try:
            logger.info(f"Highlighting element located by {locator} with color {color}")
            element = self.driver.find_element(*locator)
            original_style = element.get_attribute("style")
            new_style = f"background-color: {color}; {original_style}"

            self.driver.execute_script("arguments[0].setAttribute('style', arguments[1]);", element, new_style)
            self.driver.execute_script("setTimeout(function() {arguments[0].setAttribute('style', arguments[1]);}, 100);", element, original_style)
        except NoSuchElementException as e:
            logger.error(f"Element not found for highlighting: {locator}. Error: {e}")
            raise
        except Exception as e:
            logger.error(f"Failed to highlight element {locator}. Error: {e}")
            raise



'''from selenium.webdriver.chrome.webdriver import WebDriver
from selenium.webdriver.support.select import Select
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

class BasePage:

    TIMEOUT = 10

    def __init__(self, driver):
        self.driver: WebDriver = driver

    def fill_text(self, locator, text):
        self.highlight_element(locator, "yellow")
        self.driver.find_element(*locator).clear()
        self.driver.find_element(*locator).send_keys(text)

    def click(self, locator):
        WebDriverWait(self.driver, self.TIMEOUT).until(EC.element_to_be_clickable(locator))
        self.highlight_element(locator, "yellow")
        self.driver.find_element(*locator).click()

    def get_text(self, locator):
        WebDriverWait(self.driver, self.TIMEOUT).until(EC.presence_of_element_located(locator))
        self.highlight_element(locator, "red")
        return self.driver.find_element(*locator).text

    def select_option(self, locator, option):
        self.highlight_element(locator, "yellow")
        select = Select(self.driver.find_element(*locator))
        select.select_by_value(f"{option}")

    def get_elements_list(self, locator):
        WebDriverWait(self.driver, self.TIMEOUT).until(EC.presence_of_all_elements_located(locator))
        return self.driver.find_elements(*locator)

    def highlight_element(self, locator, color):
        element = self.driver.find_element(*locator)
        original_style = element.get_attribute("style")
        new_style = "background-color: " + color + ";" + original_style

        self.driver.execute_script("arguments[0].setAttribute('style', arguments[1]);", element, new_style)

        self.driver.execute_script("setTimeout(function() {arguments[0].setAttribute('style', arguments[1]);}, 100);"
                                   ,element, original_style)'''