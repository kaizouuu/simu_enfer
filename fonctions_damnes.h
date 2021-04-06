#ifndef FCT_DAMNES
#define FCT_DAMNES

#define TCHAINE 60
extern int timer;

typedef struct ppf{
    int id;
    char name[TCHAINE];
    int cpt ;
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

//menu
void menu(PPF **,PPF *,char *,FILE*,COURS_ALGO **, COURS_ALGO *,FILE_POSTE **,FILE_POSTE*,EPILATION_CHEVEUX **,EPILATION_CHEVEUX *,MARSEILLAIS **,MARSEILLAIS *,int);
//fonction de base de liste chainer
PPF* CreerMaillon();
void InsererMaillonEnQueue(PPF **,PPF *);
PPF* InsererMaillonEnQueuesimple(PPF *, PPF *);
void InsererMaillonBonneplace(PPF **,PPF *); //fonction pour inserer les ppf à la bonne place dans le purgatoire
void AfficherMaillon(PPF *);
void RechercherMaillon(PPF *,char *);
PPF* RechercherMaillonNombre(PPF *,int);
void SupprimerMaillon(PPF **,char *);
//fonction pour aller écrire et lire sans les fichiers
void EcrireFichier (FILE *,PPF *);
PPF* LireFichier(FILE *);
//fonction timer
void timer1(int t, PPF *cpt);

//Creer maillon pour toute les sales de l'enfer
COURS_ALGO* CreerMaillonTortureCoursAlgo(COURS_ALGO *);
COURS_ALGO * CreerMaillonTortureCoursAlgoID(int);
void InsererMaillonEnQueueTortureCoursAlgo(COURS_ALGO **,COURS_ALGO *);
void AfficherMaillonTortureCoursAlgo(COURS_ALGO *);
void RechercherMaillonTortureCoursAlgo(COURS_ALGO *,int);
void SupprimerMaillonTortureCoursAlgo(COURS_ALGO **,int);

//fonction pour manipuler les maillon des totures
//fonction pour écrire les logs des torture / pas de fonction lire car pas besoin de charger c'est fichier en entré
void EcrireLogTorture (FILE *,COURS_ALGO *);



#endif

