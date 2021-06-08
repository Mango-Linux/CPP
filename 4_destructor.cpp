/*=======================================================================================================
析构函数：
1.名字与类名相同，前面加“~”，没有参数和返回值，一个类最多只能有一个析构函数
2.对象消亡时，析构函数即自动被调用，因此可以定义析构函数在对象消亡前做善后工作，比如释放分配的空间等；
3.new出来的对象，如果没有delete，则对象不会消亡 ，不会调用析构函数
=========================================================================================================*/
#include <iostream>
#include <string.h>

using namespace std;

class Demo{
	int id;
	
public:
	Demo(int i){
		id = i;
		cout << "id=" << id << " constructor" << endl;
	}
	
	~Demo(){
		cout << "id=" << id << " destructor" << endl;	
	}
};

Demo d1(1);

void Func(){
	static Demo d2(2);
	Demo d3(3);
	cout << "func" << endl;
}

int main(){
	Demo d4(4);
	d4 = 6;
	
	cout << "main" << endl;
	{
		Demo d5(5);
	}
	Func();
	cout << "main end " << endl;
	return 0;
}

/*=============================================
运行结果：

id=1 constructor
id=4 constructor
id=6 constructor
id=6 destructor
main
id=5 constructor
id=5 destructor
id=2 constructor
id=3 constructor
func
id=3 destructor
main end 
id=6 destructor
id=2 destructor
id=1 destructor

==============================================*/
