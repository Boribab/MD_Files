'''
함수란? 
입력 값을 받아서, 특정 연산(작업)을 수행한 후에 결과를 출력하는 것
입력 값을 받아서, 특정 연산(작업)을 수행한 결과
프로그래밍에서는 결과보다는 어떤 기능을 하느냐가 더 주안점

## 사용자 함수
+ 주의사항
함수 호출 전까지는 함수 안의 문장들은 수행 X
함수는 호출 되기 전에 먼저 만들어져야 함
함수의 정의 => def 함수이름(함수의 인수...):
+ 동작과정
반환을 하는지 안 하는지 생각하기
def print_name():
def sum(a,b):
'''

# function that no return value
def func1(a):
	print(a*3)

print('start')
func1('daaa')

# function that return value
def sum(a,b):
	return a+b

a,b = input().split()
res = sum(int(a),int(b))

print(res)

# 함수는 선언하고 호출하는 위치가 중요하다.
# C언어처럼 앞에서 프로토타입을 선언할 수 없을까? 아마 안 될꺼야