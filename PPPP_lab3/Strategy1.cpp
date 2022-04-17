#pragma once
#include "Strategy.h"
#include "CarFactory.h"
#include "CarFactory.cpp"
#include "Plane.h"
#include "PlaneFactory.h"
#include "TrainFactory.h"
#include "Transport.h"
#include "Order.h"
#include <vector>
#include "Info.h"


class Strategy1 : public Strategy
{
	CarFactory carFactory;
public:
	Track createTrack(int* path, int volume) override 
	{
		Car car1 = Car();
		for (auto it = Info::getInstance().table.begin(); it != Info::getInstance().table.end(); it++)
		{
			if ((*it).first.find(Info::getInstance().points[path[0]]))
			{
				car1 = Car(Info::getInstance().tableCost[(*it).second * 3 + 2], Info::getInstance().matrixDist[path[0]][path[1]]);
			}
		}

		Track track = Track( car1, volume);
		return track;
	}
};

