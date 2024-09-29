import sys
import pytest

#pytestmark = pytest.mark.skipif(sys.platform == "win32", reason = "Will run on Linux only")
pytestmark = pytest.mark.skipif(sys.platform != "win32", reason = "Will run on Windows only")

print(sys.version_info)

const = 9 / 5

def centToFah(cent = 0):
    fah = (cent * const) + 32
    return fah

@pytest.mark.skip(reason = "Skipping for no reason")
def testCase01():
    assert type(const) == float

@pytest.mark.skipif(sys.version_info > (3, 13), reason = "Does not work on py version above 3.12")
def testCase02():
    assert centToFah() == 32

@pytest.mark.skipif(centToFah() == 32, reason= "Skipping default value test")
def testCase03():
    assert centToFah(38) == 100.4