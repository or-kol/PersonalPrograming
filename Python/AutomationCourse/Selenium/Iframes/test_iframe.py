from time import sleep

from selenium.webdriver.common.by import By


class TestIframe:

    def testWriteToIframe(self):
        self.driver.switch_to.frame("mce_0_ifr")

        text_box = self.driver.find_element(By.CSS_SELECTOR, "#tinymce")
        text_box.clear()
        text_box.send_keys("Hello, this is a test message!")

        page_title = self.driver.title
        print(page_title)

        self.driver.switch_to.default_content()
        page_title = self.driver.title
        print(page_title)

    def test_iframe(self):
        self.driver.get("https://the-internet.herokuapp.com/nested_frames")

        self.driver.switch_to.frame("frame-top")

        self.driver.switch_to.frame("frame-left")

        current_frame = self.driver.execute_script("return self.name")
        print("Current frame is:", current_frame)

        self.driver.switch_to.parent_frame()

        current_frame = self.driver.execute_script("return self.name")
        print("Current frame is:", current_frame)