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
	inf.open("D:\\����\\bookmanager2.0\\bookmanager2.0\\manager.txt");
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
	inf.open("D:\\����\\bookmanager2.0\\bookmanager2.0\\Borrowing records.txt");
	while (getline(inf, str))      //getline(inf,s)�����ж�ȡinf�е��ļ���Ϣ
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
	inf.open("D:\\����\\bookmanager2.0\\bookmanager2.0\\Return records.txt");
	while (getline(inf, str))      //getline(inf,s)�����ж�ȡinf�е��ļ���Ϣ
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
		cout << "�������û���" << endl;
		cin >> ma_name;
		while (s)
		{
			if (s->name == ma_name)
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
		std::string password;
		char ch;


		while ((ch = _getch()) != '\r') {  // ֱ������س�������ѭ��
			if (ch == '\b') {  // �����˸��
				if (!password.empty()) {
					std::cout << "\b \b";  // �����̨����˸���Ϳո񸲸�������ַ�
					password.pop_back();  // �������ַ�����ɾ�����һ���ַ�
				}
			}
			else {
				std::cout << '*';  // ��ʾ�Ǻ����ʵ��������ַ�
				password.push_back(ch);  // ��������ַ���ӵ������ַ�����
			}
		}
		ma_password = stoi(password, 0, 10);
		
		cout << endl;
		
		
		
		
		if (ma_password == s->passsword)
		{
			cout << "��½�ɹ�" << endl;
			break;
		}
		else
			cout << "�������" << endl;
	}
	cout << "1.���ͼ��" << endl << "2.ɾ��ͼ��" << endl << "3.�쳣���鴦��" << endl << "4.��������" << endl << "��������Ҫ���еĲ���" << endl;
	int ma_order;
	cin >> ma_order;
	if (ma_order == 1)
	{
		string ad_book, ad_auther;
		cout << "��������Ҫ����������������" << endl;
		cin >> ad_book >> ad_auther;
		s->add_book(ad_book,ad_auther);
	}
	if (ma_order == 2)
	{
		string dl_book, dl_auther;
		cout << "��������Ҫ����������������" << endl;
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