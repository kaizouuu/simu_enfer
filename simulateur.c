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

            if (nb_pers_cours_algo < nb_place_cours_algo)
            {
                if(pt_tete->score >= 750)
                {
                    id_tempo = pt_tete->id;
                    nouveau_cour_algo = CreerMaillonTortureCoursAlgoID(id_tempo);
                    InsererMaillonEnQueueTortureCoursAlgo(pt_tete_cours_algo, nouveau_cour_algo);
                    id_tempo = 0;
                    nb_pers_cours_algo++;
                    pt_tete->cpt = 1;
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
                    pt_tete->cpt = 1;
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
                    pt_tete->cpt = 1;

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
                    pt_tete->cpt = 1;
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

void simulation(PPF **pt_tete,COURS_ALGO **pt_tete_cours_algo,FILE_POSTE **pt_tete_file_poste,EPILATION_CHEVEUX **pt_tete_epilation_cheveux,MARSEILLAIS **pt_tete_marseillais,PPF *nouveau,COURS_ALGO *nouveau_cour_algo,FILE_POSTE *nouveau_file_poste,EPILATION_CHEVEUX *nouveau_epilation_cheveux,MARSEILLAIS *nouveau_marseillais, int nb_place_cours_algo, int nb_place_file_poste, int nb_place_epilation_cheveux, int nb_place_marseillais, int temps_torture_cours_dalgo, int temps_torture_file_poste, int temps_torture_epilation_cheveux, int temps_torture_marseilllais) {
    int nb_pers_cours_algo = 0;
    int nb_pers_file_poste = 0;
    int nb_pers_epilation_cheveux = 0;
    int nb_pers_marseillais = 0;

    int temps;
    int flag;

    printf("Entrez le nombre d'année après lequel vous voulez un update :\n");
    scanf("%d", &temps);

    do {
        printf("****** Quiter : 0 ************ \n ************ Entrez les différent temps de toture : 1 ************** \n ******************** Laisser les paramettres par defaults : 2  *************** \n ");
        scanf("%d", &flag);

        switch (flag)
        {
            case 1:
                printf("Nombre de chambre de torture en cours d'algorithimie :\n");
                scanf("%d",&nb_place_cours_algo);
                printf("Nombre de chambre de torture en file poste:\n");
                scanf("%d",&nb_place_file_poste);
                printf("Nombre de chambre de torture en epilation cheveux :\n");
                scanf("%d",&nb_place_epilation_cheveux);
                printf("Nombre de chambre de torture avec les marseillais à l'écran :\n");
                scanf("%d",&nb_place_marseillais);

                printf("Nombre d'année que duree la torture cours d'algorithme pour perdre 200 de score de dépravation:\n");
                scanf("%d",&temps_torture_cours_dalgo);
                printf("Nombre d'année que duree la torture file poste pour perdre 200 de score de dépravation :\n");
                scanf("%d",&temps_torture_file_poste);
                printf("Nombre d'année que duree la torture epilation chaveux pour perdre 200 de score de dépravation:\n");
                scanf("%d",&temps_torture_epilation_cheveux);
                printf("Nombre d'année que duree la torture marseillais pour perdre 200 de score de dépravation:\n");
                scanf("%d",&temps_torture_marseilllais);

                break;
            case 2:
                nb_place_marseillais = 4;
                nb_place_epilation_cheveux = 4;
                nb_place_file_poste = 4;
                nb_place_cours_algo = 4;
                temps_torture_marseilllais = 10;
                temps_torture_epilation_cheveux = 10;
                temps_torture_file_poste = 10;
                temps_torture_cours_dalgo = 10;
                break;
        }

    }while (flag != 0);

    while (*pt_tete != NULL)
    {

        AiguillagePurgatoire(*pt_tete, pt_tete_cours_algo, nouveau_cour_algo, pt_tete_file_poste, nouveau_file_poste, pt_tete_epilation_cheveux, nouveau_epilation_cheveux, pt_tete_marseillais,nouveau_marseillais,nb_pers_cours_algo, nb_pers_file_poste, nb_pers_epilation_cheveux, nb_pers_marseillais, nb_place_cours_algo, nb_place_file_poste, nb_place_epilation_cheveux, nb_place_marseillais);
        unsigned long secondes = 0;
        time_t begin = time( NULL );
        // Boucle du temps pour sequencer la simulation creer un tableau pour avoir des valeurs pret remplie
        while (secondes<temps)
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
        AfficherMaillonDamnes(*pt_tete);
        Affichageapresupdate(*pt_tete_cours_algo, *pt_tete_file_poste, *pt_tete_epilation_cheveux, *pt_tete_marseillais,nb_pers_cours_algo, nb_pers_file_poste, nb_pers_epilation_cheveux, nb_pers_marseillais);
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
            nouveau = RechercherMaillonNombreDamnes(pt_courant,nombrerech);
            if (nouveau != NULL)
            {
                SupprimerMaillonIDDamnes(pt_tete,nombrerech);
                InsererMaillonEnQueueDamnes(pt_tete,nouveau);
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
            nouveau = RechercherMaillonNombreDamnes(pt_courant,nombrerech);
            if (nouveau != NULL)
            {
                SupprimerMaillonIDDamnes(pt_tete,nombrerech);
                InsererMaillonEnQueueDamnes(pt_tete,nouveau);
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
            nouveau = RechercherMaillonNombreDamnes(pt_courant,nombrerech);
            if (nouveau != NULL)
            {
                SupprimerMaillonIDDamnes(pt_tete,nombrerech);
                InsererMaillonEnQueueDamnes(pt_tete,nouveau);
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
            nouveau = RechercherMaillonNombreDamnes(pt_courant,nombrerech);
            if (nouveau != NULL)
            {
                SupprimerMaillonIDDamnes(pt_tete,nombrerech);
                if (nouveau->cpt > 0)
                    InsererMaillonEnQueueDamnes(pt_tete,nouveau);
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

void Affichageapresupdate(COURS_ALGO *pt_tete_cours_algo,FILE_POSTE *pt_tete_file_poste,EPILATION_CHEVEUX *pt_tete_epilation_cheveux,MARSEILLAIS *pt_tete_marseillais,int nb_pers_cours_algo,int nb_pers_file_poste,int nb_pers_epilation_cheveux,int nb_place_marseillais )
{
    int tableau_affichage_cours_algo_id[TAFFICHAGE];
    int tableau_affichage_cours_algo_cpt[TAFFICHAGE];
    int i = 0;
    int nbdanne = 3 ;
    printf ("\n\n Affichage des dannées en cours d'algo ci dessous: \n");
    {
        if(pt_tete_cours_algo == NULL)
            printf("Les salles de cette torture sont vides, les diables ont pris leurs pause.");
        while (pt_tete_cours_algo != NULL && i < nb_pers_cours_algo)
        {
            tableau_affichage_cours_algo_id[i] = pt_tete_cours_algo->id;
            tableau_affichage_cours_algo_cpt[i] = pt_tete_cours_algo->cpt;
            pt_tete_cours_algo = pt_tete_cours_algo->suiv;
            i++;
        }
        if (i != 0)
        {
            for (i=0; i<nb_pers_cours_algo; i++)
                printf("[ID :%d Nombre d'annee : %d]",tableau_affichage_cours_algo_id[i],tableau_affichage_cours_algo_cpt[i]);
        }

    }

    int tableau_affichage_file_poste_id[TAFFICHAGE];
    int tableau_affichage_file_poste_cpt[TAFFICHAGE];
    i=0;
    printf ("\n\n Affichage des dannées qui font la queue à la poste ci dessous: \n");
    {
        if(pt_tete_file_poste == NULL)
            printf("Les salles de cette torture sont vides, les diables ont pris leurs pause.");
        while (pt_tete_file_poste != NULL && i < nb_pers_file_poste)
        {
            tableau_affichage_file_poste_id[i] = pt_tete_file_poste->id;
            tableau_affichage_file_poste_cpt[i] = pt_tete_file_poste->cpt;
            pt_tete_file_poste = pt_tete_file_poste->suiv;
            i++;
        }
        if (i != 0)
        {
            for (i=0; i<nb_pers_file_poste; i++)
                printf("[ID :%d Nombre d'annee : %d]",tableau_affichage_file_poste_id[i],tableau_affichage_file_poste_cpt[i]);

        }
    }

    int tableau_affichage_epilation_cheveux_id[TAFFICHAGE];
    int tableau_affichage_epilation_cheveux_cpt[TAFFICHAGE];
    i = 0;
    printf ("\n\n Affichage des dannées qui se font épiller un par un leurs cheveux ci dessous: \n");
    {
        if(pt_tete_epilation_cheveux == NULL)
            printf("Les salles de cette torture sont vides, les diables ont pris leurs pause.");
        while (pt_tete_epilation_cheveux != NULL && i < nb_pers_epilation_cheveux)
        {
            tableau_affichage_epilation_cheveux_id[i] = pt_tete_epilation_cheveux->id;
            tableau_affichage_epilation_cheveux_cpt[i] = pt_tete_epilation_cheveux->cpt;
            pt_tete_epilation_cheveux = pt_tete_epilation_cheveux->suiv;
            i++;
        }
        if (i != 0)
        {
            for (i=0; i<nb_pers_epilation_cheveux; i++)
                printf("[ID :%d Nombre d'annee : %d]",tableau_affichage_epilation_cheveux_id[i],tableau_affichage_epilation_cheveux_cpt[i]);
        }
    }

    int tableau_affichage_marseillais_id[TAFFICHAGE];
    int tableau_affichage_marseillais_cpt[TAFFICHAGE];
    i = 0;
    printf ("\n\n Affichage des dannées qui visionnent les maisaillais en boucle ci dessous: \n");
    {
        if(pt_tete_marseillais == NULL)
            printf("Les salles de cette torture sont vides, les diables ont pris leurs pause.");
        while (pt_tete_marseillais != NULL && i < nb_place_marseillais)
        {
            tableau_affichage_marseillais_id[i] = pt_tete_marseillais->id;
            tableau_affichage_marseillais_cpt[i] = pt_tete_marseillais->cpt;
            pt_tete_marseillais = pt_tete_marseillais->suiv;
            i++;
        }
        if (i != 0)
        {
            for (i=0; i<nb_place_marseillais; i++)
                printf("[ID :%d Nombre d'annee : %d]",tableau_affichage_marseillais_id[i],tableau_affichage_marseillais_cpt[i]);
        }
    }
}

void simulationSed(PPF **pt_tete,COURS_ALGO **pt_tete_cours_algo,FILE_POSTE **pt_tete_file_poste,EPILATION_CHEVEUX **pt_tete_epilation_cheveux,MARSEILLAIS **pt_tete_marseillais,PPF *nouveau,COURS_ALGO *nouveau_cour_algo,FILE_POSTE *nouveau_file_poste,EPILATION_CHEVEUX *nouveau_epilation_cheveux,MARSEILLAIS *nouveau_marseillais,ECH *pt_tete_enchancier, EVT *pt_tete_evenement)
{
    int nb_pers_cours_algo = 3;
    AiguillagePurgatoireSed(*pt_tete, pt_tete_enchancier);
}

void AiguillagePurgatoireSed(PPF *pt_tete,ECH *pt_tete_enchancier)
{
    int id_tempo;
    int score_tempo;
    int type_evt_tempo;
    int duree_torture_tempo = 10;
    int t_evt_tempo;
    int type_toture_tempo;

    while (pt_tete != NULL)
    {
        id_tempo = pt_tete->id;
        score_tempo = pt_tete->score;
        if (pt_tete->score >750)
        {
            type_toture_tempo = 4;
            duree_torture_tempo = ((pt_tete->score) - 750);
        }
        if (pt_tete->score > 500 && pt_tete->score <= 750)
        {
            type_toture_tempo = 3;
            duree_torture_tempo = ((pt_tete->score) - 500);
        }
        if (pt_tete->score > 250 && pt_tete->score <= 500)
        {
            type_toture_tempo = 2;
            duree_torture_tempo = ((pt_tete->score) - 250);
        }
        if (pt_tete->score > 0 && pt_tete->score <= 250)
        {
            type_toture_tempo = 1;
            duree_torture_tempo = (pt_tete->score);//RAJOUTER DUREER EVENEMENT DE L'ECHANCIER

        }
        if (pt_tete->score < 0)
            type_toture_tempo = 0;


        t_evt_tempo = pt_tete->score/10;
        type_evt_tempo = 0;

      ajouterAvecPrioriteFileEvenement(pt_tete_enchancier,id_tempo,score_tempo,type_evt_tempo, duree_torture_tempo, t_evt_tempo,type_toture_tempo);
      pt_tete =pt_tete->suiv;
    }
}




