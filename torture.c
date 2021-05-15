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
void EcrireFichierCoursAlgo(FILE *database_COURS_ALGO,COURS_ALGO *pt_tete_cours_algo)
{
    database_COURS_ALGO = fopen ("database_COURS_ALGO.bin","w+");
    int i = 0;
    while(pt_tete_cours_algo != NULL)
    {
        i = fwrite(pt_tete_cours_algo,sizeof(COURS_ALGO),1, database_COURS_ALGO);
        if(i != 1)
        {
            printf("\nErreur a l'ecriture");
            break;
        }
        pt_tete_cours_algo = pt_tete_cours_algo->suiv;
    }
    fclose(database_COURS_ALGO);
}

COURS_ALGO* LireFichierCoursAlgo(FILE *database_COURS_ALGO)
{
    database_COURS_ALGO = fopen ("database_COURS_ALGO.bin","r");
    COURS_ALGO tmp;
    COURS_ALGO *pt_tete_cours_algo = NULL;
    COURS_ALGO *pt_nouveau = NULL;
    fseek(database_COURS_ALGO,0, SEEK_SET);
    memset(&tmp,'\0', sizeof(COURS_ALGO));
    while(fread(&tmp,sizeof(COURS_ALGO),1,database_COURS_ALGO))
    {
        if(NULL == (pt_nouveau = (COURS_ALGO*)malloc(sizeof(COURS_ALGO))))
        {
            printf("\nErreur a la creation du maillon");
            break;
        }
        else
        {
            *pt_nouveau = tmp;
            pt_nouveau->suiv = NULL;
            InsererMaillonEnQueueTortureCoursAlgo(&pt_tete_cours_algo, pt_nouveau);
            memset(&tmp,'\0', sizeof(COURS_ALGO));
        }

    }
    fclose(database_COURS_ALGO);
    return pt_tete_cours_algo;
}

int CompteurCoursAlgo (COURS_ALGO *pt_tete_cours_algo)
{
    int i = 0;
    while (pt_tete_cours_algo != NULL)
    {
        i++;
        pt_tete_cours_algo =pt_tete_cours_algo->suiv;
    }
    return i;
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

FILE_POSTE* CreerMaillonTortureFilePosteID(int idtempo)
{
    FILE_POSTE *pt_maillon = NULL;
    pt_maillon = (FILE_POSTE*)malloc(sizeof(FILE_POSTE));
    pt_maillon->id = idtempo;
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

void EcrireFichierFilePoste(FILE *database_FILE_POSTE,FILE_POSTE *pt_tete_file_poste)
{
    database_FILE_POSTE = fopen ("database_FILE_POSTE.bin","w+");
    int i = 0;
    while(pt_tete_file_poste != NULL)
    {
        i = fwrite(pt_tete_file_poste,sizeof(FILE_POSTE),1, database_FILE_POSTE);
        if(i != 1)
        {
            printf("\nErreur a l'ecriture");
            break;
        }
        pt_tete_file_poste = pt_tete_file_poste->suiv;
    }
    fclose(database_FILE_POSTE);
}

FILE_POSTE* LireFichierFilePoste(FILE *database_FILE_POSTE)
{
    database_FILE_POSTE = fopen ("database_FILE_POSTE.bin","r");
    FILE_POSTE tmp;
    FILE_POSTE *pt_tete_file_poste = NULL;
    FILE_POSTE *pt_nouveau = NULL;
    fseek(database_FILE_POSTE,0, SEEK_SET);
    memset(&tmp,'\0', sizeof(FILE_POSTE));
    while(fread(&tmp,sizeof(FILE_POSTE),1,database_FILE_POSTE))
    {
        if(NULL == (pt_nouveau = (FILE_POSTE*)malloc(sizeof(FILE_POSTE))))
        {
            printf("\nErreur a la creation du maillon");
            break;
        }
        else
        {
            *pt_nouveau = tmp;
            pt_nouveau->suiv = NULL;
            InsererMaillonEnQueueTortureFilePoste(&pt_tete_file_poste, pt_nouveau);
            memset(&tmp,'\0', sizeof(FILE_POSTE));
        }

    }
    fclose(database_FILE_POSTE);
    return pt_tete_file_poste;
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

EPILATION_CHEVEUX* CreerMaillonTortureEpilationCheveuxID(int idtempo)
{
    EPILATION_CHEVEUX *pt_maillon = NULL;
    pt_maillon = (EPILATION_CHEVEUX*)malloc(sizeof(EPILATION_CHEVEUX));
    pt_maillon->id = idtempo;
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

void EcrireFichierEpilationCheveux(FILE *database_EPILATION_CHEVEUX,EPILATION_CHEVEUX *pt_tete_epilation_cheveux)
{
    database_EPILATION_CHEVEUX = fopen ("database_EPILATION_CHEVEUX.bin","w+");
    int i = 0;
    while(pt_tete_epilation_cheveux != NULL)
    {
        i = fwrite(pt_tete_epilation_cheveux,sizeof(FILE_POSTE),1, database_EPILATION_CHEVEUX);
        if(i != 1)
        {
            printf("\nErreur a l'ecriture");
            break;
        }
        pt_tete_epilation_cheveux = pt_tete_epilation_cheveux->suiv;
    }
    fclose(database_EPILATION_CHEVEUX);
}

EPILATION_CHEVEUX* LireFichierEpilationCheveux(FILE *database_EPILATION_CHEVEUX)
{
    database_EPILATION_CHEVEUX = fopen ("database_EPILATION_CHEVEUX.bin","r");
    EPILATION_CHEVEUX tmp;
    EPILATION_CHEVEUX *pt_tete_epilation_cheveux = NULL;
    EPILATION_CHEVEUX *pt_nouveau = NULL;
    fseek(database_EPILATION_CHEVEUX,0, SEEK_SET);
    memset(&tmp,'\0', sizeof(EPILATION_CHEVEUX));
    while(fread(&tmp,sizeof(EPILATION_CHEVEUX),1,database_EPILATION_CHEVEUX))
    {
        if(NULL == (pt_nouveau = (EPILATION_CHEVEUX*)malloc(sizeof(EPILATION_CHEVEUX))))
        {
            printf("\nErreur a la creation du maillon");
            break;
        }
        else
        {
            *pt_nouveau = tmp;
            pt_nouveau->suiv = NULL;
            InsererMaillonEnQueueTortureEpilationCheveux(&pt_tete_epilation_cheveux, pt_nouveau);
            memset(&tmp,'\0', sizeof(EPILATION_CHEVEUX));
        }

    }
    fclose(database_EPILATION_CHEVEUX);
    return pt_tete_epilation_cheveux;
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
MARSEILLAIS* CreerMaillonTortureMarseillaisID(int idtempo)
{
    MARSEILLAIS *pt_maillon = NULL;
    pt_maillon = (MARSEILLAIS*)malloc(sizeof(MARSEILLAIS));
    pt_maillon->id = idtempo;
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

void EcrireFichierMarseillais(FILE *database_MARSEILLAIS,MARSEILLAIS *pt_tete_marseillais)
{
    database_MARSEILLAIS = fopen ("database_MARSEILLAIS.bin","w+");
    int i = 0;
    while(pt_tete_marseillais != NULL)
    {
        i = fwrite(pt_tete_marseillais,sizeof(MARSEILLAIS),1, database_MARSEILLAIS);
        if(i != 1)
        {
            printf("\nErreur a l'ecriture");
            break;
        }
        pt_tete_marseillais = pt_tete_marseillais->suiv;
    }
    fclose(database_MARSEILLAIS);
}

MARSEILLAIS* LireFichierMarseillais(FILE *database_MARSEILLAIS)
{
    database_MARSEILLAIS = fopen ("database_MARSEILLAIS.bin","r");
    MARSEILLAIS tmp;
    MARSEILLAIS *pt_tete_file_poste = NULL;
    MARSEILLAIS *pt_nouveau = NULL;
    fseek(database_MARSEILLAIS,0, SEEK_SET);
    memset(&tmp,'\0', sizeof(MARSEILLAIS));
    while(fread(&tmp,sizeof(MARSEILLAIS),1,database_MARSEILLAIS))
    {
        if(NULL == (pt_nouveau = (MARSEILLAIS*)malloc(sizeof(MARSEILLAIS))))
        {
            printf("\nErreur a la creation du maillon");
            break;
        }
        else
        {
            *pt_nouveau = tmp;
            pt_nouveau->suiv = NULL;
            InsererMaillonEnQueueTortureMarseillais(&pt_tete_file_poste, pt_nouveau);
            memset(&tmp,'\0', sizeof(MARSEILLAIS));
        }

    }
    fclose(database_MARSEILLAIS);
    return pt_tete_file_poste;
}