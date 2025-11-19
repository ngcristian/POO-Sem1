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
			strcpy_s(this->name, strlen(name) + 1, name);
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
		throw "Error setup fan sizes";
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
	void operator=(const Computer& copy) {
		this->procesor = copy.procesor;
		this->buildYear = copy.buildYear;
		this->price = copy.price;
		this->countFans = copy.countFans;
		if (this->name != nullptr) {
			delete[]this->name;
			this->name = nullptr;
		}
		if (copy.name != nullptr) {
			this->name = new char[strlen(copy.name) + 1];
			strcpy_s(this->name, strlen(copy.name) + 1, copy.name);
		}
		else {
			this->name = nullptr;
		}
		if (this->fanSizes != nullptr) {
			delete[]this->fanSizes;
			this->fanSizes = nullptr;
		}
		if (copy.fanSizes != nullptr) {
			this->fanSizes = new int[copy.countFans];
			for (int i = 0; i < copy.countFans; i++) {
				this->fanSizes[i] = copy.fanSizes[i];
			}
		}
		else {
			this->fanSizes = nullptr;
		}
	}
	void operator+=(float addToPrice) {
		this->price += addToPrice;
	}
	bool operator<(const Computer& c) {
		return this->price < c.price;
	}
	char& operator[](int index) {
		if (index >= 0 && index < strlen(this->name)) {
			return this->name[index];
		}
		else {
			throw "Index out of bound error";
		}
	}
	explicit operator int() {
		return this->price;
	}
	Computer operator++(int) {
		Computer copy = *this;
		this->buildYear++;
		return copy;
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
	friend void operator>>(istream& in, Computer& c);
};
void operator>>(istream& in, Computer& c) {
	cout << endl << "Name: ";
	if (c.name != nullptr) {
		delete[]c.name;
		c.name = nullptr;
	}
	char buffer[20];
	in >> buffer;
	c.name = new char[strlen(buffer) + 1];
	strcpy_s(c.name, strlen(buffer) + 1, buffer);
	cout << endl << "Procesor: ";
	in >> c.procesor;
	cout << endl << "Buld year: ";
	in >> c.buildYear;
	cout << endl << "Price: ";
	in >> c.price;
	cout << endl << "Number fans: ";
	in >> c.countFans;
	cout << endl << "Fan sizes: ";
	if (c.fanSizes != nullptr) {
		delete[]c.fanSizes;
		c.fanSizes = nullptr;
	}
	c.fanSizes = new int[c.countFans];
	for (int i = 0; i < c.countFans; i++) {
		cout << endl << "Size[" << i << "]: ";
		in >> c.fanSizes[i];
	}
}
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

	void operator=(const Smartphone& copy) {
		this->model = copy.model;
		this->year = copy.year;
		this->price = copy.price;
		this->countCameras = copy.countCameras;

		if (this->name != nullptr) {
			delete[]this->name;
			this->name = nullptr;
		}
		if (copy.name != nullptr) {
			this->name = new char[strlen(copy.name) + 1];
			strcpy_s(this->name, strlen(copy.name) + 1, copy.name);
		}
		else {
			this->name = nullptr;
		}
		if (this->focalLength != nullptr) {
			delete[]this->focalLength;
			this->focalLength = nullptr;
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
	void operator+=(float addToPrice) {
		this->price += addToPrice;
	}
	bool operator<(const Smartphone& s) {
		return this->price < s.price;
	}
	char& operator[](int index) {
		if (index >= 0 && index < strlen(this->name)) {
			return this->name[index];
		}
		else {
			throw "Index out of bound error";
		}
	}
	explicit operator int() {
		return this->price;
	}
	Smartphone operator++(int) {
		Smartphone copy = *this;
		this->year++;
		return copy;
	}
	Smartphone operator++() {
		this->year++;
		return *this;
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
	friend void operator>>(istream& in, Smartphone& s);
};
void operator>>(istream& in, Smartphone& s) {
	cout << endl << "Name: ";
	if (s.name != nullptr) {
		delete[]s.name;
		s.name = nullptr;
	}
	char buffer[20];
	in >> buffer;
	s.name = new char[strlen(buffer) + 1];
	strcpy_s(s.name, strlen(buffer) + 1, buffer);
	cout << endl << "Model: ";
	in >> s.model;
	cout << endl << "Year: ";
	in >> s.year;
	cout << endl << "Price: ";
	in >> s.price;
	cout << endl << "Number cameras: ";
	in >> s.countCameras;
	cout << endl << "Focal lengths: ";
	if (s.focalLength != nullptr) {
		delete[]s.focalLength;
		s.focalLength = nullptr;
	}
	s.focalLength = new float[s.countCameras];
	for (int i = 0; i < s.countCameras; i++) {
		cout << endl << "Size[" << i << "]: ";
		in >> s.focalLength[i];
	}
}
int Smartphone::countSmartphones = 0;

class Laptop {
private:
	const int idLaptop;
	static int countLaptop;
	char* name;
	float price;
	int memoryNumber;
	int* memorySizes;

public:
	//Default
	Laptop():idLaptop(++countLaptop) {
		this->name = nullptr;
		this->price = 0.0;
		this->memoryNumber = 0;
		this->memorySizes = nullptr;
	}
	//All
	Laptop(const char* name, float price, int memoryNumber, const int* memorySizes) :idLaptop(++countLaptop) {
		this->price = price;
		this->memoryNumber = memoryNumber;
		
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);

		this->memorySizes = new int[memoryNumber];
		for (int i = 0; i < memoryNumber; i++) {
			this->memorySizes[i] = memorySizes[i];
		}
	}
	//Copy
	Laptop(const Laptop& copy) :idLaptop(++countLaptop) {
		if (copy.name != nullptr) {
			this->name = new char[strlen(copy.name) + 1];
			strcpy_s(this->name, strlen(copy.name) + 1, copy.name);
		}
		else {
			this->name = nullptr;
		}
		if (copy.memorySizes != nullptr) {
			this->memorySizes = new int[copy.memoryNumber];
			for (int i = 0; i < copy.memoryNumber; i++) {
				this->memorySizes[i] = copy.memorySizes[i];
			}
		}
		else {
			this->memorySizes = nullptr;
		}
		this->price = copy.price;
		this->memoryNumber = copy.memoryNumber;
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
	void setPrice(float price) {
		if (price > 0) {
			this->price = price;
		}
	}
	float getPrice() {
		return this->price;
	}
	void setMemoryNumber(int memoryNumber) {
		if (memoryNumber > 0) {
			this->memoryNumber = memoryNumber;
		}
	}
	int getMemoryNumber() {
		return this->memoryNumber;
	}
	void setMemorySizes(int memoryNumber, int* memorySizes) {
		if (memoryNumber > 0) {
			this->memoryNumber = memoryNumber;
			if (this->memorySizes != nullptr) {
				delete[]this->memorySizes;
			}
			this->memorySizes = new int[memoryNumber];
			for (int i = 0; i < memoryNumber; i++) {
				this->memorySizes[i] = memorySizes[i];
			}
		}
	}
	int getMemorySize(int index) {
		if (index >= 0 && index < memoryNumber) {
			return this->memorySizes[index];
		}
		throw "Error setup memory sizes";
	}
	void operator=(const Laptop& copy) {
		this->price = copy.price;
		this->memoryNumber = copy.memoryNumber;

		if (this->name != nullptr) {
			delete[]this->name;
			this->name = nullptr;
		}
		if (copy.name != nullptr) {
			this->name = new char[strlen(copy.name) + 1];
			strcpy_s(this->name, strlen(copy.name) + 1, copy.name);
		}
		else {
			this->name = nullptr;
		}
		if (this->memorySizes != nullptr) {
			delete[]this->memorySizes;
			this->memorySizes = nullptr;
		}
		if (copy.memorySizes != nullptr) {
			this->memorySizes = new int[copy.memoryNumber];
			for (int i = 0; i < copy.memoryNumber; i++) {
				this->memorySizes[i] = copy.memorySizes[i];
			}
		}
		else {
			this->memorySizes = nullptr;
		}
	}
	void operator+=(float addToPrice) {
		this->price += addToPrice;
	}
	bool operator<(const Laptop l) {
		return this->price < l.price;
	}
	char& operator[](int index) {
		if (index >= 0 && index < strlen(this->name)) {
			return this->name[index];
		}
		else {
			throw "Index out of bound error";
		}
	}
	explicit operator int() {
		return this->price;
	}
	friend void operator<<(ostream& out, Laptop l) {
		out << endl << "Id: " << l.idLaptop;
		out << endl << (l.name != nullptr ? "Name: " + string(l.name) : "No found");
		out << endl << "Price: " << l.price;
		out << endl << "Number of memory: " << l.memoryNumber;
		if (l.memorySizes != nullptr) {
			out << endl << "Memory sizes: ";
			for (int i = 0; i < l.memoryNumber - 1; i++) {
				out << l.memorySizes[i] << " Gb, ";
			}
			out << l.getMemorySize(l.memoryNumber - 1) << " Gb.";
		}
		else {
			out << endl << "No memory";
		}
	}
	friend void operator>>(istream& in, Laptop& l);
};
void operator>>(istream& in, Laptop& l) {
	cout << endl << "Name: ";
	if(l.name != nullptr){
		delete[]l.name;
		l.name = nullptr;
	}
	char buffer[20];
	in >> buffer;
	l.name = new char[strlen(buffer) + 1];
	strcpy_s(l.name, strlen(buffer) + 1, buffer);
	cout << endl << "Price: ";
	in >> l.price;
	cout << endl << "Number of memory: ";
	in >> l.memoryNumber;
	cout << endl << "Memory sizes: ";
	if (l.memorySizes != nullptr) {
		delete[]l.memorySizes;
		l.memorySizes = nullptr;
	}
	l.memorySizes = new int[l.memoryNumber];
	for (int i = 0; i < l.memoryNumber; i++) {
		cout << endl << "Memory[" << i << "]: ";
		in >> l.memorySizes[i];
	}
}
int Laptop::countLaptop = 0;

void main() {
	int* sizes = new int[3]{ 120,150,220 };

	Computer computerDefault;

	Computer computer1("Dragon", "Intel i5-14400F", 2025, 1099.99, 3, sizes);

	Computer computerCopy(computer1);

	Computer computer2;


	computerDefault.showComputer();
	computer1.showComputer();
	computerCopy.showComputer();

	cout << computer1;

	computerDefault = computer1;
	computerDefault += 100.00;

	cout << endl << computerDefault;
	cout << endl;
	if (computer1 < computerDefault) {
		cout << endl << "Fist computer is cheaper then the second computer";
	}
	else {
		cout << endl << "Second computer is cheaper then the first computer";
	}

	cout << endl << "Name starts with letter: " << computer1[0];

	cout << endl << "Cast: " << (int)computer1;

	Computer c1 = computer1++;
	cout << c1;

	cin >> computer2;
	cout << computer2;

	cout << endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

	

	float* camSizes = new float[3]{12.5,24.0,35.0 };

	Smartphone smartPhoneDefault;

	Smartphone smartPhone1("Samsung", "S22", 2022, 799.99, 3, camSizes);

	Smartphone smartCopy(smartPhone1);

	Smartphone smartPhone2;

	smartPhoneDefault.showSmartphone();
	smartPhone1.showSmartphone();
	smartCopy.showSmartphone();

	cout << smartPhone1;

	smartPhoneDefault = smartPhone1;
	smartPhoneDefault += 100;

	cout << endl << smartPhoneDefault;
	cout << endl;
	if (smartPhoneDefault < smartPhone1) {
		cout << endl << "Fist smartphone is cheaper then the second smartphone";
	}
	else {
		cout << endl << "Second smartphone is cheaper then the first smartphone";
	}

	cout << endl << "Name starts with letter: " << smartPhone1[0];

	cout << endl << "Cast: " << (int)smartPhone1;

	Smartphone s1 = smartPhone1++;
	cout << s1;
	Smartphone s2 = ++smartPhone1;
	cout << s2;

	cin >> smartPhone2;
	cout << smartPhone2;
	cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

	int* memorySizes = new int[4]{ 4,8,16,32};

	Laptop laptopDefault;
	Laptop laptop1("Legion", 1499.99, 4, memorySizes);
	Laptop laptopCopy(laptop1);
	Laptop laptop2;

	cout << laptopDefault;
	cout << laptop1;
	cout << laptopCopy;

	laptopDefault = laptop1;
	laptopDefault += 100;

	cout << endl << laptopDefault;
	cout << endl;
	if (laptopCopy< laptopDefault) {
		cout << endl << "Fist laptop is cheaper then the second laptop";
	}
	else {
		cout << endl << "Second laptop is cheaper then the first laptop";
	}

	cout << endl << "Name starts with letter: " << laptop1[0];

	cout << endl << "Cast: " << (int)laptop1;

	cin >> laptop2;
	cout << laptop2;
}