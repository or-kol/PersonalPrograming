from utils.my_config_parser import *
from utils.ConfigFileParser import ConfigFileParser

config = ConfigFileParser('prod.ini')

def test_getGmailUrl():
    print(getGmailUrl())

def test_getOutlookUrl():
    print (config.getOutlookUrl())