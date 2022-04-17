#pragma once
#include "Strategy.h"
#include "CarFactory.h"
#include "CarFactory.cpp"
#include "Plane.h"
#include "PlaneFactory.h"
#include "TrainFactory.h"
#include"Info.h"

class Strategy7 : public Strategy
{
	CarFactory carFactory;
	TrainFactory trainFactory;
	PlaneFactory planeFactory;
public:
	Track createTrack(int* path, int volume) override
	{
		
		Car car1 = Car();
		//Transport* car1 = carFactory.create();
		for (auto it = Info::getInstance().table.begin(); it != Info::getInstance().table.end(); it++)
		{
			if ((*it).first.find(Info::getInstance().points[path[0]]))
			{
				car1 =Car(Info::getInstance().tableCost[(*it).second * 3 + 2], Info::getInstance().matrixDist[path[0]][path[1]]);
			}
		}

		Train train1 = Train();
		
		for (auto it = Info::getInstance().table.begin(); it != Info::getInstance().table.end(); it++)
		{
			if ((*it).first.find(Info::getInstance().points[path[1]]))
			{
				train1 = Train(Info::getInstance().tableCost[(*it).second * 3 + 1], Info::getInstance().matrixDist[path[1]][path[2]]);
			}
		}

		
		Car car2 = Car();
		//Transport* car2 = carFactory.create();
		for (auto it = Info::getInstance().table.begin(); it != Info::getInstance().table.end(); it++)
		{
			if ((*it).first.find(Info::getInstance().points[path[2]]))
			{
				car2 = Car(Info::getInstance().tableCost[(*it).second * 3 + 2], Info::getInstance().matrixDist[path[2]][path[3]]);
			}
		}

		
		Plane plane1 = Plane();
		//Transport* plane1 = planeFactory.create();
		for (auto it = Info::getInstance().table.begin(); it != Info::getInstance().table.end(); it++)
		{
			if ((*it).first.find(Info::getInstance().points[path[3]]))
			{
				plane1 = Plane(Info::getInstance().tableCost[(*it).second * 3], Info::getInstance().matrixDist[path[3]][path[4]]);
			}
		}

		
		Car car3 = Car();
		for (auto it = Info::getInstance().table.begin(); it != Info::getInstance().table.end(); it++)
		{
			if ((*it).first.find(Info::getInstance().points[path[4]]))
			{
				car3 = Car(Info::getInstance().tableCost[(*it).second * 3 + 2], Info::getInstance().matrixDist[path[4]][path[5]]);
			}
		}

		Train train2 = Train();
		
		for (auto it = Info::getInstance().table.begin(); it != Info::getInstance().table.end(); it++)
		{
			if ((*it).first.find(Info::getInstance().points[path[5]]))
			{
				train2 = Train(Info::getInstance().tableCost[(*it).second * 3 + 1], Info::getInstance().matrixDist[path[5]][path[6]]);
			}
		}

		
		Car car4 = Car();
		//Transport* car4 = carFactory.create();
		for (auto it = Info::getInstance().table.begin(); it != Info::getInstance().table.end(); it++)
		{
			if ((*it).first.find(Info::getInstance().points[path[6]]))
			{
				car4 = Car(Info::getInstance().tableCost[(*it).second * 3 + 2], Info::getInstance().matrixDist[path[6]][path[7]]);
			}
		}

		Track track = Track(car1, car2, car3, car4, train1, train2, plane1, volume);
		return track;
	}
};