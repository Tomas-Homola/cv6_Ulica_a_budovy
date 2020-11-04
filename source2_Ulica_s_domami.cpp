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
	FamilyHouse(int number, int floors, int houseArea, int gardenArea) : Building(number, floors) { this->houseArea = houseArea; this->gardenArea = gardenArea; }
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

	FamilyHouse** familyHouses = nullptr;
	BlockOfFlats** blocksOfFlats = nullptr;
	OfficeBuilding** officeBuildings = nullptr;
	Factory** factories = nullptr;


	string getStreetName() { return streetName; }
	string getCityName() { return cityName; }

	void setStreetName(string newStreetName) { this->streetName = newStreetName; }
	void setCityName(string newCityName) { this->cityName = newCityName; }

	void generateBuildings();
	void printInfo();
};

Street::Street(string streetName, string cityName)
{
	this->streetName = streetName;
	this->cityName = cityName;
}

void Street::generateBuildings()
{
	int tempFloors = 0, tempEmplyees = 0;

	numOfFamilyHouses = rand() % 16 + 5; // 5-20
	numOfBlocksOfFlats = rand() % 8 + 3; // 3-10
	numOfOfficeBuildings = rand() % 5 + 2; // 2-6
	numOfFactories = rand() % 3 + 1; // 1-3

	familyHouses = new FamilyHouse * [numOfFamilyHouses];
	blocksOfFlats = new BlockOfFlats * [numOfBlocksOfFlats];
	officeBuildings = new OfficeBuilding * [numOfOfficeBuildings];
	factories = new Factory * [numOfFactories];

	for (int i = 0; i < numOfFamilyHouses; i++)
	{
		familyHouses[i] = new FamilyHouse(i + 7001, rand() % 2 + 1, rand() % 101 + 50, rand() % 101 + 100);
	}

	for (int i = 0; i < numOfBlocksOfFlats; i++)
	{
		tempFloors = rand() % 13 + 3; // pomocna premenna, kde bude ulozeny pocet poschodi a to sa potom pouzije na vypocet celkoveho poctu bytov v block of flats
		blocksOfFlats[i] = new BlockOfFlats(i + 7101, tempFloors, tempFloors * (rand() % 4 + 1)); // floors: 3-15, flats: 1-4
	}

	for (int i = 0; i < numOfOfficeBuildings; i++)
	{
		tempFloors = rand() % 20 + 1; // floors: 1-20
		tempEmplyees = tempFloors * (rand() % 16 + 10); // employees: 10-25 na poschodie krat pocet poschodi
		officeBuildings[i] = new OfficeBuilding(i + 7201, tempFloors, tempEmplyees, tempEmplyees * (rand() % 1000 + 100), rand() % 6 + 1); // departments: 1-6
	}

	for (int i = 0; i < numOfFactories; i++)
	{
		tempFloors = rand() % 2 + 1; // floors: 1-2
		tempEmplyees = tempFloors * (rand() % 501 + 200); // employees: 200-700
		factories[i] = new Factory(i + 7501, tempFloors, tempEmplyees, tempEmplyees * (rand() % 101 + 60), rand() % 3001 + 500); // area of production hall: 500-3500
	}

	cout << "Generating successfull" << endl;
}

void Street::printInfo()
{
	cout << "STREET NAME: " << streetName << "\nCITY: " << cityName << "\n\nFollowing buildings are located on this street:\n\n";

	if (familyHouses != nullptr) // ak by to nebolo alokovane, tak nevypise nic
	{
		cout << "FAMILY HOUSES:\n";
		for (int i = 0; i < numOfFamilyHouses; i++)
			familyHouses[i]->printInfo();
	}

	if (blocksOfFlats != nullptr)
	{
		cout << "\nBLOCKS OF FLATS:\n";
		for (int i = 0; i < numOfBlocksOfFlats; i++)
			blocksOfFlats[i]->printInfo();
	}

	if (officeBuildings != nullptr)
	{
		cout << "\nOFFICE BUILDINGS:\n";
		for (int i = 0; i < numOfOfficeBuildings; i++)
			officeBuildings[i]->printInfo();
	}

	if (factories != nullptr)
	{
		cout << "\nFACTORIES:\n";
		for (int i = 0; i < numOfFactories; i++)
			factories[i]->printInfo();
	}
}

int main()
{
	Street ulica("Racianska", "Bratislava");

	cout << ulica.getCityName() << "  " << ulica.getStreetName() << endl;

	ulica.generateBuildings();

	ulica.printInfo();

	//cout << "FH num: " << ulica.familyHouses[1]->getNumber() << ", floors: " << ulica.familyHouses[1]->getFloors() << ", house area: " << ulica.familyHouses[1]->getHouseArea() << " m^2, garden area: " << ulica.familyHouses[1]->getGardenArea() << " m^2" << endl;


	return 0;
}