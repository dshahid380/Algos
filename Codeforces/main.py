class Book:
	def __init__(self, bookid, bookName, subject, bookPrice):
		self.bookid = bookid
		self.bookName = bookName
		self.subject = subject
		self.bookPrice = bookPrice

class Library:
	def __init__(self, libraryName, bookList):
		self.libraryName = libraryName 
		self.bookList = bookList 

	def findSubjectWiseBook(self):
		d = {}
		for book in self.bookList:
			if book.subject in d:
				d[book.subject] += 1
			else:
				d[book.subject] = 1
		return d 

	def checkBooKCategoryByPrice(self, bookId):
		for book in self.bookList:
			if book.bookid == bookId:
				if book.bookPrice >= 1000:
					return "High Price" 
				elif book.bookPrice >= 750 and book.bookPrice < 1000:
					return "Medium Price"
				elif book.bookPrice >= 500 and book.bookPrice < 750:
					return "Average Price"
				else:
					return "Low Price"
		return None

#main function
bookList = []
for _ in range(int(input())):
	bookid = int(input())
	bookName = input()
	subject = input()
	bookPrice = int(input())
	bookList.append(Book(bookid, bookName, subject, bookPrice))

library = Library("xyz", bookList)
bookCount = library.findSubjectWiseBook();
books = list(bookCount.keys())
books = sorted(books)

for b in books:
	print(b, bookCount[b])
bid = int(input())
cat = library.checkBooKCategoryByPrice(bid)
if cat == None:
	print("Book Not Found")
else:
	print(cat)



