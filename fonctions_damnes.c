#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "fonctions_damnes.h"
#include "torture.h"
#include "simulateur.h"
#include "time.h"

void menu(PPF **pt_tete,PPF *nouveau,char *nomrech,FILE *database_PFF,COURS_ALGO **pt_tete_cours_algo,COURS_ALGO *nouveau_cour_algo,FILE_POSTE **pt_tete_file_poste,FILE_POSTE *nouveau_file_poste, EPILATION_CHEVEUX **pt_tete_epilation_cheveux,EPILATION_CHEVEUX *nouveau_epilation_cheveux,MARSEILLAIS **pt_tete_marseillais,MARSEILLAIS *nouveau_marseillais,int nombrerech)
{
    int i;
    int flag;
    do{
        printf("\n********** Vous etes la pour creer des lens **********\n");
        printf (" 0 pour quitter le programme\n");
        printf (" 1 pour Creer et inserer d'un nouveau maillon\n");
        printf (" 2 pour afficher la liste des maillon dans ma chaine\n");
        printf (" 3 pour recherche un maillon dans la chaine\n");
        printf (" 4 pour supprimer un maillon\n");
        printf (" 5 pour ecrire la chaine en cour dans un fichier\n");
        printf (" 6 pour lire le fichier \n");
        printf( " 7 Test unitaire torture Creer et inserer d'un nouveau maillon \n");
        printf( " 8 Test unitaire torture afficher la liste des maillon dans ma chaine \n");
        printf( " 9 Test unitaire torture Creer et inserer d'un nouveau maillon 2\n");
        printf( " 10 Test unitaire torture afficher la liste des maillon dans ma chaine 2\n");
        printf (" 11 pour recherche un maillon dans la chaine de toture\n");
        printf (" 12 pour supprimer un maillon dans la chaine de toture\n");
        printf (" 13 pour simuler de manière unitaire après avoir aiguiller\n");
        printf (" 14 pour aiguiller les dannees dans les différentes toture\n");
        scanf("%d",&i);
        switch(i)
        {
            case 0: break;
            case 1:

                nouveau = CreerMaillon();////test unitaire fonction ajoutete
                InsererMaillonEnQueue(pt_tete,nouveau);
                break;
            case 2:
                AfficherMaillon(*pt_tete);
                break;
            case 3:
                printf("Saisissez un nom a rechercher\n");
                scanf("%s",nomrech);
                RechercherMaillon(*pt_tete,nomrech);
                printf("Saisissez un nombre a rechercher\n");
                scanf("%d",&nombrerech);
                nouveau= RechercherMaillonNombre(*pt_tete,nombrerech);
                break;
            case 4:
                printf("Saisissez un id a suprimer\n");
                scanf("%s",nomrech);
                SupprimerMaillon(pt_tete,nomrech);
                break;
            case 5:
                flag = 0;
                EcrireFichier(database_PFF,*pt_tete,flag);
                break;
            case 6:
                flag = 0;
                *pt_tete = LireFichier(database_PFF,flag);
                break;
            case 7:
                nouveau_cour_algo = CreerMaillonTortureCoursAlgo(*pt_tete_cours_algo);
                InsererMaillonEnQueueTortureCoursAlgo(pt_tete_cours_algo,nouveau_cour_algo);
                break;
            case 8:
                AfficherMaillonTortureCoursAlgo(*pt_tete_cours_algo);
                break;
            case 9:
                nouveau_file_poste = CreerMaillonTortureFilePoste(*pt_tete_file_poste);
                InsererMaillonEnQueueTortureFilePoste(pt_tete_file_poste,nouveau_file_poste);
                break;
            case 10:
                AfficherMaillonTortureFilePoste(*pt_tete_file_poste);
                break;
            case 11:
                printf("Entre le nombre du maillon à rechercher:\n");
                scanf("%d",&nombrerech);
                RechercherMaillonTortureCoursAlgo(*pt_tete_cours_algo, nombrerech);
                break;
            case 12 :
                printf("Entre le nombre du maillon à rechercher:\n");
                scanf("%d",&nombrerech);
                SupprimerMaillonTortureCoursAlgo(pt_tete_cours_algo,nombrerech);
                break;
            case 13:
                simulation(pt_tete,pt_tete_cours_algo,pt_tete_file_poste,pt_tete_epilation_cheveux,pt_tete_marseillais,nouveau,nouveau_cour_algo,nouveau_file_poste,nouveau_epilation_cheveux,nouveau_marseillais);
                break;
            case 14 :
                //AiguillagePurgatoire(pt_tete, pt_tete_cours_algo, nouveau_cour_algo, pt_tete_file_poste, nouveau_file_poste, pt_tete_epilation_cheveux, nouveau_epilation_cheveux, pt_tete_marseillais,nouveau_marseillais);
                break;
            default:
                break;
        }
    }while (i != 0);
}

PPF* CreerMaillon()
{
    PPF *pt_maillon = NULL;
    pt_maillon = (PPF*)malloc(sizeof(PPF));
    printf("Donner un id a votre PFF: \n");
    scanf("%d",&(*pt_maillon).id);
    printf("Donner un nom a votre PFF: \n");
    scanf("%s",pt_maillon->name);
    pt_maillon->cpt = 0;
    printf("Entrer le score de depravation de votre PPF:\n");
    scanf("%d",&(*pt_maillon).score);
    pt_maillon->suiv=NULL;

    return pt_maillon;
}

void InsererMaillonEnQueue(PPF **pt_tete,PPF *nouveau)

{
    PPF *temp= *pt_tete;
    //cas de la liste vide
    if(*pt_tete == NULL)
        *pt_tete=nouveau;
    else
    {
        while(temp->suiv!=NULL)
        {
            temp=temp->suiv;
        }
        temp->suiv=nouveau;
    }
}

PPF* InsererMaillonEnQueuesimple(PPF *pt_tete, PPF *nouveau)
{
    PPF *temp=pt_tete;
    //cas de la liste vide
    if(pt_tete == NULL)
        return nouveau;
    while(temp->suiv != NULL)
        {
            temp=temp->suiv;
        }
    temp->suiv=nouveau;
    return temp;
}

void AfficherMaillon(PPF *pt_tete)
{
    if(pt_tete == NULL)
        printf("\nLa liste est vide");
    while (pt_tete != NULL)
    {
        printf ("\nID: %d", pt_tete->id);
        printf("\nNom: %s", pt_tete->name);
        printf("\nNombre: %d", pt_tete->score);
        pt_tete= pt_tete->suiv;
    }
}

void RechercherMaillon(PPF *pt_tete,char *nomrech)
{
    if (pt_tete == NULL)
        printf ("\nLa liste est vide");
    else
    {
        while (pt_tete != NULL && strcmp(pt_tete->name,nomrech)!=0)
        {
            pt_tete=pt_tete->suiv;
        }
        if (pt_tete == NULL)
            printf ("\n%s n'est pas dans la liste",nomrech);
        else
        {
            printf("\nID: %d",pt_tete->id);
            printf("\nNom: %s", pt_tete->name);
            printf("\nNombre: %d",pt_tete->score);
        }
    }
}

PPF* RechercherMaillonNombre(PPF *pt_tete,int nombrerech)
{
    PPF *pt_maillon = NULL;
    if (pt_tete == NULL)
        printf ("\nLa liste est vide");
    else
    {
        while (pt_tete != NULL && pt_tete->id != nombrerech)
        {
            pt_tete=pt_tete->suiv;
        }
        if (pt_tete == NULL)
            return pt_maillon;
        else
        {
            PPF *pt_maillon_ok = NULL;
            pt_maillon_ok = (PPF*)malloc(sizeof(PPF));
            pt_maillon_ok->id = pt_tete->id;
            strcpy(pt_maillon_ok->name,pt_tete->name);
            // Placer le nombre de torture en parametre et faire un case of pour le score de depravation
            pt_maillon_ok->score = pt_tete->score -200;
            pt_maillon_ok->cpt = 0;
            pt_maillon_ok->suiv = NULL;

            return pt_maillon_ok;
        }
    }
}

void SupprimerMaillon(PPF **pt_tete,char *nomrech)
{
    PPF *pt_courant = *pt_tete;
    PPF *pt_precedent = *pt_tete;
    if (*pt_tete == NULL)
        printf ("\nLa liste est vide");
    else
    {
        while (pt_tete != NULL && strcmp(pt_courant->name, nomrech)!=0)
        {
            pt_precedent = pt_courant;
            pt_courant=pt_courant->suiv;
        }
        if (pt_courant == pt_precedent)
            *pt_tete = pt_courant->suiv;
        else
        if (pt_courant== NULL)
            printf("\n%s nest pas dans la liste",nomrech);
        else
            pt_precedent->suiv=pt_courant->suiv;

        free(pt_courant);
        pt_courant=NULL;
    }
}

void SupprimerMaillonID(PPF **pt_tete,int nombrerech)
{
    PPF *pt_courant = *pt_tete;
    PPF *pt_precedent = *pt_tete;
    if (*pt_tete == NULL)
        printf ("\nLa liste est vide");
    else
    {
        while (pt_tete != NULL && pt_courant->id != nombrerech)
        {
            pt_precedent = pt_courant;
            pt_courant=pt_courant->suiv;
        }
        if (pt_courant == pt_precedent)
            *pt_tete = pt_courant->suiv;
        else
        if (pt_courant== NULL)
            printf("\n%d nest pas dans la liste", nombrerech);
        else
            pt_precedent->suiv=pt_courant->suiv;

        free(pt_courant);
        pt_courant=NULL;
    }
}

void EcrireFichier(FILE *database_PPF,PPF *pt_tete,int flag)
{
    if (flag == 0)
        database_PPF = fopen ("database_PFF.bin","w+");
    else
        database_PPF = fopen("database_PFF_SIMU.bin","w+");
    int i = 0;
    while(pt_tete != NULL)
    {
        i = fwrite(pt_tete,sizeof(PPF),1, database_PPF);
        if(i != 1)
        {
            printf("\nErreur a l'ecriture");
            break;
        }
        pt_tete = pt_tete->suiv;
    }
    fclose(database_PPF);
}

PPF* LireFichier(FILE *database_PFF, int flag)
{
    if (flag == 0)
        database_PFF = fopen ("database_PFF.bin","r");
    else
        database_PFF = fopen("database_PFF_SIMU.bin","r");
    PPF tmp;
    PPF *pt_tete = NULL;
    PPF *pt_nouveau = NULL;
    fseek(database_PFF,0, SEEK_SET);
    memset(&tmp,'\0', sizeof(PPF));
    while(fread(&tmp,sizeof(PPF),1,database_PFF))
    {
        if(NULL == (pt_nouveau = (PPF*)malloc(sizeof(PPF))))
        {
            printf("\nErreur a la creation du maillon");
            break;
        }
        else
        {
            *pt_nouveau = tmp;
            pt_nouveau->suiv = NULL;
            InsererMaillonEnQueue(&pt_tete, pt_nouveau);
            memset(&tmp,'\0', sizeof(PPF));
        }

    }
    fclose(database_PFF);
    return pt_tete;
}