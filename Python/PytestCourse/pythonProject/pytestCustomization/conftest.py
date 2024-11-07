import os
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
        f = open(os.path.join(os.path.dirname(__file__), prod_config), 'r')
    else:
        f = open(os.path.join(os.path.dirname(__file__), qa_config), 'r')
    yield f
