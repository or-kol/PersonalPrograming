import pytest


@pytest.fixture()
def setup_list():
    print("\n In Fixtures \n")
    city = ["New York", "London", "Riadh", "Singapore", "Mombai"]
    return city


def test_getItem(setup_list):
    print(setup_list[1:3])
    assert setup_list[0] == "New York"
    assert setup_list[::2] == ["New York", "Riadh", "Mombai"]


def myReverse(lst):
    lst.reverse()
    return lst

def test_reverseList(setup_list):
    assert setup_list[::-2] == ["Mombai", "Riadh", "New York"]
    assert setup_list[::-1] == myReverse(setup_list)





@pytest.mark.usefixtures("setup_list")
def test_useFixturesDemo():
    assert 1 == 1
    assert setup_list[0] == "New York"

'''
*** In this scenario (calling the fixture from the decorator) we can't use the returned value from the function. ***
'''