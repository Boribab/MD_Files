# while True:
# 	i = input()
# 	if type(i) == int and int(a) == 1:
# 		print("The end")
# 		break
# 	else:
# 		print("This is not one")


# for i in range(2,10):
# 	for j in range (1,10):
# 		print(i," * ",j," = ",i*j)
# 	print("\n")


# list_a = [3,5,9,12]
# res1 = []
# for n in list_a:
# 	res1.append(n-1)
# print(res1)

# res2 = [n-2 for n in list_a]
# print(res2)

list_a = [2,3,4,5,6,7,8,9]
list_b = [1,2,3,4,5,6,7,8,9]
res = [i*j for i in list_a for j in list_b]
print(res)