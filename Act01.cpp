#include<iostream>

using namespace std;

struct Carte {
	char* autor;
	int nrPagini;
};

void afisareCarte(Carte c) {
	cout << endl << "Cartea scrisa de " << c.autor << " are " << c.nrPagini << " pagini.";
}

int suma() {
	int suma = 0;
	int dimensiune = 4;
	int vector[] = { 17,29,45,78 };

	for (int i = 0; i < dimensiune; i++) {
		//suma = suma + vector[i];
		suma += vector[i];
	}
	return suma;
}
//Daca int* din main e la fel cu cel din definire functie se transmite prin valoare
void afisareVector(int* vector, int dim) {
	cout << endl << "Afisare vector: ";
	for (int i = 0; i < dim; i++) {
		//la afisarea se recomanda transmiterea prin valoare
		cout << endl << "vector[" << i << "]: " << vector[i];
	}
}

int pozitieMaxim(int* vector, int dim) {
	int pozMaxim = 0;
	for (int i = 1; i < dim; i++) {
		if (vector[pozMaxim] < vector[i]) {
			pozMaxim = i;
		}
	}
	return pozMaxim;
}
////De ce sunt doua stelute? (R: Prima pastreaza tipul de date din main, a doua arata ca transmite parametrul prin pointer)
//void stergereMaximDePePozitie(int** vector, int* dim, int pozitie) {
//	//Cand transmitem prin poiter trebuie sa-i fac dereferentiere adica extragem valoare de la adresa respectiva, facem prin * in fata)
//	int* vectorAux = new int[*dim - 1];
//	int j = 0;
//	for (int i = 0; i < *dim; i++) {
//		if (i != pozitie) {
//			vectorAux[j] = (*vector)[i];
//			j++;
//		}
//	}
//	delete[](*vector);
//	(*dim)--;
//	(*vector) = vectorAux;
//}
//Tema schimbam functia "stergereMaximDePePozitie" din transimeterea prin pointer in transmiterea prin referinta
void stergereMaximDePePozitie(int*& vector, int& dim, int pozitie) {
	int* vectorAux = new int[dim - 1];
	int j = 0;
	for (int i = 0; i < dim; i++) {
		if (i != pozitie) {
			vectorAux[j] = (vector)[i];
			j++;
		}
	}
	delete[](vector);
	dim--;
	vector = vectorAux;
}

void main() {
	cout << endl << "Primul seminar de POO.";

	Carte carte;
	carte.nrPagini = 250;
	carte.autor = new char[strlen("Popescu") + 1];
	strcpy_s(carte.autor, strlen("Popescu") + 1, "Popescu");

	afisareCarte(carte);

	//la orice new trebuie un delete[]
	delete[] carte.autor;


	cout << endl << "Suma calcualta este " << suma() << ".";


	//Citirea de la tastatura cu caracter dinamic
	//char* adresa;
	//char buffer[50];
	//
	//cout << endl << "Adresa este: ";

	////cin >> buffer; -> la "space" se opreste
	//cin.getline(buffer,50);
	//adresa = new char[strlen(buffer) + 1];
	//strcpy_s(adresa, strlen(buffer) + 1, buffer);
	//cout << endl << "Adesa citita este: " << adresa;
	//delete[] adresa;

	//Citirea de la tastatura vector cu nr intregi, alocare dinamica

	int* vector;
	int dim = 3;
	vector = new int[dim];

	for (int i = 0; i < dim; i++) {
		cout << endl << "vector[" << i << "]: ";
		cin >> vector[i];
	}

	afisareVector(vector, dim);
	cout << endl << "Pozitia pe care se afla maximul este: " << pozitieMaxim(vector, dim);
	stergereMaximDePePozitie(vector, dim, 1);
	afisareVector(vector, dim);
	delete[] vector;
	

}