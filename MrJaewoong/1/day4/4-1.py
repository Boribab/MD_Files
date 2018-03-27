# a = input()
# b = input()
# a = int(a)
# b = int(b)

# print(a + b)
# print(a - b)
# print(a * b)
# print("%.2f" %(a / b))
# print(a // b)
# print(a % b)


# a,b = map(int, input().split()) # 입력을 받아서 각 변수에 정수로 mapping

# print(a + b)
# print(a - b)
# print(a * b)
# print("%.2f" %(a / b))
# print(a // b)
# print(a % b)


a,b = map(int, input().split())
print(a + b, a - b, a * b, "%.2f" %(a / b), a // b, a % b, sep='\n')