#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TCHAINE 60

typedef struct pff{
	int id;
	char name[TCHAINE];
	int cpt;
	int score;
	struct pff *suiv;
}PPF;

typedef struct
{
	int id;
	int cpt;
	struct COURS_ALGO *suiv;

}COURS_ALGO;

typedef struct
{
	int id;
	int cpt;
	struct FILE_POSTE *suiv;
}FILE_POSTE;

typedef struct
{
	int id;
	int cpt;
	struct EPILATION_CHEVEUX *suiv;

}EPILATION_CHEVEUX;

typedef struct
{
	int id;
	int cpt;
	struct MARSEILLAIS *suiv;

}MARSEILLAIS;

//menu
void menu(PPF **,PPF *,char *,FILE*);
//fonction de base de liste chainer
PPF* CreerMaillon();
void InsererMaillonEnQueue(PPF **,PPF *);
void AfficherMaillon(PPF *);
void RechercherMaillon(PPF *,char *);
void SupprimerMaillon(PPF **,char *);
//fonction pour aller écrire et lire sans les fichiers
void EcrireFichier (FILE *,PPF *);
PPF* LireFichier(FILE *);

int main()
{
    FILE * database_PPF = NULL;
    PPF *nouveau = NULL;
    PPF *pt_tete = NULL;
    char nomrech[TCHAINE];

    menu(&pt_tete,nouveau,nomrech,database_PPF);
    fclose(database_PPF);
    return 0;
}

void menu(PPF **pt_tete,PPF *nouveau,char *nomrech,FILE *database_PFF)
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