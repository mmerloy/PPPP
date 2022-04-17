#pragma once
#include "Transport.h"
#include <tuple>

//Used Factory Method


__interface TransportFactory
{
public:
	virtual Transport* create() = 0;
	virtual Transport* create(std::tuple<int, int, double>, int dist) = 0;
};
//
//transportFactory.cpp
//#include "CarFactory.h";
//#include "Car.h";
//
//
//Transport* CarFactory::create() {
//
//	return new Car();
//}
//
//Transport* CarFactory::create(std::tuple<int, int, double> tuple, int dist) {
//
//	return new Car(tuple, dist);
//}
