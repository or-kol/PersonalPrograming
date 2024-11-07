import pytest
from utils.util import getData


@pytest.mark.parametrize("id, name, course, city", getData())
def test_checkDataFromFile(id, name, course, city):
    print(id)


