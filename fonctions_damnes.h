#ifndef FCT_DAMNES
#define FCT_DAMNES

#define ARRIVEE 1
#define ATTENTE 2
#define DEBUT_TORTURE 3
#define FIN_TORTURE 4
#define SIZEMAX 10

#define TCHAINE 600
#define TAFFICHAGE 20

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

typedef struct torture{
    int num;
}TORTURE;

//Mettre le code ici
typedef struct evt{
	int id_ppf;                 // je sais pas trop ce que c'est
	int id_score;            // identifiant du damné affecté
	int type_evt;           // Ils peuvent prendre les valeurs définies par les define plus haut, ARRIVE ATTENTE DEBUT_TORTURE et FIN_TORTURE
	int duree_torture;
	int t_evt;                  // temps auquel on devra sauter pour exécuter cette évènement, cet entier fait office de priorité. Le tps le plus faible est prioritaire dans la liste.
	int type_torture;  // Algo = 4, Poste = 3, Epilation = 2, Marseillais = 1 et Paradis = 0
	
	struct evt *suiv;
} EVT;

typedef struct ech{
	int t_cour;                          //garde en tête l'horloge (ou compteur)
	int nb_evt;                        // Nombre d'évènement dans l'échéancier
	EVT *debut;                     // Pointe vers le début de la liste chaînée des EVT
	int salle_torture_libre_algo;
	int salle_torture_libre_mars;
	int salle_torture_libre_poste;
	int salle_torture_libre_epil;
} ECH;

//menu
void menu(PPF **,PPF *,char *,FILE*,COURS_ALGO **, COURS_ALGO *,FILE_POSTE **,FILE_POSTE*,EPILATION_CHEVEUX **,EPILATION_CHEVEUX *,MARSEILLAIS **,MARSEILLAIS *,int, int, int, int, int, int, int, int, int,ECH*,int);
//void menu(PPF **pt_tete,PPF *nouveau,char *nomrech,FILE *database_PFF,COURS_ALGO **pt_tete_cours_algo,COURS_ALGO *nouveau_cour_algo,FILE_POSTE **pt_tete_file_poste,FILE_POSTE *nouveau_file_poste, EPILATION_CHEVEUX **pt_tete_epilation_cheveux,EPILATION_CHEVEUX *nouveau_epilation_cheveux,MARSEILLAIS **pt_tete_marseillais,MARSEILLAIS *nouveau_marseillais,int nombrerech, int nb_place_cours_algo, int nb_place_file_poste, int nb_place_epilation_cheveux, int nb_place_marseillais,int *efficacite_algo, int* efficacite_poste, int* efficacite_epil, int* efficacite_mars,ECH* echeancier, int nbr_ames_pardonnee);
//fonction de base de liste chainer
PPF* CreerMaillonDamnes();
PPF* CreerMaillonAvecIDDamnes(int identifiant_damne);
void InsererMaillonEnQueueDamnes(PPF **,PPF *);
PPF* InsererMaillonEnQueuesimpleDamnes(PPF *, PPF *);
void InsererMaillonBonneplace(PPF **,PPF *); //fonction pour inserer les ppf à la bonne place dans le purgatoire
void AfficherMaillonDamnes(PPF *);
void RechercherMaillonDamnes(PPF *,char *);
PPF* RechercherMaillonNombreDamnes(PPF *,int);
void SupprimerMaillonDamnes(PPF **,char *);
void SupprimerMaillonIDDamnes(PPF **,int);

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

//fonction pour manipuler les maillon des totures
//fonction pour écrire les logs des torture / pas de fonction lire car pas besoin de charger c'est fichier en entré
void EcrireLogTorture (FILE *,COURS_ALGO *);
//fonction aiguillage purgatoire
void AiguillageTorture(PPF *pt_tete, COURS_ALGO **pt_tete_cours_algo, COURS_ALGO *nouveau_cour_algo, FILE_POSTE **pt_tete_file_poste, FILE_POSTE *nouveau_file_poste, EPILATION_CHEVEUX **pt_tete_epilation,EPILATION_CHEVEUX *nouveau_epilation,MARSEILLAIS **pt_tete_marseillais,MARSEILLAIS *nouveau_marseillais);


void selectionArchitecture(int *nb_place_cours_algo, int *nb_place_file_poste, int *nb_place_epilation_cheveux, int *nb_place_marseillais,int *temps_torture_cours_dalgo, int *temps_torture_file_poste, int *temps_torture_epilation_cheveux, int *temps_torture_marseilllais,COURS_ALGO **pt_tete_cours_algo,COURS_ALGO *nouveau_cour_algo,FILE_POSTE **pt_tete_file_poste,FILE_POSTE *nouveau_file_poste, EPILATION_CHEVEUX **pt_tete_epilation_cheveux,EPILATION_CHEVEUX *nouveau_epilation_cheveux,MARSEILLAIS **pt_tete_marseillais,MARSEILLAIS *nouveau_marseillais);
//Fonction pour traitement de la liste à priorité des évènements
void ajouterAvecPrioriteFileEvenement(ECH* debut, int id_pff, int id_score, int type_evt, int duree_torture, int t_evt, int type_torture);
//EVT* nouveauMaillonPriorite( int id_pff, int id_score, int type_evt, int t_evt, int type_torture);
//int ajouter(ECH *F, int id_ajout);
int retirerFileEvenement(ECH *F, int *id_ppf, int *id_score, int *type_evt, int*duree_torture, int *t_evt, int *type_torture);
int filepleineEvenement(ECH*F);
int filevideEvenement(ECH *F);
void initFileEvenement(ECH *F);
void afficherFileEvenement(ECH*F);

int moteurSimulation(ECH *A); //Essai FLORENT
EVT* creerEvenement(EVT* Evt_a_traiter, int type_evt, int t_evt);

void selectionTempsArret(int * tps);
//void aiguillageDamnesArrivants( ECH* echeancier, PPF * pt_tete,int* type_torture, int*duree_torture,  int *identifiant, int *efficacite_algo, int* efficacite_poste, int* efficacite_epil, int* efficacite_mars);
void aiguillageDamnesArrivants( ECH* echeancier, PPF * pt_tete,  int *identifiant, int *efficacite_algo, int* efficacite_poste, int* efficacite_epil, int* efficacite_mars, int*nbr_ames_pardonnee);
#endif

