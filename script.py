import os

path = "../Algos"

def checkAllUnnecessaryFiles(path):
	'''
	Currently it will delete all .class, .exe files 
	and a file which do not have any extention.
	'''
	try:
		files = os.listdir(path)
		if len(files)==0:
			return
		else:
			for file in files:
				if file != '.git':
					checkAllUnnecessaryFiles(path+"/"+file)
	except NotADirectoryError:
		file = path.split("/")[-1]
		if len(file.split('.'))==1:
			raise Exception("The following \n"+path+"\n contain junk file. Please run removeExe.py before commiting")
		length = len(file.split("."))
		if length == 2:
			if file.split(".")[1] == "class":
				raise Exception("The following \n"+path+"\n contain junk file. Please run removeExe.py before commiting")
			if file.split(".")[1]=="exe":
				raise Exception("The following \n"+path+"\n contain junk file. Please run removeExe.py before commiting")
		

checkAllUnnecessaryFiles(path)



	