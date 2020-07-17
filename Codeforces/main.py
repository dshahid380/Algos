class Student:
	def __init__(self, name, sub1, sub2, sub3):
		self.name = name
		self.sub1 = sub1
		self.sub2 = sub2
		self.sub3 = sub3

	def calculateResult(self):
		if(self.sub1<40 and self.sub2<40 and self.sub3<40):
			return 0
		else:
			avg = (self.sub1 + self.sub2 + self.sub3)/3
			return avg

class School:
	def __init__(self, name, studentDict):
		self.name = name
		self.studentDict = studentDict
	
	def getStudentResult(self):
		for student in studentDict:
			if student.calculateResult()>60:
				studentDict[student] = 'pass'
			else:
			    studentDict[student] = 'fail'
      
		return studentDict

	def findStudentWithHighestMarks(self,studentList):
		res = -1
		s = Student('A',0,0,0)
		for student in studentList:
			if studentList[student] == 'pass':
          		res = max(res,student.calculateResult())
    	if res == -1:
      		return None 
    	else: return s
				 

t=int(input())

studentDict = {}
for i in range(t):
    name=input()
    sub1=float(input())
    sub2=float(input())
    sub3=float(input())
    o1=Student(name,sub1,sub2,sub3)
    studentDict[o1] = 'fail'
name=input()
o2=School(name,studentDict)
studentList=o2.getStudentResult()
#for s in studentList:
   #print(s.name,studentDict[s])
r2=o2.findStudentWithHighestMarks(studentList)
for i in studentList:
    if studentList[i]=="pass":
        print(i.name)

if r2==None:
    print("No Student Passed")
else:
    print(r2.name)




