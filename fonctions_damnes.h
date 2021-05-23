#ifndef FCT_DAMNES
#define FCT_DAMNES

struct ppf{     //structure personne peu fréquantable
    int id;     //identifiant
    int score;  //score de dépravation
    struct ppf *suiv;
};


struct ppf* CreerMaillonAvecIDDamnesAleatoire(int identifiant_damne);//creer un maillon avec un score de dépravation aléatoire
void supprimerDamnes_DoublePointeur(struct ppf **pt_tete, int *qui); //supprime les damné

void InsererMaillonEnQueueDamnes(struct ppf **,struct ppf *); //insere un ppf en queue
void AfficherMaillonDamnes(struct ppf *); //affiche le purgatoire




#endif

