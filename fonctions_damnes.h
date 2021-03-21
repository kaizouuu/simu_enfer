#define TCHAINE 60

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

//menu
void menu(PPF **,PPF *,char *,FILE*,COURS_ALGO **, COURS_ALGO *,FILE_POSTE **,EPILATION_CHEVEUX **,MARSEILLAIS **,int);
//fonction de base de liste chainer
PPF* CreerMaillon();
void InsererMaillonEnQueue(PPF **,PPF *);
void InsererMaillonBonneplace(PPF **,PPF *); //fonction pour inserer les ppf à la bonne place dans le purgatoire
void AfficherMaillon(PPF *);
void RechercherMaillon(PPF *,char *);
void SupprimerMaillon(PPF **,char *);
//fonction pour aller écrire et lire sans les fichiers
void EcrireFichier (FILE *,PPF *);
PPF* LireFichier(FILE *);
//fonction timer
int timer(int *temps)

//Creer maillon pour toute les sales de l'enfer
COURS_ALGO* CreerMaillonTortureCoursAlgo(COURS_ALGO *);
FILE_POSTE* CreerMaillonTortureFilePoste(FILE_POSTE *);
EPILATION_CHEVEUX* CreerMaillonTortureEpilationCheveux();
MARSEILLAIS* CreerMaillonTortureMarseillais();

//fonction pour manipuler les maillon des totures
void InsererMaillonEnQueueTorture(COURS_ALGO **,COURS_ALGO *);
void AfficherMaillonTorture(COURS_ALGO *);
void RechercherMaillonTorture(COURS_ALGO *,int);
void SupprimerMaillonTorture(COURS_ALGO **,int);
//fonction pour écrire les logs des torture / pas de fonction lire car pas besoin de charger c'est fichier en entré
void EcrireLogTorture (FILE *,COURS_ALGO *);
//fonction aiguillage purgatoire
void AiguillagePurgatoire (PPF *,COURS_ALGO **,COURS_ALGO *);