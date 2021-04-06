#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions_damnes.h"
#include "torture.h"

int main()
{
    FILE * database_PPF = NULL;

    PPF *nouveau = NULL;
    PPF *pt_tete = NULL;

    COURS_ALGO *pt_tete_cours_algo = NULL;
    COURS_ALGO *nouveau_cour_algo = NULL;
    FILE_POSTE *pt_tete_file_poste = NULL;
    FILE_POSTE *nouveau_file_poste = NULL;
<<<<<<< HEAD
    EPILATION_CHEVEUX *pt_tete_epilation_cheveux = NULL;
    EPILATION_CHEVEUX *nouveau_epilation_cheveux =NULL;
=======
    EPILATION_CHEVEUX *pt_tete_epilation = NULL;
    EPILATION_CHEVEUX *nouveau_epilation = NULL;
>>>>>>> AKA
    MARSEILLAIS *pt_tete_marseillais = NULL;
    MARSEILLAIS *nouveau_marseillais = NULL;

    char nomrech[TCHAINE];
    int nombrerech=0;

<<<<<<< HEAD
    menu(&pt_tete,nouveau,nomrech,database_PPF,&pt_tete_cours_algo,nouveau_cour_algo,&pt_tete_file_poste,nouveau_file_poste,&pt_tete_epilation_cheveux,nouveau_epilation_cheveux,&pt_tete_marseillais,nouveau_marseillais,nombrerech);
=======
    menu(&pt_tete,nouveau,nomrech,database_PPF,&pt_tete_cours_algo,nouveau_cour_algo,&pt_tete_file_poste,nouveau_file_poste,&pt_tete_epilation, nouveau_epilation, &pt_tete_marseillais, nouveau_marseillais,  nombrerech);
>>>>>>> AKA
    fclose(database_PPF);
    return 0;
}

