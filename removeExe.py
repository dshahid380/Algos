import os

path = "../Algos"
noOfFileDeleted = 0 

def deleteAllUnnecessaryFiles(path):
	'''
	Currently it will delete all .class, .exe files 
	and a file which do not have any extention.
	'''
	global noOfFileDeleted
	try:
		files = os.listdir(path)
		if len(files)==0:
			return
		else:
			for file in files:
				if file != '.git':
					deleteAllUnnecessaryFiles(path+"/"+file)
	except NotADirectoryError:
		file = path.split("/")[-1]
		if len(file.split('.'))==1:
			os.remove(path)
			noOfFileDeleted += 1
		length = len(file.split("."))
		if length == 2:
			if file.split(".")[1] == "class":
				os.remove(path)
				noOfFileDeleted += 1
			if file.split(".")[1]=="exe":
				os.remove(path)
				noOfFileDeleted += 1
		
deleteAllUnnecessaryFiles(path)
if noOfFileDeleted<=1:
	print(str(noOfFileDeleted)+" file has been removed.")
else:
	print(str(noOfFileDeleted)+" files have been removed.")


	