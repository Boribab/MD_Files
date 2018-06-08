'''
일종의 템플릿
- c언어의 구조체와 유사하다
차이점은?
- 구조체는 변수만 담을 수 있지만 클래스는 함수도 가능

형식
class 클래스명():
	변수명 = 변수값
	def 함수명(self, 인자···, ···)

만들어보자
- c언어의 구조체처럼 . 을 써서 클래스 내부 활용
알게 된 점
- 클래스도 함수처럼 호출되기 전에는 수행 안 됨
self?
- 클래스의 변수에 접근하기 위해 파이썬이 제공하는 변수
- 클래스 내에서 함수를 정의할 때 잊지 말고 꼭 쓰자

생성자
- 클래스 변수가 생성될 때 자동으로 호출되는 함수
- 클래스 내부에 정의된 변수 등을 초기화 할 때 사용
'''

# 간단한 클래스를 정의
class SimpleTest():
	a = 0
	postfix = '\t DSM'
	def print_with(self, string):
		print(string)
		print(self.a)
		print(str(self.a)+string+self.postfix)

s1 = SimpleTest()
s2 = SimpleTest()

print(s1.a)
print(s2.a)

s1.a = 10
s2.a = 20

print(s1.a)
print(s2.a)

s1.print_with('KSH')
s2.print_with('UYBY&HGHG')