#ifndef CONTACT_SYSTEM
#define CONTACT_SYSTEM
#include <string>
#include <vector>
using namespace std;
class  contact 
{
private:
	string name;
	string sex;
	int age=0;
	string phone;
public:
	contact(const string& n,const string& s,const int a,const string& p)
		:name(n),sex(s),age(a),phone(p){ }
	string getname() const{ return name; }
	string getsex() const { return sex; }
	int getage() const { return age; }
	string getphone() const { return phone; }

	void setname(const string& n) { name = n; }
	void setsex(const string& s) { sex=s ; }
	void setage(const int a) { age = a; }
	void setphone(const string& p) { phone = p; }

};
class contactsystem
{
private:
	vector<contact>contacts;
public:
	void showmenu()const;
	void add(const contact& contact);
	contact* search(const string& name);
	bool modify(const string& name,const contact& newinfo);
	bool deleteperson(const string& name);
	void showallperson()const;
	void clear();
	size_t size()const { return contacts.size(); };
};
#endif 