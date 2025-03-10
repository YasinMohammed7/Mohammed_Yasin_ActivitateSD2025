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

void modificaCaiPutere(struct Masina* m, int caiPutere) {
	if (caiPutere > 0)
	{
		m->caiPutere = caiPutere;
	}
}

void dezalocare(struct Masina* m) {
	if (m->marca != NULL) {
		free(m->marca);
		m->marca = NULL;
	}
}

int main() {
	struct Masina m;

	m = initializare(1, 100, "logan", 1.0, 'A');

	modificaCaiPutere(&m, 120);

	afisare(m);
	dezalocare(&m);
	afisare(m);

	return 0;
}