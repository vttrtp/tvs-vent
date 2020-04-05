# coding: utf8
import os
import json
import sys
from argparse import ArgumentParser

parser = ArgumentParser()
parser.add_argument("file",
                    help="replace config", metavar="<replace config filename>")

def replace_by_dictionary(replace_strings,filename,new_file_name):
    file_str = open(filename, "r").read()
    for key, value in replace_strings.iteritems():
        file_str = file_str.replace(key,value)
    new_file = open(new_file_name,"w") 
    new_file.write(file_str.encode("UTF-8"))

def start_build(project_conf_file):
    file_str = open("config.json", "r").read().decode('utf-8')
    json_data = json.loads(file_str )
    project_folder  = os.path.join(os.path.dirname(os.path.abspath(__file__)),json_data["project_relative_folder"])
   
    project_data = json.loads(open(project_conf_file, "r").read())
    replace_name = project_data["replace_name"]
    replace_strings = project_data["replace_strings"]

    for file_data in json_data["files"]:
        file_name = os.path.join(project_folder, file_data["name"])
        new_file_name = file_name
        if file_data["usingReplace"]:
            new_file_name = file_name.replace(json_data["name_replace_value"],replace_name)
        replace_by_dictionary(replace_strings,file_name,new_file_name)


args = parser.parse_args()
if  args.file:
    start_build(args.file)