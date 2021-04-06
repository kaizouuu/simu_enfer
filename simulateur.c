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
    int idtempo;
    if (pt_tete == NULL)
        printf ("\nLa liste est vide");
    else
    {
        while (pt_tete != NULL)
        {
            idtempo = pt_tete->id;
            nouveau_cour_algo = CreerMaillonTortureCoursAlgoID(idtempo);
            InsererMaillonEnQueueTortureCoursAlgo(pt_tete_cours_algo, nouveau_cour_algo);
            pt_tete = pt_tete->suiv;
        }
    }
}
void simulation(PPF **pt_tete,COURS_ALGO **pt_tete_cours_algo,FILE_POSTE **pt_tete_file_poste,EPILATION_CHEVEUX **pt_tete_epilation_cheveux,MARSEILLAIS **pt_tete_marseillais,PPF *nouveau,COURS_ALGO *nouveau_cour_algo,FILE_POSTE *nouveau_file_poste,EPILATION_CHEVEUX *nouveau_epilation_cheveux,MARSEILLAIS *nouveau_marseillais)
{
    unsigned long secondes = 0;
    AiguillagePurgatoire(*pt_tete, pt_tete_cours_algo,nouveau_cour_algo);
    time_t begin = time( NULL );
    while (secondes<2)
    {
        time_t end = time( NULL);
        secondes = (unsigned long) difftime( end, begin );
    }
    printf( "Finished in %ld sec\n", secondes );
    update(*pt_tete,*pt_tete_cours_algo,*pt_tete_file_poste,*pt_tete_epilation_cheveux,*pt_tete_marseillais,nouveau,nouveau_cour_algo,nouveau_file_poste,nouveau_epilation_cheveux,nouveau_marseillais);
    AfficherMaillonTortureCoursAlgo(*pt_tete_cours_algo);
}

void update(PPF *pt_tete,COURS_ALGO *pt_tete_cours_algo,FILE_POSTE *pt_tete_file_poste,EPILATION_CHEVEUX *pt_tete_epilation_cheveux,MARSEILLAIS *pt_tete_marseillais,PPF *nouveau,COURS_ALGO *nouveau_cour_algo,FILE_POSTE *nouveau_file_poste,EPILATION_CHEVEUX *nouveau_epilation_cheveux,MARSEILLAIS *nouveau_marseillais)
{
    int temps_toture_cours_dalgo = 2;
    while (pt_tete_cours_algo != NULL)
    {
        pt_tete_cours_algo->cpt = pt_tete_cours_algo->cpt + 2;
        if(pt_tete_cours_algo->cpt >= temps_toture_cours_dalgo)
        {
            int nombrerech = pt_tete_cours_algo->id;
            nouveau = RechercherMaillonNombre(pt_tete,nombrerech);
            nouveau->score = nouveau->score - 200;
            pt_tete = InsererMaillonEnQueuesimple(pt_tete,nouveau);
        }
        pt_tete_cours_algo=pt_tete_cours_algo->suiv;

    }
}

void AiguillageTorture(PPF *pt_tete,COURS_ALGO **pt_tete_cours_algo,COURS_ALGO *nouveau_cour_algo,FILE_POSTE **pt_tete_file_poste,FILE_POSTE *nouveau_file_poste,EPILATION_CHEVEUX **pt_tete_epilation,EPILATION_CHEVEUX *nouveau_epilation,MARSEILLAIS **pt_tete_marseillais,MARSEILLAIS *nouveau_marseillais)
{
    int t=0;
    if(pt_tete->score >= 750) //***Affectation PPf a sa torture en fonction de son score
    {
         if (pt_tete == NULL)
        printf ("\nLa liste est vide");
        else
        {
            while (pt_tete != NULL)
            {
                nouveau_cour_algo = CreerMaillonTortureCoursAlgo(*pt_tete_cours_algo);
                InsererMaillonEnQueueTortureCoursAlgo(pt_tete_cours_algo, nouveau_cour_algo);
                pt_tete = pt_tete->suiv;
            }
            t=10;
            //timer1(t,pt_tete);
            if(pt_tete->cpt == 10)
            {
                while (pt_tete != NULL)
                {
                    int nombrerech=0;
                    for(nombrerech=0;(nombrerech=sizeof(COURS_ALGO));nombrerech++)
                    {
                        SupprimerMaillonTortureCoursAlgo(pt_tete_cours_algo,nombrerech);
                        pt_tete=pt_tete->suiv;
                    }
                }
            }
        }
    }
      if(pt_tete->score <= 250)
    {
         if (pt_tete == NULL)
        printf ("\nLa liste est vide");
        else
        {
            while (pt_tete != NULL)
            {
                nouveau_marseillais = CreerMaillonTortureMarseillais(*pt_tete_marseillais);
                InsererMaillonEnQueueTortureMarseillais(pt_tete_marseillais, nouveau_marseillais);
                pt_tete = pt_tete->suiv;
            }
            
        }
    }


}
