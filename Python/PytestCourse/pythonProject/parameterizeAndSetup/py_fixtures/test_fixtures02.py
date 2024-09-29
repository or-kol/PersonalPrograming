import os
from os import remove

import pytest

weekdays1 = ["mon", "tue", "wed"]
weekdays2 = ["fri", "sat", "sun"]

@pytest.fixture()
def setup01():
    wk1 = weekdays1.copy()
    wk1.append("thur")
    yield wk1
    print()
    print(wk1)
    print("\n After yield in setup01 fixture \n")
    wk1.pop()
    print(wk1)

'''
*** yield allows us to return a value, but keep running the lines after it so we can close out session (DB connection for example) ***
'''

@pytest.fixture()
def setup02():
    wk2 = weekdays2.copy()
    wk2.insert(0, "thur")
    yield wk2
    print()
    print(wk2)
    print("\n After yield in setup02 fixture \n")
    wk2.remove("thur")
    print(wk2)


def test_extendList(setup01):
    all_week_days = setup01 + weekdays2
    assert all_week_days == ["mon", "tue", "wed", "thur", "fri", "sat", "sun"]


# Example of using more than one fixture in the same test.
def test_len(setup01, setup02):
    assert len(weekdays1 + setup02) == len(setup01 + weekdays2)
    assert weekdays1 + setup02 == setup01 + weekdays2




file_name = "file1.txt"

@pytest.fixture()
def setup03():
    f = open(file_name, "w")
    f.write("Pytest is good")
    f.close()

    f = open(file_name, "r+")
    yield f

    f.close()
    os.remove(file_name)


def test_fileTest(setup03):
    assert setup03.read() == "Pytest is good"


