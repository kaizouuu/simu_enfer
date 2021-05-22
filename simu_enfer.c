#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fonctions_damnes.h"
#include "simulateur.h"
#include "torture.h"



int main()
{
	srand(time(NULL));

    PPF *nouveau = NULL;
    PPF *pt_tete = NULL;

    COURS_ALGO *pt_tete_cours_algo = NULL;
    COURS_ALGO *nouveau_cour_algo = NULL;

	ECH File;
	initFileEvenement(&File);

    menu(&pt_tete,nouveau ,&pt_tete_cours_algo,nouveau_cour_algo, &File);

    
    return 0;
}
