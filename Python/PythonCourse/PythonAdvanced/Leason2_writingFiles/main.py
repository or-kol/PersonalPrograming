
import os
import json
import csv

def main():

    
    #file detection
    txt_file_path = r'PythonCourse\PythonAdvanced\Leason2_files\test.txt' #relative file path

    #print(os.path.exists(r'D:\PersonalPrograming\PythonCourse\PythonAdvanced\Leason2_files\test.txt')) #full path

    if os.path.exists(txt_file_path):
        print(f"the location '{txt_file_path}' exists")

        if os.path.isfile(txt_file_path):
            print("that is a file")
        elif os.path.isdir(txt_file_path):
            print("That is a directory")
    else:
        print("That location does not exist")
    

    ###################################################################################################

    #writing to files
    '''
    writing modes:
    x - will write only if the file does not exists
    w - will create a new file if it does not exist. if it does exist it will overide everithing in the file.
    a - append - will add to the existing file.
    '''

    '''
    ##### txt #####
    txt_data = "abc def ghij klmnop"
    
    with open(txt_file_path, "w") as file:
        file.write(txt_data)
        print("writing success")

    try:
        with open(txt_file_path, "x") as file:
            file.write(txt_data)
            print("writing success")
    except FileExistsError:
        print("This file already exists")

    with open(txt_file_path, "a") as file:
        file.write("\n" + txt_data)
        print("writing success")        

    '''
    
    '''
    ##### json #####

    json_file_path = r'PythonCourse\PythonAdvanced\Leason2_files\test.json'

    employee = {
        "name": "Or Kol",
        "Age": 36,
        "Job": "QA"
    }

    with open(json_file_path, "w") as file:
        json.dump(employee, file, indent=4)
        print("json writing success")  
    '''
    
    '''
    ##### csv #####

    csv_file_path = r'PythonCourse\PythonAdvanced\Leason2_files\test.csv'

    employees = [["name", "age", "Job"], 
                 ["Or Kol", 36, "QA"], 
                 ["james keen", 25, "Developer"], 
                 ["Sean Alexander", "30", "Team Lead"]]

    with open(csv_file_path, "w", newline="") as file:
        writer = csv.writer(file)
        for row in employees:
            writer.writerow(row)
        print("json writing success")  
    '''






if __name__ == "__main__":
    main()