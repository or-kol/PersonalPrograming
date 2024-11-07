import csv
from pathlib import Path

data_file = "data.csv"
cfg_file_directory = "config"

BASE_DIR = Path(__file__).resolve().parent.parent
DATA_FILE = BASE_DIR.joinpath(cfg_file_directory).joinpath(data_file)

def getData():
    with open(DATA_FILE, 'r') as f:
        reader = csv.reader(f)
        next(reader)
        data = [tuple(row) for row in reader]
    return data







