from time import sleep
from selenium.webdriver.common.by import By


class Jobs:
    def __init__(self, driver):
        self.driver = driver

    def printJobs(self):
        self.driver.get("http://www.wix.com/jobs/locations/tel-aviv")
        sleep(5)

        jobs_shown = ""
        all_jobs = self.driver.find_element(By.CSS_SELECTOR, ".rM7ckN.YJEKQk.comp-lr3n08cs1-container.comp-lr3n08cs1.wixui-box>#comp-lr3n08cy10").text

        while jobs_shown != all_jobs:
            self.driver.find_element(By.CSS_SELECTOR, "#comp-lr3n08d01").click()
            jobs_shown = self.driver.find_element(By.CSS_SELECTOR, ".rM7ckN.YJEKQk.comp-lr3n08cs1-container.comp-lr3n08cs1.wixui-box>#comp-lr3n08cv10").text

        jobs_list = self.driver.find_elements(By.CSS_SELECTOR, ".Mdue19.comp-lr3n08ai6.wixui-repeater>div>div")

        print("\n\n".join([job.text for job in jobs_list if "Engineer" in job.text]))

