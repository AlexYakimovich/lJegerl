#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class alcoholicDrinks
{
public:
	virtual void Drink() = 0;
private:
	static vector<alcoholicDrinks*> v;
};

