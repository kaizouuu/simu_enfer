#ifndef SIMULATEUR
#define SIMULATEUR
#define ARRIVEE 1
#define ATTENTE 2
#define DEBUT_TORTURE 3
#define FIN_TORTURE 4
#define SIZEMAX 10

//Mettre le code ici
typedef struct evt{
	int id_pff;                 // je sais pas trop ce que c'est
	int id_score;            // identifiant du damné affecté
	int type_evt;           // Ils peuvent prendre les valeurs définies par les define plus haut, ARRIVE ATTENTE DEBUT_TORTURE et FIN_TORTURE
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
	int efficacite;
} ECH;

//fonction aiguillage purgatoire
void AiguillagePurgatoire (PPF *,COURS_ALGO **,COURS_ALGO *,FILE_POSTE **,FILE_POSTE*,EPILATION_CHEVEUX **,EPILATION_CHEVEUX *,MARSEILLAIS **,MARSEILLAIS *, int, int, int, int, int, int, int, int);
void simulation(PPF **,COURS_ALGO **,FILE_POSTE **,EPILATION_CHEVEUX **,MARSEILLAIS **,PPF *,COURS_ALGO *,FILE_POSTE *,EPILATION_CHEVEUX *,MARSEILLAIS *,int, int, int, int, int, int, int, int);
void update(PPF **,COURS_ALGO **,FILE_POSTE **,EPILATION_CHEVEUX **,MARSEILLAIS **,PPF *,COURS_ALGO *,FILE_POSTE *,EPILATION_CHEVEUX *,MARSEILLAIS *, int, int, int, int);
void updatecompteur(COURS_ALGO *, FILE_POSTE *,EPILATION_CHEVEUX *,MARSEILLAIS *);
COURS_ALGO* copieListeFrag(COURS_ALGO *);
void Affichageapresupdate(COURS_ALGO *, FILE_POSTE *, EPILATION_CHEVEUX *, MARSEILLAIS *);

//Fonction pour traitement de la liste à priorité des évènements
void ajouterAvecPriorite(ECH* debut, int id_pff, int id_score, int type_evt, int t_evt, int type_torture);
EVT* nouveauMaillonPriorite( int id_pff, int id_score, int type_evt, int t_evt, int type_torture);
int ajouter(ECH *F, int id_ajout);
int retirer(ECH *F, int *id_retire);
int filepleine(ECH*F);
int filevide(ECH *F);
void initFile(ECH *F);

int moteurSimulation(ECH *A); //Essai FLORENT

#endif
