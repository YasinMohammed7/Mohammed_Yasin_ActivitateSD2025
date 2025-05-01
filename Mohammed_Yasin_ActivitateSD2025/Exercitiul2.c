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

struct Nod {
	Stilou info;
	struct Nod* next;
};
typedef struct Nod Nod;

void afisareStilou(Stilou stilou) {
	printf("ID: %d\n", stilou.id);
	printf("Lungime: %d\n", stilou.lungime);
	printf("Pret: %.1f\n", stilou.pret);
	printf("Firma: %s\n", stilou.firma);
	printf("culoare: %s\n", stilou.culoare);
	printf("Model: %c\n\n", stilou.model);
}

void afisareListaStilouri(Nod* cap) {
	while (cap) {
		afisareStilou(cap->info);
		cap = cap->next;
	}
}

void adaugaStilouInLista(Nod** cap, Stilou stilouNou) {
	// la sfarsit
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = stilouNou; // shallow copy
	nou->next = NULL;
	if (*cap) {
		Nod* p = *cap;
		while (p->next) {
			p = p->next;
		}
		p->next = nou;
	}
	else {
		*cap = nou;
	}
}

void adaugaStilouInListaLaInceput(Nod** cap, Stilou stilouNou) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->info = stilouNou; // shallow copy
	nou->next = *cap;
	*cap = nou;
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

Nod* citireListaStilouriDinDisier(const char* numeFisier) {
	Nod* cap = NULL;
	FILE* f = fopen(numeFisier, "r");
	while (!feof(f)) {
		adaugaStilouInListaLaInceput(&cap, citireStilouFisier(f));
	}
	fclose(f);
	return cap;
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

void dezalocareListaStilouri(Nod** cap) {
	Nod* p;
	while (*cap) {
		p = *cap;
		*cap = p->next;
		if (p->info.culoare) {
			free(p->info.culoare);
		}
		if (p->info.firma) {
			free(p->info.firma);
		}
		free(p);
	}
}

int main() {
	int nrStilouri = 0;

	/*Stilou* stilouri = citireVectorStilouriFisier("stilouri.txt", &nrStilouri);
	afisareVectorStilouri(stilouri, nrStilouri);
	dezalocareVectorStilouri(&stilouri, &nrStilouri);*/

	Nod* cap = citireListaStilouriDinDisier("stilouri.txt");
	afisareListaStilouri(cap);
	dezalocareListaStilouri(&cap);
	
	return 0;
} 