#pragma once
#include <iostream>
#include <vector>
#include <exception>

using namespace std;
enum class Gender
{
	MALE,
	FEMALE
};

class Person
{
public:
	Person(const string&, Gender, Person = Person(), Person = Person());
	string getName() const;
	Person giveBirth(const string&, Gender, Person = Person());
	string getGender() const;
	int getid() const;
	void Print() const;
	static vector<Person> v;
private:
	Person();
	Gender gender;
	string aname;
	int m_id = -1;
	int f_id = -1;
	int id;
};

