import pytest

months = ["Jan", "Feb", "Mar"]

def test_checkRequestFixture(setup04):
    print(setup04)
    assert "April" in setup04
    assert 4 == len(setup04)


def test_factFicture(setup05):
    assert type(setup05("list")) == list
    assert type(setup05("tuple")) == tuple