import pytest


def test_fixParam01(fixture01):
    print(type(fixture01))
    assert type(fixture01) in [tuple, list]


#assignment will fail for tuple - as tuple does not support assignment.
def test_fixParam02(fixture01, fixture02):
    if fixture02 == "Access":
        print(fixture01[0])
        assert fixture01[0] == 3
    elif fixture02 == "Slice":
        print(fixture01[::-1])
        assert fixture01[::-1] in [(4, 3), [5, 3]]
    elif fixture02 == "assign":
        fixture01[0] = 99
        print(fixture01[0])
        assert fixture01[0] == 99
    elif fixture02 == "len":
        print(len(fixture01))
        assert len(fixture01) == 2


