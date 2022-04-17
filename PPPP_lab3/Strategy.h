#pragma once
#include "Track.h"
#include <iostream>
#include <map>

//singleton??
__interface Strategy
{
public:
	virtual Track createTrack(int* path, int volume);
};

enum Type { Turbo, Standart, Economy };

class Context
{
	Strategy* strategy;
public:
	void setStrategy(Strategy* strategy)
	{
		this->strategy = strategy;
	}
	Track execStrategy(int* p, int v)
	{
		return this->strategy->createTrack(p, v);
	}
};

