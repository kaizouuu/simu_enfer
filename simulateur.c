#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions_damnes.h"
#include "torture.h"
#include "simulateur.h"
#include "time.h"


//*******************************Fonction Pour L'Aiguillage***************************************************
void AiguillagePurgatoire(PPF *pt_tete,COURS_ALGO **pt_tete_cours_algo,COURS_ALGO *nouveau_cour_algo, FILE_POSTE **pt_tete_file_poste, FILE_POSTE*nouveau_file_poste, EPILATION_CHEVEUX **pt_tete_epilation_cheveux, EPILATION_CHEVEUX *nouveau_epilation_cheveux, MARSEILLAIS **pt_tete_marseillais,MARSEILLAIS *nouveau_marseillais, int nb_pers_cours_algo, int nb_pers_file_poste, int nb_pers_epilation_cheveux, int nb_pers_marseillais, int nb_place_cours_algo, int nb_place_file_poste, int nb_place_epilation_cheveux, int nb_place_marseillais)
{
    int id_tempo;
    while (pt_tete != NULL)
    {
        if (pt_tete->cpt == 0)
        {
            // Verifier la taille des listes des chambre  dans cette section
            pt_tete->cpt = 1;
            if (nb_pers_cours_algo < nb_place_cours_algo)
            {
                if(pt_tete->score >= 750)
                {
                    id_tempo = pt_tete->id;
                    nouveau_cour_algo = CreerMaillonTortureCoursAlgoID(id_tempo);
                    InsererMaillonEnQueueTortureCoursAlgo(pt_tete_cours_algo, nouveau_cour_algo);
                    id_tempo = 0;
                    nb_pers_cours_algo++;
                }
            }
            if (nb_pers_file_poste < nb_place_file_poste)
            {
                if((pt_tete->score < 750) && (pt_tete->score >= 500))
                {
                    id_tempo = pt_tete->id;
                    nouveau_file_poste = CreerMaillonTortureFilePosteID(id_tempo);
                    InsererMaillonEnQueueTortureFilePoste(pt_tete_file_poste, nouveau_file_poste);
                    id_tempo = 0;
                }
            }
            if (nb_pers_epilation_cheveux < nb_place_epilation_cheveux)
            {
                if((pt_tete->score < 500) && (pt_tete->score >= 250))
                {
                    id_tempo = pt_tete->id;
                    nouveau_epilation_cheveux = CreerMaillonTortureEpilationCheveuxID(id_tempo);
                    InsererMaillonEnQueueTortureEpilationCheveux(pt_tete_epilation_cheveux, nouveau_epilation_cheveux);
                    id_tempo = 0;

                }
            }
            if (nb_pers_marseillais < nb_place_marseillais)
            {
                if((pt_tete->score < 250) && (pt_tete->score >= 0))
                {
                    id_tempo = pt_tete->id;
                    nouveau_marseillais = CreerMaillonTortureMarseillaisID(id_tempo);
                    InsererMaillonEnQueueTortureMarseillais(pt_tete_marseillais, nouveau_marseillais);
                    id_tempo = 0;
                }
            }
            pt_tete = pt_tete->suiv;
        }
        else
        {
            pt_tete = pt_tete->suiv;
        }
    }
}

void simulation(PPF **pt_tete,COURS_ALGO **pt_tete_cours_algo,FILE_POSTE **pt_tete_file_poste,EPILATION_CHEVEUX **pt_tete_epilation_cheveux,MARSEILLAIS **pt_tete_marseillais,PPF *nouveau,COURS_ALGO *nouveau_cour_algo,FILE_POSTE *nouveau_file_poste,EPILATION_CHEVEUX *nouveau_epilation_cheveux,MARSEILLAIS *nouveau_marseillais, int nb_place_cours_algo, int nb_place_file_poste, int nb_place_epilation_cheveux, int nb_place_marseillais, int temps_torture_cours_dalgo, int temps_torture_file_poste, int temps_torture_epilation_cheveux, int temps_torture_marseilllais)
{
    int nb_pers_cours_algo = 0 ;
    int nb_pers_file_poste = 0 ;
    int nb_pers_epilation_cheveux = 0 ;
    int nb_pers_marseillais = 0 ;

    while (*pt_tete != NULL)
    {

        AiguillagePurgatoire(*pt_tete, pt_tete_cours_algo, nouveau_cour_algo, pt_tete_file_poste, nouveau_file_poste, pt_tete_epilation_cheveux, nouveau_epilation_cheveux, pt_tete_marseillais,nouveau_marseillais,nb_pers_cours_algo, nb_pers_file_poste, nb_pers_epilation_cheveux, nb_pers_marseillais, nb_place_cours_algo, nb_place_file_poste, nb_place_epilation_cheveux, nb_place_marseillais);
        unsigned long secondes = 0;
        time_t begin = time( NULL );
        // Boucle du temps pour sequencer la simulation creer un tableau pour avoir des valeurs pret remplie
        while (secondes<2)
        {
            time_t end = time( NULL);
            secondes = (unsigned long) difftime( end, begin );
        }
        nb_pers_cours_algo = CompteurCoursAlgo(*pt_tete_cours_algo);
        nb_pers_file_poste = CompteurFilePoste(*pt_tete_file_poste);
        nb_pers_epilation_cheveux = CompteurEpilationCheveux(*pt_tete_epilation_cheveux);
        nb_pers_marseillais = CompteurMarseillais(*pt_tete_marseillais);
        printf( "\n\n******************* Mise à jour apres %ld ans **********************\n", secondes );
        update(pt_tete,pt_tete_cours_algo,pt_tete_file_poste,pt_tete_epilation_cheveux,pt_tete_marseillais,nouveau,nouveau_cour_algo,nouveau_file_poste,nouveau_epilation_cheveux,nouveau_marseillais, temps_torture_cours_dalgo, temps_torture_file_poste, temps_torture_epilation_cheveux, temps_torture_marseilllais);
        Affichageapresupdate(*pt_tete_cours_algo, *pt_tete_file_poste, *pt_tete_epilation_cheveux, *pt_tete_marseillais);
    }
}

void update(PPF **pt_tete,COURS_ALGO **pt_tete_cours_algo,FILE_POSTE **pt_tete_file_poste,EPILATION_CHEVEUX **pt_tete_epilation_cheveux,MARSEILLAIS **pt_tete_marseillais,PPF *nouveau,COURS_ALGO *nouveau_cour_algo,FILE_POSTE *nouveau_file_poste,EPILATION_CHEVEUX *nouveau_epilation_cheveux,MARSEILLAIS *nouveau_marseillais, int temps_torture_cours_dalgo, int temps_torture_file_poste, int temps_torture_epilation_cheveux, int temps_torture_marseilllais)
{
    int flag =1;
    // Faire une fonction qui augmente le compteur de toutes les chambre
    updatecompteur(*pt_tete_cours_algo,*pt_tete_file_poste,*pt_tete_epilation_cheveux,*pt_tete_marseillais);
    // Duplication des listes chaines pour pouvoir les utiliser et les metre à jour en meme temps.

    FILE * database_PFF_SIMU = NULL;
    FILE * database_COURS_ALGO = NULL;
    FILE * database_FILE_POSTE = NULL;
    FILE * database_EPILATION_CHEVEUX = NULL;
    FILE * database_MARSEILLAIS = NULL;

    PPF *pt_courant = NULL;
    COURS_ALGO *pt_courant_cours_algo = NULL;
    FILE_POSTE *pt_courant_file_poste = NULL;
    EPILATION_CHEVEUX *pt_courant_epilation_cheveux = NULL;
    MARSEILLAIS *pt_courant_marseillais = NULL;

    EcrireFichier(database_PFF_SIMU,*pt_tete,flag);
    pt_courant = LireFichier(database_PFF_SIMU,flag);
    EcrireFichierCoursAlgo(database_COURS_ALGO,*pt_tete_cours_algo);
    pt_courant_cours_algo = LireFichierCoursAlgo(database_COURS_ALGO);


    EcrireFichierFilePoste(database_FILE_POSTE,*pt_tete_file_poste);
    pt_courant_file_poste = LireFichierFilePoste(database_FILE_POSTE);


    EcrireFichierEpilationCheveux(database_EPILATION_CHEVEUX,*pt_tete_epilation_cheveux);
    pt_courant_epilation_cheveux = LireFichierEpilationCheveux(database_EPILATION_CHEVEUX);


    EcrireFichierMarseillais(database_MARSEILLAIS,*pt_tete_marseillais);
    pt_courant_marseillais = LireFichierMarseillais(database_MARSEILLAIS);

    //DEfine dans le main par utilisateur
    int nombrerech;

    // Boucle qui vient update tout les temps de torture des chambres pour pouvoir ensuite les suprimer et les replacer dans le purgatoire
    while (pt_courant_cours_algo != NULL)
    {
        if(pt_courant_cours_algo->cpt >= temps_torture_cours_dalgo)
        {
            nombrerech = pt_courant_cours_algo->id;
            nouveau = RechercherMaillonNombre(pt_courant,nombrerech);
            if (nouveau != NULL)
            {
                SupprimerMaillonID(pt_tete,nombrerech);
                InsererMaillonEnQueue(pt_tete,nouveau);
                SupprimerMaillonTortureCoursAlgo(pt_tete_cours_algo,nombrerech);
            }
        }
        pt_courant_cours_algo = pt_courant_cours_algo->suiv;
    }
    free(pt_courant_cours_algo);

    while (pt_courant_file_poste != NULL)
    {
        if(pt_courant_file_poste->cpt >= temps_torture_file_poste)
        {
            nombrerech = pt_courant_file_poste->id;
            nouveau = RechercherMaillonNombre(pt_courant,nombrerech);
            if (nouveau != NULL)
            {
                SupprimerMaillonID(pt_tete,nombrerech);
                InsererMaillonEnQueue(pt_tete,nouveau);
                SupprimerMaillonTortureFilePoste(pt_tete_file_poste,nombrerech);
            }
        }
        pt_courant_file_poste = pt_courant_file_poste->suiv;
    }
    free(pt_courant_file_poste);

    while (pt_courant_epilation_cheveux != NULL)
    {
        if(pt_courant_epilation_cheveux->cpt >= temps_torture_epilation_cheveux)
        {
            nombrerech = pt_courant_epilation_cheveux->id;
            nouveau = RechercherMaillonNombre(pt_courant,nombrerech);
            if (nouveau != NULL)
            {
                SupprimerMaillonID(pt_tete,nombrerech);
                InsererMaillonEnQueue(pt_tete,nouveau);
                SupprimerMaillonTortureEpilationCheveux(pt_tete_epilation_cheveux,nombrerech);
            }
        }
        pt_courant_epilation_cheveux = pt_courant_epilation_cheveux->suiv;
    }
    free(pt_courant_epilation_cheveux);
    while (pt_courant_marseillais != NULL)
    {
        if(pt_courant_marseillais->cpt >= temps_torture_marseilllais)
        {
            nombrerech = pt_courant_marseillais->id;
            nouveau = RechercherMaillonNombre(pt_courant,nombrerech);
            if (nouveau != NULL)
            {
                SupprimerMaillonID(pt_tete,nombrerech);
                if (nouveau->cpt > 0)
                    InsererMaillonEnQueue(pt_tete,nouveau);
                SupprimerMaillonTortureMarseillais(pt_tete_marseillais,nombrerech);
            }
        }
        pt_courant_marseillais = pt_courant_marseillais->suiv;
    }
    free(pt_courant_marseillais);
}

void updatecompteur(COURS_ALGO *pt_tete_cours_algo, FILE_POSTE *pt_tete_file_poste,EPILATION_CHEVEUX *pt_tete_epilation_cheveux,MARSEILLAIS *pt_tete_marseillais)
{
    while(pt_tete_cours_algo != NULL)
    {
        pt_tete_cours_algo->cpt = pt_tete_cours_algo->cpt +2;
        pt_tete_cours_algo = pt_tete_cours_algo->suiv;
    }
    while (pt_tete_file_poste != NULL)
    {
        pt_tete_file_poste->cpt = pt_tete_file_poste->cpt +2;
        pt_tete_file_poste = pt_tete_file_poste->suiv;
    }
    while (pt_tete_epilation_cheveux != NULL)
    {
        pt_tete_epilation_cheveux->cpt = pt_tete_epilation_cheveux->cpt +2;
        pt_tete_epilation_cheveux = pt_tete_epilation_cheveux->suiv;
    }
    while (pt_tete_marseillais != NULL)
    {
        pt_tete_marseillais->cpt = pt_tete_marseillais->cpt +2;
        pt_tete_marseillais = pt_tete_marseillais->suiv;
    }
}

COURS_ALGO* copieListeFrag(COURS_ALGO *S) {
    COURS_ALGO *copie = NULL;
    if (S != NULL) {
        while (S ->suiv != NULL) {
            copie = malloc(sizeof(COURS_ALGO));
            copie -> id = S -> id;
            copie -> cpt = copie -> cpt;
            copie -> suiv = S -> suiv;
            S = S -> suiv;
            copieListeFrag(S);
        }
    }
    return copie;
}

void Affichageapresupdate(COURS_ALGO *pt_tete_cours_algo,FILE_POSTE *pt_tete_file_poste,EPILATION_CHEVEUX *pt_tete_epilation_cheveux,MARSEILLAIS *pt_tete_marseillais)
{
    int tableau_affichage_cours_algo_id[TAFFICHAGE];
    int tableau_affichage_cours_algo_cpt[TAFFICHAGE];
    int i = 0;
    int nbdanne = 3 ;
    printf ("\n\n Affichage des dannées en cours d'algo ci dessous: \n");
    {
        if(pt_tete_cours_algo == NULL)
            printf("Les salles de cette torture sont vides, les diables ont pris leurs pause.");
        while (pt_tete_cours_algo != NULL && i < nbdanne)
        {
            tableau_affichage_cours_algo_id[i] = pt_tete_cours_algo->id;
            tableau_affichage_cours_algo_cpt[i] = pt_tete_cours_algo->cpt;
            pt_tete_cours_algo = pt_tete_cours_algo->suiv;
            i++;
        }
        for (i=0; i<nbdanne; i++)
            printf("[ID :%d Nombre d'annee : %d]",tableau_affichage_cours_algo_id[i],tableau_affichage_cours_algo_cpt[i]);
    }

    int tableau_affichage_file_poste_id[TAFFICHAGE];
    int tableau_affichage_file_poste_cpt[TAFFICHAGE];
    i=0;
    printf ("\n\n Affichage des dannées qui font la queue à la poste ci dessous: \n");
    {
        if(pt_tete_file_poste == NULL)
            printf("Les salles de cette torture sont vides, les diables ont pris leurs pause.");
        while (pt_tete_file_poste != NULL && i < nbdanne)
        {
            tableau_affichage_file_poste_id[i] = pt_tete_file_poste->id;
            tableau_affichage_file_poste_cpt[i] = pt_tete_file_poste->cpt;
            pt_tete_file_poste = pt_tete_file_poste->suiv;
            i++;
        }
        for (i=0; i<nbdanne; i++)
            printf("[ID :%d Nombre d'annee : %d]",tableau_affichage_file_poste_id[i],tableau_affichage_file_poste_cpt[i]);
    }

    int tableau_affichage_epilation_cheveux_id[TAFFICHAGE];
    int tableau_affichage_epilation_cheveux_cpt[TAFFICHAGE];
    i = 0;
    printf ("\n\n Affichage des dannées qui se font épiller un par un leurs cheveux ci dessous: \n");
    {
        if(pt_tete_epilation_cheveux == NULL)
            printf("Les salles de cette torture sont vides, les diables ont pris leurs pause.");
        while (pt_tete_epilation_cheveux != NULL && i < nbdanne)
        {
            tableau_affichage_epilation_cheveux_id[i] = pt_tete_epilation_cheveux->id;
            tableau_affichage_epilation_cheveux_cpt[i] = pt_tete_epilation_cheveux->cpt;
            pt_tete_epilation_cheveux = pt_tete_epilation_cheveux->suiv;
            i++;
        }
        for (i=0; i<nbdanne; i++)
            printf("[ID :%d Nombre d'annee : %d]",tableau_affichage_epilation_cheveux_id[i],tableau_affichage_epilation_cheveux_cpt[i]);
    }

    int tableau_affichage_marseillais_id[TAFFICHAGE];
    int tableau_affichage_marseillais_cpt[TAFFICHAGE];
    i = 0;
    printf ("\n\n Affichage des dannées qui visionnent les maisaillais en boucle ci dessous: \n");
    {
        if(pt_tete_marseillais == NULL)
            printf("Les salles de cette torture sont vides, les diables ont pris leurs pause.");
        while (pt_tete_marseillais != NULL && i < nbdanne)
        {
            tableau_affichage_marseillais_id[i] = pt_tete_marseillais->id;
            tableau_affichage_marseillais_cpt[i] = pt_tete_marseillais->cpt;
            pt_tete_marseillais = pt_tete_marseillais->suiv;
            i++;
        }
        for (i=0; i<nbdanne; i++)
            printf("[ID :%d Nombre d'annee : %d]",tableau_affichage_marseillais_id[i],tableau_affichage_marseillais_cpt[i]);
    }
}


//~ int moteurSimulation(ECH *A)
//~ {
	//~ int temps_traite;
	//~ int type_traite; //ARR ou ATT ou Debut ou Fin
	
	//~ EVT *Evt_cree=NULL;
	//~ int etat = 1;
	
	//~ if (filevide(A) == 1) // Si la file de l'échéancier est vide 
		//~ etat = 0;
	//~ else
	//~ {
		//~ retirer(A, int *id_retire);            // On traite le premier élèment de liste à évènements
		//~ A->t_cour	= temps_traite;                  // C'est ici que le temps de la simulation saute à celui de l'événement en cours de traitement 
		//~ // 
		//~ switch (type_traite)
		//~ {
			//~ case ARRIVEE :
			
			//~ case ATTENTE :
			
			
			//~ case DEBUT_TORTURE :
			
			//~ case FIN_TORTURE : 
			
			//~ default :
				//~ etat = -1;
		//~ }
		//~ //affichage aff_type(type_traite, st_type_trait)
		//~ if (type_traite != FIN_TORTURE)
			//~ //affichage aff_type(Evt_cree->type_evt, st_type_chg);
		//~ else strcpy(st_type_chg, "VIDE");
			//~ fprintf
			//~ st_type_trait, st_type_chg, temps_traite, A->Laveurs);
	//~ }
	//~ return etat;
//~ }


// FIFO à priorité pour les évènements 
void initFile(ECH *F)
{
	F->debut = NULL;

}

int filevide(ECH *F)		/* retourne 1 si la file est vide, 0 sinon*/
{	if (F->debut == NULL)
		return 1;
	else
		return 0;
}

int filepleine(ECH*F)	/* retourne 1 si la file est pleine SIZEMAX, 0 sinon*/
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

int retirer(ECH *F, int *id_retire)
{	EVT *aSupp;
	if(filevide(F)==1)
	{	printf("\nFile vide\n");
		return 0;
	}
	else
	{	aSupp = F->debut;
		*id_retire = aSupp->id_pff;
		F->debut = aSupp->suiv; 
		//~ if (F->premier == NULL) //Inutile avec priorité ?
			//~ F->dernier = NULL;
		free(aSupp);
		return 1;
	}
}

//~ int ajouter(ECH *F, int id_ajout)
//~ {	EVT *E;
	//~ if (filepleine(F) ==1)
	//~ {	printf("\ntaille maximale de la file atteinte, ajout interdit\n");
		//~ return 0;
	//~ }	
	//~ E = (PPF*) malloc(sizeof(PPF));
	//~ if (E == NULL) 
	//~ {	printf("\nAjout impossible !\n");
		//~ return 0;
	//~ }
	//~ else
	//~ {	E->id = id_ajout;
		//~ E->suiv = NULL;
		//~ if (filevide(F)==1)
			//~ F->premier = E;
		//~ else
			//~ F->dernier->suiv = E;
		//~ F->dernier = E;
		//~ return 1;
	//~ }
//~ }

// Function to Create A New Node
EVT* nouveauMaillonPriorite( int id_pff, int id_score, int type_evt, int t_evt, int type_torture)
{
	EVT* temp = (EVT*)malloc(sizeof(EVT));
	temp->id_pff = id_pff;
	temp->id_score = id_score;
	temp->type_evt= type_evt;
	temp->t_evt = t_evt;
	temp->type_torture = type_torture;
	
	temp->suiv = NULL;

	return temp;
}
	
void ajouterAvecPriorite(ECH* debut_ech, int id_pff, int id_score, int type_evt, int t_evt, int type_torture)
{
	EVT* start = debut_ech->debut;

	// Create new Node
	EVT* temp = nouveauMaillonPriorite(id_pff,  id_score,  type_evt,  t_evt,  type_torture);

	// Special Case: The head of list has lesser
	// priority than new node. So insert new
	// node before head node and change head node.
	if (debut_ech->debut->t_evt > t_evt) {

		// Insert New Node before head
		temp->suiv = debut_ech->debut;
		debut_ech->debut = temp;
	}
	else {

		// Traverse the list and find a
		// position to insert new node
		while (start->suiv != NULL &&
			start->suiv->t_evt < t_evt) {
			start = start->suiv;
		}

		// Either at the ends of the list
		// or at required position
		temp->suiv = start->suiv;
		start->suiv = temp;
	}
}

