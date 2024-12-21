from selenium import webdriver
from jobs import Jobs


def main():
    driver = webdriver.Chrome()
    driver.maximize_window()

    jobs = Jobs(driver)

    jobs.printJobs()


if __name__ == "__main__":
    main()