#count
a = 'programming'
res = a.count('m')
print(res)
# count함수가 메소드로 지정된 변수의 문자열에서
# count함수 인자(문자)의 개수를 반환한다.
# 만약 a에 숫자를 담고 count에 숫자 인자를 넣으면?
# -> 불가능하다. 이유는 문자열 함수이기 때문
# -> 그래도 숫자를 세고 싶다면? => 문자열로 만들어주면 됨

#find
a = 'programming'
res = a.find('m')
print(res)
# find함수가 메소드로 지정된 변수의 문자열에서
# find함수 인자(문자)의 인덱스를 반환한다.
# 만약 찾는 문자가 없다면? => -1 출력
# 반환되는 -1이 정수이기 때문에 연산이 가능하다.
# ex) if(res == -1) 또는 res+1

#index
a = 'programming'
res = a.index('m')
print(res)
# 만약 찾는 문자가 없다면? => error 출력 

#join
a = '_m-_-m_'
res = a.join('ABC')
print(res)
# join함수가 메소드로 지정되 변수의 문자를
# join함수의 인자(문자) 사이에 삽입한다.
# 숫자도 될까? => 당연히 안됨. 문자열 함수이므로.
# 가능하게 하는 방법은? => 숫자를 문자로 지정해주면 가능
# 한 줄씩 띄우게 하고 싶을 땐?
# => a = '\n'

a = [1, 'sdf', 123, 'sdfsdfsdf']
print(str(a)[1:-1])

#upper
a = 'programming'
res = a.upper()
print(res)

#lower
a = 'PROGRAMMING'
res = a.lower()
print(res)
# 특수 문자에 대해서도 될까? => upper, lower 둘 다 안됨.

#replace
a = 'programming'
res = a.replace('', '1')
print(res)
# 문자열을 치환한 결과를 반환한다.
# 공백으로부터 치환이 가능할까? replace('','1')
# 공백으로 치환이 가능할까? replace('g','')
# 띄어쓰기로부터 치환이 가능할까? replace(' ','1')
# 없는 문자열은 치환이 불가능하다. => 원본 그대로 출력

#split
a = 'a1p1p1l1e'
res = a.split('1')
print(res[0] + res[1] + res[2] + res[3] + res[4])
# 문자열을 나눈 결과를 반환한다. => result is list type
# a = 'a1p1p1l1e' // res = a.split('1')
# 결과가 리스트이므로 나눈 결과를 결합하려면 인덱스를 활용한다.

# lstrip
a = '          programming            '
res = a.lstrip()
print(res + 'hello') # 왼쪽 공백 삭제 확인

# rstrip
a = '          programming            '
res = a.rstrip()
print(res + 'hello') # 오른쪽 공백 삭제 확인

# strip
a = '          programming            '
res = a.strip()
print(res + 'hello')

#type
a = 'programming'
res = type(a)
print(res)

#str
a = 123
res = str(a)
print(res*10)
# 문자열인지 확인

#int
a = '123'
res = int(a)
print(res * 10)
# 문자로 표현된 숫자를 정수형으로 바꿈
# 순수 문자는 정수로 변경 X
# 바꾼 숫자로 계산은 당연히 가능

# ord
a = 'A'
res = ord(a)
print(res)
# 문자를 아스키코드(정수)로 바꿈

#chr
a = 65
res = chr(a)
print(res)
# 정수에 해당하는 아스키코드 문자를 반환
# chr(a*2) 가능
# chr(a/2) 불가능
# a/2는 자료형이 float이기 때문

#리스트 함수

#append
res = [1,2,3]
res.append(4)
print(res)
# 인자를 문자열 뒤에 추가
# a=[1,2,3], res = a.append(4)
# -> 반환값이 없는 함수이므로 none

#sort
res1 = ['e','a','h']
res2 = [1,6,2]
res1.sort()
res2.sort(reverse = True)
res3 = sorted(res1)
res4 = sorted(res1, reverse = True)
res.reverse()
print(res1)
print(res2)
print(res3)
print(res4)
# sorted는 딕셔너리 정렬이 가능하다
a = {'2':'B','1':'A','3':'U'}
a1 = sorted(a)
print(a1)

#insert
res = [100, 123, 523]
res.insert(1,2)
print(res)
# 특정 인덱스의 값이 되도록 요소를 추가한다
# 계산값을 넣어도 된다

#remove
res = [10,20,30,40]
res.remove(10)
print(res)
# 함수의 인자값을 찾아서 삭제
# 값이 여러개면 가장 첫번째 요소 삭제

# pop
res = [10,20,30,40]
a = res.pop() #반환값 O
print(a)
# 마지막 요소를 삭제하는 함수

#count
a = [10,10,101,102,10,'ab']
res = a.count(10)
print(res)
# 함수의 인자값을 찾아서 개수를 센다
# 내부의 계산값을 넣어도 된다 ex) res = a.count(5+5)

# 딕셔너리 함수

#keys
a = {'a':123,'b':456}
res = a.keys()
print(res)
# 딕셔너리의 키를 반환한다.

#values
a = {'a':123,'b':456}
res = list(a.values())
print(res)

#items
a = {'a':123,'b':456}
res = a.items()
print(res)

#dict~~~ 라는 말을 없애고 싶다면 list 활용

#get
a = {'q':123, 'w':456}
res = a.get('t',789)
print(res)
print(a['t'])
# get 함수를 쓸 때 키가 없는 값을 찾으면 none or 2번째 인자
# 키 값으로 찾으면 오류

#in
a = {'q':123,'w':456}
print('q' in a)
# 키 값이 있는지 없는지 검사
# 있으면 True, 없으면 False