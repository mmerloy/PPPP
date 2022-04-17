#pragma once
#include "TransportFactory.h";

using namespace std;
class CarFactory : public TransportFactory
{
	
public:
	Transport* create() override;
	Transport* create(tuple<int, int, double>, int dist) override;
};