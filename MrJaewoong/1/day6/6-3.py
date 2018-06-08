# 가상의 이메일 전송 함수

def send_mail(from_mail, to_mail, subject, contents):
	print("From: \t" + from_mail)
	print("To: \t" + to_mail)
	print("Subject : "+ subject)
	print("*"*20)
	print(contents)
	print("*"*20)
	print("*"*20)

my_email = "boribori6046@gmail.com"

users = []
users.append({'name' : 'Bori', 'email' : 'boribori6046@gmail.com'})
users.append({'name' : 'JW', 'email' : 'skyjjw79@hanmail.net'})

contents = "Hello Mr.Kim"

for user in users:
	title = 'Dear. '+ user['name']
	send_mail(my_email,user['email'],title,contents)