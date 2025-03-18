#define CRT_SECURE_NO_WARNINGS
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

void afisareStilou(Stilou stilou) {
	printf("ID: %d", stilou.id);
	printf("Lungime: %d", stilou.lungime);
	printf("Pret: %.1f", stilou.pret);
	printf("Firma: %s", stilou.firma);
	printf("culoare: %s", stilou.culoare);
	printf("Model: %c", stilou.model);
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
	free((*stilouri));
	(*stilouri) = aux;
	(*nrStilouri)++;
}

Stilou citireStilouFisier(FILE* file) {
	//functia citeste o Stilou dintr-un strceam deja deschis
	//Stilou citita este returnata;
}

Stilou* citireVectorStilouriFisier(const char* numeFisier, int* nrStilouriCitite) {
	//functia primeste numele fisierului, il deschide si citeste toate Stilourile din fisier
	//prin apelul repetat al functiei citireStilouFisier()
	//numarul de Stilouri este determinat prin numarul de citiri din fisier
	//ATENTIE - la final inchidem fisierul/stream-ul
}

void dezalocareVectorStilouri(Stilou** vector, int* nrStilouri) {
	//este dezalocat intreg vectorul de masini
}

int main() {
	
	return 0;
}