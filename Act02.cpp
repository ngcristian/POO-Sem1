#include <iostream>

using namespace std;

class Fruct {
private:  //!!Implicit intr-o clasa atributele sunt private!!
	//numarFructe
	// const int idFruct;
	char* nume;
	string culoare;
	float greautate;
	int lunaMaturitate;
	int nrSeminte;
	float* greutatiSeminte;



public:

	//Contructorul nu are return type si se numeste la fel ca clasa
	//Are rol de a initializa atributele
	Fruct() {
		this->culoare = "Rusu";
		this->greautate = 0.1;
		this->lunaMaturitate = 6;
		this->nrSeminte = 0;
		this->greutatiSeminte = nullptr;
		this->nume = nullptr;
	}
	//sa nu uitam de const la pointer cu *
	Fruct(const char* nume, string culoare, float greautate, int lunaMaturitate, int nrSeminte, const float* greutatiSeminte) {
		this->culoare = culoare;
		this->greautate = greautate;
		this->lunaMaturitate = lunaMaturitate;
		this->nrSeminte = nrSeminte;

		//Nu are spatiu alocat, nu are nevoie de verificare memory leak
		this->greutatiSeminte = new float[nrSeminte];
		for (int i = 0; i < nrSeminte; i++) {
			this->greutatiSeminte[i] = greutatiSeminte[i];
		}
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);

	}

	//Prin set si get se ofera un access controlat
	//De regula un setter este de tip void
	void setGreutate(float greutate) {
		if (greutate > 0) {
			//!! this este un pointer la obiect / adresa obiectul curent la care s-a apelat!!
			this->greautate = greutate;//-> inseamna deferentiere + accesare, altfel trebuie folosit (*this).greutate

		}
	}
	float getGreutate() {//In majoritatea cazurilor, get nu are parametrii
		return this->greautate;//Merge si fara this->, dar e bine de scris
	}
	//const adica functia trebuie sa promita ca nu modifica acel pointer
	void setNume(const char* nume) {
		if (strlen(nume) > 0) {
			//memory leak 
			if (this->nume != nullptr) {
				delete[]this->nume;
			}
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}
	}

	char* getNume() {
		return this->nume;
	}

	void setCuloare(string culoare) {
		if (culoare.length() > 0) {
			this->culoare = culoare;
		}
	}

	void setGreutatiSeminte(int nrSeminte, float* greutatiSeminte) {
		if (nrSeminte > 0) {
			this->nrSeminte = nrSeminte;
			if (this->greutatiSeminte != nullptr) {
				delete[] this->greutatiSeminte;
			}
			this->greutatiSeminte = new float[nrSeminte];
			for (int i = 0; i < nrSeminte; i++) {
				this->greutatiSeminte[i] = greutatiSeminte[i];
			}
		}
	}

	float* getGreutatiSeminte() {
		return this->greutatiSeminte;
	}
	//exceptie la get can nu are acelasi return ca variabila 
	float getGreutateSamanta(int pozitie) {
		if (pozitie >= 0 && pozitie < nrSeminte) {
			return this->greutatiSeminte[pozitie];
		}
		return -1;//aruncam exceptie...atunci cand le invatam
	}
};


void main() {

	Fruct fruct;
	cout << fruct.getGreutate() << endl << endl;
	Fruct f;
	Fruct para;

	fruct.setGreutate(2.5);
	fruct.setGreutate(-56);
	//cout << fruct.getGreutate();

	fruct.setNume("Mar");

	int seminte = 3;
	float* vector = new float[3]{ 0.1,0.2,0.3 };
	fruct.setGreutatiSeminte(seminte, vector);

	cout << fruct.getGreutatiSeminte()[0] << endl;
	cout << fruct.getGreutatiSeminte()[1] << endl;
	cout << fruct.getGreutatiSeminte()[2] << endl;
	cout << fruct.getGreutateSamanta(2) << endl;


	Fruct mar("Mar", "Galben", 0.4, 8, 3, vector);
	cout << mar.getNume();

	//disctuie despre atribute constante
	//atributele statice
	//constructor de copiere
	//destructor
	//operator = (de atribuire)
	//alti operatori
}