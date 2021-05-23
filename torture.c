#include "torture.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fonctions_damnes.h"
#include "simulateur.h"
#include "evenements.h"


//fonction pour creer les totures
//********************************FONCTION LISTE TORTURE COURS D'ALGO**********************************************************//

struct cours_algo* CreerMaillonTortureCoursAlgoSimulation(int id_ppf)//creer un maillon de torture
{
    struct cours_algo*pt_maillon = NULL;
    pt_maillon = (struct cours_algo*)malloc(sizeof(struct cours_algo));
 

    pt_maillon->id = id_ppf;
    pt_maillon->cpt = 0;  //à voir si c'est utile
    pt_maillon->suiv=NULL;

    return pt_maillon;
}

void InsererMaillonEnQueueTortureCoursAlgo(struct cours_algo **pt_tete_cours_algo , struct cours_algo *nouveau_cour_algo)
{
    struct cours_algo *pt_courant = *pt_tete_cours_algo;
    struct cours_algo *pt_precedent = *pt_tete_cours_algo;

    if (*pt_tete_cours_algo == NULL)
        *pt_tete_cours_algo = nouveau_cour_algo;
    else
    {
        while ((pt_courant!=NULL)&& pt_courant->id < nouveau_cour_algo->id)
        {
            pt_precedent = pt_courant;
            pt_courant=pt_courant->suiv;
        }
        if (pt_courant == *pt_tete_cours_algo)
        {
            nouveau_cour_algo->suiv=pt_courant;
            *pt_tete_cours_algo= nouveau_cour_algo;
        }
        else
        {
            nouveau_cour_algo->suiv=pt_courant;
            pt_precedent->suiv=nouveau_cour_algo;
        }
    }
}

void AfficherMaillonTortureCoursAlgo(struct cours_algo *pt_tete_cours_algo)//affiche les salles de tortures
{
    {
        if(pt_tete_cours_algo == NULL)
            printf("\nLa liste est vide");
        while (pt_tete_cours_algo != NULL)
        {
            printf ("\nID: %d", pt_tete_cours_algo->id);
            printf("\ncpt: %d", pt_tete_cours_algo->cpt);
            pt_tete_cours_algo = pt_tete_cours_algo->suiv;
        }
    }
}

void RechercherMaillonTortureCoursAlgo(struct cours_algo *pt_tete_cours_algo,int nombrerech)//recherche un damné par son id
{
    if (pt_tete_cours_algo == NULL)
        printf ("\nLa liste est vide");
    else
    {
        while (pt_tete_cours_algo != NULL && pt_tete_cours_algo->id != nombrerech)
        {
            pt_tete_cours_algo=pt_tete_cours_algo->suiv;
        }
        if (pt_tete_cours_algo == NULL)
            printf ("\n%d n'est pas dans la liste",nombrerech);
        else
        {
            printf("\nID: %d",pt_tete_cours_algo->id);
            printf("\ncompteur: %d", pt_tete_cours_algo->cpt);
        }
    }
}

void SupprimerMaillonTortureCoursAlgo(struct cours_algo **pt_tete_cours_algo,int nombrerech)//supprime un damné par son id
{
    struct cours_algo *pt_courant = *pt_tete_cours_algo;
    struct cours_algo *pt_precedent = *pt_tete_cours_algo;
    if (*pt_tete_cours_algo == NULL)
        printf ("\nLa liste est vide");
    else
    {
        while (pt_tete_cours_algo != NULL && pt_courant->id != nombrerech)
        {
            pt_precedent = pt_courant;
            pt_courant=pt_courant->suiv;
        }
        if (pt_courant == pt_precedent)
            *pt_tete_cours_algo = pt_courant->suiv;
        else
        if (pt_courant== NULL)
            printf("\n%d nest pas dans la liste",nombrerech);
        else
            pt_precedent->suiv=pt_courant->suiv;

        free(pt_courant);
        pt_courant=NULL;
    }
}




