import math
import pytest

test_input1 = [82, 78, 45, 66]
@pytest.mark.parametrize("test_input", test_input1)
def test_param01(test_input):
    assert test_input > 50


test_input2 = [(2, 4), (3, 27), (4, 256)]
@pytest.mark.parametrize("input, output", test_input2)
def test_param02(input, output):
    assert math.pow(input, input) == output


data = [
    ([2, 3, 4], "sum", 9),
    ([2, 3, 4], "prod", 24)
]
@pytest.mark.parametrize("a, b, c", data)
def test_param03(a, b, c):
    if "sum" == b:
        assert sum(a) == c
    elif b == "prod":
        assert math.prod(a) == c















