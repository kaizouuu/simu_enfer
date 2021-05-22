#ifndef FCT_DAMNES
#define FCT_DAMNES

struct ppf{
    int id;
    int score;
    struct ppf *suiv;
};


struct ppf* CreerMaillonAvecIDDamnesAleatoire(int identifiant_damne);
void supprimerDamnes_DoublePointeur(struct ppf **pt_tete, int *qui);

void InsererMaillonEnQueueDamnes(struct ppf **,struct ppf *);
struct ppf* InsererMaillonEnQueuesimpleDamnes(struct ppf*, struct ppf*);
void InsererMaillonBonneplace(struct ppf **,struct ppf*); //fonction pour inserer les ppf à la bonne place dans le purgatoire
void AfficherMaillonDamnes(struct ppf *);
void RechercherMaillonDamnes(struct ppf *,char *);
struct ppf* RechercherMaillonNombreDamnes(struct ppf *,int);
void SupprimerMaillonDamnes(struct ppf **,char *);
void SupprimerMaillonIDDamnes(struct ppf **,int);




#endif

