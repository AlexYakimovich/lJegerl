#include "vodka.h"
#include <iostream>
using namespace std;
void vodka::Drink()
{
	cout << "Beluga" << endl;
}
void vodka::SetVolume(double _volume)
{ 
	volume = _volume; 
};
double vodka::GetVolume()  const
{
	return volume; 
}