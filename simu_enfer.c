#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "evenements.h"
#include "simulateur.h"
#include "fonctions_damnes.h"
#include "torture.h"

//~ struct cours_algo;
//~ struct evt;
//~ struct ech;
//~ struct ppf;


int main()
{
	srand(time(NULL));

    struct ppf *nouveau = NULL;
    struct ppf *pt_tete = NULL;

    struct cours_algo*pt_tete_cours_algo = NULL;
	struct cours_algo*nouveau_cour_algo = NULL;

	struct ech echeancier;
	initFileEvenement(&echeancier);

    menu(&pt_tete,nouveau ,&pt_tete_cours_algo,nouveau_cour_algo, &echeancier);

    
    return 0;
}
