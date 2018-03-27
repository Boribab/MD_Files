'''
python : 스크립트 언어 
script language? 컴파일 없이 실행 가능한 언어
compile? 어떤 언어의 코드를 다른 언어로 변환
ex) 원시 언어(고급언어) => 목적 언어(저급 언어, 기계어)

compiler         vs           interprinter

프로그램 단위로 번역               명령 줄 단위 번역
번역 속도 느림                    번역 속도 빠름
실행 속도 빠름                    실행 속도 느림
큰 메모리 필요 (메모리 부족 에러)     적은 메모리 필요

프로그램 크기가 큰 프로그램 : compiler
* 작은 프로그램 : interprinter

자료형 : 데이터를 변수에 담는 순간 자료형이 정해짐, 자료형마다 연산을 지원 
새로 추가된 연산자 
1. ** 제곱
2. // 나누었을 때의 몫

정수와 실수의 연산 => 실수
음수를 나누었을 때 나머지가 있는 경우 -11 // 2 => -6 
문자열 넣을때 """ ~ """ 
ctrl + tap || shift + tap

슬라이싱 : 문자열 자르기 
a[:]

딕셔너리 : 대응관계를 나타낼 수 있는 자료형 (key -> value) 사전같은 느낌, 자체 연산 X, 인덱싱만 되고 슬라이싱 안됨

내장함수 : count, index, find, join, upper, lower, replace, split, lstrip, 
         rstrip, strip, type, int, str, ord, chr
'''
'''
count 
>>> a = "refrigerator"
>>> r=a.count()
>>> r = a.count('r')
>>> print(r)
4

find : -1
>>> r=a.find('r')
>>> print(r)
0

index : error
>>> r=a.index('r')
>>> print(r)
0

join
>>> a = ', '
>>> r = a.join('DSM')
>>> print(r)
D, S, M

upper
>>> a = 'dsm'
>>> r = a.upper()
>>> print(r)
DSM

lower
>>> a = 'DSM'
>>> r = a.lower()
>>> print(r)
dsm

replace
>>> a = "I love DSM"
>>> r = a.replace('love','hate')
>>> print(r)
I hate DSM

split
>>> a = "Oh Yeah ^^"
>>> r = a.split()
>>> print(r)
['Oh', 'Yeah', '^^']

lstrip
>>> a = '        hehe    '
>>> r = a.lstrip()
>>> print(r)
hehe

rstrip
>>> a = 'hehe           '
>>> a.rstrip()
'hehe'

strip
>>> a = '            hehe             '
>>> a.strip()
'hehe'

type
>>> a = [123, 1.1, 'hao']
>>> type(a)
<class 'list'>
>>> type(a[0])
<class 'int'>
>>> type(a[1])
<class 'float'>
>>> type(a[2])
<class 'str'>

int
>>> a = 1.5
>>> int(a)
1

str
>>> a = 11545
>>> str(a)
'11545'

ord
>>> ord('A')
65

chr
>>> chr(65)
'A'
'''