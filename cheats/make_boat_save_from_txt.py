#! /bin/python3
# -*- coding: Utf-8 -*
##
## EPITECH PROJECT, 2019
## MUL_my_rpg_2019
## File description:
## make_boat_save_from_txt.py
##

import sys
import os
import argparse

def get_args():
    description = "This program is a hack to customize your boat for your save"
    parser = argparse.ArgumentParser(description=description)
    parser.add_argument("boat_file", type=str, help="The txt file")
    parser.add_argument("save_folder", type=str, help="The save folder which was stored the boat.sav file")
    return parser.parse_args()

def main():
    args = get_args()
    if not os.path.isfile(args.boat_file):
        print("The text file doesn't exists")
        return 84
    if not os.path.isdir(args.save_folder):
        print("The save folder doesn't exists")
        return 84
    with open(args.boat_file, "r") as boat_file:
        boat_file_content = boat_file.read()
    buffer = list()
    for line in boat_file_content.splitlines():
        line += "\n"
        buffer += [(ord(character) - ord('a')) for character in line]
    with open(os.path.join(args.save_folder, "boat.sav"), "wb") as boat_save:
        boat_save.write(len(buffer).to_bytes(4, "little"))
        for byte in buffer:
            boat_save.write(byte.to_bytes(1, "little", signed=True))
    return 0

sys.exit(main())
