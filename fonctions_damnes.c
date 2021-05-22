#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "fonctions_damnes.h"
#include "torture.h"
#include "simulateur.h"
#include "time.h"

void menu(PPF **pt_tete,PPF *nouveau, COURS_ALGO **pt_tete_cours_algo,COURS_ALGO *nouveau_cour_algo, ECH* echeancier)
{
    int i = 0 ;
    int l = 0, m = 0, n = 0, o = 0, p = 0, p2 =0 ;  // utilisé en test 14 pour entrer dans la structure évènement
    int q = 0, r=0, s=0, t=0, u=0, v=0 ; ; //utilisé en test 15 pour retirer dans la structure évènement
    int simu_en_marche = 1 ;
    int flag ;
    int t_final_arret = 0;
    int nbr_ames_a_cree=0;
	int dernier_id_ppf = 0;
	int id_suppr = 0;
	
	int a_test =0;
  
	EVT *evt_cour = NULL;
	PPF *ppf_cour = NULL;
    
    do{
		system("clear");
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
					{
						getchar();
					}
                break;
            case 4:       
				system("clear");
                printf("Saisisser l'identifiant de l'âme damnée à supprimer\n");
				scanf("%d", &id_suppr);
				supprimerDamnes_DoublePointeur(pt_tete,  &id_suppr);
				
				printf("\nAppuyer sur ENTREE pour continuer:"); 
					while ((getchar())!= '\n');
					{
						getchar();
					}
                break;
            case 8:
				system("clear");
                AfficherMaillonTortureCoursAlgo(*pt_tete_cours_algo);
                
                printf("\nAppuyer sur ENTREE pour continuer:"); 
					while ((getchar())!= '\n');
					{
						getchar();
					}
                break;

            case 15:
				system("clear");
				afficherFileEvenement(echeancier);
				
				printf("\nAppuyer sur ENTREE pour continuer:"); 
					while ((getchar())!= '\n');
					{
						getchar();
					}
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
				{
					getchar();
				}
				break;
             
			case 17:
				system("clear");
				selectionTempsArret(& t_final_arret);
				
				printf("\nAppuyer sur ENTREE pour continuer:"); 
					while ((getchar())!= '\n');
					{
						getchar();
					}
					
                break;
                
            case 18:
				system("clear");
				selectionArchitecture(echeancier);
				
				printf("\nAppuyer sur ENTREE pour continuer:"); 
					while ((getchar())!= '\n');
					{
						getchar();
					}
					
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
					{
						getchar();
					}
					
                break;
                
            
            case 20:
				system("clear");
				printf("\nOn prend les âmes damnées créer dans la configuration initial et on en fait des évènements ARRIVEE:\n");	
				
				ppf_cour =  *pt_tete;
				
				while (ppf_cour != NULL)
				{	
					aiguillageDamnesArrivants(echeancier, * pt_tete,  &ppf_cour->id,0, t_final_arret);
					
					ppf_cour = ppf_cour->suiv;
				 }
				printf("\nAppuyer sur ENTREE pour continuer:"); 
					while ((getchar())!= '\n');
					{
						getchar();
					}

                break;
            case 21:
				system("clear");
				while (simu_en_marche == 1)
				{
					printf("\nSimulation début"); 
					simu_en_marche = moteurSimulation(echeancier, pt_tete_cours_algo);
					printf("\nAppuyer sur ENTREE pour continuer:"); 
					while ((getchar())!= '\n');
					{
						getchar();
					}
				}
                break;
            case 22:
				system("clear");
				simu_en_marche = moteurSimulation(echeancier, pt_tete_cours_algo);
				afficherFileEvenement(echeancier);
				printf("\nAppuyer sur ENTREE pour continuer:"); 
					while ((getchar())!= '\n');
					{
						getchar();
					}
				break;

                
            default:
                break;
        }
    }while (i != 0);
}

//~ PPF* CreerMaillonDamnes()
//~ {
    //~ PPF *pt_maillon = NULL;
    //~ pt_maillon = (PPF*)malloc(sizeof(PPF));
    //~ printf("Donner un id a votre PFF: \n");
    //~ scanf("%d",&(*pt_maillon).id);
    //~ printf("Donner un nom a votre PFF: \n");
    //~ scanf("%s",pt_maillon->name);
    //~ pt_maillon->cpt = 0;
    //~ printf("Entrer le score de depravation de votre PPF:\n");
    //~ scanf("%d",&(*pt_maillon).score);
    //~ pt_maillon->suiv=NULL;

    //~ return pt_maillon;
//~ }

//~ PPF* CreerMaillonAvecIDDamnes(int identifiant_damne)
//~ {
    //~ PPF *pt_maillon = NULL;
    //~ pt_maillon = (PPF*)malloc(sizeof(PPF));
    //~ pt_maillon->id = identifiant_damne;
    
    //~ printf("\n\nDonner un nom a votre PFF: \n");
    //~ scanf("%s",pt_maillon->name);
    //~ pt_maillon->cpt = 0;
    //~ printf("Entrer le score de depravation de votre PPF:\n");
    //~ scanf("%d",&(*pt_maillon).score);
    //~ pt_maillon->suiv=NULL;

    //~ return pt_maillon;
//~ }

PPF* CreerMaillonAvecIDDamnesAleatoire(int identifiant_damne)
{
    PPF *pt_maillon = NULL;
    pt_maillon = (PPF*)malloc(sizeof(PPF));
    pt_maillon->id = identifiant_damne;

    pt_maillon->score = rand() % 1000; //1000 est le score maximal
    pt_maillon->suiv=NULL;

    return pt_maillon;
}

void InsererMaillonEnQueueDamnes(PPF **pt_tete,PPF *nouveau)

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



void AfficherMaillonDamnes(PPF *pt_tete)
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

void selectionArchitecture(ECH *A)
{
    printf("\n\nCombien de salles voulez-vous affecter à la section de torture par cours d'algorithmique ?\t");    
    scanf ("%d", &A->nb_place_cours_algo);


    printf("\nCombien de points de dépravation sont éliminés tous les coups d'horloge ?\t");
    scanf("%d", &A->efficacite_algo);


}

// FIFO à priorité pour les évènements 
void initFileEvenement(ECH *F)
{
	F->t_cour = 0;                       
	F->nb_evt = 0;                        
	F->efficacite_algo = 10;
	F->nb_place_cours_algo=1; //à remettre à zéro une fis les tests fini
	F->nb_pers_cours_algo=0;
	F->nbr_ames_pardonnees=0;
	F->debut = NULL;

}

int filevideEvenement(ECH *F)		/* retourne 1 si la file est vide, 0 sinon*/
{	if (F->debut == NULL)
		return 1;
	else
		return 0;
}

int filepleineEvenement(ECH*F)	/* retourne 1 si la file est pleine SIZEMAX, 0 sinon*/
{
	int iNb = 0;
	EVT *cour;	
	for(cour = F->debut; cour != NULL; cour = cour->suiv)
		iNb++;
	if (iNb >= SIZEMAX)
		return 1;
	else 	
		return 0;
}


int retirerFileEvenement(ECH *F, int *id_ppf, int *id_score, int *type_evt, int * duree_torture, int *t_evt, int *type_torture) //On envoie Id_retire en pointeur, donc on l'a quand même à la fin de la simulation
{	EVT *aSupp;
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


void ajouterAvecPrioriteFileEvenement(ECH *F, int id_ppf, int id_score, int type_evt, int duree_torture, int t_evt, int type_torture)
{	EVT*E = NULL;
	EVT*E_cour = F->debut; 
	EVT*E_prec = NULL; 
	
	if (filepleineEvenement(F) ==1)
	{	printf("\nTaille maximale de la file atteinte, ajout interdit\n");

	}	
	
	E = (EVT*) malloc(sizeof(EVT));
	
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


void afficherFileEvenement(ECH*F)
{
			EVT *cour = NULL;
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
void selectionTempsArret(int * tps)
{
	printf("\nVeuillez sélectionner le temps d'arrêt de la simulation: ");
		scanf("%d",tps);
}		


int moteurSimulation(ECH *A, COURS_ALGO **pt_tete_cours_algo)
{

	EVT *Evt_a_traiter = NULL; //Nous servira à garder les informations de ce qu'on retire de la file
	Evt_a_traiter = (EVT*) malloc(sizeof(EVT));
	EVT *Evt_cree = NULL; //Pointera vers le nouvelle évènement qu'on génére
	COURS_ALGO *nouveau_cour_algo;
	
	int etat = 1;
	printf("\nDébut moteur simulation"); 
	//A->nb_pers_cours_algo = CompteurCoursAlgo(*pt_tete_cours_algo);
	
	if (filevideEvenement(A) == 1) // Si la file de l'échéancier est vide, on arrête la simulation  
	{	etat = 0;
		printf("\nArrêt Simulation"); 
	}
	else
	{
		printf("\nElse dans la simulation"); 
		retirerFileEvenement(A, &Evt_a_traiter->id_ppf, &Evt_a_traiter->id_score, &Evt_a_traiter->type_evt, &Evt_a_traiter->duree_torture, &Evt_a_traiter->t_evt, &Evt_a_traiter->type_torture );        // On traite le premier élèment de liste à évènements, avec les pointeurs on a mis un truc intéressant dans valeur
		A->t_cour = Evt_a_traiter->t_evt;                  // C'est ici que le temps de la simulation saute à celui de l'événement en cours de traitement ?
		// 
		switch (Evt_a_traiter->type_evt)
		{
			case ARRIVEE :
				if (Evt_a_traiter->type_torture == 1)
				{
					if (A->nb_pers_cours_algo < A->nb_place_cours_algo)
					{
						printf("\nNb pers cours algo %d", A->nb_pers_cours_algo); 
						printf("\nNb place cours algo %d", A->nb_place_cours_algo); 
						A-> nb_pers_cours_algo = A-> nb_pers_cours_algo + 1;
						Evt_cree = creerEvenement(Evt_a_traiter, DEBUT_TORTURE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_cree->id_ppf, Evt_cree->id_score, Evt_cree->type_evt,Evt_cree->duree_torture,  Evt_cree->t_evt, Evt_cree->type_torture );

					}
					else
					{
						Evt_cree = creerEvenement(Evt_a_traiter, ATTENTE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_cree->id_ppf, Evt_cree->id_score, Evt_cree->type_evt,Evt_cree->duree_torture,  Evt_cree->t_evt, Evt_cree->type_torture );
						
					}
				}
				else
					printf("\n\nERREUR DANS LA FONCTION MOTEUR SIMULATION ARRIVE\n");
			break;
			
			case ATTENTE :
				if (Evt_a_traiter->type_torture == 1)
				{
					if (A->nb_pers_cours_algo < A->nb_place_cours_algo)
					{
						A-> nb_pers_cours_algo ++;
						Evt_cree = creerEvenement(Evt_a_traiter, DEBUT_TORTURE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_cree->id_ppf, Evt_cree->id_score, Evt_cree->type_evt,Evt_cree->duree_torture,  Evt_cree->t_evt, Evt_cree->type_torture );

					}
					else
					{
						Evt_cree = creerEvenement(Evt_a_traiter, ATTENTE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_cree->id_ppf, Evt_cree->id_score, Evt_cree->type_evt,Evt_cree->duree_torture,  Evt_cree->t_evt, Evt_cree->type_torture );
						
					}
				}
				
				else
					printf("\n\nERREUR DANS LA FONCTION MOTEUR SIMULATION ATTENTE\n");
			
			break;
			
			case DEBUT_TORTURE : //Faut il rajouter un while (pt_tete !=NULL) pour faire boucler les damnes
			//CREER UNE SALLE DE TORTURE POUR MON DAMNE		
				if(Evt_a_traiter->type_torture == 1)
				{
					nouveau_cour_algo = CreerMaillonTortureCoursAlgoSimulation(Evt_a_traiter->id_ppf);
					InsererMaillonEnQueueTortureCoursAlgo(pt_tete_cours_algo,nouveau_cour_algo);
				}
				//int a = Evt_a_traiter->duree_torture;
				Evt_cree = creerEvenement(Evt_a_traiter, FIN_TORTURE, A->t_cour+Evt_a_traiter->duree_torture); //LE PLUS 20 EST A MODIFIER EN FONCTION DU TEMPS QUE PREND LA TORTURE -> duree_torture
				ajouterAvecPrioriteFileEvenement(A,  Evt_cree->id_ppf, Evt_cree->id_score, Evt_cree->type_evt,Evt_cree->duree_torture,  Evt_cree->t_evt, Evt_cree->type_torture);

					
			break;
			
			case FIN_TORTURE : 
				if (Evt_a_traiter->type_torture == 1)
				{
						A-> nb_pers_cours_algo --;
						//SUPPRIMER LA SALLE DE TORTURE DU DAMNE					
						SupprimerMaillonTortureCoursAlgo(pt_tete_cours_algo, Evt_a_traiter->id_ppf);		
				}
				else
					printf("\n\nERREUR DANS LA FONCTION MOTEUR SIMULATION ATTENTE\n");
				
			break;
			
			default :
				etat = -1;
				
		}
//AFFICHAGE
	}
	free(Evt_a_traiter);
	return etat;
}


EVT* creerEvenement(EVT* Evt_a_traiter, int type_evt, int t_evt)
{
	EVT *E = NULL;
	E = (EVT*) malloc(sizeof(EVT));
	int t_aleatoire = 0;
	
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
		if (Evt_a_traiter->type_torture == 1)
		{//E->id_score = Evt_a_traiter->id_score; //Dans le cas des 4 tortures on met 4 if qui teste le type de torture
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

void aiguillageDamnesArrivants( ECH* echeancier, PPF * pt_tete,  int *identifiant, int aleatoire_bool, int t_final_arret)
{
	printf("\n\nAiguillageDamnesArrivants\n");
	
	int type_torture = 0; 
	int duree_torture = 0;
	int t_aleatoire = 0;
	
	ECH *A = echeancier;
	PPF *pt_damne_a_traiter = pt_tete;
	printf("\n\nAiguillageDamnesArrivants\n");
	printf("\n\nPT TETE VALEUR %d", pt_damne_a_traiter->id);
	
	while(pt_damne_a_traiter->id != *identifiant)
	{
		printf("\n\nAiguillageDamnesArrivantsBOUCLE\n");
		pt_damne_a_traiter = pt_damne_a_traiter->suiv;
		printf("\n\nAiguillageDamnesArrivantsBOUCLE\n");
	}
	
	printf("\n%d\n", pt_damne_a_traiter->id);
	printf("\n%d\n", pt_damne_a_traiter->score);
		
	if (pt_damne_a_traiter->score <= 0)
	{
		//~ printf("\n\nPARADIS\n");
		//~ SupprimerMaillonIDDamnes(&pt_tete, *identifiant);
		//~ A->nbr_ames_pardonnees ++;
		//PARTIE CODE POUR UTILISATION DE PLUSIEURS TORTURES EVENTUELLES
	}
	else 
	{
		printf("\n\nBLABLA\n");
		type_torture =1;
		duree_torture = pt_damne_a_traiter->score / A->efficacite_algo;
		
	}
/*	
	else if ((pt_damne_a_traiter->score > 0 ) && (pt_damne_a_traiter->score <= 250))
	{
		
		printf("\n\nCas où Marseillais\n");
		type_torture = 1;
		
		duree_torture = pt_damne_a_traiter->score / *efficacite_mars;
	}
/*
/*	
	else if ((pt_damne_a_traiter->score > 250  ) && (pt_damne_a_traiter->score <= 500))
	{
		printf("\n\nCas où Epilation\n");
		type_torture = 2;
		
		duree_torture = (pt_damne_a_traiter->score - 250)/ *efficacite_epil;
	}
	
	else if ((pt_damne_a_traiter->score > 500 ) && (pt_damne_a_traiter->score <= 750))
	{
		printf("\n\nCas où File Poste\n");
		type_torture = 3;
		
		duree_torture = (pt_damne_a_traiter->score - 500)/ *efficacite_poste;
	}
	
	else if (pt_damne_a_traiter->score > 750 )
	{
		printf("\n\nCas où Cours Algo\n");
		type_torture = 4;
		printf("\n\nCas où Cours Algo\n");
		duree_torture = ((pt_damne_a_traiter->score) - 750)/ *efficacite_algo;
	}
*/

	printf("\n\nAjout\n");
	printf("\n\nBOOLEEN %d\n", aleatoire_bool);
	
	//ajouterAvecPrioriteFileEvenement(A,  pt_damne_a_traiter->id, pt_damne_a_traiter->score, 1, duree_torture, A->t_cour+1, type_torture ); 
	if (aleatoire_bool != 1)
		ajouterAvecPrioriteFileEvenement(A,  pt_damne_a_traiter->id, pt_damne_a_traiter->score, 1, duree_torture, A->t_cour+1, type_torture ); // génére des évènements arrivee
	else
	{
		//srand(time(NULL));
		printf("\n\nOK SRAND\n");
		t_aleatoire = (rand() % t_final_arret-1) + 1; //+1 pour ne pas avoir d'évènement à t = 0 et -1 pour ne pas générer d'évènement après le tps de fin. 
		printf("\n\nOK RAND\n");
		ajouterAvecPrioriteFileEvenement(A,  pt_damne_a_traiter->id, pt_damne_a_traiter->score, 1, duree_torture, A->t_cour+t_aleatoire, type_torture ); // génére des évènements arrivee
		printf("\n\ncouille\n");
	}
}


void supprimerDamnes_DoublePointeur(PPF **pt_tete, int *qui)
{
    PPF *pt_prec = *pt_tete;
    PPF *pt_courant = *pt_tete;
    
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
