#pragma once
#include "Transport.h"

class  Car : public Transport
{
public:
	Car();
	Car(std::tuple<int, int, double>, int);
	double sumCost(int mass, int dist);
	double sumTime(int dist);
	int getDistance();
};
