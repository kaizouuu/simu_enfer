#ifndef FCT_DAMNES
#define FCT_DAMNES

#define TCHAINE 600
#define TAFFICHAGE 20
#define ARRIVEE 1
#define ATTENTE 2
#define DEBUT_TORTURE 3
#define FIN_TORTURE 4
#define SIZEMAX 10

extern int timer;

typedef struct ppf{
    int id;
    char name[TCHAINE];
    int cpt;
    int score;
    struct ppf *suiv;
}PPF;

typedef struct cours_algo{
    int id;
    int cpt;
    struct cours_algo *suiv;

}COURS_ALGO;

typedef struct file_poste{
    int id;
    int cpt;
    struct file_poste *suiv;
}FILE_POSTE;

typedef struct epilation_cheveux{
    int id;
    int cpt;
    struct epilation_cheveux *suiv;

}EPILATION_CHEVEUX;

typedef struct marseillais {
    int id;
    int cpt;
    struct marseillais *suiv;

}MARSEILLAIS;

typedef struct evt{
    int id_ppf;               // je sais pas trop ce que c'est
    int id_score;            // identifiant du damné affecté
    int type_evt;            // Ils peuvent prendre les valeurs définies par les define plus haut, ARRIVE ATTENTE DEBUT_TORTURE et FIN_TORTURE
    int t_evt;               // temps auquel on devra sauter pour exécuter cette évènement, cet entier fait office de priorité. Le tps le plus faible est prioritaire dans la liste.
    int type_torture;        // Algo = 4, Poste = 3, Epilation = 2, Marseillais = 1 et Paradis = 0

    struct evt *suiv;
} EVT;

typedef struct ech{
    int t_cour;                      //garde en tête l'horloge (ou compteur)
    int nb_evt;                      // Nombre d'évènement dans l'échéancier
    EVT *debut;                     // Pointe vers le début de la liste chaînée des EVT
    int salle_torture_libre_algo;
    int salle_torture_libre_mars;
    int salle_torture_libre_poste;
    int salle_torture_libre_epil;
    int efficacite;
} ECH;

//menu
void menu(PPF **,PPF *,char *,FILE*,COURS_ALGO **, COURS_ALGO *,FILE_POSTE **,FILE_POSTE*,EPILATION_CHEVEUX **,EPILATION_CHEVEUX *,MARSEILLAIS **,MARSEILLAIS *,int,ECH*,EVT*);

//fonction de base de liste chainer
PPF* CreerMaillon();
void InsererMaillonEnQueue(PPF **,PPF *);
PPF* InsererMaillonEnQueuesimple(PPF *, PPF *);
void InsererMaillonBonneplace(PPF **,PPF *); //fonction pour inserer les ppf à la bonne place dans le purgatoire
void AfficherMaillon(PPF *);
void RechercherMaillon(PPF *,char *);
PPF* RechercherMaillonNombre(PPF *,int);
void SupprimerMaillon(PPF **,char *);
void SupprimerMaillonID(PPF **,int);
//fonction pour aller écrire et lire sans les fichiers
void EcrireFichier (FILE *,PPF *,int);
PPF* LireFichier(FILE *, int);
//fonction timer


//Creer maillon pour toute les sales de l'enfer
COURS_ALGO* CreerMaillonTortureCoursAlgo(COURS_ALGO *);
COURS_ALGO * CreerMaillonTortureCoursAlgoID(int);
MARSEILLAIS* CreerMaillonTortureMarseillaisID(int);
EPILATION_CHEVEUX* CreerMaillonTortureEpilationCheveuxID(int);
FILE_POSTE* CreerMaillonTortureFilePosteID(int);


void InsererMaillonEnQueueTortureCoursAlgo(COURS_ALGO **,COURS_ALGO *);
void AfficherMaillonTortureCoursAlgo(COURS_ALGO *);
void RechercherMaillonTortureCoursAlgo(COURS_ALGO *,int);
void SupprimerMaillonTortureCoursAlgo(COURS_ALGO **,int);


//Fonction pour traitement de la liste à priorité des évènements
void ajouterAvecPriorite(ECH* debut, int id_pff, int id_score, int type_evt, int t_evt, int type_torture);
EVT* nouveauMaillonPriorite( int id_pff, int id_score, int type_evt, int t_evt, int type_torture);
int ajouter(ECH *F, int id_ajout);
int retirer(ECH *F, int *id_retire);
int filepleine(ECH*F);

#endif

