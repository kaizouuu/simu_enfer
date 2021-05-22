#include "evenements.h"
#include "simulateur.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "fonctions_damnes.h"
#include "torture.h"

//*******************************Fonction Pour L'Aiguillage*************************************************

int moteurSimulation(struct ech*A, struct ppf * pt_tete , struct cours_algo **pt_tete_cours_algo, struct file_poste **pt_tete_file_poste, struct epilation_cheveux **pt_tete_epilation_cheveux, struct marseillais **pt_tete_marseillais, int* t_final_arret)
{
	struct evt *Evt_a_traiter = NULL; //Nous servira à garder les informations de ce qu'on retire de la file
//	Evt_a_traiter = (EVT*) malloc(sizeof(EVT));
Evt_a_traiter = malloc(sizeof(struct evt));
	struct evt *Evt_cree = NULL; //Pointera vers le nouvelle évènement qu'on génére
	struct cours_algo*nouveau_cour_algo;
	struct file_poste*nouveau_file_poste;
	struct epilation_cheveux*nouveau_epilation_cheveux;
	struct marseillais*nouveau_marseillais;
	
	struct ppf *pt_tete_ppf = pt_tete;

	int etat = 1;

	//A->nb_pers_cours_algo = CompteurCoursAlgo(*pt_tete_cours_algo);
	
	if (filevideEvenement(A) == 1) // Si la file de l'échéancier est vide, on arrête la simulation  
	{	etat = 0;
		printf("\nArrêt Simulation"); 
	}
	else
	{

		retirerFileEvenement(A, &Evt_a_traiter->id_ppf, &Evt_a_traiter->id_score, &Evt_a_traiter->type_evt, &Evt_a_traiter->duree_torture, &Evt_a_traiter->t_evt, &Evt_a_traiter->type_torture );        // On traite le premier élèment de liste à évènements, avec les pointeurs on a mis un truc intéressant dans valeur
		A->t_cour = Evt_a_traiter->t_evt;                  // C'est ici que le temps de la simulation saute à celui de l'événement en cours de traitement ?
		// 
		switch (Evt_a_traiter->type_evt)
		{
			case ARRIVEE :
				A->nbr_evt_arrivee =A->nbr_evt_arrivee - 1;
				if (Evt_a_traiter->type_torture == 4)
				{
					if (A->nb_pers_cours_algo < A->nb_place_cours_algo)
					{
						Evt_cree = creerEvenement(Evt_a_traiter, DEBUT_TORTURE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_cree->id_ppf, Evt_cree->id_score, Evt_cree->type_evt,Evt_cree->duree_torture,  Evt_cree->t_evt, Evt_cree->type_torture );
						++A->nbr_evt_debut_torture;

					}
					else
					{
						Evt_cree = creerEvenement(Evt_a_traiter, ATTENTE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_cree->id_ppf, Evt_cree->id_score, Evt_cree->type_evt,Evt_cree->duree_torture,  Evt_cree->t_evt, Evt_cree->type_torture );
						++A->nbr_evt_attente;
					}
				}
	

				else if (Evt_a_traiter->type_torture == 3)
				{
					if (A->nb_pers_file_poste < A->nb_place_file_poste)
					{
						Evt_cree = creerEvenement(Evt_a_traiter, DEBUT_TORTURE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_cree->id_ppf, Evt_cree->id_score, Evt_cree->type_evt,Evt_cree->duree_torture,  Evt_cree->t_evt, Evt_cree->type_torture );
						++A->nbr_evt_debut_torture;

					}
					else
					{
						Evt_cree = creerEvenement(Evt_a_traiter, ATTENTE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_cree->id_ppf, Evt_cree->id_score, Evt_cree->type_evt,Evt_cree->duree_torture,  Evt_cree->t_evt, Evt_cree->type_torture );
						++A->nbr_evt_attente;
					}
				}
			

				else if (Evt_a_traiter->type_torture == 2)
				{
					if (A->nb_pers_epilation_cheveux < A->nb_place_epilation_cheveux)
					{
						Evt_cree = creerEvenement(Evt_a_traiter, DEBUT_TORTURE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_cree->id_ppf, Evt_cree->id_score, Evt_cree->type_evt,Evt_cree->duree_torture,  Evt_cree->t_evt, Evt_cree->type_torture );
						++A->nbr_evt_debut_torture;

					}
					else
					{
						Evt_cree = creerEvenement(Evt_a_traiter, ATTENTE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_cree->id_ppf, Evt_cree->id_score, Evt_cree->type_evt,Evt_cree->duree_torture,  Evt_cree->t_evt, Evt_cree->type_torture );
						++A->nbr_evt_attente;
					}
				}
			

				else if (Evt_a_traiter->type_torture == 1)
				{
					if (A->nb_pers_marseillais < A->nb_place_marseillais)
					{
						Evt_cree = creerEvenement(Evt_a_traiter, DEBUT_TORTURE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_cree->id_ppf, Evt_cree->id_score, Evt_cree->type_evt,Evt_cree->duree_torture,  Evt_cree->t_evt, Evt_cree->type_torture );
						++A->nbr_evt_debut_torture;

					}
					else
					{
						Evt_cree = creerEvenement(Evt_a_traiter, ATTENTE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_cree->id_ppf, Evt_cree->id_score, Evt_cree->type_evt,Evt_cree->duree_torture,  Evt_cree->t_evt, Evt_cree->type_torture );
						++A->nbr_evt_attente;
					}
				}
				else
					printf("\n\nERREUR DANS LA FONCTION MOTEUR SIMULATION ATTENTE\n");
		
			break;
			
			case ATTENTE :
				A->nbr_evt_attente =A->nbr_evt_attente - 1;
				if (Evt_a_traiter->type_torture == 4)
				{
					if (A->nb_pers_cours_algo < A->nb_place_cours_algo)
					{
						Evt_cree = creerEvenement(Evt_a_traiter, DEBUT_TORTURE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_cree->id_ppf, Evt_cree->id_score, Evt_cree->type_evt,Evt_cree->duree_torture,  Evt_cree->t_evt, Evt_cree->type_torture );
						++A->nbr_evt_debut_torture;
					}
					else
					{
						Evt_cree = creerEvenement(Evt_a_traiter, ATTENTE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_cree->id_ppf, Evt_cree->id_score, Evt_cree->type_evt,Evt_cree->duree_torture,  Evt_cree->t_evt, Evt_cree->type_torture );
						A->nbr_evt_attente = A->nbr_evt_attente + 1;
					}
				}
				else if (Evt_a_traiter->type_torture == 3)
				{
					if (A->nb_pers_file_poste < A->nb_place_file_poste)
					{
						Evt_cree = creerEvenement(Evt_a_traiter, DEBUT_TORTURE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_cree->id_ppf, Evt_cree->id_score, Evt_cree->type_evt,Evt_cree->duree_torture,  Evt_cree->t_evt, Evt_cree->type_torture );
						++A->nbr_evt_debut_torture;

					}
					else
					{
						Evt_cree = creerEvenement(Evt_a_traiter, ATTENTE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_cree->id_ppf, Evt_cree->id_score, Evt_cree->type_evt,Evt_cree->duree_torture,  Evt_cree->t_evt, Evt_cree->type_torture );
						++A->nbr_evt_attente;
					}
				}
				

				else if (Evt_a_traiter->type_torture == 2)
				{
					if (A->nb_pers_epilation_cheveux < A->nb_place_epilation_cheveux)
					{
						Evt_cree = creerEvenement(Evt_a_traiter, DEBUT_TORTURE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_cree->id_ppf, Evt_cree->id_score, Evt_cree->type_evt,Evt_cree->duree_torture,  Evt_cree->t_evt, Evt_cree->type_torture );
						++A->nbr_evt_debut_torture;

					}
					else
					{
						Evt_cree = creerEvenement(Evt_a_traiter, ATTENTE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_cree->id_ppf, Evt_cree->id_score, Evt_cree->type_evt,Evt_cree->duree_torture,  Evt_cree->t_evt, Evt_cree->type_torture );
						++A->nbr_evt_attente;
					}
				}
		

				else if (Evt_a_traiter->type_torture == 1)
				{
					if (A->nb_pers_marseillais < A->nb_place_marseillais)
					{
						Evt_cree = creerEvenement(Evt_a_traiter, DEBUT_TORTURE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_cree->id_ppf, Evt_cree->id_score, Evt_cree->type_evt,Evt_cree->duree_torture,  Evt_cree->t_evt, Evt_cree->type_torture );
						++A->nbr_evt_debut_torture;

					}
					else
					{
						Evt_cree = creerEvenement(Evt_a_traiter, ATTENTE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_cree->id_ppf, Evt_cree->id_score, Evt_cree->type_evt,Evt_cree->duree_torture,  Evt_cree->t_evt, Evt_cree->type_torture );
						++A->nbr_evt_attente;
					}
				}
				else
					printf("\n\nERREUR DANS LA FONCTION MOTEUR SIMULATION ATTENTE\n");
	
			break;
			
			case DEBUT_TORTURE : //Faut il rajouter un while (pt_tete !=NULL) pour faire boucler les damnes
				--A->nbr_evt_debut_torture;
			//CREER UNE SALLE DE TORTURE POUR MON DAMNE		
				if(Evt_a_traiter->type_torture == 4)
				{
					++A-> nb_pers_cours_algo;
					nouveau_cour_algo = CreerMaillonTortureCoursAlgoSimulation(Evt_a_traiter->id_ppf);
					InsererMaillonEnQueueTortureCoursAlgo(pt_tete_cours_algo,nouveau_cour_algo);
				}
				else if(Evt_a_traiter->type_torture == 3)
				{
					++A-> nb_pers_file_poste;
					nouveau_file_poste = CreerMaillonTortureFilePosteSimulation(Evt_a_traiter->id_ppf);
					InsererMaillonEnQueueTortureFilePoste(pt_tete_file_poste,nouveau_file_poste);
				}
				else if(Evt_a_traiter->type_torture == 2)
				{
					++A-> nb_pers_epilation_cheveux;
					nouveau_epilation_cheveux = CreerMaillonTortureEpilationCheveuxSimulation(Evt_a_traiter->id_ppf);
					InsererMaillonEnQueueTortureEpilationCheveux(pt_tete_epilation_cheveux,nouveau_epilation_cheveux);
				}
				else if(Evt_a_traiter->type_torture == 1)
				{
					++A-> nb_pers_marseillais;
					nouveau_marseillais = CreerMaillonTortureMarseillaisSimulation(Evt_a_traiter->id_ppf);
					InsererMaillonEnQueueTortureMarseillais(pt_tete_marseillais,nouveau_marseillais);
				}
				else
					printf("\n\nERREUR DANS LA FONCTION MOTEUR SIMULATION ATTENTE\n");

				Evt_cree = creerEvenement(Evt_a_traiter, FIN_TORTURE, A->t_cour+Evt_a_traiter->duree_torture); 
				ajouterAvecPrioriteFileEvenement(A,  Evt_cree->id_ppf, Evt_cree->id_score, Evt_cree->type_evt,Evt_cree->duree_torture,  Evt_cree->t_evt, Evt_cree->type_torture);
				++A->nbr_evt_fin_torture;
			break;
			
			case FIN_TORTURE : 
				--A->nbr_evt_fin_torture;
				while(&pt_tete_ppf->id != &Evt_a_traiter->id_ppf )
				{
					pt_tete_ppf = pt_tete_ppf->suiv;
				}
				//~ pt_tete_ppf->score = Evt_a_traiter->id_score;
				printf("pt_tete_ppf->score: %d et  Evt_a_traiter->id_score :%d",  pt_tete_ppf->score, Evt_a_traiter->id_score);
				
				if (Evt_a_traiter->type_torture == 4)
				{
						--A-> nb_pers_cours_algo;
						//SUPPRIMER LA SALLE DE TORTURE DU DAMNE					
						SupprimerMaillonTortureCoursAlgo(pt_tete_cours_algo, Evt_a_traiter->id_ppf);	
						aiguillageDamnesArrivants(A,  pt_tete_ppf,  &Evt_a_traiter->id_ppf, 0, *t_final_arret);
				}
				else if (Evt_a_traiter->type_torture == 3)
				{
						--A-> nb_pers_file_poste;
						//SUPPRIMER LA SALLE DE TORTURE DU DAMNE					
						SupprimerMaillonTortureFilePoste(pt_tete_file_poste, Evt_a_traiter->id_ppf);	
						aiguillageDamnesArrivants(A,  pt_tete_ppf,  &Evt_a_traiter->id_ppf, 0, *t_final_arret);
				}
				else if (Evt_a_traiter->type_torture == 2)
				{
						--A-> nb_pers_epilation_cheveux;
						//SUPPRIMER LA SALLE DE TORTURE DU DAMNE					
						SupprimerMaillonTortureEpilationCheveux(pt_tete_epilation_cheveux, Evt_a_traiter->id_ppf);	
						aiguillageDamnesArrivants(A,  pt_tete_ppf,  &Evt_a_traiter->id_ppf, 0, *t_final_arret);

				}
				else if (Evt_a_traiter->type_torture == 1)
				{
						--A-> nb_pers_marseillais;
						//SUPPRIMER LA SALLE DE TORTURE DU DAMNE					
						SupprimerMaillonTortureMarseillais(pt_tete_marseillais, Evt_a_traiter->id_ppf);	
						++A->nbr_ames_pardonnees;

				}

				else
					printf("\n\nERREUR DANS LA FONCTION MOTEUR SIMULATION ATTENTE\n");
				
			break;
			
			default :
				etat = -1;
				
		}
	}
	free(Evt_a_traiter);
	return etat;
}

void aiguillageDamnesArrivants(struct ech* echeancier, struct ppf * pt_tete,  int *identifiant, int aleatoire_bool, int t_final_arret)
{
	
	int type_torture = 0; 
	int duree_torture = 0;
	int t_aleatoire = 0;
	
	struct ech *A = echeancier;
	//struct evt *E = A->debut;
	struct ppf *pt_damne_a_traiter = pt_tete;
	
	while(pt_damne_a_traiter->id != *identifiant)
	{
		pt_damne_a_traiter = pt_damne_a_traiter->suiv;
	}

			
	if ((pt_damne_a_traiter->score > 0 ) && (pt_damne_a_traiter->score <= 250))
	{
		type_torture = 1;
		duree_torture = pt_damne_a_traiter->score / A->efficacite_marseillais;
		++echeancier->nbr_evt_arrivee;
	}
	else if ((pt_damne_a_traiter->score > 250  ) && (pt_damne_a_traiter->score <= 500))
	{
		type_torture = 2;
		duree_torture = (pt_damne_a_traiter->score - 250)/ A->efficacite_epilation_cheveux;
		++echeancier->nbr_evt_arrivee;
	}
	
	else if ((pt_damne_a_traiter->score > 500 ) && (pt_damne_a_traiter->score <= 750))
	{
		type_torture = 3;
		duree_torture = (pt_damne_a_traiter->score - 500)/ A->efficacite_file_poste;
		++echeancier->nbr_evt_arrivee;
	}
	
	else if (pt_damne_a_traiter->score > 750 )
	{
		type_torture = 4;
		duree_torture = ((pt_damne_a_traiter->score) - 750)/ A->efficacite_algo;
		++echeancier->nbr_evt_arrivee;
	}


	if (aleatoire_bool != 1)
		ajouterAvecPrioriteFileEvenement(A,  pt_damne_a_traiter->id, pt_damne_a_traiter->score, 1, duree_torture, A->t_cour+1, type_torture ); // génére des évènements arrivee
	else
	{

		t_aleatoire = (rand() % t_final_arret-1) + 1; //+1 pour ne pas avoir d'évènement à t = 0 et -1 pour ne pas générer d'évènement après le tps de fin. 

		ajouterAvecPrioriteFileEvenement(A,  pt_damne_a_traiter->id, pt_damne_a_traiter->score, 1, duree_torture, A->t_cour+t_aleatoire, type_torture ); // génére des évènements arrivee

	}
}


void selectionTempsArret(int * tps)
{
	printf("\nVeuillez sélectionner le temps d'arrêt de la simulation: ");
		scanf("%d",tps);
}		


void menu(struct ppf **pt_tete, struct ppf*nouveau, struct cours_algo **pt_tete_cours_algo, struct cours_algo *nouveau_cour_algo, struct ech* echeancier, struct file_poste **pt_tete_file_poste,struct file_poste *nouveau_file_poste, struct epilation_cheveux **pt_tete_epilation_cheveux, struct epilation_cheveux *nouveau_epilation_cheveux, struct marseillais **pt_tete_marseillais, struct marseillais *nouveau_marseillais)
{
    int i = 0 ;
    int q = 0, r=0, s=0, t=0, u=0, v=0 ; ; //utilisé en test 15 pour retirer dans la structure évènement
    int simu_en_marche = 1 ;
    int t_final_arret = 0;
    int nbr_ames_a_cree=0;
	int dernier_id_ppf = 0;
	int id_suppr = 0;
	
	int a_test =0;
	
	int t_cour_prec = 0;
	int t_cour_suiv = 0;
	int t_diff = 0;
	
	
	//struct evt *evt_cour = NULL;
	//struct ppf *ppf_cour = NULL;
    
    do{
		//system("clear");
        printf("\n********** Configuration de la Simulation **********\n");
        printf ("|  0 | Quitter le programme\n");

        printf ("|  2 | Test unitaire damnés: Afficher la liste des âmes damnées\n");

        printf ("|  4 | Test unitaire damnés: Supprimer un damné\n");
        
        printf( "|  8 | Test unitaire torture : Afficher la liste des maillon dans ma chaine ALGO\n");

        printf ("| 15 | Test unitaire évènement : Afficher la file des évènements\n");
        printf ("| 16 | Test unitaire évènement : Retirer évènement (avec t_evt le plus petit)\n\n");
        
        printf ("| 17 | FONCTION CONFIGURATION : Sélection du temps d'arrêt de la simulation\n");
        printf ("| 18 | FONCTION CONFIGURATION : Séléction de l'Architecture des Enfers\n");
        printf ("| 19 | FONCTION CONFIGURATION : Séléction du nombre de damnés original à générer à t 0 et à t aléatoire\n\n");
        

        printf ("| 21 | FONCTION EVENEMENT : SIMULATION TOURNANT TOUTE SEULE\n");
        printf ("| 22 | FONCTION EVENEMENT : SIMULATION ESSAI UNITAIRE \n\n");

        
        printf("\n********** Configuration de la Simulation **********\n");
        scanf("%d",&i);
        switch(i)
        {
            case 0: 
                system("clear");
				exit(-69);
				break;
            case 2:
				system("clear");
                AfficherMaillonDamnes(*pt_tete);
                
                printf("\nAppuyer sur ENTREE pour continuer:"); 
					while ((getchar())!= '\n');
					getchar();
                break;
            case 4:       
				system("clear");
                printf("Saisisser l'identifiant de l'âme damnée à supprimer\n");
				scanf("%d", &id_suppr);
				supprimerDamnes_DoublePointeur(pt_tete,  &id_suppr);
				
				printf("\nAppuyer sur ENTREE pour continuer:"); 
					while ((getchar())!= '\n');
					getchar();
                break;
            case 8:
				system("clear");
                AfficherMaillonTortureCoursAlgo(*pt_tete_cours_algo);
                
                printf("\nAppuyer sur ENTREE pour continuer:"); 
					while ((getchar())!= '\n');
					getchar();
                break;

            case 15:
				system("clear");
				afficherFileEvenement(echeancier);
				
				printf("\nAppuyer sur ENTREE pour continuer:"); 
					while ((getchar())!= '\n');
					getchar();
				break;
                
            case 16:
				system("clear");
				if (retirerFileEvenement(echeancier, &q, &r, &s, &t, &u, &v)== 1)
				{
					printf("\nIdentifiant du damné: %d", q);
					printf("\nScore du damné: %d", r);
					printf("\nType de l'évènement (1 pour ARRIVEE, 2 pour ATTENTE, 3 pour DEBUT_TORTURE et 4 pour FIN_TORTURE): %d", s); //faire un truc pour ne pas afficher le nombre mais le string
					printf("\nTemps déroulement de l'évènement: %d", u);
					printf("\nDuree Torture: %d", t);
					printf("\nType de torture (Algo = 4, Poste = 3, Epilation = 2, Marseillais = 1 et Paradis = 0): %d\n", v);
				}
				else
					printf("\nFile vide aucune valeur récupérée\n");
					
				printf("\nAppuyer sur ENTREE pour continuer:"); 
				while ((getchar())!= '\n');
				getchar();
				break;
             
			case 17:
				system("clear");
				selectionTempsArret(& t_final_arret);
				
				printf("\nAppuyer sur ENTREE pour continuer:"); 
					while ((getchar())!= '\n');
					getchar();
					
                break;
                
            case 18:
				system("clear");
				selectionArchitecture(echeancier);
				
				printf("\nAppuyer sur ENTREE pour continuer:"); 
					while ((getchar())!= '\n');
					getchar();
					
                break;
                
            case 19:
				system("clear");
				printf("\nCombien d'âmes damnées souhaitez-vous créer pour lancer la simulation ?\n");	
				scanf("%d",&nbr_ames_a_cree);
				
				for ( int j = 0;  j < nbr_ames_a_cree;  j = j+1)
				{
					// srand(time(NULL));    
					nouveau = CreerMaillonAvecIDDamnesAleatoire(dernier_id_ppf+j+1);////test unitaire fonction ajoutete
					InsererMaillonEnQueueDamnes(pt_tete,nouveau);
					a_test = dernier_id_ppf+j+1;
					aiguillageDamnesArrivants(echeancier, * pt_tete,  &a_test, 0, t_final_arret);
				}
				dernier_id_ppf = nbr_ames_a_cree + dernier_id_ppf;
				
				printf("\nCombien d'âmes damnées souhaitez-vous créer pour lancer la simulation ?\n");	
				scanf("%d",&nbr_ames_a_cree);
				
				for ( int j = 0;  j < nbr_ames_a_cree;  j = j+1)
				{
					// srand(time(NULL));    
					nouveau = CreerMaillonAvecIDDamnesAleatoire(dernier_id_ppf+j+1);////test unitaire fonction ajoutete
					InsererMaillonEnQueueDamnes(pt_tete,nouveau);
					a_test = dernier_id_ppf+j+1;
					aiguillageDamnesArrivants(echeancier, * pt_tete,  &a_test, 1, t_final_arret);
				}
				dernier_id_ppf = nbr_ames_a_cree + dernier_id_ppf;
				
				printf("\nAppuyer sur ENTREE pour continuer:"); 
					while ((getchar())!= '\n');
					getchar();
					
                break;

            case 21:
				system("clear");
				printf("\n*************Simulation début*************"); 
				while (simu_en_marche == 1 && echeancier->t_cour < t_final_arret)
				{					
					t_cour_prec = echeancier->t_cour;
					t_cour_suiv = echeancier->t_cour;
					simu_en_marche = moteurSimulation(echeancier,*pt_tete, pt_tete_cours_algo, pt_tete_file_poste, pt_tete_epilation_cheveux, pt_tete_marseillais, &t_final_arret);
					
					t_cour_suiv = echeancier->t_cour;
					//calcul
					t_diff = t_cour_suiv - t_cour_prec;
					
					//sleep(t_diff/1000);
					
					//system("clear");
					printf("\rHorloge:%d, Nbr Pers Algo = %d, Nbr Pers File= %d,Nbr Pers Epil = %d,Nbr Pers Mar = %d, Arr = %d, Att = %d, Début Torture = %d et Fin Torture = %d. AmesP = %d", echeancier->t_cour, echeancier-> nb_pers_cours_algo, echeancier-> nb_pers_file_poste, echeancier-> nb_pers_epilation_cheveux, echeancier-> nb_pers_marseillais, echeancier->nbr_evt_arrivee, echeancier->nbr_evt_attente, echeancier->nbr_evt_debut_torture, echeancier->nbr_evt_fin_torture, echeancier->nbr_ames_pardonnees);
				
					affichageInfoSimulation (echeancier);
					fflush(stdout);
						
					//printf("\nHorloge interne simulation:%d", echeancier->t_cour );
					//afficherFileEvenement(echeancier);
					//printf("\nAppuyer sur ENTREE pour continuer:"); 
					while ((getchar())!= '\n');
					getchar();
					
				}
                break;
            case 22:
				system("clear");
				simu_en_marche = moteurSimulation(echeancier, *pt_tete, pt_tete_cours_algo, pt_tete_file_poste, pt_tete_epilation_cheveux, pt_tete_marseillais, &t_final_arret);
				afficherFileEvenement(echeancier);
				printf("\nAppuyer sur ENTREE pour continuer:"); 
				while ((getchar())!= '\n');
				getchar();
				break;

                
            default:
                break;
        }
    }while (i != 0);
}


void affichageInfoSimulation (struct ech *A)
{
	//printf("\rHorloge interne simulation:%d, Nbr Personne Cours Algo = %d, Arrivee = %d, Attente = %d, Début Torture = %d et Fin Torture = %d. Ames Pardonnees = %d", echeancier->t_cour, echeancier-> nb_pers_cours_algo, echeancier->nbr_evt_arrivee, echeancier->nbr_evt_attente, echeancier->nbr_evt_debut_torture, echeancier->nbr_evt_fin_torture, echeancier->nbr_ames_pardonnees);
	//~ printf("| DAMNES | STATUT |            \n");
	//~ printf("|                                                                               ");

	//~ printf("| Horloge : %d |", A->t_cour);
	//~ printf("| Horloge : %d |", A->t_cour);
	//~ printf("| DAMNES | STATUT |            \n");
	//~ printf("|                                                                               ");
	
	struct evt *cour = NULL;
	cour = A->debut;
	while(cour!=NULL)
	{	
		
		printf("\n\rIdentifiant du damné: %d |", cour->id_ppf);
		printf("Score du damné: %d |", cour->id_score);
		printf("Type de l'évènement : %d |", cour->type_evt); //faire un truc pour ne pas afficher le nombre mais le string
		printf("Temps évènement: %d |", cour->t_evt);
		printf("Duree Torture: %d |", cour->duree_torture);
		printf("Type Torture %d\n ", cour->type_torture);
		cour = cour->suiv;
	}
	
	
	
}
