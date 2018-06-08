import RSA
import os

path_dir = '/Users/dsm2017/Desktop/lock/samples'

file_list = os.listdir(path_dir)

file_list.sort()

for i in file_list:
	RSA.encrypt(i)

path_dir = '/Users/dsm2017/Desktop/lock/samples'

file_list = os.listdir(path_dir)

file_list.sort()

for i in file_list:
	fname, ext = os.path.splitext(os.getcwd()+"\\samples\\"+i)

	if(ext == '.hello'):
		RSA.decrypt(i)