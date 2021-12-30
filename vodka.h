#pragma once
#include "alcoholicDrinks.h"
class vodka : public alcoholicDrinks
{
public:
	void Drink();
	void SetVolume(double _volume);
	double GetVolume() const;
private:
	double volume;
};

