import sys
import pytest

def test_strjoin():
    s1 = "python,Pytest and Automation"
    l1 = ["python,Pytest", "and", "Automation"]
    l2 = ["python", "Pytest and Automation"]
    assert ' '.join(l1) == s1


#example for xpass - which means we marked it as xfail, but test pass.
@pytest.mark.xfail
def test_str04():
    letters = "abcdefghijklmnopqrstuvwxyz"
    assert letters[10]

#example for xfail only for the error raised by the test - will be marked as xfail
@pytest.mark.xfail(raises = IndexError, reason = "Known issue")
def test_str041():
    letters = "abcdefghijklmnopqrstuvwxyz"
    assert letters[100]

#example for xfail defined for wrong type error - will be marked as fail
@pytest.mark.xfail(raises = TypeError, reason = "Known issue")
def test_str042():
    letters = "abcdefghijklmnopqrstuvwxyz"
    assert letters[100]


@pytest.mark.xfail(reason  = "Known issue")
def test_str05():
    letters = "abcd"
    num = 1234
    assert letters + num == "abcd1234"


#example for xfail for a certain platform - will marked as xfail for windows, fail for linux.
#@pytest.mark.xfail(sys.platform == "win32", reason  = "Works only in win32")
@pytest.mark.xfail(sys.platform == "Linux", reason  = "Works only in win32")
def test_str06():
    letters = "abcd"
    num = 1234
    assert letters + num == "abcd1234"









