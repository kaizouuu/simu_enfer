#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions_damnes.h"
#include "torture.h"

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
//********************************FONCTION LISTE TORTURE FILE POSTE**********************************************************//


FILE_POSTE* CreerMaillonTortureFilePoste(FILE_POSTE *pt_tete_file_poste)
{
    FILE_POSTE *pt_maillon = NULL;
    pt_maillon = (FILE_POSTE*)malloc(sizeof(FILE_POSTE));
    int i = 0;
    if(pt_tete_file_poste == NULL)
    pt_maillon->id = 0;
    else
    {
        while(pt_tete_file_poste != NULL)
        {
            pt_tete_file_poste = pt_tete_file_poste->suiv;
            i ++;
        }
    }
    pt_maillon->id = i;
    pt_maillon->cpt = 0;
    pt_maillon->suiv=NULL;
    return pt_maillon;
}
void InsererMaillonEnQueueTortureFilePoste(FILE_POSTE **pt_tete_file_poste ,FILE_POSTE *nouveau_file_poste)
{
    FILE_POSTE *pt_courant = *pt_tete_file_poste;
    FILE_POSTE *pt_precedent = *pt_tete_file_poste;

    if (*pt_tete_file_poste == NULL)
        *pt_tete_file_poste = nouveau_file_poste;
    else
    {
        while ((pt_courant!=NULL)&& pt_courant->id < nouveau_file_poste->id)
        {
            pt_precedent = pt_courant;
            pt_courant=pt_courant->suiv;
        }
        if (pt_courant == *pt_tete_file_poste)
        {
            nouveau_file_poste->suiv=pt_courant;
            *pt_tete_file_poste= nouveau_file_poste;
        }
        else
        {
            nouveau_file_poste->suiv=pt_courant;
            pt_precedent->suiv=nouveau_file_poste;
        }
    }
}

void AfficherMaillonTortureFilePoste(FILE_POSTE *pt_tete_file_poste)
{
    {
        if(pt_tete_file_poste == NULL)
            printf("\nLa liste est vide");
        while (pt_tete_file_poste != NULL)
        {
            printf ("\nID: %d", pt_tete_file_poste->id);
            printf("\ncpt: %d", pt_tete_file_poste->cpt);
            pt_tete_file_poste = pt_tete_file_poste->suiv;
        }
    }
}

void RechercherMaillonTortureFilePoste(FILE_POSTE *pt_tete_file_poste,int nombrerech)
{
    if (pt_tete_file_poste == NULL)
        printf ("\nLa liste est vide");
    else
    {
        while (pt_tete_file_poste != NULL && pt_tete_file_poste->id != nombrerech)
        {
            pt_tete_file_poste=pt_tete_file_poste->suiv;
        }
        if (pt_tete_file_poste == NULL)
            printf ("\n%d n'est pas dans la liste",nombrerech);
        else
        {
            printf("\nID: %d",pt_tete_file_poste->id);
            printf("\ncompteur: %d", pt_tete_file_poste->cpt);
        }
    }
}

void SupprimerMaillonTortureFilePoste(FILE_POSTE **pt_tete_file_poste,int nombrerech)
{
    FILE_POSTE *pt_courant = *pt_tete_file_poste;
    FILE_POSTE *pt_precedent = *pt_tete_file_poste;
    if (*pt_tete_file_poste == NULL)
        printf ("\nLa liste est vide");
    else
    {
        while (pt_tete_file_poste != NULL && pt_courant->id != nombrerech)
        {
            pt_precedent = pt_courant;
            pt_courant=pt_courant->suiv;
        }
        if (pt_courant == pt_precedent)
            *pt_tete_file_poste = pt_courant->suiv;
        else
        if (pt_courant== NULL)
            printf("\n%d nest pas dans la liste",nombrerech);
        else
            pt_precedent->suiv=pt_courant->suiv;

        free(pt_courant);
        pt_courant=NULL;
    }
}

//********************************FONCTION LISTE TORTURE EPILATION CHEVEUX**********************************************************//

EPILATION_CHEVEUX* CreerMaillonTortureEpilationCheveux(EPILATION_CHEVEUX *pt_tete_epilation)
{
    EPILATION_CHEVEUX *pt_maillon = NULL;
    pt_maillon = (EPILATION_CHEVEUX*)malloc(sizeof(EPILATION_CHEVEUX));
    int i = 0;
    if(pt_tete_epilation == NULL)
    pt_maillon->id = 0;
    else
    {
        while(pt_tete_epilation != NULL)
        {
            pt_tete_epilation = pt_tete_epilation->suiv;
            i ++;
        }
    }
    pt_maillon->id = i;
    pt_maillon->cpt = 0;
    pt_maillon->suiv=NULL;
    return pt_maillon;
}

void InsererMaillonEnQueueTortureEpilationCheveux(EPILATION_CHEVEUX **pt_tete_epilation ,EPILATION_CHEVEUX *nouveau_epilation)
{
    EPILATION_CHEVEUX *pt_courant = *pt_tete_epilation;
    EPILATION_CHEVEUX *pt_precedent = *pt_tete_epilation;

    if (*pt_tete_epilation == NULL)
        *pt_tete_epilation = nouveau_epilation;
    else
    {
        while ((pt_courant!=NULL)&& pt_courant->id < nouveau_epilation->id)
        {
            pt_precedent = pt_courant;
            pt_courant=pt_courant->suiv;
        }
        if (pt_courant == *pt_tete_epilation)
        {
            nouveau_epilation->suiv=pt_courant;
            *pt_tete_epilation= nouveau_epilation;
        }
        else
        {
            nouveau_epilation->suiv=pt_courant;
            pt_precedent->suiv=nouveau_epilation;
        }
    }
}

void AfficherMaillonTortureEpilationCheveux(EPILATION_CHEVEUX *pt_tete_epilation)
{
    {
        if(pt_tete_epilation == NULL)
            printf("\nLa liste est vide");
        while (pt_tete_epilation != NULL)
        {
            printf ("\nID: %d", pt_tete_epilation->id);
            printf("\ncpt: %d", pt_tete_epilation->cpt);
            pt_tete_epilation = pt_tete_epilation->suiv;
        }
    }
}

void RechercherMaillonTortureEpilationCheveux(EPILATION_CHEVEUX *pt_tete_epilation,int nombrerech)
{
    if (pt_tete_epilation == NULL)
        printf ("\nLa liste est vide");
    else
    {
        while (pt_tete_epilation != NULL && pt_tete_epilation->id != nombrerech)
        {
            pt_tete_epilation=pt_tete_epilation->suiv;
        }
        if (pt_tete_epilation == NULL)
            printf ("\n%d n'est pas dans la liste",nombrerech);
        else
        {
            printf("\nID: %d",pt_tete_epilation->id);
            printf("\ncompteur: %d", pt_tete_epilation->cpt);
        }
    }
}

void SupprimerMaillonTortureEpilationCheveux(EPILATION_CHEVEUX **pt_tete_epilation,int nombrerech)
{
    EPILATION_CHEVEUX *pt_courant = *pt_tete_epilation;
    EPILATION_CHEVEUX *pt_precedent = *pt_tete_epilation;
    if (*pt_tete_epilation == NULL)
        printf ("\nLa liste est vide");
    else
    {
        while (pt_tete_epilation != NULL && pt_courant->id != nombrerech)
        {
            pt_precedent = pt_courant;
            pt_courant=pt_courant->suiv;
        }
        if (pt_courant == pt_precedent)
            *pt_tete_epilation = pt_courant->suiv;
        else
        if (pt_courant== NULL)
            printf("\n%d nest pas dans la liste",nombrerech);
        else
            pt_precedent->suiv=pt_courant->suiv;

        free(pt_courant);
        pt_courant=NULL;
    }
}

//********************************FONCTION LISTE TORTURE MARSEILLAIS**********************************************************//
MARSEILLAIS* CreerMaillonTortureMarseillais(MARSEILLAIS *pt_tete_marseillais)
{
    MARSEILLAIS *pt_maillon = NULL;
    pt_maillon = (MARSEILLAIS*)malloc(sizeof(MARSEILLAIS));
    int i = 0;
    if(pt_tete_marseillais == NULL)
    pt_maillon->id = 0;
    else
    {
        while(pt_tete_marseillais != NULL)
        {
            pt_tete_marseillais = pt_tete_marseillais->suiv;
            i ++;
        }
    }
    pt_maillon->id = i;
    pt_maillon->cpt = 0;
    pt_maillon->suiv=NULL;
    return pt_maillon;
}

void InsererMaillonEnQueueTortureMarseillais(MARSEILLAIS **pt_tete_marseillais ,MARSEILLAIS *nouveau_marseillais)
{
    MARSEILLAIS *pt_courant = *pt_tete_marseillais;
    MARSEILLAIS *pt_precedent = *pt_tete_marseillais;

    if (*pt_tete_marseillais == NULL)
        *pt_tete_marseillais = nouveau_marseillais;
    else
    {
        while ((pt_courant!=NULL)&& pt_courant->id < nouveau_marseillais->id)
        {
            pt_precedent = pt_courant;
            pt_courant=pt_courant->suiv;
        }
        if (pt_courant == *pt_tete_marseillais)
        {
            nouveau_marseillais->suiv=pt_courant;
            *pt_tete_marseillais= nouveau_marseillais;
        }
        else
        {
            nouveau_marseillais->suiv=pt_courant;
            pt_precedent->suiv=nouveau_marseillais;
        }
    }
}

void AfficherMaillonTortureMarseillais(MARSEILLAIS *pt_tete_marseillais)
{
    {
        if(pt_tete_marseillais == NULL)
            printf("\nLa liste est vide");
        while (pt_tete_marseillais != NULL)
        {
            printf ("\nID: %d", pt_tete_marseillais->id);
            printf("\ncpt: %d", pt_tete_marseillais->cpt);
            pt_tete_marseillais = pt_tete_marseillais->suiv;
        }
    }
}

void RechercherMaillonTortureMarseillais(MARSEILLAIS *pt_tete_marseillais,int nombrerech)
{
    if (pt_tete_marseillais == NULL)
        printf ("\nLa liste est vide");
    else
    {
        while (pt_tete_marseillais != NULL && pt_tete_marseillais->id != nombrerech)
        {
            pt_tete_marseillais=pt_tete_marseillais->suiv;
        }
        if (pt_tete_marseillais == NULL)
            printf ("\n%d n'est pas dans la liste",nombrerech);
        else
        {
            printf("\nID: %d",pt_tete_marseillais->id);
            printf("\ncompteur: %d", pt_tete_marseillais->cpt);
        }
    }
}

void SupprimerMaillonTortureMarseillais(MARSEILLAIS **pt_tete_marseillais,int nombrerech)
{
    MARSEILLAIS *pt_courant = *pt_tete_marseillais;
    MARSEILLAIS *pt_precedent = *pt_tete_marseillais;
    if (*pt_tete_marseillais == NULL)
        printf ("\nLa liste est vide");
    else
    {
        while (pt_tete_marseillais != NULL && pt_courant->id != nombrerech)
        {
            pt_precedent = pt_courant;
            pt_courant=pt_courant->suiv;
        }
        if (pt_courant == pt_precedent)
            *pt_tete_marseillais = pt_courant->suiv;
        else
        if (pt_courant== NULL)
            printf("\n%d nest pas dans la liste",nombrerech);
        else
            pt_precedent->suiv=pt_courant->suiv;

        free(pt_courant);
        pt_courant=NULL;
    }
}
