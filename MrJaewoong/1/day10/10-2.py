from selenium import webdriver
from selenium.webdriver.common.keys import Keys 

driver = webdriver.Chrome('chromedriver')

try:
	driver.get('http://www.naver.com')
	print(driver.title)

	elem = driver.find_element_by_id('query')
	elem.clear()
	elem.send_keys('히든싱어')
	elem.send_keys(Keys.RETURN)

	# news = driver.find_element_by_xpath("//*[@id=\"main_pack\"]/div[4]/ul")
	# news_list = news.find_elements_by_class_name('_sp_each_title')

	news = driver.find_element_by_class_name("news")
	news_list = news.find_elements_by_xpath('./ul/li')

	for post in news_list:
		# print(post.text)
		news_title = post.find_element_by_class_name('_sp_each_title')
		print(news_title.text)

except Exception as e:
	print(e)

finally:
	driver.close()