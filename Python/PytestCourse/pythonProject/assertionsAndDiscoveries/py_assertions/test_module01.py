

def testA1():
    assert 4 < 5
    assert 4 != 5

def testA2():
    assert -1 # => True - this will pass (every number except 0)
    #assert 0 will fail (False)

def testA3():
    assert "Hello" == "Hello"

def testA4():
    assert 1 in divmod(9, 5)
    assert "py" in "This is pytest"
    assert "put" not in "This is pytest"

def testA5():
    assert 1