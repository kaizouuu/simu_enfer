#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions_damnes.h"


void menu(PPF **pt_tete,PPF *nouveau,char *nomrech,FILE *database_PFF,COURS_ALGO **pt_tete_cours_algo,COURS_ALGO *nouveau_cour_algo,FILE_POSTE **pt_tete_file_poste,FILE_POSTE *nouveau_file_poste, EPILATION_CHEVEUX **pt_tete_epilation_cheveux,MARSEILLAIS **pt_tete_marseillais,int nombrerech)
{
    int i;
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
        printf (" 13 pour aiguiller les dannees dans les différentes toture\n");
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
                break;
            case 4:
                printf("Saisissez un nom a suprimer\n");
                scanf("%s",nomrech);
                SupprimerMaillon(pt_tete,nomrech);
                break;
            case 5:
                EcrireFichier(database_PFF,*pt_tete);
                break;
            case 6:
                *pt_tete = LireFichier(database_PFF);
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
                AiguillagePurgatoire(*pt_tete, pt_tete_cours_algo,nouveau_cour_algo);
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
    printf("Entrer le score de depravation de votre PPF:\n");
    scanf("%d",&(*pt_maillon).score);
    pt_maillon->suiv=NULL;

    return pt_maillon;
}

void InsererMaillonEnQueue(PPF **pt_tete,PPF *nouveau)

{
    PPF *temp=*pt_tete;
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

void EcrireFichier(FILE *database_PPF,PPF *pt_tete)
{
    database_PPF = fopen ("database_PFF.bin","w+");
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

PPF* LireFichier(FILE *database_PFF)
{
    database_PFF = fopen ("database_PFF.bin","r");
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


//*******************************Fonction Pour L'Aiguillage***************************************************
void AiguillagePurgatoire(PPF *pt_tete,COURS_ALGO **pt_tete_cours_algo,COURS_ALGO *nouveau_cour_algo)
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
            //t=10;
            //timer1(t,pt_tete->cpt);
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

/*void timer1(int *t,PPF *cpt)
{
    for(0;t;t++)
    {
        if(sleep(1000)==0)
            printf("%d",cpt);
            cpt++;
    }
}*/
/*EPILATION_CHEVEUX* CreerMaillonTortureEpilationCheveux(EPILATION_CHEVEUX *pt_tete_epilation_cheveux)
{
    EPILATION_CHEVEUX *pt_maillon = NULL;
    pt_maillon = (EPILATION_CHEVEUX*)malloc(sizeof(EPILATION_CHEVEUX));
    int i = 0;
    if(pt_tete_epilation_cheveux == NULL)
        pt_maillon->id = 0;
    else
    {
        while(pt_tete_epilation_cheveux != NULL)
        {
            pt_tete_epilation_cheveux = pt_tete_epilation_cheveux->suiv;
            i ++;
        }
    }
    pt_maillon->id = i;
    pt_maillon->cpt = 0;
    pt_maillon->suiv=NULL;

    return pt_maillon;
}

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
    }*/

//fonction timer
/*int timer(int *temps)
{
	
	int timer0=0;
	int *t=temps;
	clock_t depart, arrivee = 0;
	depart=clock();

	if((depart - arrivee) == *t)
	{
		timer0++;
		arrivee = depart;
		printf("ca compte\n");
	}
	return timer0;
}
*/
