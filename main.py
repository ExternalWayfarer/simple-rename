import os
import sys
import platform
import random
import time
from pathlib import Path

directory = "C:\\Users\\user\\Desktop\\renamer"
#my_dir = Path(directory)
#my_file = Path(directory, "file.txt")
#os.path.join(directory, filename)
#os.walk(directory)

list_dir = os.listdir(directory)
print(list_dir)
#print(os.name, platform.system())

#is_file = os.path.isfile("file.txt")
#is_dir = os.path.isdir(directory)
#os.path.exists(directory)
#print(is_file, is_dir, my_file.is_file(), my_dir.is_dir(), my_file.exists())



def rename():

    counter = 0 
    addition = 'joepeach'
    exclude_dir = 'venv'
    for root, dirs, files in os.walk(directory):            
        for file in files:
            if 'flex' in file and addition not in file and exclude_dir not in root:
                file_ext = Path(file).suffix
                if file_ext:
                    
                    filename = file.rsplit(file_ext, 1)[0]
                    os.rename(os.path.join(root, filename+file_ext), os.path.join(root, addition+filename+file_ext))
                    counter+=1
    print('Переименовано: ', str(counter))
#rename()

def get_time(file):
    ti_c = os.path.getctime(os.path.join(directory, file))
    ti_m = os.path.getmtime(os.path.join(directory, file))
    c_ti = time.ctime(ti_c)
    m_ti = time.ctime(ti_m)
    return c_ti, m_ti
file = 'file.txt'
#print(get_time(file))


def function(*args, **kwargs):
    