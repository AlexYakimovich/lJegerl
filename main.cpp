
#include <iostream>
#include "Person.h"
using namespace std;
int main()
{
	Person Eva("Eva", Gender::FEMALE);
	Person Adam("Adam", Gender::MALE);
	Person Sasha = Eva.giveBirth("Sasha", Gender::MALE);
	Person Jane = Eva.giveBirth("Jane", Gender::FEMALE);
	Person Yegor = Jane.giveBirth("Yegor", Gender::MALE,Sasha);
	Yegor.Print();
}

