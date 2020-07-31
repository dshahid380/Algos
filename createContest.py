import os 
import sys

parent_dir = "./contests"
noOfFiles = int(sys.argv[2])

path = os.path.join(parent_dir, sys.argv[1])
os.makedirs(path)
print("Following directory structure is created.")
print(sys.argv[1])
for i in range(noOfFiles):
    file_path = path+"/"+chr(65+i)+".cpp"
    file = open(file_path,"w")
    with open("template.cpp","r") as temp:
        for line in temp:
            file.write(line)
    print("     ├──"+chr(65+i)+".cpp")

input_file = open("input.in","w")
output_file = open("output.in","w")
print("     ├──input.in")
print("     ├──output.in")
print(str(noOfFiles+2)+" files have created.")











