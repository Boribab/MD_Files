import os

def encrypt(file):
	N = 10403
	d = 6029
	e = 269

	f1 = open(os.getcwd()+"\\samples\\"+file, "rb")
	f2 = open(os.getcwd()+"\\samples\\"+file+".hello", "wb")

	arr = f1.read()

	f1.close()

	for i in arr:
		a = ((i**e) % N).to_bytes(2, 'big') 
		f2.write(a)

	f2.close()

def decrypt(file):
	N = 10403
	d = 6029
	e = 269

	f1 = open(os.getcwd()+"\\samples\\"+file, "rb")
	f2 = open(os.getcwd()+"\\samples\\"+"D_"+file[:-6], "wb")

	arr = f1.read()

	f1.close()

	i = 0

	while(i < len(arr)):
		data = arr[i]*256 + arr[i+1]

		dcdata = ((data**d) % N).to_bytes(1, 'big')

		f2.write(dcdata)

		i = i + 2

	f2.close()