
import csv
import json

def main():
    
    #reading txt file
    txt_file_path = r"PythonCourse\PythonAdvanced\Leason2_writingFiles\test.txt"

    try:
        with open(txt_file_path, "r") as file:
            txt_read = file.read() # in the parentheses we can add an integer to indicate how many characters to read
            print(txt_read)
    except FileNotFoundError:
        print("file was not found")
    except PermissionError:
        print("You do not have permission to read that file")


    #reading json file
    json_file_path = r"PythonCourse\PythonAdvanced\Leason2_writingFiles\test.json"

    try:
        with open(json_file_path, "r") as file:
            json_read = json.load(file) # this creates a dictionary
            print(json_read)
    except FileNotFoundError:
        print("file was not found")
    except PermissionError:
        print("You do not have permission to read that file")


    #reading csv file
    csv_file_path = r"PythonCourse\PythonAdvanced\Leason2_writingFiles\test.csv"

    try:
        with open(csv_file_path, "r") as file:
            csv_read = csv.reader(file) # this gets an adress - we need for loop to print.
            for line in csv_read:
                print(line)
    except FileNotFoundError:
        print("file was not found")
    except PermissionError:
        print("You do not have permission to read that file")





if __name__ == "__main__":
    main()