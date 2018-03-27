'''
a = [10, 5, 1, 2, 6, 8, 7, 3]
temp = 0
temp = int(temp)

for i in range(0, 7):
	for j in range(i+1, 8):
		if(a[i] > a[j]):
			temp = a[i]
			a[i] = a[j]
			a[j] = temp

print(a)
'''

a = [10, 5, 1, 2, 6, 8, 7, 3]
a.sort()
print(a)