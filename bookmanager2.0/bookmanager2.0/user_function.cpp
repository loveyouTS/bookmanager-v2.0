#include<iostream>
#include<string>
#include<Windows.h>
#include<fstream>
#include"class.h"
#include<ctime>
using namespace std;
ostream& operator>>(ostream&, user a)
{
	cout << "ID:" << a.id << " " << "姓名:" << a.name << " " << "密码:" << a.passsword << endl;
	return cout;
}
void user::borrowbook(user*u,string br_name, string br_auther)
{
	book* us_book,*p=NULL,*q=NULL;
	us_book = get_book();
	if (us_book->name == br_name && us_book->auther == br_auther)
	{
		p = us_book;
		ofstream out;    //定义输出流对象
		string filePath1 = "D:\\代码\\bookmanager2.0\\bookmanager2.0\\Borrowing records.txt";
		out.open(filePath1);    //打开文件
		if (!out)
		{
			cout << "打开文件失败" << endl;
			exit(1);
		}

		//向文件中写入数据
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
			cout << "抱歉查无此书" << endl;
			return;
		}
		else
		{
			
			ofstream out;    //定义输出流对象
			string filePath1 = "D:\\代码\\bookmanager2.0\\bookmanager2.0\\Borrowing records.txt";
			out.open(filePath1);    //打开文件
			if (!out)
			{
				cout << "打开文件失败" << endl;
				exit(1);
			}

			//向文件中写入数据
			out  << u->name << endl << p->auther << endl << p->name << endl << time(nullptr) << endl;
			q->next = p->next;
			delete p;
		}
	}
	ofstream outfile;    //定义输出流对象
	string filePath = "D:\\代码\\bookmanager2.0\\bookmanager2.0\\book.txt";
	outfile.open(filePath);    //打开文件
	if (!outfile)
	{
		cout << "打开文件失败" << endl;
		exit(1);
	}

	//向文件中写入数据
	while (us_book)
	{
		outfile << us_book->auther << endl << us_book->name << endl;
		us_book = us_book->next;
	}
	
		
	cout << "借阅成功" << endl;
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
	ofstream out;    //定义输出流对象
	string filePath1 = "D:\\代码\\bookmanager2.0\\bookmanager2.0\\Return records.txt";
	out.open(filePath1);    //打开文件
	if (!out)
	{
		cout << "打开文件失败" << endl;
		exit(1);
	}

	//向文件中写入数据
	out << u->name << endl << p->auther << endl << p->name << endl << time(nullptr) << endl;
	ofstream outfile;    //定义输出流对象
	string filePath = "D:\\代码\\bookmanager2.0\\bookmanager2.0\\book.txt";
	outfile.open(filePath);    //打开文件
	if (!outfile)
	{
		cout << "打开文件失败" << endl;
		exit(1);
	}

	//向文件中写入数据
	while (q)
	{
		outfile << q->auther << endl << q->name << endl;
		q = q->next;
	}
	cout << "归还成功" << endl;
}
void user::book_search(string se_name, string se_auther)
{
	book* s;
	s = get_book();
	while (s)
	{
		if (s->name == se_name && s->auther == se_auther)
		{
			cout << "本馆有此藏书" << endl;
			break;
		}
		s = s->next;
	}
	if (s == NULL)
		cout << "抱歉本馆没有此书" << endl;
}
void user::bulletin()
{
	ifstream file("D:\\代码\\bookmanager2.0\\bookmanager2.0\\announce.txt");

	if (file.is_open()) {
		string line;

		cout << "最新公告内容：" << endl;

		while (getline(file, line)) {
			cout << line << endl;
		}

		file.close();
	}
	else {
		std::cout << "无法打开公告文件。" << std::endl;
	}
}

