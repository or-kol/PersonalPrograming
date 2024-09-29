

def testA1():
    print("This is my first test")
    assert 5 + 5 == 10
    assert 5 - 5 == 0
    assert 5 * 5 == 25
    assert 5 / 5 == 1

def testA2():
    assert 9 / 5 == 1, "Failed test intentionally"

def testA3():
    assert 9 // 5 == 1