class SimpleTest () :
	my_data = 0

	def __init__(self):
		self.my_data = 100
		print('Call init!')

simple = SimpleTest()
simple.__init__()
print(simple.my_data)