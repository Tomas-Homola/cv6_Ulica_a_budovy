#include <iostream>
#include <iomanip>
#include <string>

class FamilyHouse
{
protected:
	int number = 0;
	int floors = 0;
	int houseArea = 0;
	int gardenArea = 0;

public:
	FamilyHouse() {}
	FamilyHouse(int number, int floors, int houseArea, int gardenArea);
	~FamilyHouse() { std::cout << "destruktor family house\n"; }

	// funkcie na vratenie premennych
	int getNumber() { return number; }
	int getNumOfFloors() { return floors; }
	int getHouseArea() { return houseArea; }
	int getGardenArea() { return gardenArea; }

	// funkcie na prepis premennych
	void setNumber(int newNumber) { number = newNumber; }
	void setNumOfFloors(int newNumOfFloors) { floors = newNumOfFloors; }
	void setHouseArea(int newHouseArea) { houseArea = newHouseArea; }
	void setGardenArea(int newGardenArea) { gardenArea = newGardenArea; }

	void printInfo();
};

FamilyHouse::FamilyHouse(int number, int floors, int houseArea, int gardenArea)
{
	this->number = number;
	this->floors = floors;
	this->houseArea = houseArea;
	this->gardenArea = gardenArea;
}

void FamilyHouse::printInfo()
{
	std::cout << "Family house number: " << number << "\nNumber of floors: " << floors << "\nHouse area: " << houseArea << " m^2\nGarden area: " << gardenArea << " m^2\n" << std::endl;
}

//################################################################################//

class BlockOfFlats
{
protected:
	int number = 0;
	int floors = 0;
	int flats = 0;

public:
	BlockOfFlats() {}
	BlockOfFlats(int number, int floors, int flats);
	~BlockOfFlats() { std::cout << "destruktor blocks of flats\n"; }

	// funkcie na vratenie premennych
	int getNumber() { return number; }
	int getNumOfFloors() { return floors; }
	int getNumOfFlats() { return flats; }

	// funkcie na prepis premennych
	void setNumber(int newNumber) { number = newNumber; }
	void setNumOfFloors(int newNumOfFloors) { floors = newNumOfFloors; }
	void setNumOfFlats(int newNumOfFlats) { flats = newNumOfFlats; }

	void printInfo();
};

BlockOfFlats::BlockOfFlats(int number, int floors, int flats)
{
	this->number = number;
	this->floors = floors;
	this->flats = flats;
}


void BlockOfFlats::printInfo()
{
	std::cout << "Block of Flats number: " << number << "\nNumber of floors: " << floors << "\nNumber of flats: " << flats << std::endl << std::endl;
}

//################################################################################//

class OfficeBuilding
{
protected:
	int number = 0;
	int floors = 0;
	int employees = 0;
	int averageDailyTurnover = 0;
	int departments = 0;

public:
	OfficeBuilding() {}
	OfficeBuilding(int number, int floors, int employees, int averageDailyTurnover, int departments);
	~OfficeBuilding() { std::cout << "destruktor office building\n"; }

	// funkcie na vratenie premennych
	int getNumber() { return number; }
	int getNumOfFloors() { return floors; }
	int getNumOfEmployees() { return employees; }
	int getAverageDailyTurnover() { return averageDailyTurnover; }
	int getNumOfDepartments() { return departments; }

	// funkcie na prepis premennych
	void setNumber(int newNumber) { number = newNumber; }
	void setNumOfFloors(int newNumOfFloors) { floors = newNumOfFloors; }
	void setNumOfEmployees(int newNumOfEmployees) { employees = newNumOfEmployees; }
	void setAverageDailyTurnover(int newAverageDailyTurnover) { averageDailyTurnover = newAverageDailyTurnover; }
	void setNumOfDepartments(int newNumOfDepartments) { departments = newNumOfDepartments; }

	void printInfo();
};

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
	std::cout << "Office building number: " << number << "\nNumber of floors: " << floors << "\nNumber of employees: " << employees << "\nAverage daily turnover: " << averageDailyTurnover << " EUR\nNumber of departments: " << departments << "\n\n";
}

//################################################################################//

class Factory
{
protected:
	int number = 0;
	int floors = 0;
	int employees = 0;
	int averageDailyTurnover = 0;
	int areaOfProductionHall = 0;

public:
	Factory() {}
	Factory(int number, int floors, int employees, int averageDailyTurnover, int areaOfProductionHall);
	~Factory() { std::cout << "destruktor factory\n"; }

	// funkcie na vratenie premennych
	int getNumber() { return number; }
	int getNumOfFloors() { return floors; }
	int getNumOfEmployees() { return employees; }
	int getAverageDailyTurnover() { return averageDailyTurnover; }
	int getAreaOfProductionHall() { return areaOfProductionHall; }

	// funkcie na prepis premennych
	void setNumber(int newNumber) { number = newNumber; }
	void setNumOfFloors(int newNumOfFloors) { floors = newNumOfFloors; }
	void setNumOfEmployees(int newNumOfEmployees) { employees = newNumOfEmployees; }
	void setAverageDailyTurnover(int newAverageDailyTurnover) { averageDailyTurnover = newAverageDailyTurnover; }
	void setAreaOfProductionHall(int newAreaOfProductionHall) { areaOfProductionHall = newAreaOfProductionHall; }

	void printInfo();
};

Factory::Factory(int number, int floors, int employees, int averageDailyTurnover, int areaOfProductionHall)
{
	this->number = number;
	this->floors = floors;
	this->employees = employees;
	this->averageDailyTurnover = averageDailyTurnover;
	this->areaOfProductionHall = areaOfProductionHall;
}

void Factory::printInfo()
{
	std::cout << "Factory number: " << number << "\nNumber of floors: " << floors << "\nNumber of employees: " << employees << "\nAverage daily turnover: " << averageDailyTurnover << " EUR\nArea of the production hall: " << areaOfProductionHall << " m^2\n" << std::endl;
}

//################################################################################//

class Street : public FamilyHouse, public BlockOfFlats, public OfficeBuilding, public Factory
{
protected:
	std::string city;
	std::string streetName;

	int numOfFamilyHouses;
	int numOfBlocksOfFlats;
	int numOfOfficeBuildings;
	int numOfFactories;
	
	Street** familyHouses;
	Street** blocksOfFlats;
	Street** officeBuildings;
	Street** factories;

public:
	Street(std::string city, std::string streetName);
	~Street();

	void generateBuildings();
	void printInfo();
};

Street::Street(std::string city, std::string streetName)
{
	this->city = city;
	this->streetName = streetName;

	familyHouses = NULL;
	blocksOfFlats = NULL;
	officeBuildings = NULL;
	factories = NULL;
}

Street::~Street()
{
	for (int i = 0; i < numOfFamilyHouses; i++)
		delete familyHouses[i];
	
	delete[] familyHouses;

	for (int i = 0; i < numOfBlocksOfFlats; i++)
		delete blocksOfFlats[i];

	delete[] familyHouses;

	for (int i = 0; i < numOfOfficeBuildings; i++)
		delete officeBuildings[i];

	delete[] officeBuildings;

	for (int i = 0; i < numOfFactories; i++)
		delete factories[i];
	
	delete[] factories;
}

void Street::generateBuildings()
{


	
}

void Street::printInfo()
{
	std::cout << "Street name: " << streetName << "\nCity: " << city << "\n\nFollowing buildings are located on this street:\n\n";

	
}


int main()
{
	srand((unsigned)time(0));

	Street ulica("Bratislava", "Racianska");

	//ulica.printInfo();
	
	ulica.generateBuildings();
	ulica.printInfo();

	

	return 0;
}