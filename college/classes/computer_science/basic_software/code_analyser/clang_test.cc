#include <iostream>

namespace n6
{
	void f(int*) {}

	void testUseMiddleArgAfterDelete(int* p){
		delete p;
		f(p); //warn: use after free
	}
}

int main()
{
	using namespace n6;
	
	int* value;
	testUseMiddleArgAfterDelete(value);
}