#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions_damnes.h"
#include "simulateur.h"
#include "torture.h"
#include "time.h"

//fonction pour creer les totures
//********************************FONCTION LISTE TORTURE COURS D'ALGO**********************************************************//

COURS_ALGO* CreerMaillonTortureCoursAlgo(COURS_ALGO *pt_tete_cours_algo)
{
    COURS_ALGO *pt_maillon = NULL;
    pt_maillon = (COURS_ALGO*)malloc(sizeof(COURS_ALGO));
    int i = 0;
    if(pt_tete_cours_algo == NULL)
        pt_maillon->id = 0;
    else
    {
        while(pt_tete_cours_algo != NULL)
        {
            pt_tete_cours_algo = pt_tete_cours_algo->suiv;
            i ++;
        }
    }
    pt_maillon->id = i;
    pt_maillon->cpt = 0;
    pt_maillon->suiv=NULL;

    return pt_maillon;
}

COURS_ALGO* CreerMaillonTortureCoursAlgoSimulation(int id_ppf)
{
    COURS_ALGO *pt_maillon = NULL;
    pt_maillon = (COURS_ALGO*)malloc(sizeof(COURS_ALGO));
 

    pt_maillon->id = id_ppf;
    pt_maillon->cpt = 0;  //à voir si c'est utile
    pt_maillon->suiv=NULL;

    return pt_maillon;
}

COURS_ALGO* CreerMaillonTortureCoursAlgoID(int idtempo)
{
    COURS_ALGO *pt_maillon = NULL;
    pt_maillon = (COURS_ALGO*)malloc(sizeof(COURS_ALGO));
    pt_maillon->id = idtempo;
    pt_maillon->cpt = 0;
    pt_maillon->suiv=NULL;

    return pt_maillon;
}

void InsererMaillonEnQueueTortureCoursAlgo(COURS_ALGO **pt_tete_cours_algo ,COURS_ALGO *nouveau_cour_algo)
{
    COURS_ALGO *pt_courant = *pt_tete_cours_algo;
    COURS_ALGO *pt_precedent = *pt_tete_cours_algo;

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

void AfficherMaillonTortureCoursAlgo(COURS_ALGO *pt_tete_cours_algo)
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

void RechercherMaillonTortureCoursAlgo(COURS_ALGO *pt_tete_cours_algo,int nombrerech)
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

void SupprimerMaillonTortureCoursAlgo(COURS_ALGO **pt_tete_cours_algo,int nombrerech)
{
    COURS_ALGO *pt_courant = *pt_tete_cours_algo;
    COURS_ALGO *pt_precedent = *pt_tete_cours_algo;
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




