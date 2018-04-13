def stair(x):
	if(x<3): return x
	else: return stair(x-1)+stair(x-2)

n = int(input())

print(stair(n))