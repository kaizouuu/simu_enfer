#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "fonctions_damnes.h"
#include "torture.h"
#include "simulateur.h"
#include "time.h"

void menu(PPF **pt_tete,PPF *nouveau,char *nomrech,FILE *database_PFF,COURS_ALGO **pt_tete_cours_algo,COURS_ALGO *nouveau_cour_algo,FILE_POSTE **pt_tete_file_poste,FILE_POSTE *nouveau_file_poste, EPILATION_CHEVEUX **pt_tete_epilation_cheveux,EPILATION_CHEVEUX *nouveau_epilation_cheveux,MARSEILLAIS **pt_tete_marseillais,MARSEILLAIS *nouveau_marseillais,int nombrerech, int nb_place_cours_algo, int nb_place_file_poste, int nb_place_epilation_cheveux, int nb_place_marseillais,int efficacite_algo, int efficacite_poste, int efficacite_epil, int efficacite_mars,ECH* echeancier, int nbr_ames_pardonnees)
{
    int i = 0 ;
    int l = 0, m = 0, n = 0, o = 0, p = 0, p2 =0 ;  // utilisé en test 14 pour entrer dans la structure évènement
    int q = 0, r=0, s=0, t=0, u=0, v=0 ; //utilisé en test 15 pour retirer dans la structure évènement
    int simu_en_marche = 1 ;
    int flag ;
    int t_final_arret = 0;
    int nbr_ames_initial=0;
    int nbr_ames_actuel=0;
  
	EVT *evt_cour = NULL;
	PPF *ppf_cour = NULL;
    
    do{
		      
        printf("\n********** Configuration de la Simulation **********\n");
        printf ("|  0 | Quitter le programme\n");
        printf ("|  1 | Test unitaire damnés: Créer une nouvelle âme damnées\n");
        printf ("|  2 | Test unitaire damnés: Afficher la liste des âmes damnées\n");
        printf ("|  3 | Test unitaire damnés: Rechercher un damné\n");  
        printf ("|  4 | Test unitaire damnés: Supprimer un damné\n");
        printf ("|  5 | Test unitaire damnés: Séléction de l'Architecture des Enfers\n");
        printf ("|  6 | Test unitaire damnés: Séléction du temps de fin du programme\n\n");
        
        printf ("|  5 | Sauvegarde MARCHE PAS\n");
        printf ("|  6 | Chargement Sauvegarde MARCHE PAS\n\n");
        
        printf( "|  7 | Test unitaire torture : Creer et inserer d'un nouveau maillon ALGO\n");
        printf( "|  8 | Test unitaire torture : Afficher la liste des maillon dans ma chaine ALGO\n");
        printf( "|  9 | Test unitaire torture : Creer et inserer d'un nouveau maillon POSTE\n");
        printf( "| 10 | Test unitaire torture : Afficher la liste des maillon dans ma chaine POSTE\n");
        printf ("| 11 | Test unitaire torture : Rechercher un maillon dans la chaine de torture ALGO\n");
        printf ("| 12 | Test unitaire torture : Supprimer un maillon dans la chaine de torture ALGO\\nn");
        
        printf ("| 13 | LANCER LA SIMULATION\n\n");
        
        printf ("| 14 | Test unitaire évènement : Créer Maillon de la File et insérer à la bonne place\n");
        printf ("| 15 | Test unitaire évènement : Afficher la file des évènements\n");
        printf ("| 16 | Test unitaire évènement : Retirer évènement (avec t_evt le plus petit)\n\n");
        
        printf ("| 17 | FONCTION CONFIGURATION : Sélection du temps d'arrêt de la simulation\n");
        printf ("| 18 | FONCTION CONFIGURATION : Séléction de l'Architecture des Enfers\n");
        printf ("| 19 | FONCTION CONFIGURATION : Séléction du nombre de damnés original à générer\n\n");
        
        printf ("| 20 | FONCTION EVENEMENT : Création des évènements ARRIVEE\n");
        printf ("| 21 | FONCTION EVENEMENT : Aiguillage et Création des évènements ATTENTE et DEBUT_TORTURE\n");
        printf ("| 22 | FONCTION EVENEMENT : Séléction du nombre de damnés original à générer\n\n");
        
        
        printf("\n********** Configuration de la Simulation **********\n");
        scanf("%d",&i);
        switch(i)
        {
            case 0: break;
            case 1:

                nouveau = CreerMaillonDamnes();////test unitaire fonction ajoutete
                InsererMaillonEnQueueDamnes(pt_tete,nouveau);
                break;
            case 2:
                AfficherMaillonDamnes(*pt_tete);
                break;
            case 3:
                printf("Saisissez un nom a rechercher\n");
                scanf("%s",nomrech);
                RechercherMaillonDamnes(*pt_tete,nomrech);
                printf("\nSaisissez un nombre a rechercher\n");
                scanf("%d",&nombrerech);
                nouveau= RechercherMaillonNombreDamnes(*pt_tete,nombrerech);
                break;
            case 4:
                printf("Saisissez le nom du damné a supprimer\n");
                scanf("%s",nomrech);
                SupprimerMaillonDamnes(pt_tete,nomrech);
                break;
            case 5:
                //~ flag = 0;
                //~ EcrireFichier(database_PFF,*pt_tete,flag);
                break;
            case 6:
                //~ flag = 0;
                //~ *pt_tete = LireFichier(database_PFF,flag);
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
				while (simu_en_marche)
				{
					simu_en_marche = moteurSimulation(echeancier);
					printf("\nAppuyer sur ENTREE pour sauter au prochain évènement"); 
						while ((getchar())!= '\n');
							getchar();
               }
                break;
            case 14 :
                //AiguillagePurgatoire(pt_tete, pt_tete_cours_algo, nouveau_cour_algo, pt_tete_file_poste, nouveau_file_poste, pt_tete_epilation_cheveux, nouveau_epilation_cheveux, pt_tete_marseillais,nouveau_marseillais);
                 //DemandeUtilisateur(nb_place_cours_algo, nb_place_file_poste, nb_place_epilation_cheveux, nb_place_marseillais,temps_torture_cours_dalgo, temps_torture_file_poste, temps_torture_epilation_cheveux, temps_torture_marseilllais);
			
				printf("Entrerle id_ppf:\n");
                scanf("%d",&l);
                printf("Entrer le id_score:\n");
                scanf("%d",&m);
                printf("Entrer le type_evt:\n");
                scanf("%d",&n);
                printf("Entrer la duree_torture:\n");
                scanf("%d",&o);
                printf("Entrer le t_evt:\n");
                scanf("%d",&p);
                printf("Entrer le type_torture:\n");
                scanf("%d",&p2);
				//ajouterAvecPriorite(ECH* debut_ech, int id_pff, int id_score, int type_evt, int t_evt, int type_torture);
				ajouterAvecPrioriteFileEvenement(echeancier, l, m, n, o, p, p2);
                break;
                
                case 15:
				afficherFileEvenement(echeancier);
                break;
                
                case 16:
                //~ if (retirer(&FILE, &theVal)== 1)
				//~ printf("\nValeur récupérée : %d", (int) theVal);	
			//~ else
				//~ printf("\nFile vide aucune valeur récupérée");	
			//~ break;
			
				if (retirerFileEvenement(echeancier, &q, &r, &s, &t, &u, &v)== 1)	
				{
					printf("\nIdentifiant du damné: %d", q);
					printf("\nScore du damné: %d", r);
					printf("\nType de l'évènement (1 pour ARRIVEE, 2 pour ATTENTE, 3 pour DEBUT_TORTURE et 4 pour FIN_TORTURE): %d", s); //faire un truc pour ne pas afficher le nombre mais le string
					printf("\nTemps déroulement de l'évènement: %d", t);
					printf("\nTemps déroulement de l'évènement: %d", u);
					printf("\nType de torture (Algo = 4, Poste = 3, Epilation = 2, Marseillais = 1 et Paradis = 0): %d\n", v);
				}
				else
					printf("\nFile vide aucune valeur récupérée\n");	
				break;
             
				case 17:
					//~ printf("\nVeuillez sélectionner le temps d'arrêt de la simulation: ");
					//~ scanf("%d",&t_final_arret);
					selectionTempsArret(& t_final_arret);
					
                break;
                
                case 18:
					selectionArchitecture(&nb_place_cours_algo, &nb_place_file_poste, &nb_place_epilation_cheveux, &nb_place_marseillais, &efficacite_algo, &efficacite_poste, &efficacite_epil, &efficacite_mars, pt_tete_cours_algo, nouveau_cour_algo, pt_tete_file_poste, nouveau_file_poste, pt_tete_epilation_cheveux, nouveau_epilation_cheveux, pt_tete_marseillais, nouveau_marseillais);
					//void selectionArchitecture(int *nb_place_cours_algo, int *nb_place_file_poste, int *nb_place_epilation_cheveux, int *nb_place_marseillais,int *temps_torture_cours_dalgo, int *temps_torture_file_poste, int *temps_torture_epilation_cheveux, int *temps_torture_marseilllais,COURS_ALGO **pt_tete_cours_algo,COURS_ALGO *nouveau_cour_algo,FILE_POSTE **pt_tete_file_poste,FILE_POSTE *nouveau_file_poste, EPILATION_CHEVEUX **pt_tete_epilation_cheveux,EPILATION_CHEVEUX *nouveau_epilation_cheveux,MARSEILLAIS **pt_tete_marseillais,MARSEILLAIS *nouveau_marseillais)
					echeancier->salle_torture_libre_algo = nb_place_cours_algo;
					echeancier->salle_torture_libre_poste = nb_place_file_poste;
					echeancier->salle_torture_libre_epil= nb_place_epilation_cheveux;
					echeancier->salle_torture_libre_mars = nb_place_marseillais;
					
                break;
                
                case 19:
					printf("\nCombien d'âmnes damnées souhaitez-vous créer pour lancer la simulation ?\n");	
					scanf("%d",&nbr_ames_initial);
					nbr_ames_actuel=nbr_ames_initial;
					
					for ( int j = 0;  j < nbr_ames_initial;  j = j+1)
					{
						nouveau = CreerMaillonAvecIDDamnes(j+1);////test unitaire fonction ajoutete
						InsererMaillonEnQueueDamnes(pt_tete,nouveau);
					}
					
                break;
                
                 case 20:
					printf("\nOn prend les âmes damnées créer dans la configuration initial et on en fait des évènements ARRIVEE:\n");	
					
					ppf_cour =  *pt_tete;
					
					while (ppf_cour != NULL)
					{	
						//aiguillageDamnesArrivants( * echeancier,  * pt_tete,* type_torture, *duree_torture,   *identifiant,  *efficacite_algo, * efficacite_poste, * efficacite_epil, * efficacite_mars);
						aiguillageDamnesArrivants( echeancier, * pt_tete,  &ppf_cour->id, &efficacite_algo, &efficacite_poste,  &efficacite_epil, &efficacite_mars, &nbr_ames_pardonnees);
						
						ppf_cour = ppf_cour->suiv;
                     }
                break;
                
            default:
                break;
        }
    }while (i != 0);
}

PPF* CreerMaillonDamnes()
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

PPF* CreerMaillonAvecIDDamnes(int identifiant_damne)
{
    PPF *pt_maillon = NULL;
    pt_maillon = (PPF*)malloc(sizeof(PPF));
    pt_maillon->id = identifiant_damne;
    printf("Donner un nom a votre PFF: \n");
    scanf("%s",pt_maillon->name);
    pt_maillon->cpt = 0;
    printf("Entrer le score de depravation de votre PPF:\n\n");
    scanf("%d",&(*pt_maillon).score);
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

//~ PPF* InsererMaillonEnQueuesimpleDamnes(PPF *pt_tete, PPF *nouveau)  // UTILE CE TRUC ???
    //~ PPF *temp=pt_tete;
    //~ //cas de la liste vide
    //~ if(pt_tete == NULL)
        //~ return nouveau;
    //~ while(temp->suiv != NULL)
        //~ {
            //~ temp=temp->suiv;
        //~ }
    //~ temp->suiv=nouveau;
    //~ return temp;
//~ }

void AfficherMaillonDamnes(PPF *pt_tete)
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

void RechercherMaillonDamnes(PPF *pt_tete,char *nomrech)
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

PPF* RechercherMaillonNombreDamnes(PPF *pt_tete,int nombrerech)
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

void SupprimerMaillonDamnes(PPF **pt_tete,char *nomrech)
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

void SupprimerMaillonIDDamnes(PPF **pt_tete,int nombrerech)
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

//~ void EcrireFichier(FILE *database_PPF,PPF *pt_tete,int flag)
//~ {
    //~ if (flag == 0)
        //~ database_PPF = fopen ("database_PFF.bin","w+");
    //~ else
        //~ database_PPF = fopen("database_PFF_SIMU.bin","w+");
    //~ int i = 0;
    //~ while(pt_tete != NULL)
    //~ {
        //~ i = fwrite(pt_tete,sizeof(PPF),1, database_PPF);
        //~ if(i != 1)
        //~ {
            //~ printf("\nErreur a l'ecriture");
            //~ break;
        //~ }
        //~ pt_tete = pt_tete->suiv;
    //~ }
    //~ fclose(database_PPF);
//~ }

//~ PPF* LireFichier(FILE *database_PFF, int flag)
//~ {
    //~ if (flag == 0)
        //~ database_PFF = fopen ("database_PFF.bin","r");
    //~ else
        //~ database_PFF = fopen("database_PFF_SIMU.bin","r");
    //~ PPF tmp;
    //~ PPF *pt_tete = NULL;
    //~ PPF *pt_nouveau = NULL;
    //~ fseek(database_PFF,0, SEEK_SET);
    //~ memset(&tmp,'\0', sizeof(PPF));
    //~ while(fread(&tmp,sizeof(PPF),1,database_PFF))
    //~ {
        //~ if(NULL == (pt_nouveau = (PPF*)malloc(sizeof(PPF))))
        //~ {
            //~ printf("\nErreur a la creation du maillon");
            //~ break;
        //~ }
        //~ else
        //~ {
            //~ *pt_nouveau = tmp;
            //~ pt_nouveau->suiv = NULL;
            //~ InsererMaillonEnQueue(&pt_tete, pt_nouveau);
            //~ memset(&tmp,'\0', sizeof(PPF));
        //~ }

    //~ }
    //~ fclose(database_PFF);
    //~ return pt_tete;
//~ }

void selectionArchitecture(int *nb_place_cours_algo, int *nb_place_file_poste, int *nb_place_epilation_cheveux, int *nb_place_marseillais,int *temps_torture_cours_dalgo, int *temps_torture_file_poste, int *temps_torture_epilation_cheveux, int *temps_torture_marseilllais,COURS_ALGO **pt_tete_cours_algo,COURS_ALGO *nouveau_cour_algo,FILE_POSTE **pt_tete_file_poste,FILE_POSTE *nouveau_file_poste, EPILATION_CHEVEUX **pt_tete_epilation_cheveux,EPILATION_CHEVEUX *nouveau_epilation_cheveux,MARSEILLAIS **pt_tete_marseillais,MARSEILLAIS *nouveau_marseillais)
{
	
	 printf("\nQuelques explications s'imposent...'\n\nLes enfers sont divisés en 4 différentes sections chargées de torturer les damnés en fonction de leur niveau de dépravation.\nLes voici de la plus dure à la plus douce: un cours d'algorithme, une file de poste sans fin, une épilation totale et brutale et enfin un visionnage forcée du meilleur des \"Marseillais\" \n\
	 Les âmes les plus pêcheresses devront passer par les 4 sections afin d'être purifiées et de pouvoir rejoindre le paradis.\n\
	 \nChaque section comporte un nombre fini de salles et est plus ou moins efficace quant à la réduction du niveau de dépravation.\nUne salle ne pourra torturer qu'une seule âme damnée à la fois. L'efficacité d'un type de torture définit le nombre de points de dépravation enlevés pour chaque coup d'horloge\n");    
	 
	 printf("\nAppuyer sur ENTREE pour commencer la saisie des informations."); 
	while ((getchar())!= '\n');
		getchar();

    printf("\n\nCombien de salles voulez-vous affecter à la section de torture par cours d'algorithmique ?\t");    
    scanf ("%d",nb_place_cours_algo);
	
	for ( int j = 0;  j < *nb_place_cours_algo;  j = j+1)
		{
			nouveau_cour_algo = CreerMaillonTortureCoursAlgo(*pt_tete_cours_algo);
            InsererMaillonEnQueueTortureCoursAlgo(pt_tete_cours_algo,nouveau_cour_algo);
		}

    printf("\nCombien de points de dépravation sont éliminés tous les coups d'horloge pour cette section ?\t");
    scanf("%d",temps_torture_cours_dalgo);


    printf("\n\nCombien de salles voulez-vous affecter à la section de torture par file de poste?\t");    
    scanf("%d",nb_place_file_poste);
    
    for ( int j = 0;  j < *nb_place_file_poste;  j = j+1)
		{
			nouveau_file_poste = CreerMaillonTortureFilePoste(*pt_tete_file_poste);
            InsererMaillonEnQueueTortureFilePoste(pt_tete_file_poste,nouveau_file_poste);
		}

    printf("\nCombien de points de dépravation sont éliminés tous les coups d'horloge pour cette section ?\t");
    scanf("%d",temps_torture_file_poste);


    printf("\n\nCombien de salles voulez-vous affecter à la section de torture par épilation intégrale (et oui, même le maillot) ?\t");    
    scanf("%d",nb_place_epilation_cheveux);
    
    for ( int j = 0;  j < *nb_place_epilation_cheveux;  j = j+1)
		{
			nouveau_epilation_cheveux = CreerMaillonTortureEpilationCheveux(*pt_tete_epilation_cheveux);
            InsererMaillonEnQueueTortureEpilationCheveux(pt_tete_epilation_cheveux,nouveau_epilation_cheveux);
		}

    printf("\nCombien de points de dépravation sont éliminés tous les coups d'horloge pour cette section ?\t");   
    scanf("%d",temps_torture_epilation_cheveux);


    printf("\n\nCombien de salles voulez-vous affecter à la section de torture par visionnage intensif des \"Marseillais\" ?\t");      
    scanf("%d",nb_place_marseillais);
    
    for ( int j = 0;  j < *nb_place_marseillais;  j = j+1)
		{
			nouveau_marseillais= CreerMaillonTortureMarseillais(*pt_tete_file_poste);
            InsererMaillonEnQueueTortureMarseillais(pt_tete_marseillais,nouveau_marseillais);
		}

    printf("\nCombien de points de dépravation sont éliminés tous les coups d'horloge pour cette section ?\t");
    scanf("%d",temps_torture_marseilllais);
}

// FIFO à priorité pour les évènements 
void initFileEvenement(ECH *F)
{
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
{	EVT*E;
	EVT*E_cour;
	
	if (filepleineEvenement(F) ==1)
	{	printf("\nTaille maximale de la file atteinte, ajout interdit\n");

	}	
	
	E = (EVT*) malloc(sizeof(EVT));
	E_cour =  (EVT*) malloc(sizeof(EVT));
	
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
			F->debut = E;
			
		else if(( F->debut->t_evt) > t_evt ) //Cas où le premier élèment de la file à un t_evt plus éloigné, notre évènement passe donc en tête de file
		 {
			E_cour = F->debut;
			F->debut = E;
		    F->debut->suiv = E_cour;
		 }
		else 
		{
			E_cour = F->debut;
			while(E_cour != NULL  && E_cour->t_evt > t_evt)
			{
				E_cour = E_cour->suiv;
			}	
			
		E->suiv = E_cour->suiv;;
		E_cour->suiv = E;
		
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


int moteurSimulation(ECH *A)
{
	int temps_traite;
	int type_traite; //ARR ou ATT ou Debut ou Fin
	int valeur;
	
	EVT Evt_a_traiter; //Nous servira à garder les informations de ce qu'on retire de la file
	EVT *Evt_cree=NULL; //Pointera vers le nouvelle évènement qu'on génére
	int etat = 1;
	
	if (filevideEvenement(A) == 1) // Si la file de l'échéancier est vide, on arrête la simulation  
		etat = 0;
	else
	{
		retirerFileEvenement(A, &Evt_a_traiter.id_ppf, &Evt_a_traiter.id_score, &Evt_a_traiter.type_evt, &Evt_a_traiter.duree_torture, &Evt_a_traiter.t_evt, &Evt_a_traiter.type_torture );            // On traite le premier élèment de liste à évènements, avec les pointeurs on a mis un truc intéressant dans valeur
		A->t_cour = Evt_a_traiter.t_evt;                  // C'est ici que le temps de la simulation saute à celui de l'événement en cours de traitement ?
		// 
		switch (Evt_a_traiter.type_evt)
		{
			case ARRIVEE :
				if (Evt_a_traiter.type_torture == 4)
				{
					if (A->salle_torture_libre_algo > 0)
					{
						A->salle_torture_libre_algo = A->salle_torture_libre_algo - 1;
						Evt_cree = creerEvenement(&Evt_a_traiter, DEBUT_TORTURE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_a_traiter.id_ppf, Evt_a_traiter.id_score, Evt_a_traiter.type_evt, Evt_a_traiter.duree_torture, Evt_a_traiter.t_evt, Evt_a_traiter.type_torture );
						
					}
					else //cas ou il n'y a plus de place
					{
						Evt_cree = creerEvenement(&Evt_a_traiter, ATTENTE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_a_traiter.id_ppf, Evt_a_traiter.id_score, Evt_a_traiter.type_evt, Evt_a_traiter.duree_torture, Evt_a_traiter.t_evt, Evt_a_traiter.type_torture );
						
					}
				}
				
				else if (Evt_a_traiter.type_torture == 3)
				{
					if (A->salle_torture_libre_poste > 0)
					{
						A->salle_torture_libre_poste = A->salle_torture_libre_poste - 1;
						Evt_cree = creerEvenement(&Evt_a_traiter, DEBUT_TORTURE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_a_traiter.id_ppf, Evt_a_traiter.id_score, Evt_a_traiter.type_evt, Evt_a_traiter.duree_torture, Evt_a_traiter.t_evt, Evt_a_traiter.type_torture );
						
					}
					else
					{
						Evt_cree = creerEvenement(&Evt_a_traiter, ATTENTE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_a_traiter.id_ppf, Evt_a_traiter.id_score, Evt_a_traiter.type_evt, Evt_a_traiter.duree_torture, Evt_a_traiter.t_evt, Evt_a_traiter.type_torture );
						
					}
					
				}
				
				else if (Evt_a_traiter.type_torture == 2)
				{
					if (A->salle_torture_libre_epil > 0)
					{
						A->salle_torture_libre_epil = A->salle_torture_libre_epil - 1;
						Evt_cree = creerEvenement(&Evt_a_traiter, DEBUT_TORTURE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_a_traiter.id_ppf, Evt_a_traiter.id_score, Evt_a_traiter.type_evt,Evt_a_traiter.duree_torture,  Evt_a_traiter.t_evt, Evt_a_traiter.type_torture );
						
					}
					else
					{
						Evt_cree = creerEvenement(&Evt_a_traiter, ATTENTE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_a_traiter.id_ppf, Evt_a_traiter.id_score, Evt_a_traiter.type_evt, Evt_a_traiter.duree_torture, Evt_a_traiter.t_evt, Evt_a_traiter.type_torture );
						
					}
				}
				
				else if (Evt_a_traiter.type_torture == 1)
				{
					if (A->salle_torture_libre_mars > 0)
					{
						A->salle_torture_libre_mars = A->salle_torture_libre_mars - 1;
						Evt_cree = creerEvenement(&Evt_a_traiter, DEBUT_TORTURE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_a_traiter.id_ppf, Evt_a_traiter.id_score, Evt_a_traiter.type_evt,Evt_a_traiter.duree_torture,  Evt_a_traiter.t_evt, Evt_a_traiter.type_torture );
						
					}
					else
					{
						Evt_cree = creerEvenement(&Evt_a_traiter, ATTENTE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_a_traiter.id_ppf, Evt_a_traiter.id_score, Evt_a_traiter.type_evt, Evt_a_traiter.duree_torture, Evt_a_traiter.t_evt, Evt_a_traiter.type_torture );
						
					}
				}
				
				else
					printf("\n\nERREUR DANS LA FONCTION MOTEUR SIMULATION ARRIVE\n");
			break;
			
			case ATTENTE :
				if (Evt_a_traiter.type_torture == 4)
				{
					if (A->salle_torture_libre_algo > 0)
					{
						A->salle_torture_libre_algo = A->salle_torture_libre_algo - 1;
						Evt_cree = creerEvenement(&Evt_a_traiter, DEBUT_TORTURE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_a_traiter.id_ppf, Evt_a_traiter.id_score, Evt_a_traiter.type_evt, Evt_a_traiter.duree_torture, Evt_a_traiter.t_evt, Evt_a_traiter.type_torture );
						
					}
					else //cas ou il n'y a plus de place
					{
						Evt_cree = creerEvenement(&Evt_a_traiter, ATTENTE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_a_traiter.id_ppf, Evt_a_traiter.id_score, Evt_a_traiter.type_evt, Evt_a_traiter.duree_torture, Evt_a_traiter.t_evt, Evt_a_traiter.type_torture );
						
					}
				}
				
				else if (Evt_a_traiter.type_torture == 3)
				{
					if (A->salle_torture_libre_poste > 0)
					{
						A->salle_torture_libre_poste = A->salle_torture_libre_poste - 1;
						Evt_cree = creerEvenement(&Evt_a_traiter, DEBUT_TORTURE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_a_traiter.id_ppf, Evt_a_traiter.id_score, Evt_a_traiter.type_evt, Evt_a_traiter.duree_torture, Evt_a_traiter.t_evt, Evt_a_traiter.type_torture );
						
					}
					else
					{
						Evt_cree = creerEvenement(&Evt_a_traiter, ATTENTE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_a_traiter.id_ppf, Evt_a_traiter.id_score, Evt_a_traiter.type_evt, Evt_a_traiter.duree_torture, Evt_a_traiter.t_evt, Evt_a_traiter.type_torture );
						
					}
					
				}
				
				else if (Evt_a_traiter.type_torture == 2)
				{
					if (A->salle_torture_libre_epil > 0)
					{
						A->salle_torture_libre_epil = A->salle_torture_libre_epil - 1;
						Evt_cree = creerEvenement(&Evt_a_traiter, DEBUT_TORTURE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_a_traiter.id_ppf, Evt_a_traiter.id_score, Evt_a_traiter.type_evt,Evt_a_traiter.duree_torture,  Evt_a_traiter.t_evt, Evt_a_traiter.type_torture );
						
					}
					else
					{
						Evt_cree = creerEvenement(&Evt_a_traiter, ATTENTE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_a_traiter.id_ppf, Evt_a_traiter.id_score, Evt_a_traiter.type_evt, Evt_a_traiter.duree_torture, Evt_a_traiter.t_evt, Evt_a_traiter.type_torture );
						
					}
				}
				
				else if (Evt_a_traiter.type_torture == 1)
				{
					if (A->salle_torture_libre_mars > 0)
					{
						A->salle_torture_libre_mars = A->salle_torture_libre_mars - 1;
						Evt_cree = creerEvenement(&Evt_a_traiter, DEBUT_TORTURE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_a_traiter.id_ppf, Evt_a_traiter.id_score, Evt_a_traiter.type_evt,Evt_a_traiter.duree_torture,  Evt_a_traiter.t_evt, Evt_a_traiter.type_torture );
						
					}
					else
					{
						Evt_cree = creerEvenement(&Evt_a_traiter, ATTENTE, A->t_cour+1);
						ajouterAvecPrioriteFileEvenement(A,  Evt_a_traiter.id_ppf, Evt_a_traiter.id_score, Evt_a_traiter.type_evt, Evt_a_traiter.duree_torture, Evt_a_traiter.t_evt, Evt_a_traiter.type_torture );
						
					}
				}
				
				else
					printf("\n\nERREUR DANS LA FONCTION MOTEUR SIMULATION ATTENTE\n");
			
			break;
			
			case DEBUT_TORTURE :
				Evt_cree = creerEvenement(&Evt_a_traiter, FIN_TORTURE, A->t_cour+20); //LE PLUS 20 EST A MODIFIER EN FONCTION DU TEMPS QUE PREND LA TORTURE
				ajouterAvecPrioriteFileEvenement(A,  Evt_a_traiter.id_ppf, Evt_a_traiter.id_score, Evt_a_traiter.type_evt, Evt_a_traiter.duree_torture, Evt_a_traiter.t_evt, Evt_a_traiter.type_torture );
			break;
			
			case FIN_TORTURE : 
				if (Evt_a_traiter.type_torture == 4)
				{
					if (A->salle_torture_libre_algo > 0)
					{
						A->salle_torture_libre_algo = A->salle_torture_libre_algo + 1;
						
					}
				}
				
				else if (Evt_a_traiter.type_torture == 3)
				{
					if (A->salle_torture_libre_poste > 0)
					{
						A->salle_torture_libre_poste = A->salle_torture_libre_poste + 1;
						
					}
					
				}
				
				else if (Evt_a_traiter.type_torture == 2)
				{
					if (A->salle_torture_libre_epil > 0)
					{
						A->salle_torture_libre_epil = A->salle_torture_libre_epil +1;

					}
				}
				
				else if (Evt_a_traiter.type_torture == 1)
				{
					if (A->salle_torture_libre_mars > 0)
					{
						A->salle_torture_libre_mars = A->salle_torture_libre_mars +1;						
					}
				}
				
				
			break;
			
			default :
				etat = -1;
				
		}
		//~ //affichage aff_type(type_traite, st_type_trait)
		//~ if (type_traite != FIN_TORTURE)
			//~ //affichage aff_type(Evt_cree->type_evt, st_type_chg);
		//~ else strcpy(st_type_chg, "VIDE");
			//~ fprintf
			//~ st_type_trait, st_type_chg, temps_traite, A->Laveurs);
	}
	return etat;
}


EVT* creerEvenement(EVT* Evt_a_traiter, int type_evt, int t_evt)
{
	EVT *E = NULL;

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
		//Génération Evt Attente
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
		//Génération Evt Attente
		E->id_ppf = Evt_a_traiter->id_ppf;
		E->id_score = Evt_a_traiter->id_score;
		E->type_evt = type_evt;
		E->duree_torture = Evt_a_traiter->duree_torture;
		E->t_evt = t_evt;
		E->type_torture = Evt_a_traiter->type_torture;
		E->suiv = NULL;
	}
	
	else
		printf("\n\nProblèmes dans creer evenements\n\n");
	

		return E;
}

void aiguillageDamnesArrivants( ECH* echeancier, PPF * pt_tete,  int *identifiant, int *efficacite_algo, int* efficacite_poste, int* efficacite_epil, int* efficacite_mars, int*nbr_ames_pardonnees)
{
	printf("\n\nAiguillageDamnesArrivants\n");
	
	int type_torture = 0; 
	int duree_torture = 0;
	
	ECH *A = echeancier;
	PPF *pt_damne_a_traiter = pt_tete;
	printf("\n\nAiguillageDamnesArrivants\n");
	while(&pt_damne_a_traiter->id != identifiant)
	{
		printf("\n\nAiguillageDamnesArrivantsBOUCLE\n");
		pt_damne_a_traiter = pt_damne_a_traiter->suiv;
	}
	printf("\n%d\n", pt_damne_a_traiter->id);
		printf("\n%d\n", pt_damne_a_traiter->score);
		
	if (pt_damne_a_traiter->score == 0)
	{
		printf("\n\nPARADIS\n");
		SupprimerMaillonIDDamnes(&pt_tete, *identifiant);
		nbr_ames_pardonnees = nbr_ames_pardonnees + 1;
	}
	
	else if ((pt_damne_a_traiter->score > 0 ) && (pt_damne_a_traiter->score <= 250))
	{
		
		printf("\n\nCas où Marseillais\n");
		type_torture = 1;
		
		duree_torture = pt_damne_a_traiter->score / *efficacite_mars;
	}
	
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
	
	printf("\n\nAjout\n");
	ajouterAvecPrioriteFileEvenement(A,  pt_damne_a_traiter->id, pt_damne_a_traiter->score, 1, duree_torture, A->t_cour+1, type_torture );
}
