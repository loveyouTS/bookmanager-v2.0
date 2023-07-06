#include<iostream>
using namespace std;
class book
{
public:
	string name;
	string auther;
	int time;
	book* next;
};
class user
{
public:
	string name;
	int id;
	int passsword;
	void borrowbook(user*u,string name1, string auther1);
	void returnbook(user*,string, string);
	void personal();
	void book_search(string name3, string auther3);
	void bulletin();
	friend ostream& operator>>(ostream&, user a);
	user* next;
};
class manager
{
public:
	string name;
	int id;
	int passsword;
	void add_book(string, string);
	void delete_book(string name1, string auther1);
	void punish();
	void publish();
	manager* next;
};
class supermanager
{
	string name;
	int id;
	int passsword;
	void change_password1();
	void change_user(int, string, int);
	void change_manager(int, string, int);
	supermanager* next;
};
class borrow_book
{
public:
	string name,bk_name,bk_auther;
	int time;
	borrow_book* next;
};
class return_book
{
public:
	string name, bk_name, bk_auther;
	int time;
	return_book* next;
};
void user_login();
void manager_login();
void super_manager_login();
string UTF8ToGB(const char* str);
book* get_book();
user* get_user();
borrow_book* get_borrow();
return_book* get_return();