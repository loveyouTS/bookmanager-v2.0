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

	//�����ʱ�����Ĵ�С
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

	//�����ʱ�����Ĵ�С
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
	inf.open("D:\\����\\bookmanager2.0\\bookmanager2.0\\user.txt");
	while (getline(inf, str))      //getline(inf,s)�����ж�ȡinf�е��ļ���Ϣ
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
	inf.open("D:\\����\\bookmanager2.0\\bookmanager2.0\\book.txt");
	while (getline(inf, str))      //getline(inf,s)�����ж�ȡinf�е��ļ���Ϣ
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
		cout << "�������û���" << endl;
		cin >> us_name;
		while (s)
		{
			if (s->name == us_name)
				break;
		}

		if (s == NULL)
			cout << "���û�������" << endl;
		else
			break;

	}
	while (1)
	{
		cout << "����������" << endl;
		cin >> us_password;
		if (us_password == s->passsword)
		{
			cout << "��½�ɹ�"<<endl;
			break;
		}
		else
			cout << "�������" << endl;
	}
		
		
	cout  << "1.����" << endl << "2.����" << endl << "3.��ѯ������Ϣ" << endl << "4.ͼ���ѯ" << endl << "5.�鿴����"<<endl<<"��������Ҫ���еĲ���"<<endl;
	int us_order;
	cin >> us_order;
	if (us_order == 1)
	{
		string bo_book, bo_auther;
		cout << "��������Ҫ���ĵ�����������" << endl;
		cin >> bo_book >> bo_auther;
		s->borrowbook(s,bo_book,bo_auther);
	}
	if (us_order == 2)
	{
		string re_book, re_auther;
		cout << "��������Ҫ�黹������������" << endl;
		cin >> re_book >> re_auther;
		s->returnbook(s,re_book, re_auther);
	}
	if (us_order == 3)
	{
		cout << "ID: " << s->id << " " << "����: " << s->name << " " << "����: " << s->passsword << endl;
	}
	if (us_order == 4)
	{
		string se_book, se_auther;
		cout << "��������Ҫ���ҵ�����������" << endl;
		cin >> se_book >> se_auther;
		s->book_search(se_book, se_auther);
	}
	if (us_order == 5)
	{
		s->bulletin();
	}
}