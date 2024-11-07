

class TestMyStuffSuite():
    def testType(self):
        assert type(1) == int

    def testStr(self):
        assert str.upper('python') == 'PYTHON'
        assert 'pytest'.capitalize() == 'Pytest'