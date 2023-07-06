#include<iostream>
#include"class.h"
using namespace std;
int main()
{

		cout << "1.普通用户登陆" << endl << "2.管理员登陆" << endl << "3.超级管理员登陆"<<endl<<"请输入你的操作"<<endl;
		int judge = 0;
		cin >> judge;
		switch (judge)
		{
		case 1:
			user_login();
			break;
		case 2:
			manager_login();
			break;
		case 3:
			break;
		}
	
}