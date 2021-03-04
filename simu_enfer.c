#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions_damnes.h"

typedef struct
{
	int id;
	char name;
	int cpt;
	int score;
	struct ppf *suiv;
}ppf;

typedef struct
{
	int id;
	int cpt;
	struct COURS_ALGO *suiv;

}COURS_ALGO;

typedef struct
{
	int id;
	int cpt;
	struct FILE_POSTE *suiv;
}FILE_POSTE;

typedef struct
{
	int id;
	int cpt;
	struct EPILATION_CHEVEUX *suiv;

}EPILATION_CHEVEUX;

typedef struct
{
	int id;
	int cpt;
	struct MARSEILLAIS *suiv;

}MARSEILLAIS;

int main()
{
	printf("NIKE ZEBIIIIIIIIIIIIIII\n");
    return 0;
}
