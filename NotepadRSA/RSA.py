import os

def encrypt(file):
	N = 217
	d = 11
	e = 131

	f1 = open(os.getcwd()+"\\samples\\"+file, "rb")
	f2 = open(os.getcwd()+"\\samples\\"+file+".hello", "wb")

	for i in f1.read():
		f2.write(bytes([(i**e) % N]))

	f1.close()
	f2.close()

def decrypt(file):
	N = 217
	d = 11
	e = 131

	f1 = open(os.getcwd()+"\\samples\\"+file, "rb")
	f2 = open(os.getcwd()+"\\samples\\"+"D_"+file[:-6], "wb")

	for i in f1.read():
		f2.write(bytes([(i**d) % N]))

	f1.close()
	f2.close()