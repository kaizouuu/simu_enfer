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
    EPILATION_CHEVEUX *pt_tete_epilation_cheveux = NULL;
    EPILATION_CHEVEUX *nouveau_epilation_cheveux =NULL;
    MARSEILLAIS *pt_tete_marseillais = NULL;
    MARSEILLAIS *nouveau_marseillais = NULL;

    char nomrech[TCHAINE];
    int nombrerech = 0;
    int nb_place_cours_algo =0;
    int nb_place_file_poste =0;
    int nb_place_epilation_cheveux =0;
    int nb_place_marseillais =0;
    int temps_torture_cours_dalgo = 8;
    int temps_torture_file_poste = 8;
    int temps_torture_epilation_cheveux = 8;
    int temps_torture_marseilllais = 8;


    menu(&pt_tete,nouveau,nomrech,database_PPF,&pt_tete_cours_algo,nouveau_cour_algo,&pt_tete_file_poste,nouveau_file_poste,&pt_tete_epilation_cheveux,nouveau_epilation_cheveux,&pt_tete_marseillais,nouveau_marseillais,nombrerech, nb_place_cours_algo, nb_place_file_poste, nb_place_epilation_cheveux, nb_place_marseillais, temps_torture_cours_dalgo, temps_torture_file_poste, temps_torture_epilation_cheveux, temps_torture_marseilllais);

    fclose(database_PPF);
    return 0;
}