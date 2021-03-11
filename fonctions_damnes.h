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
void menu(PPF **,PPF *,char *,FILE*);
//fonction de base de liste chainer
PPF* CreerMaillon();
void InsererMaillonEnQueue(PPF **,PPF *);
void AfficherMaillon(PPF *);
void RechercherMaillon(PPF *,char *);
void SupprimerMaillon(PPF **,char *);
//fonction pour aller écrire et lire sans les fichiers
void EcrireFichier (FILE *,PPF *);
PPF* LireFichier(FILE *);

