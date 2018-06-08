'''
문자열을 입력받음
문자열 내에 'skip'이라는 단어가 있으면 'rejected' 출력
'skip'이라는 단어가 없으면 그대로 출력
매 출력마다 '-'*10 출력해서 구분
사용자가 'quit'을 입력하여 끝낼 때까지 프로그램을 무한 반복
'''

# skip을 포함하는 문자열일 경우 rejected를 출력하고 구분선을 출력하지 않는 함수

def check(a):
	if 'skip' in a:
		print('rejected')
		return
	else: 
		print(a)
	print('-'*10)

user_input = ' '
while user_input != 'quit':
	user_input = input('input : ')
	check(user_input)