#include "evenements.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fonctions_damnes.h"
#include "simulateur.h"
#include "torture.h"

struct evt* creerEvenement(struct evt* Evt_a_traiter, int type_evt, int t_evt)
{
	struct evt *E = NULL;
	E =  malloc(sizeof(struct evt));
	
	if (type_evt == ATTENTE)
	{
		//Génération Evt Attente
		E->id_ppf = Evt_a_traiter->id_ppf;
		E->id_score = Evt_a_traiter->id_score;
		E->type_evt = type_evt;
		E->duree_torture = Evt_a_traiter->duree_torture;
		E->t_evt = t_evt;
		E->type_torture = Evt_a_traiter->type_torture;
		E->suiv = NULL;
	}	
	else if (type_evt == DEBUT_TORTURE)
	{
		//Génération Evt Debut_Torture
		E->id_ppf = Evt_a_traiter->id_ppf;
		E->id_score = Evt_a_traiter->id_score;
		E->type_evt = type_evt;
		E->duree_torture = Evt_a_traiter->duree_torture;
		E->t_evt = t_evt;
		E->type_torture = Evt_a_traiter->type_torture;
		E->suiv = NULL;
	}
	
	else if (type_evt == FIN_TORTURE)
	{
		//Génération Evt Fin_Torture
		E->id_ppf = Evt_a_traiter->id_ppf;
		if (Evt_a_traiter->type_torture == 4)
		{
			E->id_score = 749;
		}
		else if (Evt_a_traiter->type_torture == 3)
		{
			E->id_score = 499;
		}
		else if (Evt_a_traiter->type_torture == 2)
		{
			E->id_score = 249;
		}
		else if (Evt_a_traiter->type_torture == 1)
		{
			E->id_score = 0;
		}
		E->type_evt = type_evt;
		E->duree_torture = Evt_a_traiter->duree_torture;
		E->t_evt = t_evt;
		E->type_torture = Evt_a_traiter->type_torture;
		E->suiv = NULL;
	}
	
	
	else
	{
		printf("\n\nProblèmes dans creer evenements\n\n");
	}

		return E;
}


void afficherFileEvenement(struct ech*F)
{
			struct evt *cour = NULL;
			cour = F->debut;
			printf("\nFILE : \n");
			while(cour!=NULL)
			{	
				
				printf("\nIdentifiant du damné: %d", cour->id_ppf);
				printf("\nScore du damné: %d", cour->id_score);
				printf("\nType de l'évènement (1 pour ARRIVEE, 2 pour ATTENTE, 3 pour DEBUT_TORTURE et 4 pour FIN_TORTURE): %d", cour->type_evt); //faire un truc pour ne pas afficher le nombre mais le string
				printf("\nTemps déroulement de l'évènement: %d", cour->t_evt);
				printf("\nDuree Torture: %d", cour->duree_torture);
				printf("\nType de torture (Algo = 4, Poste = 3, Epilation = 2, Marseillais = 1 et Paradis = 0): %d\n", cour->type_torture);
				cour = cour->suiv;
			}
}

//AUTRE TRUC AHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH


void initFileEvenement(struct ech *F)
{
	F->t_cour = 0;                  
	F->nb_evt = 0;                        
	F->efficacite_algo = 0;
	F->nb_place_cours_algo=0; //à remettre à zéro une fis les tests fini
	F->nb_place_epilation_cheveux=0;
	F->nb_place_file_poste=0;
	F->nb_place_marseillais=0;
	F->nb_pers_cours_algo=0;
	F->nb_pers_marseillais=0;
	F->nb_pers_epilation_cheveux=0;
	F->nb_pers_file_poste=0;

	F->nbr_ames_pardonnees=0;
	F->nbr_evt_arrivee=0;
	F->nbr_evt_attente=0;
	F->nbr_evt_debut_torture=0;
	F->nbr_evt_fin_torture=0;
	F->debut = NULL;

}

int filevideEvenement(struct ech *F)		/* retourne 1 si la file est vide, 0 sinon*/
{	if (F->debut == NULL)
		return 1;
	else
		return 0;
}

int filepleineEvenement(struct ech*F)	/* retourne 1 si la file est pleine SIZEMAX, 0 sinon*/
{
	int iNb = 0;
	struct evt *cour;	
	for(cour = F->debut; cour != NULL; cour = cour->suiv)
		iNb++;
	if (iNb >= SIZEMAX)
		return 1;
	else 	
		return 0;
}


int retirerFileEvenement(struct ech *F, int *id_ppf, int *id_score, int *type_evt, int * duree_torture, int *t_evt, int *type_torture) //On envoie Id_retire en pointeur, donc on l'a quand même à la fin de la simulation
{	
	struct evt *aSupp;
	if(filevideEvenement(F)==1)
	{	printf("\nFile vide\n");
		return 0;
	}
	else
	{	aSupp = F->debut;
		*id_ppf = aSupp->id_ppf;
		*id_score = aSupp->id_score;
		*type_evt = aSupp->type_evt;
		*duree_torture = aSupp->duree_torture;
		*t_evt = aSupp->t_evt;
		*type_torture = aSupp->type_torture;
		
		
		F->debut = aSupp->suiv; 
		
		free(aSupp);
		return 1;
	}
}


void ajouterAvecPrioriteFileEvenement(struct ech *F, int id_ppf, int id_score, int type_evt, int duree_torture, int t_evt, int type_torture)
{	
	struct evt*E = NULL;
	struct evt*E_cour = F->debut; 
	struct evt*E_prec = NULL; 
	
	if (filepleineEvenement(F) ==1)
	{	printf("\nTaille maximale de la file atteinte, ajout interdit\n");

	}	
	
	E = malloc(sizeof(struct evt));
	
	if (E == NULL) 
	{	
		printf("\nAjout impossible !\n");
	}
	else
	{	
		E->id_ppf = id_ppf;
		E->id_score = id_score;
		E->type_evt = type_evt;
		E->duree_torture = duree_torture;
		E->t_evt = t_evt;
		E->type_torture = type_torture;
		E->suiv = NULL;
		
		if (filevideEvenement(F)==1)
		{
			F->debut = E;
			return;
		}
		
		else if(( F->debut->t_evt) >= t_evt ) //Cas où le premier élèment de la file à un t_evt plus éloigné, notre évènement passe donc en tête de file
		 {
			F->debut = E;
		    F->debut->suiv = E_cour;
		 }
		else 
		{			
			while(E_cour != NULL  && (E_cour->t_evt < t_evt))
			{
				E_prec = E_cour;
				E_cour = E_cour->suiv;
			}				
			E->suiv = E_cour;
			E_prec->suiv = E;
		
		}
	}
}

void selectionArchitecture(struct ech *A)
{
    printf("\n\nCombien de salles voulez-vous affecter à la section de torture par cours d'algorithmique ?\t");    
    scanf ("%d", &A->nb_place_cours_algo);
    printf("\nCombien de points de dépravation sont éliminés tous les coups d'horloge ?\t");
    scanf("%d", &A->efficacite_algo);


    printf("\n\nCombien de salles voulez-vous affecter à la section de torture epilation cheveux ?\t");    
    scanf ("%d", &A->nb_place_epilation_cheveux);
    printf("\nCombien de points de dépravation sont éliminés tous les coups d'horloge ?\t");
    scanf("%d", &A->efficacite_epilation_cheveux);


	printf("\n\nCombien de salles voulez-vous affecter à la section de torture file poste ?\t");    
    scanf ("%d", &A->nb_place_file_poste);
    printf("\nCombien de points de dépravation sont éliminés tous les coups d'horloge ?\t");
    scanf("%d", &A->efficacite_file_poste);    
	
	
	printf("\n\nCombien de salles voulez-vous affecter à la section de torture marseillais ?\t");    
    scanf ("%d", &A->nb_place_marseillais);
    printf("\nCombien de points de dépravation sont éliminés tous les coups d'horloge ?\t");
    scanf("%d", &A->efficacite_marseillais);

}














