/*==========================================================================================
1.构造函数时成员函数的一种
2.名字与类名相同，可以有参数，不能有返回值（void）也不行；
3.作用是对对象进行初始化，如给成员变量赋初值
4.如果定义类时没有写构造函数，则编译器生成一个默认的无参构造函数，该函数不做任何操作
5.如果定义了构造函数，则编译器不会生成默认的
6.对象生成时构造函数被自动调用。
7.一个类可以有多个构造函数（重载）
8.为什么需要构造函数：
1）构造函数可以执行必要的初始化工作
2）有时对象没有被初始化，会导致程序错误
=============================================================================================*/

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

/*==================================================
运行结果：
call constructor 1
call constructor 2
call constructor 0
=========================================
call constructor 2
call constructor 2
call constructor 1
=========================================
call constructor 1
call constructor 2
=========================================
=========================================
call Destructor 
call Destructor 
call Destructor 
call Destructor 
call Destructor 
call Destructor 
===================================================*/



