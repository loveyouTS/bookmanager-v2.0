#include<iostream>
#include<string>
#include<Windows.h>
#include<fstream>
#include"class.h"
using namespace std;
string UTF8ToGB(const char* str)
{
	std::string result;
	WCHAR* strSrc;
	LPSTR szRes;

	//获得临时变量的大小
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

	//获得临时变量的大小
	i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new CHAR[i + 1];
	WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

	result = szRes;
	delete[]strSrc;
	delete[]szRes;

	return result;
}
user* get_user()
{
	user* s=NULL, *p=NULL,*head=NULL;
	int d=1;
	s = new user;
	s->next = NULL;
	string str;
	ifstream inf;
	inf.open("D:\\代码\\bookmanager2.0\\bookmanager2.0\\user.txt");
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
			s = new user;
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
book* get_book()
{
	int a = 1;
	book* head=NULL, * s,*p=NULL;
	s = new book;
	s->next=NULL;
	string str;
	ifstream inf;
	inf.open("D:\\代码\\bookmanager2.0\\bookmanager2.0\\book.txt");
	while (getline(inf, str))      //getline(inf,s)是逐行读取inf中的文件信息
	{
		if (a == 1)
		{
			if (head == NULL)
				head = s;
			//str = UTF8ToGB(str.c_str()).c_str();
			s->auther= str;
			a = 2;
			continue;
		}
		else
		{
			//str = UTF8ToGB(str.c_str()).c_str();
			s->name = str;
			p = s;
			s = new book;
			s->next = NULL;
			p->next = s;
			a = 1;
		}
	}
	delete s;
	p->next = NULL;
	inf.close();
	return head;
}
void user_login()
{
	string us_name;
	user* s;
	int us_password;
	while (1)
	{
		s = get_user();
		cout << "请输入用户名" << endl;
		cin >> us_name;
		while (s)
		{
			if (s->name == us_name)
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
		cin >> us_password;
		if (us_password == s->passsword)
		{
			cout << "登陆成功"<<endl;
			break;
		}
		else
			cout << "密码错误" << endl;
	}
		
		
	cout  << "1.借书" << endl << "2.还书" << endl << "3.查询个人信息" << endl << "4.图书查询" << endl << "5.查看公告"<<endl<<"请输入你要进行的操作"<<endl;
	int us_order;
	cin >> us_order;
	if (us_order == 1)
	{
		string bo_book, bo_auther;
		cout << "请输入你要借阅的书名和作者" << endl;
		cin >> bo_book >> bo_auther;
		s->borrowbook(s,bo_book,bo_auther);
	}
	if (us_order == 2)
	{
		string re_book, re_auther;
		cout << "请输入你要归还的书名和作者" << endl;
		cin >> re_book >> re_auther;
		s->returnbook(s,re_book, re_auther);
	}
	if (us_order == 3)
	{
		cout << "ID: " << s->id << " " << "名字: " << s->name << " " << "密码: " << s->passsword << endl;
	}
	if (us_order == 4)
	{
		string se_book, se_auther;
		cout << "请输入你要查找的书名和作者" << endl;
		cin >> se_book >> se_auther;
		s->book_search(se_book, se_auther);
	}
	if (us_order == 5)
	{
		s->bulletin();
	}
}