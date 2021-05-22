#ifndef SIMULATEUR
#define SIMULATEUR

#define ARRIVEE 1
#define ATTENTE 2
#define DEBUT_TORTURE 3
#define FIN_TORTURE 4
#define SIZEMAX 50




struct evt{
	int id_ppf;                 // je sais pas trop ce que c'est
	int id_score;            // identifiant du damné affecté
	int type_evt;           // Ils peuvent prendre les valeurs définies par les define plus haut, ARRIVE ATTENTE DEBUT_TORTURE et FIN_TORTURE
	int duree_torture;
	int t_evt;                  // temps auquel on devra sauter pour exécuter cette évènement, cet entier fait office de priorité. Le tps le plus faible est prioritaire dans la liste.
	int type_torture;  // Algo = 4, Poste = 3, Epilation = 2, Marseillais = 1 et Paradis = 0
	
	struct evt *suiv;
} ;

struct ech{
	int t_cour;                          //garde en tête l'horloge (ou compteur)
	int nb_evt;                        // Nombre d'évènement dans l'échéancier
	struct evt *debut;                     // Pointe vers le début de la liste chaînée des EVT
	int nb_place_cours_algo;
	int nb_pers_cours_algo;
	int efficacite_algo;
	int nbr_evt_arrivee;
	int nbr_evt_attente;
	int nbr_evt_debut_torture;
	int nbr_evt_fin_torture;
	int nbr_ames_pardonnees;
} ;

void selectionArchitecture(struct ech *);

void ajouterAvecPrioriteFileEvenement(struct ech* debut, int id_pff, int id_score, int type_evt, int duree_torture, int t_evt, int type_torture);
int retirerFileEvenement(struct ech*F, int *id_ppf, int *id_score, int *type_evt, int * duree_torture, int *t_evt, int *type_torture) ;
int filepleineEvenement(struct ech*F);
int filevideEvenement(struct ech*F);
void initFileEvenement(struct ech *F);
void afficherFileEvenement(struct ech*F);
struct evt* creerEvenement(struct evt* Evt_a_traiter, int type_evt, int t_evt);






#endif
