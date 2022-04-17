#pragma once
#include "Transport.h"
#include "TransportFactory.h"
#include "Plane.h"
#include "Car.h"
#include "Train.h"
#include "Track.h"
#include "Strategy.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <map>
#include <tuple>


enum Type { Turbo, Standart, Economy };
class Order
{
	double cost;
	int volume;
	std::string startPoint;
	std::string finishPoint;
	enum::Type type;
	Track track;

public:
	Order();
	Order(Type, std::string, std::string, int);
	//~Order();
	int decr(std::string);
	int** matrixUpd(Type);
	int* optim(int**, int, int);
	Track best(std::string, std::string, Type, int);
};
