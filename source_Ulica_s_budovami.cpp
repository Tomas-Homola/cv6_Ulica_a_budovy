#include <iostream>
#include <iomanip>
#include <string>

class FamilyHouse
{
protected:
	int number;
	int floors;
	int houseArea;
	int gardenArea;

public:
	FamilyHouse();
	FamilyHouse(int number, int floors, int houseArea, int gardenArea);

	// funkcie na vratenie premennych
	int getNumber() { return number; }
	int getNumOfFloors() { return floors; }
	int getHouseArea() { return houseArea; }
	int getGardenArea() { return gardenArea; }

	// funkcie na prepis premennych
	void changeNumber(int newNumber) { number = newNumber; }
	void changeNumOfFloors(int newNumOfFloors) { floors = newNumOfFloors; }
	void changeHouseArea(int newHouseArea) { houseArea = newHouseArea; }
	void changeGardenArea(int newGardenArea) { gardenArea = newGardenArea; }

	void printInfo();
};

FamilyHouse::FamilyHouse()
{
	number = -1;
	floors = -1;
	houseArea = -1;
	gardenArea = -1;
}

FamilyHouse::FamilyHouse(int number, int floors, int houseArea, int gardenArea)
{
	this->number = number;
	this->floors = floors;
	this->houseArea = houseArea;
	this->gardenArea = gardenArea;
}

void FamilyHouse::printInfo()
{
	std::cout << "Family house number: " << number << "\nNumber of floors: " << floors << "\nHouse area: " << houseArea << " m^2\nGarden area: " << gardenArea << " m^2" << std::endl;
}

//################################################################################//

class BlockOfFlats
{
protected:
	int number;
	int floors;
	int flats;

public:
	BlockOfFlats();
	BlockOfFlats(int number, int floors, int flats);

	// funkcie na vratenie premennych
	int getNumber() { return number; }
	int getNumOfFloors() { return floors; }
	int getNumOfFlats() { return flats; }

	// funkcie na prepis premennych
	void changeNumber(int newNumber) { number = newNumber; }
	void changeNumOfFloors(int newNumOfFloors) { floors = newNumOfFloors; }
	void changeNumOfFlats(int newNumOfFlats) { flats = newNumOfFlats; }

	void printInfo();
};

BlockOfFlats::BlockOfFlats()
{
	number = -1;
	floors = -1;
	flats = -1;
}

BlockOfFlats::BlockOfFlats(int number, int floors, int flats)
{
	this->number = number;
	this->floors = floors;
	this->flats = flats;
}

void BlockOfFlats::printInfo()
{
	std::cout << "Block of Flats number: " << number << "\nNumber of floors: " << floors << "\nNumber of flats: " << flats << std::endl;
}

//################################################################################//

class OfficeBuilding
{
protected:
	int number;
	int floors;
	int employees;
	double averageDailyTurnover;
	int departments;

public:
	OfficeBuilding();
	OfficeBuilding(int number, int floors, int employees, int averageDailyTurnover, int departments);

	// funkcie na vratenie premennych
	int getNumber() { return number; }
	int getNumOfFloors() { return floors; }
	int getNumOfEmployees() { return employees; }
	double getAverageDailyTurnover() { return averageDailyTurnover; }
	int getNumOfDepartments() { return departments; }

	// funkcie na prepis premennych
	void changeNumber(int newNumber) { number = newNumber; }
	void changeNumOfFloors(int newNumOfFloors) { floors = newNumOfFloors; }
	void changeNumOfEmployees(int newNumOfEmployees) { employees = newNumOfEmployees; }
	void changeAverageDailyTurnover(double newAverageDailyTurnover) { averageDailyTurnover = newAverageDailyTurnover; }
	void changeNumOfDepartments(int newNumOfDepartments) { departments = newNumOfDepartments; }

	void printInfo();
};

OfficeBuilding::OfficeBuilding()
{
	number = -1;
	floors = -1;
	employees = -1;
	averageDailyTurnover = 0.0;
	departments = -1;
}

OfficeBuilding::OfficeBuilding(int number, int floors, int employees, int averageDailyTurnover, int departments)
{
	this->number = number;
	this->floors = floors;
	this->employees = employees;
	this->averageDailyTurnover = averageDailyTurnover;
	this->departments = departments;
}

void OfficeBuilding::printInfo()
{
	std::cout << "Office building number: " << number << "\nNumber of floors: " << floors << "\nNumber of employees: " << employees << "\nAverage daily turnover: " << averageDailyTurnover << " EUR\nNumber of departments: " << departments << std::endl;
}

//################################################################################//

class Factory
{
protected:
	int number;
	int floors;
	int employees;
	double averageDailyTurnover;
	int areaOfProductionHall;

public:
	Factory();
	Factory(int number, int floors, int employees, double averageDailyTurnover, int areaOfProductionHall);

	// funkcie na vratenie premennych
	int getNumber() { return number; }
	int getNumOfFloors() { return floors; }
	int getNumOfEmployees() { return employees; }
	double getAverageDailyTurnover() { return averageDailyTurnover; }
	int getAreaOfProductionHall() { return areaOfProductionHall; }

	// funkcie na prepis premennych
	void changeNumber(int newNumber) { number = newNumber; }
	void changeNumOfFloors(int newNumOfFloors) { floors = newNumOfFloors; }
	void changeNumOfEmployees(int newNumOfEmployees) { employees = newNumOfEmployees; }
	void changeAverageDailyTurnover(double newAverageDailyTurnover) { averageDailyTurnover = newAverageDailyTurnover; }
	void changeAreaOfProductionHall(int newAreaOfProductionHall) { areaOfProductionHall = newAreaOfProductionHall; }

	void printInfo();
};

Factory::Factory()
{
	number = -1;
	floors = -1;
	employees = -1;
	averageDailyTurnover = 0.0;
	areaOfProductionHall = -1;
}

Factory::Factory(int number, int floors, int employees, double averageDailyTurnover, int areaOfProductionHall)
{
	this->number = number;
	this->floors = floors;
	this->employees = employees;
	this->averageDailyTurnover = averageDailyTurnover;
	this->areaOfProductionHall = areaOfProductionHall;
}

void Factory::printInfo()
{
	std::cout << "Factory number: " << number << "\nNumber of floors: " << floors << "\nNumber of employees: " << employees << "\nAverage daily turnover: " << averageDailyTurnover << " EUR\nArea of the production hall: " << areaOfProductionHall << " m^2" << std::endl;
}

//################################################################################//

class Street : public FamilyHouse, public BlockOfFlats, public OfficeBuilding, public Factory
{
private:
	std::string city;
	std::string streetName;

	int numOfFamilyHouses;
	int numOfBlocksOfFlats;
	int numOfOfficeBuildings;
	int numOfFactories;
	
	FamilyHouse* familyHouses;
	BlockOfFlats* blocksOfFlats;
	OfficeBuilding* officeBuildings;
	Factory* factories;

public:
	Street();
	Street(std::string city, std::string streetName);

	void generateBuildings();
	void printInfo();
};

Street::Street()
{
	city = "N/A";
	streetName = "N/A";

	familyHouses = nullptr;
	blocksOfFlats = nullptr;
	officeBuildings = nullptr;
	factories = nullptr;
}

Street::Street(std::string city, std::string streetName)
{
	this->city = city;
	this->streetName = streetName;

	familyHouses = nullptr;
	blocksOfFlats = nullptr;
	officeBuildings = nullptr;
	factories = nullptr;
}

void Street::generateBuildings()
{
	int temp = 0;

	// generovanie pre family houses
	temp = std::rand() % 20;
	if (temp != 0)
	{
		numOfFamilyHouses = temp;
		familyHouses = new FamilyHouse[numOfFamilyHouses];
	}
}

void Street::printInfo()
{
	std::cout << "Street name: " << streetName << "\nCity: " << city << "\nFollowing buildings are located on this street:" << std::endl;

	// vypis pre family houses
	if (familyHouses == nullptr)
		std::cout << "There are no family houses on this street" << std::endl;
	else
		for (int i = 0; i < numOfFamilyHouses; i++)
			familyHouses[i].printInfo();

	// vypis pre blocks of flats
	if (blocksOfFlats == nullptr)
		std::cout << "There are no blocks of flats on this street" << std::endl;
	else
		for (int i = 0; i < numOfBlocksOfFlats; i++)
			blocksOfFlats[i].printInfo();

	// vypis pre office buildings
	if (officeBuildings == nullptr)
		std::cout << "There are no office buildings on this street" << std::endl;
	else
		for (int i = 0; i < numOfOfficeBuildings; i++)
			officeBuildings[i].printInfo();

	// vypis pre factories
	if (factories == nullptr)
		std::cout << "There are no factories on this street" << std::endl;
	else
		for (int i = 0; i < numOfFactories; i++)
			factories[i].printInfo();
}
