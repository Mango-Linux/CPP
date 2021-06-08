/*================================================================================================
复制构造函数有如下特征：
1.只有一个参数，即同类对象的引用如 形如X::X(&X) 或者 X::X(const X&) ，后者以常量对象作为参数
2.如果没有定义复制构造函数，那么编译器会默认生成

复制构造函数起作用的三种情况：
1.当用一个对象去初始化同类的另一个对象时，如
Complex c2(c1);
complex c2 = c1; //初始化语句，非赋值语句
2.如果某一个函数有一个参数是类A的对象，那么这个函数被调用时，类A的复制构造函数将被调用，如
void Func（A a1）{}
int main（）{
	A a2；
	Func（a2）；
	return 0；
}
3.如果一个函数的返回值时类A的对象时，则函数返回时，A的复制构造函数将会被调用
A Func(){
	A b(4);
	return b;
}

int main(){
	cout << Func().v << endl;
	return 0;
}
4.如下func1函数会调用复制构造函数，会增加开销，
所以可以改成如下func2函数，因为参数是引用，为了不想修改参数值，所以加上const
void func1(complex c){
	cout << "call func1======>" << endl;
}

void func2(const complex & c){
	cout << "call func2======>" << endl;
}
=====================================================================================================*/
#include <iostream>
#include <string.h>

using namespace std;

class complex{
	public:
		int real;
		int imag;

	public:
		complex(){
			cout << "call constructor,11111====>" << endl;
		}
	
		complex(int m, int n){
					real = m;
					imag = n;
					cout << "call constructor,2222====>" << endl;
		}

		complex(const complex & c){
			real = c.real;
			imag = c.imag;
			cout << "call copy constructor====>" << endl;
		}
};

void func1(complex c){
	cout << "call func1======>" << endl;
}

complex func2(void){
	complex A(3,4);
	cout << "call func2======>" << endl;
	return A;
}

void func3(const complex & c){
	//c.imag = 10;
	//c.real = 20; compile error
	cout << "call func3======>" << endl;
}

int main()
{
	complex A(1,2);
	complex B(A);
	complex C = B;
	complex D;
	complex & E = B;
	
	cout << "B.real=" << B.real << endl << "B.imag=" << B.imag << endl;
	cout << "C.real=" << C.real << endl << "C.imag=" << C.imag << endl;
	cout << "===========================1111111===========================" << endl;
	func1(A);
	cout << "===========================2222222===========================" << endl;
	D = func2();
	cout << "D.real=" << D.real << endl << "D.imag=" << D.imag << endl;
	cout << "===========================3333333===========================" << endl;
	func3(E);
	return 0;
}

/*=================================================================================
运行结果：

call constructor,2222====>
call copy constructor====>
call copy constructor====>
call constructor,11111====>
B.real=1
B.imag=2
C.real=1
C.imag=2
===================1111111================
call copy constructor====>
call func1======>
===================2222222================
call constructor,2222====>
call func2======>
D.real=3
D.imag=4
===================3333333================
call func3======>

===================================================================================*/
