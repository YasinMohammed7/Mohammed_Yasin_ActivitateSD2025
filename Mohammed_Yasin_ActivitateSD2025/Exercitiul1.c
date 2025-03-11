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

	vectorNou = (struct Masina*)malloc(sizeof(struct Masina) * nrElementeCopiate);

	for (int i = 0; i < nrElementeCopiate; i++) {
		vectorNou[i] = vector[i];
		vectorNou[i].marca = (char*)malloc(sizeof(char) * (strlen(vector[i].marca)+1));
		strcpy_s(vectorNou[i].marca, strlen(vector[i].marca) + 1, vector[i].marca);
	}

	return vectorNou;
}

void dezalocare(struct Masina** vector, int* nrElemente) {
	for (int i = 0; i < (*nrElemente); i++)
	{
		if ((*vector)[i].marca != NULL) {
			free((*vector)[i].marca);
		}
	}

	free(*vector);
	*vector = NULL;
	*nrElemente = 0;
}

void copiazaMasiniPuternice(struct Masina* vector, char nrElemente, float capacitateMinima, struct Masina** vectorNou, int* dimensiune) {
	*dimensiune = 0;

	for (int i = 0; i < nrElemente; i++)
	{
		if (vector[i].capacitateMotor > capacitateMinima) {
			(*dimensiune)++;
		}
	}

	if ((*vectorNou) != NULL) {
		free(*vectorNou);
	}

	int k = 0;

	*vectorNou = (struct Masina*)malloc(sizeof(struct Masina) * (*dimensiune));
	for (int i = 0; i < nrElemente; i++)
	{
		if (vector[i].capacitateMotor > capacitateMinima)
		{
			(*vectorNou)[k] = vector[i];
			(*vectorNou)[k].marca = (char*)malloc(sizeof(char) * (strlen(vector[i].marca) + 1));
			strcpy_s((*vectorNou)[k].marca, strlen(vector[i].marca) + 1, vector[i].marca);
			k++;
		}
	}
}

struct Masina getPrimaMasinabyMarca(struct Masina* vector, int nrElemente, const char* marca) {
	
	struct Masina m;
	m.marca = NULL;
	for (int i = 0; i < nrElemente; i++)
	{
		if (strcmp(vector[i].marca, marca) == 0) {
			m = vector[i];
			m.marca = (char*)malloc(strlen(vector[i].marca) + 1);
			strcpy_s(m.marca, strlen(vector[i].marca) + 1, vector[i].marca);
			return m;
		}
	}

	return m;
}

int main() {
	//struct Masina m;

	//m = initializare(1, 100, "logan", 1.0, 'A');

	//modificaCaiPutere(&m, 120);

	//afisare(m);
	//dezalocare(&m);

	struct Masina* masini = NULL;
	int nrMasini = 3;
	masini = (struct Masina*)malloc(sizeof(struct Masina) * nrMasini);

	masini[0] = initializare(1, 100, "Tesla", 2.2, 'S');
	masini[1] = initializare(2, 140, "BMW", 2.6, 'C');
	masini[2] = initializare(3, 190, "Maseratti", 3.6, 'T');

	afisareVector(masini, nrMasini);

	struct Masina* primeleMasini = NULL;
	int nrPrimeleMasini = 2;

	primeleMasini = copiazaPrimeleNElemente(masini, nrMasini, nrPrimeleMasini);

	afisareVector(primeleMasini, nrPrimeleMasini);

	dezalocare(&primeleMasini, &nrPrimeleMasini);
	afisareVector(primeleMasini, nrPrimeleMasini);

	struct Masina* masiniPuternice = NULL;
	int nrMasiniPuternice = 0;
	copiazaMasiniPuternice(masini, nrMasini, 2.0, &masiniPuternice, &nrMasiniPuternice);
	printf("\n\nMasini puternice:\n");
	afisareVector(masiniPuternice, nrMasiniPuternice);

	dezalocare(&masiniPuternice, &nrMasiniPuternice);
	printf("\n\nPrima masina:\n");
	struct Masina primaMasina = getPrimaMasinabyMarca(masini, nrMasini, "Maseratti");
	afisare(primaMasina);

	if (primaMasina.marca != NULL)
	{
		free(primaMasina.marca);
		primaMasina.marca = NULL;
	}

	dezalocare(&masini, &nrMasini);
	return 0;
}