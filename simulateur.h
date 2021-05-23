#ifndef SIMUL
#define SIMUL

struct cours_algo;
struct ech;
struct ppf;

void menu(struct ppf **, struct ppf *, struct cours_algo **, struct cours_algo *, struct ech*);//affichage du menu et utilisation des fonctions
int moteurSimulation(struct ech *A,  struct cours_algo **pt_tete_cours_algo); //fais tourner la simulation
void selectionTempsArret(int * tps);//selection le temps final de la simu
void aiguillageDamnesArrivants( struct ech* echeancier, struct ppf* pt_tete,  int *identifiant, int aleatoire_bool, int t_final_arret); //genere un evenement d'arriver et aiguille dans les torture



#endif
