'''
단계

Selenium 설정
네이버 이동 후 분석
	검색어 창의 태그 분석
	검색어 창으로 원하는 입력 값 전송
검색 후 결과창 분석
	블로그, 카페, 뉴스 등
	클래스 구분이 띄어쓰기인 것을 알 수 있음
		Ctrl + F => .클래스명으로 고유한 값인지 확인
'''

from selenium import webdriver
from selenium.webdriver.common.keys import Keys 

driver = webdriver.Chrome('chromedriver')

try:
	driver.get('http://www.naver.com')
	print(driver.title)

	elem = driver.find_element_by_id('query')
	elem.clear()
	# clear()를 해주는 이유는 간혹 포털마다
	# 검색어가 이미 입력되어 있는 경우가 있기 때문
	elem.send_keys('히오스')
	elem.send_keys(Keys.RETURN)

	blogs = driver.find_element_by_class_name('_blogBase')
	blogs_list = blogs.find_elements_by_tag_name('li')
	# blogs_list의 자료형은 list
	for post in blogs_list:
		# print(post.text)
		# print('-'*20)

		post_title = post.find_element_by_class_name('sh_blog_title')
		# print(post_title.text)
		# 여기서 한 가지 의문 무엇 => ...나오는 것
		print(post_title.get_attribute('title'))
		# ...으로 title이 생략되어 있는 부분의 제목을 출력하기 => 속성 : title
		# 응용 : URL도 같이 ㄱ
		print(post_title.get_attribute('href'))
		print('-'*20)

except Exception as e:
	print(e)

finally:
	driver.close()