from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
import smtplib

SMTP_SERVER = 'smtp.gmail.com'
SMTP_PORT = 465
SMTP_USER = 'boribori6046@gmail.com'
SMTP_PASSWORD = ''

def sandwich(name, addr):
	mal = MIMEMultipart()

	mal['From'] = SMTP_USER
	mal['To'] = addr
	mal['Subject'] = "20406 박보현 4번 수행평가"

	contents = 'JONJAL JEONG SSAM'

	halmal = MIMEText(_text = contents, _charset = 'utf-8')
	mal.attach(halmal)

	smtp = smtplib.SMTP_SSL(SMTP_SERVER, SMTP_PORT) 

	smtp.login(SMTP_USER, SMTP_PASSWORD)

	smtp.sendmail(SMTP_USER, addr, mal.as_string())

	smtp.close()

sandwich("치질", "xsolute01@gmail.com")