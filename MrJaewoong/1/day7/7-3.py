'''
이메일 보내기
필요한 설정 정보
- SMTP 서버 : 메일을 보내는 서버
- POP3 서버 : 메일을 받는 서버
- 계정 정보 : ID/PW

라이브러리
email, smtplib
- 기본 라이브러리로 제공함, 따로 설치 X

라이브러리 내부
MIME : 전자우편을 위한 인터넷 표준 포맷
MIMEText, MIMEMultipart : SMTP가 사용하는 양식에 맞춰서 내용을 작성해주는 클래스 

from ~ import ~ : 라이브러리 내에 함수 하나만 갖다 쓴다 
import ~ : 라이브러리만 빼온다
'''

from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
import smtplib

SMTP_SERVER = 'smtp.gmail.com'
SMTP_PORT = 465

SMTP_USER = 'boribori6046@gmail.com'
SMTP_PASSWORD = ''

def send_mail(name, addr):
	msg = MIMEMultipart()

	msg['From'] = SMTP_USER
	msg['To'] = addr
	msg['Subject'] = name + '님에게 메일이 도착하였습니다.'

	contents = name + '''님에게 메일이 도착하였습니다.
	안녕하세여 ㅋㅎ 오홍홍 조아용'''

	# msg['text'] = contents

	text = MIMEText(_text = contents, _charset = 'utf-8')
	msg.attach(text)

	# SMTP로 접속할 서버 정보를 가진 클래스 변수를 생성한다.
	smtp = smtplib.SMTP_SSL(SMTP_SERVER, SMTP_PORT)

	# 계정 정보로 로그인
	smtp.login(SMTP_USER, SMTP_PASSWORD)

	# 메일 발송
	smtp.sendmail(SMTP_USER, addr, msg.as_string())

	print("\n 메일이 전송되었습니다 \n")

	smtp.close()

send_mail('self', 'boribori6046@gmail.com')