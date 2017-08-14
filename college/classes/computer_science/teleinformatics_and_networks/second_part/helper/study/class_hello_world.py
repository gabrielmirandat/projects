class PrintMe:
    def __init__(self, str):
        self.mystr = str

    def __exit__(self):
    	pass

    def show_str(self):
    	print self.mystr

    def show_any(self, any):
    	print any

if __name__ == "__main__":
	p = PrintMe("hi")
	p.show_str()
	p.show_any("any")
