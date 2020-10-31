#include <iostream>
#include <iomanip>
#include <string>

class FamilyHouse
{
private:
	int number;
	int numOfFloors;
	int houseArea;
	int gardenArea;

public:
	FamilyHouse();
	FamilyHouse(int number, int numOfFloors, int houseArea, int gardenArea);

	// funkcie na vratenie premennych
	int getNumber() { return number; }
	int getNumOfFloors() { return numOfFloors; }
	int getHouseArea() { return houseArea; }
	int getGardenArea() { return gardenArea; }

	// funkcie na prepis premennych
	void changeNumber(int newNumber) { number = newNumber; }
	void changeNumOfFloors(int newNumOfFloors) { numOfFloors = newNumOfFloors; }
	void changeHouseArea(int newHouseArea) { houseArea = newHouseArea; }
	void changeGardenArea(int newGardenArea) { gardenArea = newGardenArea; }

};

FamilyHouse::FamilyHouse()
{
	number = -1;
	numOfFloors = -1;
	houseArea = -1;
	gardenArea = -1;
}

FamilyHouse::FamilyHouse(int number, int numOfFloors, int houseArea, int gardenArea)
{
	this->number = number;
	this->numOfFloors = numOfFloors;
	this->houseArea = houseArea;
	this->gardenArea = gardenArea;
}

//################################################################################//

class BlockOfFlats
{
private:
	int number;
	int numOfFloors;
	int numOfFlats;

public:
	BlockOfFlats();
	BlockOfFlats(int number, int numOffFloors, int numOfFlats);

	// funkcie na vratenie premennych
	int getNumber() { return number; }
	int getNumOfFloors() { return numOfFloors; }
	int getNumOfFlats() { return numOfFlats; }

	// funkcie na prepis premennych
	void changeNumber(int newNumber) { number = newNumber; }
	void changeNumOfFloors(int newNumOfFloors) { numOfFloors = newNumOfFloors; }
	void changeNumOfFlats(int newNumOfFlats) { numOfFlats = newNumOfFlats; }
};

BlockOfFlats::BlockOfFlats()
{
	number = -1;
	numOfFloors = -1;
	numOfFlats = -1;
}

BlockOfFlats::BlockOfFlats(int number, int numOffFloors, int numOfFlats)
{
	this->number = number;
	this->numOfFloors = numOffFloors;
	this->numOfFlats = numOfFlats;
}

//################################################################################//

class OfficeBuilding
{
private:
	int number;
	int numOfFloors;
	int numOfEmployees;
	double averageDailyTurnover;
	int numOfDepartments;

public:
	OfficeBuilding();
	OfficeBuilding(int number, int numOfFloors, int numOfEmployees, int averageDailyTurnover, int numOfDepartments);

	// funkcie na vratenie premennych
	int getNumber() { return number; }
	int getNumOfFloors() { return numOfFloors; }
	int getNumOfEmployees() { return numOfEmployees; }
	double getAverageDailyTurnover() { return averageDailyTurnover; }
	int getNumOfDepartments() { return numOfDepartments; }

	// funkcie na prepis premennych
	void changeNumber(int newNumber) { number = newNumber; }
	void changeNumOfFloors(int newNumOfFloors) { numOfFloors = newNumOfFloors; }
	void changeNumOfEmployees(int newNumOfEmployees) { numOfEmployees = newNumOfEmployees; }
	void changeAverageDailyTurnover(double newAverageDailyTurnover) { averageDailyTurnover = newAverageDailyTurnover; }
	void changeNumOfDepartments(int newNumOfDepartments) { numOfDepartments = newNumOfDepartments; }
};

OfficeBuilding::OfficeBuilding()
{
	number = -1;
	numOfFloors = -1;
	numOfEmployees = -1;
	averageDailyTurnover = 0.0;
	numOfDepartments = -1;
}

OfficeBuilding::OfficeBuilding(int number, int numOfFloors, int numOfEmployees, int averageDailyTurnover, int numOfDepartments)
{
	this->number = number;
	this->numOfFloors = numOfFloors;
	this->numOfEmployees = numOfEmployees;
	this->averageDailyTurnover = averageDailyTurnover;
	this->numOfDepartments = numOfDepartments;
}

//################################################################################//

class Factory
{
private:
	int number;
	int numOfFloors;
	int numOfEmployees;
	double averageDailyTurnover;
	int areaOfProductionHall;

public:
	Factory();
	Factory(int number, int numOfFloors, int numOfEmployees, double averageDailyTurnover, int areaOfProductionHall);

	// funkcie na vratenie premennych
	int getNumber() { return number; }
	int getNumOfFloors() { return numOfFloors; }
	int getNumOfEmployees() { return numOfEmployees; }
	double getAverageDailyTurnover() { return averageDailyTurnover; }
	int getAreaOfProductionHall() { return areaOfProductionHall; }

	// funkcie na prepis premennych
	void changeNumber(int newNumber) { number = newNumber; }
	void changeNumOfFloors(int newNumOfFloors) { numOfFloors = newNumOfFloors; }
	void changeNumOfEmployees(int newNumOfEmployees) { numOfEmployees = newNumOfEmployees; }
	void changeAverageDailyTurnover(double newAverageDailyTurnover) { averageDailyTurnover = newAverageDailyTurnover; }
	void changeAreaOfProductionHall(int newAreaOfProductionHall) { areaOfProductionHall = newAreaOfProductionHall; }
};

Factory::Factory()
{
	number = -1;
	numOfFloors = -1;
	numOfEmployees = -1;
	averageDailyTurnover = 0.0;
	areaOfProductionHall = -1;
}

Factory::Factory(int number, int numOfFloors, int numOfEmployees, double averageDailyTurnover, int areaOfProductionHall)
{
	this->number = number;
	this->numOfFloors = numOfFloors;
	this->numOfEmployees = numOfEmployees;
	this->averageDailyTurnover = averageDailyTurnover;
	this->areaOfProductionHall = areaOfProductionHall;
}

//################################################################################//

class Street : public FamilyHouse, public BlockOfFlats, public OfficeBuilding, public Factory
{
private:
	std::string city;
	std::string streetName;
	int numOfBuildings;
	
	FamilyHouse* familyHouses;
	BlockOfFlats* blocksOfFlats;
	OfficeBuilding* officeBuildings;
	Factory* factories;

public:
	Street();
	Street(std::string city, std::string streetName, int numOfBuildings);
};

Street::Street()
{
	city = "N/A";
	streetName = "N/A";
	numOfBuildings = -1;

	familyHouses = nullptr;
}

Street::Street(std::string city, std::string streetName, int numOfBuildings)
{
}
