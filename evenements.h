#ifndef SIMULATEUR
#define SIMULATEUR

#define ARRIVEE 1
#define ATTENTE 2
#define DEBUT_TORTURE 3
#define FIN_TORTURE 4
#define SIZEMAX 50




struct evt{
	int id_ppf;                //id damné
	int id_score;            // score du damné affecté
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
	int nb_place_cours_algo;			//nombre de place dans la torture cours algo
	int nb_pers_cours_algo;				//nombre de personne présente dans la torture
	int efficacite_algo;				//nombre de pôint que perd le damné a chaque coup d'horloge
	int nbr_evt_arrivee;				//nombre de damné dans l'evenement arrivee
	int nbr_evt_attente;				//nombre de damné dans l'évenement attente
	int nbr_evt_debut_torture;			//nombre de damné dans l'évenement debut_torture
	int nbr_evt_fin_torture;			//nombre de damné dans l'évenement fin_torture
	int nbr_ames_pardonnees;			//nombre de damné au paradis
} ;

void selectionArchitecture(struct ech *); //permet à l'utilisateur de rentrer le nombre de place de la torture et son efficacité

void ajouterAvecPrioriteFileEvenement(struct ech* debut, int id_pff, int id_score, int type_evt, int duree_torture, int t_evt, int type_torture); //ajoute le maillon à la bonne place
int retirerFileEvenement(struct ech*F, int *id_ppf, int *id_score, int *type_evt, int * duree_torture, int *t_evt, int *type_torture) ; //retire le maillon en tete
int filepleineEvenement(struct ech*F);  //si on veut mettre une limite pour les evenement
int filevideEvenement(struct ech*F);	//
void initFileEvenement(struct ech *F);  //
void afficherFileEvenement(struct ech*F);//affiche l'echéancier
struct evt* creerEvenement(struct evt* Evt_a_traiter, int type_evt, int t_evt);// creer le maillon de l'evenement






#endif
