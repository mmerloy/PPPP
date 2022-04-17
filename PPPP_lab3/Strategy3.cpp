#include "Strategy.h"
#include "CarFactory.h"
#include "CarFactory.cpp"
#include "Plane.h"
#include "PlaneFactory.h"
#include "TrainFactory.h"
#include "Info.h"

class Strategy3 : public Strategy
{
	CarFactory carFactory;
	TrainFactory trainFactory;
	PlaneFactory planeFactory;

public:
	Track createTrack(int* path, int volume) override {

		Car car1 = Car();
		//Transport* car1 = carFactory.create();
		for (auto it = Info::getInstance().table.begin(); it != Info::getInstance().table.end(); it++)
		{
			if ((*it).first.find(Info::getInstance().points[path[0]]))
			{
				car1 = Car(Info::getInstance().tableCost[(*it).second * 3 + 2], Info::getInstance().matrixDist[path[0]][path[1]]);
			}
		}

		Car car2 = Car();
		for (auto it = Info::getInstance().table.begin(); it != Info::getInstance().table.end(); it++)
		{
			if ((*it).first.find(Info::getInstance().points[path[2]]))
			{
				car2 = Car(Info::getInstance().tableCost[(*it).second * 3 + 2], Info::getInstance().matrixDist[path[2]][path[3]]);
			}
		}

		Train train1 = Train();
		Plane plane1 = Plane();
		//Transport* train1 = trainFactory.create();
		//Transport* plane1 = planeFactory.create();
		Track track = Track();

		for (auto it = Info::getInstance().table.begin(); it != Info::getInstance().table.end(); it++)
		{
			if ((*it).first.find(Info::getInstance().points[path[1]]) && Info::getInstance().points[path[1]].find("TS"))
			{
				train1 = Train(Info::getInstance().tableCost[(*it).second * 3 + 1], Info::getInstance().matrixDist[path[1]][path[2]]);
				track = Track(car1, car2, train1, volume);
			}

			if ((*it).first.find(Info::getInstance().points[path[1]]) && Info::getInstance().points[path[1]].find("AP"))
			{
				plane1 = Plane(Info::getInstance().tableCost[(*it).second * 3], Info::getInstance().matrixDist[path[1]][path[2]]);
				track = Track(car1, car2, plane1, volume);
			}
		}
		return track;
	}
};
