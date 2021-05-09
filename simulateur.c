#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions_damnes.h"
#include "torture.h"
#include "simulateur.h"
#include "time.h"


//*******************************Fonction Pour L'Aiguillage***************************************************
void AiguillagePurgatoire(PPF *pt_tete,COURS_ALGO **pt_tete_cours_algo,COURS_ALGO *nouveau_cour_algo)
{
    if (pt_tete == NULL)
        printf ("\nLa liste est vide");
    else
    {
        while (pt_tete != NULL)
        {
            int id_tempo = pt_tete->id;
            nouveau_cour_algo = CreerMaillonTortureCoursAlgoID(id_tempo);
            InsererMaillonEnQueueTortureCoursAlgo(pt_tete_cours_algo, nouveau_cour_algo);
            pt_tete = pt_tete->suiv;
        }

    }
}

void simulation(PPF **pt_tete,COURS_ALGO **pt_tete_cours_algo,FILE_POSTE **pt_tete_file_poste,EPILATION_CHEVEUX **pt_tete_epilation_cheveux,MARSEILLAIS **pt_tete_marseillais,PPF *nouveau,COURS_ALGO *nouveau_cour_algo,FILE_POSTE *nouveau_file_poste,EPILATION_CHEVEUX *nouveau_epilation_cheveux,MARSEILLAIS *nouveau_marseillais)
{
    unsigned long secondes = 0;
    time_t begin = time( NULL );
    // Boucle du temps pour sequencer la simulation creer un tableau pour avoir des valeurs pret remplie
    while (secondes<2)
    {
        time_t end = time( NULL);
        secondes = (unsigned long) difftime( end, begin );
    }
    printf( "Finished in %ld sec\n", secondes );
    update(pt_tete,pt_tete_cours_algo,*pt_tete_file_poste,*pt_tete_epilation_cheveux,*pt_tete_marseillais,nouveau,nouveau_cour_algo,nouveau_file_poste,nouveau_epilation_cheveux,nouveau_marseillais);
    AfficherMaillonTortureCoursAlgo(*pt_tete_cours_algo);
}

void update(PPF **pt_tete,COURS_ALGO **pt_tete_cours_algo,FILE_POSTE *pt_tete_file_poste,EPILATION_CHEVEUX *pt_tete_epilation_cheveux,MARSEILLAIS *pt_tete_marseillais,PPF *nouveau,COURS_ALGO *nouveau_cour_algo,FILE_POSTE *nouveau_file_poste,EPILATION_CHEVEUX *nouveau_epilation_cheveux,MARSEILLAIS *nouveau_marseillais)
{
    PPF *pt_courant = *pt_tete;
    COURS_ALGO *pt_courant_cours_algo = *pt_tete_cours_algo;

    int temps_toture_cours_dalgo = 2;
    // Boucle qui vient update tout les temps de toture des chambres pour pouvoir ensuite les suprimer et les replacer dans le purgatoire
    while (pt_courant_cours_algo != NULL)
    {
        pt_courant_cours_algo->cpt = pt_courant_cours_algo->cpt + 2;
        if(pt_courant_cours_algo->cpt >= temps_toture_cours_dalgo)
        {
            int nombrerech = pt_courant_cours_algo->id;
            nouveau = RechercherMaillonNombre(pt_courant,nombrerech);
            SupprimerMaillonID(pt_tete,nombrerech);
            *pt_tete = InsererMaillonEnQueuesimple(*pt_tete,nouveau);
        }
        pt_courant_cours_algo = pt_courant_cours_algo->suiv;
    }
}
