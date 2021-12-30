#include "Person.h"
#include <iostream>
using namespace std;

string Person::getName() const 
{
	return aname;
}
string Person::getGender() const 
{
	if (this->gender == Gender::MALE) 
	{
		return "male";
	}
	else 
	{
		return "female";
	}
}

vector<Person> Person::v = vector<Person>();

Person::Person() 
{
	id = -1;
}
Person::Person(const string& name, Gender gen, Person mother, Person father) 
{
	aname = name;
	gender = gen;
	f_id = father.id;
	m_id = mother.id;
	id = v.size();
	v.push_back(*this);
	if (m_id == -1 && name != "Adam" && name != "Eva") 
	{
		cout << "Only Adam and Eva haven't got mother";
	}
	if (m_id != -1 && v[m_id].gender != Gender::FEMALE) 
	{
		cout << "Mother must be female";
	}
	if (f_id != -1 && v[f_id].gender != Gender::MALE) 
	{
		cout << "Father must be male";
	}
}

Person Person::giveBirth(const string& name, Gender gen, Person father) 
{
	string babyname = " ";
	babyname = name;

	auto baby = Person(babyname, gen, *this, father);
	return baby;
}
int Person::getid() const 
{
	return id;
}
void Person::Print() const
{
	cout << getName() << " - " << getGender();
}
