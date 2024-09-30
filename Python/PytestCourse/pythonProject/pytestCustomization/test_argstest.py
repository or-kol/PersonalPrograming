

def test_argTest(cmdOpt):
    #print("Read config file: " + cmdOpt.readline())
    assert cmdOpt.readline().index("Lab")

'''
in cmd:
pytest -v -s test_argstest.py --cmdopt=prod     ==> will read from prod.prod.
pytest -v -s test_argstest.py                   ==> will read the default
'''