import requests 
import html5lib
from bs4 import BeautifulSoup 

def getContestList(page):
	res = requests.get("https://codeforces.com/contests/page/"+str(page))
	sp = BeautifulSoup(res.content, 'html5lib')
	tab = sp.find('div', attrs = {'class':'contests-table'})
	tn = tab.table.tbody 
	contest_list = tn.find_all('tr')
	#print(contest_list[1].td)
	contests = []
	for i in range(1,len(contest_list)):
		tdi = contest_list[i].td
		ta = tdi.find('a')['href']
		contests.append(ta)
	return contests

def getProblem(contest):
	res1 = requests.get('https://codeforces.com'+contest)
	sp1 = BeautifulSoup(res1.content, 'html5lib')
	tab1 = sp1.find('table', attrs = {'class':'problems'})
	tn1 = tab1.tbody
	prob = tn1.find_all('tr')
	problems = []
	for i in range(1,len(prob)):
		ti = prob[i].td 
		problems.append(ti.find('a')['href'])
	return problems
