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

    struct file_poste*pt_tete_file_poste = NULL;
	struct file_poste*nouveau_file_poste = NULL;

    struct epilation_cheveux*pt_tete_epilation_cheveux = NULL;
	struct epilation_cheveux*nouveau_epilation_cheveux = NULL;
    struct marseillais*pt_tete_marseillais = NULL;
	struct marseillais*nouveau_marseillais = NULL;
	struct ech echeancier;
	initFileEvenement(&echeancier);

    menu(&pt_tete,nouveau ,&pt_tete_cours_algo,nouveau_cour_algo, &echeancier, &pt_tete_file_poste, nouveau_file_poste, &pt_tete_epilation_cheveux, nouveau_epilation_cheveux, &pt_tete_marseillais, nouveau_marseillais);

    
    return 0;
}
