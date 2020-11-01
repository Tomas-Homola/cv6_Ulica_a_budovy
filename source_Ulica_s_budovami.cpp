#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Street
{
protected:
	std::string city = "";
	std::string streetName = "";

	int numOfFamilyHouses = 0;
	int numOfBlocksOfFlats = 0;
	int numOfOfficeBuildings = 0;
	int numOfFactories = 0;

public:
	Street() {}
	Street(std::string city, std::string streetName);
	//virtual ~Street();

	Street** familyHouses = nullptr;
	Street** blocksOfFlats = nullptr;
	Street** officeBuildings = nullptr;
	Street** factories = nullptr;

	string getCityName() { return city; }
	string getStreetName() { return streetName; }

	void setCityName(string city) { this->city = city; }
	void setStreetName(string streetName) { this->streetName = streetName; }

	void generateBuildings(); // ??? umiestnenie v public/protected/private
	virtual void printInfo();
};

Street::Street(std::string city, std::string streetName)
{
	this->city = city;
	this->streetName = streetName;

	generateBuildings();
}

/*Street::~Street()
{
	for (int i = 0; i < numOfFamilyHouses; i++)
	{
		delete familyHouses[i]; // vymazu sa jendotlive family houses, podobne aj pre ostatne
	}
		
	delete[] familyHouses; // potom ten prvy smernik, podobne aj pre ostatne

	for (int i = 0; i < numOfBlocksOfFlats; i++)
	{
		delete blocksOfFlats[i];
	}

	delete[] familyHouses;

	for (int i = 0; i < numOfOfficeBuildings; i++) // tu je nejaky problem, ale program aj tak skonci dobre, lebo sa vrati na konci nula
	{
		delete officeBuildings[i];
	}

	delete[] officeBuildings;

	for (int i = 0; i < numOfFactories; i++)
	{
		delete factories[i];
	}

	delete[] factories;
}*/

void Street::printInfo()
{
	cout << "STREET NAME: " << streetName << "\nCITY: " << city << "\n\nFollowing buildings are located on this street:\n\n";

	cout << "FAMILY HOUSES:\n";
	for (int i = 0; i < numOfFamilyHouses; i++)
		familyHouses[i]->printInfo();

	cout << endl;
	cout << "BLOCKS OF FLATS:\n";
	for (int i = 0; i < numOfBlocksOfFlats; i++)
		blocksOfFlats[i]->printInfo();

	cout << endl;
	cout << "OFFICE BUILDINGS:\n";
	for (int i = 0; i < numOfOfficeBuildings; i++)
		officeBuildings[i]->printInfo();

	cout << endl;
	cout << "FACTORIES:\n";
	for (int i = 0; i < numOfFactories; i++)
		factories[i]->printInfo();
}

class FamilyHouse : public Street
{
private:
	int number = 0;
	int floors = 0;
	int houseArea = 0;
	int gardenArea = 0;

public:
	FamilyHouse() {}
	FamilyHouse(int number, int floors, int houseArea, int gardenArea);
	~FamilyHouse() {}//{ std::cout << "destruktor family house\n"; }

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
	cout << "Family house number: " << number << ", Number of floors: " << floors << ", House area: " << houseArea << " m^2, Garden area: " << gardenArea << " m^2" << endl;
}

//################################################################################//

class BlockOfFlats : public Street
{
protected:
	int number = 0;
	int floors = 0;
	int flats = 0;

public:
	BlockOfFlats() {}
	BlockOfFlats(int number, int floors, int flats);
	~BlockOfFlats() {}//{ cout << "destruktor blocks of flats\n"; }

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
	cout << "Block of Flats number: " << number << ", Number of floors: " << floors << ", Number of flats: " << flats << endl;
}

//################################################################################//

class OfficeBuilding : public Street
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
	~OfficeBuilding() {}//{ std::cout << "destruktor office building\n"; }

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
	std::cout << "Office building number: " << number << ", Number of floors: " << floors << ", Number of employees: " << employees << ", Average daily turnover: " << averageDailyTurnover << " EUR, Number of departments: " << departments << endl;
}

//################################################################################//

class Factory : public Street
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
	~Factory() {}//{ std::cout << "destruktor factory\n"; }

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
	std::cout << "Factory number: " << number << ", Number of floors: " << floors << ", Number of employees: " << employees << ", Average daily turnover: " << averageDailyTurnover << " EUR, Area of the production hall: " << areaOfProductionHall << " m^2" << endl;
}

//################################################################################//

int main()
{
	srand((unsigned)time(0));

	Street ulica("Bratislava", "Racianska");

	ulica.printInfo();

	/*FamilyHouse domcek(1, 2, 100, 150);
	domcek.setStreetName("Demanovska");

	cout << domcek.getCityName() << endl << domcek.getStreetName() << endl;
	domcek.printInfo();*/

	return 0;
}

void Street::generateBuildings()
{
	int tempFloors = 0, tempEmplyees = 0;

	numOfFamilyHouses = rand() % 16 + 5; // 5-20
	numOfBlocksOfFlats = rand() % 8 + 3; // 
	numOfOfficeBuildings = rand() % 5 + 1;
	numOfFactories = rand() % 3 + 1;

	familyHouses = new Street * [numOfFamilyHouses];
	blocksOfFlats = new Street * [numOfBlocksOfFlats];
	officeBuildings = new Street * [numOfOfficeBuildings];
	factories = new Street * [numOfFactories];

	for (int i = 0; i < numOfFamilyHouses; i++)
		familyHouses[i] = new FamilyHouse(i + 7001, rand() % 2 + 1, rand() % 101 + 50, rand() % 101 + 100); // pri number 7000 preto lebo v mojej adrese je 7009

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
}