import pytest


qa_config = "qa.prod"
prod_config = "prod.prod"


def pytest_addoption(parser):
    parser.addoption("--cmdopt", default = "QA")

@pytest.fixture()
def cmdOpt(pytestconfig):
    opt = pytestconfig.getoption("cmdopt")
    print("\n In cmpOpt fixture function")
    if opt == "prod":
        f = open(prod_config, 'r')
    else:
        f = open(qa_config, 'r')
    yield f
