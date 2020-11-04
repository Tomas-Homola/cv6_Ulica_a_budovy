#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Building
{
protected:
	int number;
	int floors;

public:
	Building() { number = 0; floors = 0; } // default hodnoty nastavene na 0 -> este neboli nijako nastavene
	Building(int number, int floors) { this->number = number; this->floors = floors; } // konstruktor pre konkretne hodnoty
	~Building() {}

	// funkcie na ziskanie premennych
	int getNumber() { return number; }
	int getFloors() { return floors; }

	// funkcie na zmenu premennych
	void setNumber(int newNumber) { this->number = newNumber; }
	void setFloors(int newFloors) { this->floors = newFloors; }

	virtual void printInfo() {}
};

//################################################################################//

class FamilyHouse : public Building
{
private:
	int houseArea;
	int gardenArea;

public:
	FamilyHouse() : Building(0, 0) { this->houseArea = 0; this->gardenArea = 0; } // funkcie setNumber() a setFloors() su zdedene z triedy Building
	FamilyHouse(int number, int floors, int houseArea, int gardenArea) : Building(0, 0) { this->houseArea = houseArea; this->gardenArea = gardenArea; }
	~FamilyHouse() {}//{ std::cout << "destruktor family house\n"; }

	// funkcie na vratenie premennych
	int getHouseArea() { return houseArea; }
	int getGardenArea() { return gardenArea; }

	// funkcie na prepis premennych
	void setHouseArea(int newHouseArea) { houseArea = newHouseArea; }
	void setGardenArea(int newGardenArea) { gardenArea = newGardenArea; }

	void printInfo();
};

void FamilyHouse::printInfo()
{
	cout << "Family house number: " << number << ", Floors: " << floors << ", House area: " << houseArea << " m^2, Garden area: " << gardenArea << " m^2" << endl;
}

//################################################################################//

class BlockOfFlats : public Building
{
protected:
	int flats;

public:
	BlockOfFlats() : Building(0, 0) { this->flats = 0; }
	BlockOfFlats(int number, int floors, int flats) : Building(number, floors) { this->flats = flats; }
	~BlockOfFlats() {}

	// funkcie na vratenie premennych
	int getNumOfFlats() { return flats; }

	// funkcie na prepis premennych
	void setNumOfFlats(int newNumOfFlats) { flats = newNumOfFlats; }

	void printInfo();
};

void BlockOfFlats::printInfo()
{
	cout << "Block of flats number: " << number << ", Floors: " << floors << ", Flats: " << flats << endl;
}

//################################################################################//

class OfficeBuilding : public Building
{
protected:
	int employees;
	int averageDailyTurnover;
	int departments;

public:
	OfficeBuilding() : Building(0, 0) { this->employees = 0; this->averageDailyTurnover = 0; this->departments = 0; }
	OfficeBuilding(int number, int floors, int employees, int averageDailyTurnover, int departments) : Building(number, floors) { this->employees = employees; this->averageDailyTurnover = averageDailyTurnover; this->departments = departments; }
	~OfficeBuilding() {}//{ std::cout << "destruktor office building\n"; }

	// funkcie na vratenie premennych
	int getEmployees() { return employees; }
	int getAverageDailyTurnover() { return averageDailyTurnover; }
	int getDepartments() { return departments; }

	// funkcie na prepis premennych
	void setEmployees(int newEmployees) { employees = newEmployees; }
	void setAverageDailyTurnover(int newAverageDailyTurnover) { averageDailyTurnover = newAverageDailyTurnover; }
	void setDepartments(int newDepartments) { departments = newDepartments; }

	void printInfo();
};

void OfficeBuilding::printInfo()
{
	cout << "Office building number: " << number << ", Floors: " << floors << ", Employees: " << employees << ", Average daily turnover: " << averageDailyTurnover << " EUR, Departments: " << departments << endl;
}

//################################################################################//

class Factory : public Building
{
protected:
	int employees;
	int averageDailyTurnover;
	int areaOfProductionHall;

public:
	Factory() : Building(0, 0) { this->employees = 0; this->averageDailyTurnover = 0; this->areaOfProductionHall = 0; }
	Factory(int number, int floors, int employees, int averageDailyTurnover, int areaOfProductionHall) : Building(number, floors) { this->employees = employees; this->averageDailyTurnover = averageDailyTurnover; this->areaOfProductionHall = areaOfProductionHall; }
	~Factory() {}//{ std::cout << "destruktor factory\n"; }

	// funkcie na vratenie premennych
	int getEmployees() { return employees; }
	int getAverageDailyTurnover() { return averageDailyTurnover; }
	int getAreaOfProductionHall() { return areaOfProductionHall; }

	// funkcie na prepis premennych
	void setEmployees(int newNumOfEmployees) { employees = newNumOfEmployees; }
	void setAverageDailyTurnover(int newAverageDailyTurnover) { averageDailyTurnover = newAverageDailyTurnover; }
	void setAreaOfProductionHall(int newAreaOfProductionHall) { areaOfProductionHall = newAreaOfProductionHall; }

	void printInfo();
};

void Factory::printInfo()
{
	cout << "Factory number: " << number << ", Floors: " << floors << ", Employees: " << employees << ", Average daily turnover: " << averageDailyTurnover << ", Area of production hall: " << areaOfProductionHall << endl;
}

//################################################################################//

class Street
{
private:
	string streetName = "";
	string cityName = "";

	int numOfFamilyHouses = 0;
	int numOfBlocksOfFlats = 0;
	int numOfOfficeBuildings = 0;
	int numOfFactories = 0;

public:
	Street() {};
	Street(string streetName, string cityName);

	Building** familyHouses = nullptr;
	Building** blocksOfFlats = nullptr;
	Building** officeBuildings = nullptr;
	Building** factories = nullptr;
};

Street::Street(string streetName, string cityName)
{
	this->streetName = streetName;
	this->cityName = cityName;
}