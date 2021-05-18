#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "fonctions_damnes.h"
#include "torture.h"
#include "simulateur.h"
#include "time.h"

void menu(PPF **pt_tete,PPF *nouveau,char *nomrech,FILE *database_PFF,COURS_ALGO **pt_tete_cours_algo,COURS_ALGO *nouveau_cour_algo,FILE_POSTE **pt_tete_file_poste,FILE_POSTE *nouveau_file_poste, EPILATION_CHEVEUX **pt_tete_epilation_cheveux,EPILATION_CHEVEUX *nouveau_epilation_cheveux,MARSEILLAIS **pt_tete_marseillais,MARSEILLAIS *nouveau_marseillais,int nombrerech, int nb_place_cours_algo, int nb_place_file_poste, int nb_place_epilation_cheveux, int nb_place_marseillais,int temps_torture_cours_dalgo, int temps_torture_file_poste, int temps_torture_epilation_cheveux, int temps_torture_marseilllais,ECH* echeancier)
{
    int i = 0 ;
    int l = 0, m = 0, n = 0, o = 0, p = 0 ;  // utilisé en test 14 pour entrer dans la structure évènement
    int q = 0, r=0, s=0, t=0, u=0 ; //utilisé en test 15 pour retirer dans la structure évènement
    int simu_en_marche = 1 ;
    int flag ;
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
        printf ("| 16 | Test unitaire évènement : Retirer évènement (avec t_evt le plus petit)\n");
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
				//~ while (simu_en_marche)
					//~ simu_en_marche = moteurSimulation(A);
                //~ simulation(pt_tete,pt_tete_cours_algo,pt_tete_file_poste,pt_tete_epilation_cheveux,pt_tete_marseillais,nouveau,nouveau_cour_algo,nouveau_file_poste,nouveau_epilation_cheveux,nouveau_marseillais,nb_place_cours_algo, nb_place_file_poste,nb_place_epilation_cheveux, nb_place_marseillais, temps_torture_cours_dalgo, temps_torture_file_poste, temps_torture_epilation_cheveux, temps_torture_marseilllais);
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
                printf("Entrer le t_evt:\n");
                scanf("%d",&o);
                printf("Entrer le type_torture:\n");
                scanf("%d",&p);
				//ajouterAvecPriorite(ECH* debut_ech, int id_pff, int id_score, int type_evt, int t_evt, int type_torture);
				ajouterAvecPrioriteFileEvenement(echeancier, l, m, n, o, p);
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
			
			if (retirerFileEvenement(echeancier, &q, &r, &s, &t, &u)== 1)	
			{
				printf("\nIdentifiant du damné: %d", q);
				printf("\nScore du damné: %d", r);
				printf("\nType de l'évènement (1 pour ARRIVEE, 2 pour ATTENTE, 3 pour DEBUT_TORTURE et 4 pour FIN_TORTURE): %d", s); //faire un truc pour ne pas afficher le nombre mais le string
				printf("\nTemps déroulement de l'évènement: %d", t);
				printf("\nType de torture (Algo = 4, Poste = 3, Epilation = 2, Marseillais = 1 et Paradis = 0): %d\n", u);
			}
			else
				printf("\nFile vide aucune valeur récupérée");	
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

PPF* InsererMaillonEnQueuesimpleDamnes(PPF *pt_tete, PPF *nouveau)
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
/*void DemandeUtilisateur(int *nb_place_cours_algo, int *nb_place_file_poste, int *nb_place_epilation_cheveux, int *nb_place_marseillais,int *temps_torture_cours_dalgo, int *temps_torture_file_poste, int *temps_torture_epilation_cheveux, int *temps_torture_marseilllais)
{

    printf("Combien de place voulez-vous affecter à la torture Cours Algo :");    
    scanf ("%d",nb_place_cours_algo);

    printf("Combien de temps voulez-vous affecter à la torture Cours Algo :");
    scanf("%d",temps_torture_cours_dalgo);


    printf("Combien de place voulez-vous affecter à la torture File Poste :");        
    scanf("%d",nb_place_file_poste);

    printf("Combien de temps voulez-vous affecter à la torture File Poste :");
    scanf("%d",temps_torture_file_poste);


    printf("Combien de place voulez-vous affecter à la torture Epilation Cheveux :");    
    scanf("%d",nb_place_epilation_cheveux);

    printf("Combien de temps voulez-vous affecter à la torture Epilation Cheveux :");
    scanf("%d",temps_torture_epilation_cheveux);


    printf("Combien de place voulez-vous affecter à la torture Marseillais :");    
    scanf("%d",nb_place_marseillais);

    printf("Combien de temps voulez-vous affecter à la torture Marseillais :");
    scanf("%d",temps_torture_marseilllais);
}*/


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

int retirerFileEvenement(ECH *F, int *id_ppf, int *id_score, int *type_evt, int *t_evt, int *type_torture) //On envoie Id_retire en pointeur, donc on l'a quand même à la fin de la simulation
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
		*t_evt = aSupp->t_evt;
		*type_torture = aSupp->type_torture;
		
		
		F->debut = aSupp->suiv; 
		
		free(aSupp);
		return 1;
	}
}

void ajouterAvecPrioriteFileEvenement(ECH *F, int id_ppf, int id_score, int type_evt, int t_evt, int type_torture)
{	EVT*E;
	EVT*E_cour;
	
	if (filepleineEvenement(F) ==1)
	{	printf("\ntaille maximale de la file atteinte, ajout interdit\n");

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
