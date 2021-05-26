import os 
import sys

parent_dir = "./contests"
noOfFiles = int(sys.argv[2])
folder = sys.argv[1]
dir_list = os.listdir(parent_dir)

if folder in dir_list:
	print("Directory already exists.Please choose another name.")
	exit(0)

path = os.path.join(parent_dir, folder)
os.makedirs(path)
print("Following directory structure is created.")
print(folder)
for i in range(noOfFiles):
    file_path = path+"/"+chr(65+i)+".cpp"
    file = open(file_path,"w")
    with open("template.cpp","r") as temp:
        for line in temp:
            file.write(line)
    print("     ├──"+chr(65+i)+".cpp")

input_file = open(path+"/"+"input.in","w")
output_file = open(path+"/"+"output.in","w")
print("     ├──input.in")
print("     ├──output.in")
print(str(noOfFiles+2)+" files have created.")











