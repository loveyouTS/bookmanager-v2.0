#include<iostream>
#include"class.h"
using namespace std;
int main()
{

		cout << "1.��ͨ�û���½" << endl << "2.����Ա��½" << endl << "3.��������Ա��½"<<endl<<"��������Ĳ���"<<endl;
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