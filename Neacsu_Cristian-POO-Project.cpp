#include <iostream>

using namespace std;

class Computer {
private:
	const int idComputer;
	static int countComputers;
	char* name;
	string procesor;
	int buildYear;
	float price;
	int countFans;
	int* fanSizes;
public:
	//default
	Computer() :idComputer(++countComputers) {
		this->name = nullptr;
		this->procesor = "Default";
		this->price = 0.0;
		this->countFans = 0;
		this->fanSizes = nullptr;
	}
	Computer(const char* name, string procesor, int buildYear, float price, int countFans, const int* fanSizes) :idComputer(++countComputers) {
		this->procesor = procesor;
		this->buildYear = buildYear;
		this->price = price;
		this->countFans = countFans;

		this->fanSizes = new int[countFans];
		for (int i = 0; i < countFans; i++) {
			this->fanSizes[i] = fanSizes[i];
		}
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	//copy
	Computer(const Computer& copy):idComputer(++countComputers) {
		this->procesor = copy.procesor;
		this->buildYear = copy.buildYear;
		this->price = copy.price;
		this->countFans = copy.countFans;

		if (copy.fanSizes != nullptr) {
			this->fanSizes = new int[copy.countFans];
			for (int i = 0; i < copy.countFans; i++) {
				this->fanSizes[i] = copy.fanSizes[i];
			}
		}
		else {
			this->fanSizes = nullptr;
		}
		if (copy.name != nullptr) {
			this->name = new char[strlen(copy.name) + 1];
			strcpy_s(this->name, strlen(copy.name) + 1, copy.name);
		}
	}

	void setName(const char* name) {
		if (strlen(name) > 0) {
			if (this->name != nullptr) {
				delete[]this->name;
			}
			this->name = new char[strlen(name) + 1];
			strcpy_s(this->name,strlen(name)+1, name);
		}
	}
	char* getName() {
		return this->name;
	}
	void setProcesor(string procesor) {
		if (procesor.length() > 0) {
			this->procesor = procesor;
		}
	}
	string getProcesor() {
		return this->procesor;
	}
	void setBuildYear(int buildYear) {
		if (buildYear > 0) {
			this->buildYear = buildYear;
		}
	}
	int getBuildYear() {
		return this->buildYear;
	}
	void setPrice(float price) {
		if (price > 0) {
			this->price = price;
		}
	}
	float getPrice() {
		return this->price;
	}
	void setCountFans(int countFans) {
		if (countFans >= 0) {
			this->countFans = countFans;
		}
	}
	int getCountFans() {
		return this->countFans;
	}
	void setFanSizes(int countFans, int* fanSizes) {
		if (countFans > 0) {
			this->countFans = countFans;
			if (this->fanSizes != nullptr) {
				delete[] this->fanSizes;
			}
			this->fanSizes = new int[countFans];
			for (int i = 0; i < countFans; i++) {
				this->fanSizes[i] = fanSizes[i];
			}
		}
	}
	int getFanSizes(int index) {
		if (index >= 0 && index < countFans) {
			return this->fanSizes[index];
		}
		throw "Out of bound exception";
	}
	int getIdComputer() {
		return this->idComputer;
	}
	void setCountComputer(int numberComputers) {
		countComputers = numberComputers;
	}
	void showComputer() {
		cout << endl << this->getIdComputer()<<". The ";
		if (this->getName() != nullptr) {
			cout << this->getName();
		}
		else {
			cout << "No name";
		}
		cout << " computer have " << this->getProcesor() << " processor, " << "buid in " << this->getBuildYear()
			<< " year, sold at " << this->getPrice() << "$. Comes with " << this->getCountFans() << " fans";
		if(this->getCountFans() > 0) {
			cout << " with the following sizes: ";
			for (int i = 0; i < this->getCountFans() - 1; i++) {
				cout << this->getFanSizes(i) << " mm, ";
			}
			cout << this->getFanSizes(this->getCountFans() - 1) << " mm.";
		}
	}
};
int Computer::countComputers = 0;
void main() {
	int* sizes = new int[3]{ 120,150,220 };

	Computer computerDefault;

	Computer computer1("Dragon", "Intel i5-14400F", 2025, 1099.99, 3, sizes);

	Computer computerCopy(computer1);

	computerDefault.showComputer();
	computer1.showComputer();
	computerCopy.showComputer();
}