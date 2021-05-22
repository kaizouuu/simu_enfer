#include "fonctions_damnes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "torture.h"
#include "evenements.h"
#include "simulateur.h"




struct ppf* CreerMaillonAvecIDDamnesAleatoire(int identifiant_damne)
{
    struct ppf *pt_maillon = NULL;
    pt_maillon = malloc(sizeof(struct ppf));
    pt_maillon->id = identifiant_damne;

    pt_maillon->score = rand() % 1000; //1000 est le score maximal
    pt_maillon->suiv=NULL;

    return pt_maillon;
}

void InsererMaillonEnQueueDamnes(struct ppf **pt_tete,struct ppf *nouveau)

{
    struct ppf *temp= *pt_tete;
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


void AfficherMaillonDamnes(struct ppf *pt_tete)
{
    if(pt_tete == NULL)
        printf("\nLa liste est vide");
    while (pt_tete != NULL)
    {
        printf ("\nID: %d", pt_tete->id);
        printf("\nNombre: %d", pt_tete->score);
        pt_tete= pt_tete->suiv;
    }
}




void supprimerDamnes_DoublePointeur(struct ppf **pt_tete, int *qui)
{
    struct ppf *pt_prec = *pt_tete;
    struct ppf *pt_courant = *pt_tete;
    
    //Cas de la liste vide
    if(*pt_tete == NULL)
        printf("La liste est vide");
    else
    {
        //Parcours de la liste jusqu'à trouver l'élément à supprimer ou atteindre la fin de la liste
        while((pt_courant != NULL) && ((&pt_courant->id) == qui))
        {
			//~ if ((&pt_courant->id) != qui)
			pt_prec=pt_courant;
            pt_courant=pt_courant->suiv;
        }
        // Cas où la suppression est faite en tête
        if(pt_courant == pt_prec)
            *pt_tete = pt_courant->suiv;
        //sinon suppression de l'élément
        else
        {
            if(pt_courant == NULL)
			{
                printf("\n%d n'est pas dans la liste", *qui);
			}
            else
			{
                pt_prec->suiv=pt_courant->suiv;
			}
		}
        free(pt_courant);
        pt_courant=NULL;
    }
}
