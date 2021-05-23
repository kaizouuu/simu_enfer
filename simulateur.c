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

int moteurSimulation(struct ech*A, struct cours_algo **pt_tete_cours_algo)//fais tourner la simulation
{

	struct evt *Evt_a_traiter = NULL; //Nous servira à garder les informations de ce qu'on retire de la file
//	Evt_a_traiter = (EVT*) malloc(sizeof(EVT));
Evt_a_traiter = malloc(sizeof(struct evt));
	struct evt *Evt_cree = NULL; //Pointera vers le nouvelle évènement qu'on génére
	struct cours_algo*nouveau_cour_algo;
	
	int etat = 1;
	
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
				A->nbr_evt_arrivee --;
				if (Evt_a_traiter->type_torture == 1)
				{
					if (A->nb_pers_cours_algo < A->nb_place_cours_algo)
					{
						A-> nb_pers_cours_algo = A-> nb_pers_cours_algo + 1;
						Evt_cree = creerEvenement(Evt_a_traiter, DEBUT_TORTURE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_cree->id_ppf, Evt_cree->id_score, Evt_cree->type_evt,Evt_cree->duree_torture,  Evt_cree->t_evt, Evt_cree->type_torture );
						A->nbr_evt_debut_torture ++;

					}
					else
					{
						Evt_cree = creerEvenement(Evt_a_traiter, ATTENTE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_cree->id_ppf, Evt_cree->id_score, Evt_cree->type_evt,Evt_cree->duree_torture,  Evt_cree->t_evt, Evt_cree->type_torture );
						A->nbr_evt_attente ++;
					}
				}
				else
					printf("\n\nERREUR DANS LA FONCTION MOTEUR SIMULATION ATTENTE\n");
			break;
			
			case ATTENTE :
				A->nbr_evt_attente =A->nbr_evt_attente - 1;
				if (Evt_a_traiter->type_torture == 1)
				{
					if (A->nb_pers_cours_algo < A->nb_place_cours_algo)
					{
						A-> nb_pers_cours_algo ++;
						Evt_cree = creerEvenement(Evt_a_traiter, DEBUT_TORTURE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_cree->id_ppf, Evt_cree->id_score, Evt_cree->type_evt,Evt_cree->duree_torture,  Evt_cree->t_evt, Evt_cree->type_torture );
						A->nbr_evt_debut_torture ++;
					}
					else
					{
						Evt_cree = creerEvenement(Evt_a_traiter, ATTENTE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_cree->id_ppf, Evt_cree->id_score, Evt_cree->type_evt,Evt_cree->duree_torture,  Evt_cree->t_evt, Evt_cree->type_torture );
						A->nbr_evt_attente = A->nbr_evt_attente + 1;
					}
				}
				
				else
					printf("\n\nERREUR DANS LA FONCTION MOTEUR SIMULATION ATTENTE\n");
			
			break;
			
			case DEBUT_TORTURE : //Faut il rajouter un while (pt_tete !=NULL) pour faire boucler les damnes
				A->nbr_evt_debut_torture --;
				if(Evt_a_traiter->type_torture == 1)
				{
					nouveau_cour_algo = CreerMaillonTortureCoursAlgoSimulation(Evt_a_traiter->id_ppf);
					InsererMaillonEnQueueTortureCoursAlgo(pt_tete_cours_algo,nouveau_cour_algo);
				}
	
				Evt_cree = creerEvenement(Evt_a_traiter, FIN_TORTURE, A->t_cour+Evt_a_traiter->duree_torture); //LE PLUS 20 EST A MODIFIER EN FONCTION DU TEMPS QUE PREND LA TORTURE -> duree_torture
				ajouterAvecPrioriteFileEvenement(A,  Evt_cree->id_ppf, Evt_cree->id_score, Evt_cree->type_evt,Evt_cree->duree_torture,  Evt_cree->t_evt, Evt_cree->type_torture);
				A->nbr_evt_fin_torture ++;
					
			break;
			
			case FIN_TORTURE : 
				A->nbr_evt_fin_torture --;
				if (Evt_a_traiter->type_torture == 1)
				{
						A-> nb_pers_cours_algo --;			
						SupprimerMaillonTortureCoursAlgo(pt_tete_cours_algo, Evt_a_traiter->id_ppf);	
						A->nbr_ames_pardonnees ++;	
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



void aiguillageDamnesArrivants(struct ech* echeancier, struct ppf * pt_tete,  int *identifiant, int aleatoire_bool, int t_final_arret)//genere un evenement d'arriver et aiguille dans les torture
{	
	int type_torture = 0; 
	int duree_torture = 0;
	int t_aleatoire = 0;
	
	struct ech *A = echeancier;
	struct ppf *pt_damne_a_traiter = pt_tete;
	
	while(pt_damne_a_traiter->id != *identifiant)
	{
		pt_damne_a_traiter = pt_damne_a_traiter->suiv;
	}
		
	if (pt_damne_a_traiter->score <= 0)
	{
		//PARTIE CODE POUR UTILISATION DE PLUSIEURS TORTURES EVENTUELLES
	}
	else 
	{
		type_torture =1;
		duree_torture = pt_damne_a_traiter->score / A->efficacite_algo;
		echeancier->nbr_evt_arrivee ++;
	}

	if (aleatoire_bool != 1)
		ajouterAvecPrioriteFileEvenement(A,  pt_damne_a_traiter->id, pt_damne_a_traiter->score, 1, duree_torture, A->t_cour+1, type_torture ); // génére des évènements arrivee
	else
	{
		t_aleatoire = (rand() % t_final_arret-1) + 1; //+1 pour ne pas avoir d'évènement à t = 0 et -1 pour ne pas générer d'évènement après le tps de fin. 
		ajouterAvecPrioriteFileEvenement(A,  pt_damne_a_traiter->id, pt_damne_a_traiter->score, 1, duree_torture, A->t_cour+t_aleatoire, type_torture ); // génére des évènements arrivee
	}
}


void selectionTempsArret(int * tps)//selection le temps final de la simu
{
	printf("\nVeuillez sélectionner le temps d'arrêt de la simulation: ");
		scanf("%d",tps);
}		


void menu(struct ppf **pt_tete, struct ppf*nouveau, struct cours_algo **pt_tete_cours_algo, struct cours_algo *nouveau_cour_algo, struct ech* echeancier)//affichage du menu et utilisation des fonctions
{
    int i = 0 ;
    int q = 0, r=0, s=0, t=0, u=0, v=0 ; ; //utilisé en test 15 pour retirer dans la structure évènement
    int simu_en_marche = 1 ;
    int t_final_arret = 0;
    int nbr_ames_a_cree=0;
	int dernier_id_ppf = 0;
	int id_suppr = 0;
	
	int a_test =0;

    
    do{
		system("clear");
        printf("\n********** Configuration de la Simulation **********\n");
        printf ("|  0 | Quitter le programme\n");
        printf ("|  2 | Test unitaire damnés: Afficher la liste des âmes damnées\n");
        printf ("|  4 | Test unitaire damnés: Supprimer un damné\n");
        printf( "|  8 | Test unitaire torture : Afficher la liste des maillon dans ma chaine ALGO\n\n");

        printf ("| 15 | Test unitaire évènement : Afficher la file des évènements\n");
        printf ("| 16 | Test unitaire évènement : Retirer évènement (avec t_evt le plus petit)\n\n");
        
        printf ("| 17 | FONCTION CONFIGURATION : Sélection du temps d'arrêt de la simulation\n");
        printf ("| 18 | FONCTION CONFIGURATION : Séléction de l'Architecture des Enfers\n");
        printf ("| 19 | FONCTION CONFIGURATION : Séléction du nombre de damnés original à générer à t=0 et à t=aléatoire\n\n");

        printf ("| 21 | SIMULATION : Automatique\n");
        printf ("| 22 | SIMULATION : Coup par coup\n\n");

        
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
				printf("\nCombien d'âmes damnées souhaitez-vous créer pour lancer la simulation à t = 0 ?\n");	
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
				
				printf("\nCombien d'âmes damnées souhaitez-vous créer aléatoirement ?\n");	
				scanf("%d",&nbr_ames_a_cree);
				
				for ( int j = 0;  j < nbr_ames_a_cree;  j = j+1)
				{
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
					simu_en_marche = moteurSimulation(echeancier, pt_tete_cours_algo);

					printf("\nHorloge interne simulation:%d, Nbr Personne Cours Algo = %d, Arrivee = %d, Attente = %d, Début Torture = %d et Fin Torture = %d. Ames Pardonnees = %d", echeancier->t_cour, echeancier-> nb_pers_cours_algo, echeancier->nbr_evt_arrivee, echeancier->nbr_evt_attente, echeancier->nbr_evt_debut_torture, echeancier->nbr_evt_fin_torture, echeancier->nbr_ames_pardonnees);
					fflush(stdout);
	
				}
				printf("\nAppuyer sur ENTREE pour continuer:"); 
				while ((getchar())!= '\n');
				getchar();
                break;
            case 22:
				system("clear");
				while (simu_en_marche == 1 && echeancier->t_cour < t_final_arret)
				{		
				simu_en_marche = moteurSimulation(echeancier, pt_tete_cours_algo);
				afficherFileEvenement(echeancier);
				printf("\nAppuyer sur continuer la simulation:"); 
				while ((getchar())!= '\n');
				getchar();
				system("clear");
				}
				break;

                
            default:
                break;
        }
    }while (i != 0);
}
