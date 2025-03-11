#include<stdio.h>
#include<stdlib.h>

struct Masina {
	int id;
	int caiPutere;
	char* marca;
	float capacitateMotor;
	char model;
};

struct Masina initializare(int id, int caiPutere, const char* marca, float capacitateMotor, char model) {
	struct Masina m;
	m.id = id;
	m.caiPutere = caiPutere;
	m.capacitateMotor = capacitateMotor;
	m.model = model;
	m.marca = (char*)malloc(sizeof(char) * (strlen(marca) + 1));
	strcpy_s(m.marca, strlen(marca) + 1, marca);
	return m;
}

void afisare(struct Masina m) {
	if (m.marca != NULL)
		printf("%d. Masina cu marca %s are %d cai putere, %.2f capacitate motor si modelul %c\n", m.id, m.marca,m.caiPutere, m.capacitateMotor, m.model);
	else 
		printf("%d. Masina are %d cai putere, %.2f capacitate motor si modelul %c\n", m.id, m.caiPutere, m.capacitateMotor, m.model);

}

//void modificaCaiPutere(struct Masina* m, int caiPutere) {
//	if (caiPutere > 0)
//	{
//		m->caiPutere = caiPutere;
//	}
//}
//
//void dezalocare(struct Masina* m) {
//	if (m->marca != NULL) {
//		free(m->marca);
//		m->marca = NULL;
//	}
//}

void afisareVector(struct Masina* vector, int nrElemente) {
	for (int i = 0; i < nrElemente; i++)
	{
		afisare(vector[i]);
	}
}

struct Masina* copiazaPrimeleNElemente(struct Masina* vector, int nrElemente, int nrElementeCopiate) {
	
	struct Masina *vectorNou=NULL;

	return vectorNou;
}

void dezalocare(struct Masina** vector, int* nrElemente) {

}

void copiazaAnumiteElemente(struct Masina* vector, char nrElemente, float prag, struct Masina** vectorNou, int* dimensiune) {
	
}

struct Masina getPrimulElementConditionat(struct Masina* vector, int nrElemente, const char* conditie) {
	
	struct Masina m;
	m.id = 1;

	return m;
}

int main() {
	struct Masina m;

	m = initializare(1, 100, "logan", 1.0, 'A');

	//modificaCaiPutere(&m, 120);

	afisare(m);
	//dezalocare(&m);

	struct Masina* masini = NULL;
	int nrMasini = 2;
	masini = (struct Masina*)malloc(sizeof(struct Masina) * nrMasini);

	masini[0] = initializare(1, 100, "Tesla", 2.2, 'S');
	masini[1] = initializare(2, 140, "BMW", 2.6, 'C');

	afisareVector(masini, nrMasini);

	return 0;
}