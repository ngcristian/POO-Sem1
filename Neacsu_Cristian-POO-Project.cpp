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
		this->buildYear = 0;
		this->price = 0.0;
		this->countFans = 0;
		this->fanSizes = nullptr;
	}
	//all
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
		else {
			this->name = nullptr;
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
		throw "Error setup focal length";
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
		cout << " desktop computer have " << this->getProcesor() << " processor, " << "buid in " << this->getBuildYear()
			<< " year, sold at " << this->getPrice() << "$. Comes with " << this->getCountFans() << " fans";
		if(this->getCountFans() > 0) {
			cout << " with the following sizes: ";
			for (int i = 0; i < this->getCountFans() - 1; i++) {
				cout << this->getFanSizes(i) << " mm, ";
			}
			cout << this->getFanSizes(this->getCountFans() - 1) << " mm.";
		}
	}

	friend void operator<<(ostream& out, Computer c) {
		out << endl << "Id: " << c.idComputer;
		out << endl << (c.name != nullptr ? "Name: " + string(c.name) : "No found");
		out << endl << "Procesor: " << c.procesor;
		out << endl << "Buld year: " << c.buildYear;
		out << endl << "Price: " << c.price;
		out << endl << "Number fans: " << c.countFans;
		if (c.fanSizes != nullptr) {
			out << endl << "Fan sizes: ";
			for (int i = 0; i < c.countFans - 1; i++) {
				out << c.fanSizes[i]<<" mm, ";
			}
			out << c.getFanSizes(c.countFans - 1) << " mm.";
		}
		else {
			out << endl << "No fans";
		}
	}
};
int Computer::countComputers = 0;

class Smartphone {

private:
	const int idSmartphone;
	static int countSmartphones;
	char* name;
	string model;
	int year;
	float price;
	int countCameras;
	float* focalLength;

public:
	//Default
	Smartphone() :idSmartphone(++countSmartphones) {
		this->name = nullptr;
		this->model = "defaul";
		this->year = 0;
		this->price = 0.0;
		this->countCameras = 0;
		this->focalLength = nullptr;
	}
	//all
	Smartphone(const char* name, string model, int year, float price, int countCameras,const float* focalLength) :idSmartphone(++countSmartphones) {
		this->model = model;
		this->year = year;
		this->price = price;
		this->countCameras = countCameras;

		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);

		this->focalLength = new float[countCameras];
		for (int i = 0; i < countCameras; i++) {
			this->focalLength[i] = focalLength[i];
		}
	}
	//copy
	Smartphone(const Smartphone& copy) :idSmartphone(++countSmartphones) {
		this->model = copy.model;
		this->year = copy.year;
		this->price = copy.price;
		this->countCameras = copy.countCameras;

		if (copy.name != nullptr) {
			this->name = new char[strlen(copy.name) + 1];
			strcpy_s(this->name, strlen(copy.name) + 1, copy.name);
		}
		else {
			this->name = nullptr;
		}
		if (copy.focalLength != nullptr) {
			this->focalLength = new float[copy.countCameras];
			for (int i = 0; i < copy.countCameras; i++) {
				this->focalLength[i] = copy.focalLength[i];
			}
		}
		else {
			this->focalLength = nullptr;
		}
	}

	void setName(const char* name) {
		if (strlen(name) > 0) {
			if (this->name != nullptr) {
				delete[]this->name;
			}
			this->name = new char[strlen(name) + 1];
			strcpy_s(this->name, strlen(name) + 1, name);
		}
	}
	char* getName() {
		return this->name;
	}
	void setModel(string model) {
		if (model.length() > 0) {
			this->model = model;
		}
	}
	string getModel() {
		return this->model;
	}
	void setYear(int year) {
		if (year > 0) {
			this->year = year;
		}
	}
	int getYear() {
		return this->year;
	}
	void setPrice(float price) {
		if (price > 0) {
			this->price = price;
		}
	}
	float getPrice() {
		return this->price;
	}
	void setCountCameras(int countCameras) {
		if (countCameras >= 0){
		this->countCameras = countCameras;
		}
	}
	int getCountCameras() {
		return this->countCameras;
	}
	void setFocalLength(int countCameras, float* focalLength) {
		if (countCameras > 0) {
			this->countCameras = countCameras;
			if (focalLength != nullptr) {
				delete[]this->focalLength;
			}
			this->focalLength = new float[countCameras];
			for (int i = 0; i < countCameras; i++) {
				this->focalLength[i] = focalLength[i];
			}
			throw "Error setup focal length";
		}
	}
	float getFocalLength(int index) {
		if (index >= 0 && index < countCameras) {
			return this->focalLength[index];
		}
	}
	int getIdSmartphones() {
		return this->idSmartphone;
	}
	void setCountSmartphones(int numberSmartphones) {
		countSmartphones = numberSmartphones;
	}
	void showSmartphone() {
		cout << endl << this->getIdSmartphones() << ". The ";
		if (this->getName() != nullptr) {
			cout << this->getName();
		}
		else {
			cout << "No name";
		}
		cout << " smartphone, model " << this->getModel() <<
			", year " << this->getYear() << ", sold at " << this->getPrice()
			<< ". The smartphone have " << this->getCountCameras() << " cameras";
		if (this->getCountCameras() > 0) {
			cout << " with the following focal lengths: ";
			for (int i = 0; i < this->getCountCameras() - 1; i++) {
				cout << this->getFocalLength(i) << " mm, ";
			}
			cout << this->getFocalLength(this->countCameras - 1) << " mm.";
		}
		cout << ".";
	}

	friend void operator<<(ostream& out, Smartphone s) {
		out << endl << "Id: " << s.idSmartphone;
		out << endl << (s.name != nullptr ? "Name: " + string(s.name) : "No found");
		out << endl << "Model: " << s.model;
		out << endl << "Year: " << s.year;
		out << endl << "Price: " << s.price;
		out << endl << "Number cameras: " << s.countCameras;
		if (s.focalLength != nullptr) {
			out << endl << "Focal lengths: ";
			for (int i = 0; i < s.countCameras - 1; i++) {
				out << s.focalLength[i] << " mm, ";
			}
			out << s.getFocalLength(s.countCameras - 1)<<" mm.";
		}
		else {
			out << endl << "No cameras.";
		}
	}
};
int Smartphone::countSmartphones = 0;
void main() {
	int* sizes = new int[3]{ 120,150,220 };

	Computer computerDefault;

	Computer computer1("Dragon", "Intel i5-14400F", 2025, 1099.99, 3, sizes);

	Computer computerCopy(computer1);


	computerDefault.showComputer();
	computer1.showComputer();
	computerCopy.showComputer();

	cout << computer1;

	cout << endl;

	float* camSizes = new float[3]{12.5,24.0,35.0 };

	Smartphone smartPhoneDefault;

	Smartphone smartPhone1("Samsung", "S22", 2022, 799.99, 3, camSizes);

	Smartphone smartCopy(smartPhone1);

	smartPhoneDefault.showSmartphone();
	smartPhone1.showSmartphone();
	smartCopy.showSmartphone();

	cout << smartPhone1;
}