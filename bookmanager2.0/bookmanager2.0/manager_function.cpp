#include<iostream>
#include<string>
#include<Windows.h>
#include<fstream>
#include"class.h"
using namespace std;
void manager::add_book(string ad_name, string ad_auther)
{
	book* s, * p, * q;
	p = new book;
	p->auther = ad_auther;
	p->name = ad_name;
	s = get_book();
	q = s;
	while (s->next != NULL)
	{
		s = s->next;
	}
	s->next = p;
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
	cout << "��ӳɹ�" << endl;
}
void manager::delete_book(string dl_name, string dl_auther)
{
	book* us_book, * p = NULL, * q = NULL;
	us_book = get_book();
	if (us_book->name == dl_name && us_book->auther == dl_auther)
	{
		p = us_book;
		us_book = us_book->next;
		delete p;
	}
	else
	{
		for (q = us_book, p = us_book->next; p; q = p, p = p->next)
		{
			if (p->name == dl_name && p->auther == dl_auther)
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
	cout << "ɾ���ɹ�" << endl;
}
void manager::publish()
{
	std::ofstream file("D:\\����\\bookmanager2.0\\bookmanager2.0\\announce.txt", ios::out);

	if (file.is_open()) {
		cout << "�����빫�����ݣ����� Ctrl+Z �������룩��" << endl;

		std::string line;
		while (getline(cin, line)) {
			file << line << endl;
		}

		file.close();

		cout << "���淢���ɹ���" << endl;
	}
	else {
		cout << "�޷��򿪹����ļ���" << endl;
	}
}
void manager::punish()
{
	borrow_book* reader1;
	return_book* reader2,*reader3;
	reader1 = get_borrow();
	reader2 = get_return();
	ofstream out;    //�������������
	string filePath1 = "D:\\����\\bookmanager2.0\\bookmanager2.0\\punish list.txt";
	out.open(filePath1);    //���ļ�
	if (!out)
	{
		cout << "���ļ�ʧ��" << endl;
		exit(1);
	}
	while (reader1 != NULL)
	{
		reader2 = get_return();
		while (reader2 != NULL)
		{
			if (reader2->name == reader1->name)
			{
				if ((reader2->time - reader1->time) > 10)
				{
					

					out << reader1->name << endl;
					
				}
			}
			reader2 = reader2->next;
		}
		reader1 = reader1->next;
	}
	cout << "�ͷ�����������" << endl;
}
