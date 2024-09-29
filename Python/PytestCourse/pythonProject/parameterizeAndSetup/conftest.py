import os
import pytest


##### test_fixtures03
def pytest_configure():
    pytest.file_name = "file1.txt"

@pytest.fixture()
def setup03():
    f = open(pytest.file_name, "w")
    f.write("Pytest is good")
    f.close()

    f = open(pytest.file_name, "r+")
    yield f
    print("\n Fixture setup03 is closing")
    f.close()
    os.remove(pytest.file_name)




##### test_fixtures04
@pytest.fixture()
def setup04(request):
    mon = getattr(request.module, "months")
    print("\n In fixture setup04")
    print(f"\n Fixture scope: {str(request.scope)}")
    print(f"\n Calling function: {str(request.function.__name__)}")
    print(f"\n Calling module: {str(request.module.__name__)}")
    mon.append("April")
    yield mon


@pytest.fixture()
def setup05():
    def getStructure(name):
        if name == "list":
            return [1, 2, 3]
        else:
            return (1, 2, 3)
    return getStructure




##### test_fixtures05
@pytest.fixture(params=[(3, 4), [3, 5]], ids = ["tuple", "list"])
def fixture01(request):
    return request.param


@pytest.fixture(params = ["Access", "Slice", "assign", "len"])
def fixture02(request):
    return request.param




