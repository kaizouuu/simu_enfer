#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions_damnes.h"
#include "simulateur.h"
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

	ECH File;
	//~ EVT *cour = NULL;
	initFileEvenement(&File);
	
    //~ ECH *pt_tete_echancier = NULL;
    //~ EVT *pt_tete_evenement = NULL;

    char nomrech[TCHAINE];
    int nombrerech = 0;
    
    int nb_place_cours_algo =0;
    int nb_place_file_poste =0;
    int nb_place_epilation_cheveux =0;
    int nb_place_marseillais =0;
    int efficacite_algo = 2;
    int efficacite_poste = 2;
    int efficacite_epil = 2;
    int efficacite_mars = 2;    
    

    //menu(&pt_tete,nouveau,nomrech,database_PPF,&pt_tete_cours_algo,nouveau_cour_algo,&pt_tete_file_poste,nouveau_file_poste,&pt_tete_epilation_cheveux,nouveau_epilation_cheveux,&pt_tete_marseillais,nouveau_marseillais,nombrerech,pt_tete_echancier,pt_tete_evenement, nb_place_cours_algo, nb_place_file_poste, nb_place_epilation_cheveux, nb_place_marseillais, temps_torture_cours_dalgo,temps_torture_file_poste, temps_torture_epilation_cheveux, temps_torture_marseilllais);

    menu(&pt_tete,nouveau,nomrech,database_PPF,&pt_tete_cours_algo,nouveau_cour_algo,&pt_tete_file_poste,nouveau_file_poste,&pt_tete_epilation_cheveux,nouveau_epilation_cheveux,&pt_tete_marseillais,nouveau_marseillais,nombrerech, nb_place_cours_algo, nb_place_file_poste, nb_place_epilation_cheveux, nb_place_marseillais, efficacite_algo, efficacite_poste, efficacite_epil, efficacite_mars, &File);

    fclose(database_PPF);
    return 0;
}
