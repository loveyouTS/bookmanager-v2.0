#include<iostream>
#include<string>
#include<Windows.h>
#include<fstream>
#include"class.h"
#include<ctime>
using namespace std;
ostream& operator>>(ostream&, user a)
{
	cout << "ID:" << a.id << " " << "����:" << a.name << " " << "����:" << a.passsword << endl;
	return cout;
}
void user::borrowbook(user*u,string br_name, string br_auther)
{
	book* us_book,*p=NULL,*q=NULL;
	us_book = get_book();
	if (us_book->name == br_name && us_book->auther == br_auther)
	{
		p = us_book;
		ofstream out;    //�������������
		string filePath1 = "D:\\����\\bookmanager2.0\\bookmanager2.0\\Borrowing records.txt";
		out.open(filePath1);    //���ļ�
		if (!out)
		{
			cout << "���ļ�ʧ��" << endl;
			exit(1);
		}

		//���ļ���д������
		out <<  u->name << endl << p->auther << endl << p->name << endl << time(nullptr) << endl;
		us_book = us_book->next;
		delete p;
	}
	else
	{
		for (q = us_book, p = us_book->next; p; q = p, p = p->next)
		{
			if (p->name == br_name && p->auther == br_auther)
			{
				break;
			}
		}
		if (p == NULL)
		{
			cout << "��Ǹ���޴���" << endl;
			return;
		}
		else
		{
			
			ofstream out;    //�������������
			string filePath1 = "D:\\����\\bookmanager2.0\\bookmanager2.0\\Borrowing records.txt";
			out.open(filePath1);    //���ļ�
			if (!out)
			{
				cout << "���ļ�ʧ��" << endl;
				exit(1);
			}

			//���ļ���д������
			out  << u->name << endl << p->auther << endl << p->name << endl << time(nullptr) << endl;
			q->next = p->next;
			delete p;
		}
	}
	ofstream outfile;    //�������������
	string filePath = "D:\\����\\bookmanager2.0\\bookmanager2.0\\book.txt";
	outfile.open(filePath);    //���ļ�
	if (!outfile)
	{
		cout << "���ļ�ʧ��" << endl;
		exit(1);
	}

	//���ļ���д������
	while (us_book)
	{
		outfile << us_book->auther << endl << us_book->name << endl;
		us_book = us_book->next;
	}
	
		
	cout << "���ĳɹ�" << endl;
}
void user::returnbook(user*u,string re_name, string re_auther)
{
	book* s,*p,*q;
	p = new book;
	p->auther = re_auther;
	p->name = re_name;
	s = get_book();
	q = s;
	while (s->next != NULL)
	{
		s = s->next;
	}
	s->next = p;
	ofstream out;    //�������������
	string filePath1 = "D:\\����\\bookmanager2.0\\bookmanager2.0\\Return records.txt";
	out.open(filePath1);    //���ļ�
	if (!out)
	{
		cout << "���ļ�ʧ��" << endl;
		exit(1);
	}

	//���ļ���д������
	out << u->name << endl << p->auther << endl << p->name << endl << time(nullptr) << endl;
	ofstream outfile;    //�������������
	string filePath = "D:\\����\\bookmanager2.0\\bookmanager2.0\\book.txt";
	outfile.open(filePath);    //���ļ�
	if (!outfile)
	{
		cout << "���ļ�ʧ��" << endl;
		exit(1);
	}

	//���ļ���д������
	while (q)
	{
		outfile << q->auther << endl << q->name << endl;
		q = q->next;
	}
	cout << "�黹�ɹ�" << endl;
}
void user::book_search(string se_name, string se_auther)
{
	book* s;
	s = get_book();
	while (s)
	{
		if (s->name == se_name && s->auther == se_auther)
		{
			cout << "�����д˲���" << endl;
			break;
		}
		s = s->next;
	}
	if (s == NULL)
		cout << "��Ǹ����û�д���" << endl;
}
void user::bulletin()
{
	ifstream file("D:\\����\\bookmanager2.0\\bookmanager2.0\\announce.txt");

	if (file.is_open()) {
		string line;

		cout << "���¹������ݣ�" << endl;

		while (getline(file, line)) {
			cout << line << endl;
		}

		file.close();
	}
	else {
		std::cout << "�޷��򿪹����ļ���" << std::endl;
	}
}

