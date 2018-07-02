import pyautogui

# 화면의 크기를 반환하는 'pyautogui 라이브러리' 함수

scrWD, scrHE = pyautogui.size()

print(scrWD, scrHE) # ctrl + shift + B (빠른 실행)
'''
# moveTo
# 원하는 위치(절대좌표)로 마우스를 이동
# 마우스의 위치를 확인하고 싶다면 ctrl 옵션을 설정하면 된다.

pyautogui.moveTo(scrWD/2, scrHE/2)


# moveRel
# 원하는 위치(상대 좌표)로 마우스를 이동
# 이동하지 않으려면 None값으로 인자를 설정한다.

i = 0
pyautogui.moveRel(0, -150)
pyautogui.moveRel(150, 0)

while(i < 10):
	pyautogui.moveRel(0, 300)
	pyautogui.moveRel(-300, 0)
	pyautogui.moveRel(0, -300)
	pyautogui.moveRel(300, 0)
	i = i + 1

# click
# 딱 봐도 클릭하는 함수
# 옵션을 통해 횟수와 버튼 지정 가능
# x, y -> 마우스 위치 이동
# clicks -> 마우스 클릭 횟수
# interval -> 클릭 간격 조정 (값 : second)
# button -> 마우스 버튼 위치 선택(left, right)

pyautogui.click(x = scrWD/3, y = scrHE/2, clicks = 2, interval = 3, button = 'left')

# typewrite
# 키를 입력하는 함수
# 지금은 영어만 입력할 수 있음

pyautogui.typewrite('calc')

#press
# 특수키를 입력할 때 사용하는 함수
pyautogui.press('enter')
'''

#locateCenterOnScreen
#그림과 일치하는 위치의 좌표 반환
#그림 파일을 png로 설정해야 함

lx, ly = pyautogui.locateCenterOnScreen('cap.png')
pyautogui.moveTo(lx, ly)

