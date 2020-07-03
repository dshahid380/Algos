class Vegetable:
    def __init__(self, name, price, quantity):
        self.name = name
        self.price = price
        self.quantity = quantity

class Store:
    def __init__(self, storeName, vegList):
        self.storeName = storeName
        self.vegList = vegList 

    def categorizeVegetablesAlphabetically(self):
        vl = []
        for veg in vegList:
            vl.append(veg.name)
        res = {}
        vl.sort()
        for veg in vl:
            if veg[0] in res:
                res[veg[0]].append(veg)
            else:
                res[veg[0]] = [veg]
        for key in res:
            res[key] = tuple(sorted(res[key]))
        return res

    def filterVegetablesForPriceRange(self, minPrice, maxPrice):
        res = []
        for veg in vegList:
            if veg.price >= minPrice and veg.price <= maxPrice:
                res.append(veg.name)
        res.sort()
        return res 

t=int(input())
vegList=[]
for i in range(t):
    name=input()
    price=float(input())
    quantity=int(input())
    v=Vegetable(name,price,quantity)
    vegList.append(v)
sname=input()
s=Store(sname,vegList)
mini=float(input())
maxi=float(input())

vegCat=s.categorizeVegetablesAlphabetically()
vegLet = list(sorted(vegCat.keys()))
for v in vegLet:
    print(v)
    for el in vegCat[v]:
        print(el)

r2=s.filterVegetablesForPriceRange(mini,maxi)
if len(r2)==0:
    print("No Vegetable found for given price range")
else:
    print(str(mini)+"-"+str(maxi))
    for el in r2:
        print(el)


