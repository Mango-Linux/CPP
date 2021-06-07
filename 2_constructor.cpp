#include <iostream>
#include <string.h>

using namespace std;

class Test{
	public:
		int n;
		Test(){
			cout << "call constructor 0" << endl;
		}
		Test(int m){
			cout << "call constructor 1" << endl;
		}
		Test(int m, int n){
			cout << "call constructor 2" << endl;
		}
		~Test(){
			cout << "call Destructor " << endl;
		}
};

int main()
{
	Test array1[3] = {1, Test(1,2)};
	cout << "=========================================" << endl;
	Test array2[3] = {Test(1,2), Test(2,3), 4};
	cout << "=========================================" << endl;
	Test *array3[3] = {new Test(5),new Test(6,7), NULL};

	cout << "=========================================" << endl;
	//delete []array3;
	cout << "=========================================" << endl;
	
	return 0;
}



