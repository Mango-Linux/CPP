/*
1.私有成员变量不能被外部直接访问，需要通过公有的成员函数访问
2.设置私有成员变量的方式被称作“隐藏”，好处是以后如果成员变量有变化，只需要对应的修改成员函数就好了，使用的地方不用修改
*/
#include <iostream>
#include <string.h>

using namespace std;


class CEmployee{
	private:
		char szname[32];
		
	public:
		int salary;
		void setName(char* name);
		void getName(char* name);
		void aveSalary(CEmployee e1, CEmployee e2);
};

void CEmployee::setName(char * name){
	strcpy(szname, name);
}

void CEmployee::getName(char * name){
	strcpy(name, szname);
}

void CEmployee::aveSalary(CEmployee e1, CEmployee e2){
	cout << e1.szname;
	salary = (e1.salary + e2.salary)/2;
}

int main(int argc,char *argv[])
{
    CEmployee e;
	char name[32] = {0};
	
	//strcpy(e.szname, "mango"); compile error e.szname is private.
	
	e.setName("Linux");
	e.salary = 5000;

	e.getName(name);
	cout << name << endl;

	return 0;
}

