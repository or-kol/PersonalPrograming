import pytest


# writing the fixtures in conftest.py file will make them available for all tests in the folder and sub-folders
# Example:
def test_fileTest(setup03):
    assert setup03.read() == "Pytest is good"


# If there is a fixture with the same name in the test file and in the conftest file,
# the fixture in the test file will override the conftest file.

file_name = "file1.txt"
def test_fileTest2():
    with pytest.raises(FileNotFoundError):
        f = open(file_name, "r+")