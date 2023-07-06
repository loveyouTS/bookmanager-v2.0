#include<iostream>
#include<string>
#include<fstream>
#include"class.h"
#include <conio.h>
using namespace std;
manager* get_manager()
{
	manager* s = NULL, * p = NULL, * head = NULL;
	int d = 1;
	s = new manager;
	s->next = NULL;
	string str;
	ifstream inf;
	inf.open("D:\\代码\\bookmanager2.0\\bookmanager2.0\\manager.txt");
	while (getline(inf, str))      //getline(inf,s)是逐行读取inf中的文件信息
	{
		if (d == 1)
		{

			if (head == NULL)
				head = s;
			d = 2;
			//s = s.substr(0, s.find_last_not_of('\r'));
			s->id = stoi(str, 0, 10);
			continue;
		}

		if (d == 2)
		{
			str = UTF8ToGB(str.c_str()).c_str();
			s->name = str;
			d = 3;
			continue;
		}
		if (d == 3)
		{
			s->passsword = stoi(str, 0, 10);
			d = 1;
			p = s;
			s = new manager;
			p->next = s;
			s->next = NULL;
			continue;
		}
	}
	delete s;
	p->next = NULL;
	inf.close();
	return head;
}
borrow_book* get_borrow()
{
	borrow_book* s = NULL, * p = NULL, * head = NULL;
	int d = 1;
	s = new borrow_book;
	s->next = NULL;
	string str;
	ifstream inf;
	inf.open("D:\\代码\\bookmanager2.0\\bookmanager2.0\\Borrowing records.txt");
	while (getline(inf, str))      //getline(inf,s)是逐行读取inf中的文件信息
	{
		if (d == 1)
		{

			if (head == NULL)
				head = s;
			d = 2;
			s->name = str;
			continue;
		}

		if (d == 2)
		{
			//str = UTF8ToGB(str.c_str()).c_str();
			s->bk_auther = str;
			d = 3;
			continue;
		}
		if (d == 3)
		{
			s->bk_name = str;
			d = 4;
			continue;
		}
		if (d == 4)
		{
			s->time = stoi(str, 0, 10);
			d = 1;
			p = s;
			s = new borrow_book;
			p->next = s;
			s->next = NULL;
			continue;
		}
	}
	delete s;
	p->next = NULL;
	inf.close();
	return head;
}
return_book* get_return()
{
	return_book* s = NULL, * p = NULL, * head = NULL;
	int d = 1;
	s = new return_book;
	s->next = NULL;
	string str;
	ifstream inf;
	inf.open("D:\\代码\\bookmanager2.0\\bookmanager2.0\\Return records.txt");
	while (getline(inf, str))      //getline(inf,s)是逐行读取inf中的文件信息
	{
		if (d == 1)
		{

			if (head == NULL)
				head = s;
			d = 2;
			s->name = str;
			continue;
		}

		if (d == 2)
		{
			//str = UTF8ToGB(str.c_str()).c_str();
			s->bk_auther = str;
			d = 3;
			continue;
		}
		if (d == 3)
		{
			s->bk_name = str;
			d = 4;
			continue;
		}
		if (d == 4)
		{
			s->time = stoi(str, 0, 10);
			d = 1;
			p = s;
			s = new return_book;
			p->next = s;
			s->next = NULL;
			continue;
		}
	}
	delete s;
	p->next = NULL;
	inf.close();
	return head;
}
void manager_login()
{
	string ma_name;
	int ma_password;
	manager* s;
	while (1)
	{
		s = get_manager();
		cout << "请输入用户名" << endl;
		cin >> ma_name;
		while (s)
		{
			if (s->name == ma_name)
				break;
		}

		if (s == NULL)
			cout << "此用户不存在" << endl;
		else
			break;

	}
	while (1)
	{
		cout << "请输入密码" << endl;
		std::string password;
		char ch;


		while ((ch = _getch()) != '\r') {  // 直到输入回车键结束循环
			if (ch == '\b') {  // 处理退格键
				if (!password.empty()) {
					std::cout << "\b \b";  // 向控制台输出退格符和空格覆盖输入的字符
					password.pop_back();  // 从密码字符串中删除最后一个字符
				}
			}
			else {
				std::cout << '*';  // 显示星号替代实际输入的字符
				password.push_back(ch);  // 将输入的字符添加到密码字符串中
			}
		}
		ma_password = stoi(password, 0, 10);
		
		cout << endl;
		
		
		
		
		if (ma_password == s->passsword)
		{
			cout << "登陆成功" << endl;
			break;
		}
		else
			cout << "密码错误" << endl;
	}
	cout << "1.添加图书" << endl << "2.删除图书" << endl << "3.异常还书处罚" << endl << "4.发布公告" << endl << "请输入你要进行的操作" << endl;
	int ma_order;
	cin >> ma_order;
	if (ma_order == 1)
	{
		string ad_book, ad_auther;
		cout << "请输入你要添加书的书名和作者" << endl;
		cin >> ad_book >> ad_auther;
		s->add_book(ad_book,ad_auther);
	}
	if (ma_order == 2)
	{
		string dl_book, dl_auther;
		cout << "请输入你要添加书的书名和作者" << endl;
		cin >> dl_book >> dl_auther;
		s->delete_book(dl_book, dl_auther);
	}
	if (ma_order == 3)
	{
		s->punish();
	}
	if (ma_order == 4)
	{
		s->publish();
	}
}