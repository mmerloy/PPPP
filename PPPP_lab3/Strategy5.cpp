#include "Strategy.h"
#include "CarFactory.h"
#include "CarFactory.cpp"
#include "Plane.h"
#include "PlaneFactory.h"
#include "TrainFactory.h"
#include "Info.h"

class Strategy5 : public Strategy
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
				car1 = Car(Info::getInstance().tableCost[(*it).second * 3 + 2], Info::getInstance().matrixDist[path[0]][path[1]]);
			}
		}

		Train train1 = Train();
		Plane plane1 = Plane();
		for (auto it = Info::getInstance().table.begin(); it != Info::getInstance().table.end(); it++)
		{
			if ((*it).first.find(Info::getInstance().points[path[1]]) && Info::getInstance().points[path[1]].find("TS"))
			{
				train1 = Train(Info::getInstance().tableCost[(*it).second * 3 + 1], Info::getInstance().matrixDist[path[1]][path[2]]);
			}
			if ((*it).first.find(Info::getInstance().points[path[1]]) && Info::getInstance().points[path[1]].find("AP"))
			{
				plane1 = Plane(Info::getInstance().tableCost[(*it).second * 3], Info::getInstance().matrixDist[path[1]][path[2]]);
			}
		}

		Car car2= Car();
		//Transport* car2 = carFactory.create();
		for (auto it = Info::getInstance().table.begin(); it != Info::getInstance().table.end(); it++)
		{
			if ((*it).first.find(Info::getInstance().points[path[2]]))
			{
				car2 = Car(Info::getInstance().tableCost[(*it).second * 3 + 2], Info::getInstance().matrixDist[path[2]][path[3]]);
			}
		}

		for (auto it = Info::getInstance().table.begin(); it != Info::getInstance().table.end(); it++)
		{
			if ((*it).first.find(Info::getInstance().points[path[3]]) && Info::getInstance().points[path[3]].find("AP"))
			{
				plane1 = Plane(Info::getInstance().tableCost[(*it).second * 3], Info::getInstance().matrixDist[path[3]][path[4]]);
			}
			if ((*it).first.find(Info::getInstance().points[path[3]]) && Info::getInstance().points[path[3]].find("TS"))
			{
				train1 = Train(Info::getInstance().tableCost[(*it).second * 3 + 1], Info::getInstance().matrixDist[path[3]][path[4]]);
			}
		}

		Car car3 = Car();
		//Transport* car3 = carFactory.create();
		for (auto it = Info::getInstance().table.begin(); it != Info::getInstance().table.end(); it++)
		{
			if ((*it).first.find(Info::getInstance().points[path[4]]))
			{
				car3 = Car(Info::getInstance().tableCost[(*it).second * 3 + 2], Info::getInstance().matrixDist[path[4]][path[5]]);
			}
		}

		Track track = Track(car1, car2, car3, train1, plane1, volume);
		return track;

	}
};