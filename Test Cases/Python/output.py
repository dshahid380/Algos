for k in range(5):
	inp = open("input"+str(k)+".in","r+") # Taking input in read mode
	out = open("output"+str(k)+".out","w+") # Opening a new output file in write mode
	#tot = out[1:] 
	"""n = []
	arr = []
	for i in range(1,len(out)):
		if i%2==1:
			n.append(out[i][0])
		else:
			arr.append(out[i]) 
	for i in range()
	"""
	for i in out:
		#out.write(str(i)+"\n")
		print(i)
	out.close()
	inp.close()
		
