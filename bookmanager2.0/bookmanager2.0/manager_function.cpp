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
	cout << "添加成功" << endl;
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
			cout << "抱歉查无此书" << endl;
			return;
		}
		else
		{
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
	cout << "删除成功" << endl;
}
void manager::publish()
{
	std::ofstream file("D:\\代码\\bookmanager2.0\\bookmanager2.0\\announce.txt", ios::out);

	if (file.is_open()) {
		cout << "请输入公告内容（输入 Ctrl+Z 结束输入）：" << endl;

		std::string line;
		while (getline(cin, line)) {
			file << line << endl;
		}

		file.close();

		cout << "公告发布成功！" << endl;
	}
	else {
		cout << "无法打开公告文件。" << endl;
	}
}
void manager::punish()
{
	borrow_book* reader1;
	return_book* reader2,*reader3;
	reader1 = get_borrow();
	reader2 = get_return();
	ofstream out;    //定义输出流对象
	string filePath1 = "D:\\代码\\bookmanager2.0\\bookmanager2.0\\punish list.txt";
	out.open(filePath1);    //打开文件
	if (!out)
	{
		cout << "打开文件失败" << endl;
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
	cout << "惩罚名单已生成" << endl;
}
