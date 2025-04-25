#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//trebuie sa folositi fisierul masini.txt
//sau va creati un alt fisier cu alte date

struct StructuraStilou {
	int id;
	int lungime;
	float pret;
	char* firma;
	char* culoare;
	unsigned char model;
};
typedef struct StructuraStilou Stilou;

typedef struct {
	Stilou info;
	struct Nod* next;
} Nod;

void afisareListaStilouri(Nod* cap) {
	while (cap != NULL) {
		afisareStilou(cap->info);
		cap = cap->next;
	}
}

void afisareStilou(Stilou stilou) {
	printf("ID: %d\n", stilou.id);
	printf("Lungime: %d\n", stilou.lungime);
	printf("Pret: %.1f\n", stilou.pret);
	printf("Firma: %s\n", stilou.firma);
	printf("culoare: %s\n", stilou.culoare);
	printf("Model: %c\n\n", stilou.model);
}

void afisareVectorStilouri(Stilou* stilouri, int nrStilouri) {
	for (int i = 0; i < nrStilouri; i++)
	{
		afisareStilou((stilouri[i]));
	}
}

void adaugaStilouInVector(Stilou** stilouri, int* nrStilouri, Stilou stilouNou) {
	Stilou* aux = (Stilou*)malloc(sizeof(Stilou) * ((*nrStilouri) + 1));
	for (int i = 0; i < *nrStilouri; i++)
	{
		aux[i] = (*stilouri)[i];
	}

	aux[(*nrStilouri)] = stilouNou; // shallow copy
	free(*stilouri);
	(*stilouri) = aux;
	(*nrStilouri)++;
}

Stilou citireStilouFisier(FILE* file) {
	Stilou s;
	char buffer[100];
	char sep[4] = ",;\n";
	fgets(buffer, 100, file);
	s.id = atoi(strtok(buffer, sep));
	s.lungime = atoi(strtok(NULL, sep));
	s.pret = atof(strtok(NULL,sep));
	char* aux;
	aux = strtok(NULL, sep);
	s.firma = (char*)malloc(strlen(aux) + 1);
	strcpy(s.firma, aux);
	aux = strtok(NULL, sep);
	s.culoare = (char*)malloc(strlen(aux) + 1);
	strcpy(s.culoare, aux);
	s.model = strtok(NULL, sep)[0];

	return s;
}

Stilou* citireVectorStilouriFisier(const char* numeFisier, int* nrStilouriCitite) {
	FILE* file = fopen(numeFisier, "r");
	Stilou* stilouri = NULL;
	while (!feof(file)) {
		adaugaStilouInVector(&stilouri, nrStilouriCitite, citireStilouFisier(file));
	}

	fclose(file);
	return stilouri;
}

void dezalocareVectorStilouri(Stilou** vector, int* nrStilouri) {
	for (int i = 0; i < *nrStilouri; i++)
	{
		if ((*vector)[i].firma != NULL)
			free((*vector)[i].firma);
		if ((*vector)[i].culoare != NULL)
			free((*vector)[i].culoare);

	}

	free(*vector);
	(*vector) = NULL;
	(*nrStilouri) = 0;
}

int main() {
	int nrStilouri = 0;

	Stilou* stilouri = citireVectorStilouriFisier("stilouri.txt", &nrStilouri);
	afisareVectorStilouri(stilouri, nrStilouri);
	dezalocareVectorStilouri(&stilouri, &nrStilouri);
	
	return 0;
} 