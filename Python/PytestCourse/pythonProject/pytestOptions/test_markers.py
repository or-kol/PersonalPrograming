import pytest

pytestmark = [pytest.mark.smoke, pytest.mark.strtest]

@pytest.mark.sanity
def test_str01():
    num = 9 / 4
    s1 = "I like " + "pytest automation"
    assert str(num) == "2.25"
    assert s1 == "I like pytest automation"
    assert s1 + str(num) == "I like pytest automation2.25"

@pytest.mark.sanity
def test_str02():
    letters = "abcdefghijklmnopqrstuvwxyz"
    assert len(letters) == 26


def test_str03():
    letters = "abcdefghijklmnopqrstuvwxyz"
    assert letters[0] == 'a'
    assert letters[-1] == 'z' == letters[25]

@pytest.mark.sanity
@pytest.mark.str
def test_str04():
    letters = "abcdefghijklmnopqrstuvwxyz"
    assert letters[:] == letters
    assert letters[10:] == "klmnopqrstuvwxyz"
    assert letters[-3:] == "xyz"
    assert letters[:25:5] == "afkpu"

@pytest.mark.str
def test_strsplit():
    s1 = "pytest,python and automation"
    assert s1.split() == ["pytest,python", "and", "automation"]
    assert s1.split(',') == ["pytest", "python and automation"]


'''
To work with markers we should run from command line:
pytest pytestOptions\test_markers.py -v -m "sanity"              - will trigger all tests marked as sanity
pytest pytestOptions\test_markers.py -v -m "sanity and not str"  - will trigger all tests marked as sanity unless they are also marked as str
pytest pytestOptions\test_markers.py -v -m "sanity and str"      - will trigger only tests that have both markers (sanity and str)
pytest pytestOptions\test_markers.py -v -m "sanity or str"       - will trigger tests that have one of the markers or both (sanity and str)
'''



