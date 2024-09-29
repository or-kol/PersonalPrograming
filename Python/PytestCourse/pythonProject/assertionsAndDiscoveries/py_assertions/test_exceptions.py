import pytest


def testCase01():
    with pytest.raises(ZeroDivisionError):
        assert 1 / 0

def testCase02():
    with pytest.raises(AssertionError):
        assert 3 > 3

def testCase03():
    with pytest.raises(Exception) as excptinfo:
        assert (1,2,3) == (1,2,4)
    print(excptinfo)

def func1():
    raise ValueError("Exception func1 raised")

def testCase04():
    with pytest.raises(Exception) as excptinfo:
        func1()
    assert str(excptinfo.value) == "Exception func1 raised"


