#pragma once
#include <tuple>

class Transport
{
protected:
	int speed;
	int volume;
	double price;
	int distance;
public:
	Transport();
	~Transport();
	Transport(std::tuple<int, int, double>, int dist);
	double sumCost(int mass, int dist);
	double sumTime(int dist);
	int getDistance();
};
