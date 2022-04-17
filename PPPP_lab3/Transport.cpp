#include "Transport.h"


Transport::Transport(std::tuple<int, int, double> tuple, int dist)
{
	this->price = std::get<0>(tuple);
	this->speed = std::get<1>(tuple);
	this->volume = std::get<2>(tuple);
	this->distance = dist;
}


double Transport::sumCost(int mass, int dist)
{
	return (mass / volume) * sumTime(dist) * price;
}

double Transport::sumTime(int dist)
{
	return dist / speed;
}

int Transport::getDistance()
{
	return this->distance;
}