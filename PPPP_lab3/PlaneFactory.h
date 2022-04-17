#pragma once
#include "TransportFactory.h";

class PlaneFactory : public TransportFactory
{
public:
	Transport* create() override;
	Transport* create(std::tuple<int, int, double>, int dist) override;
};