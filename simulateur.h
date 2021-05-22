#ifndef SIMUL
#define SIMUL

struct cours_algo;
struct ech;
struct ppf;

void menu(struct ppf **, struct ppf *, struct cours_algo **, struct cours_algo *, struct ech*);
int moteurSimulation(struct ech *A,  struct cours_algo **pt_tete_cours_algo); //Essai FLORENT
void selectionTempsArret(int * tps);
void aiguillageDamnesArrivants( struct ech* echeancier, struct ppf* pt_tete,  int *identifiant, int aleatoire_bool, int t_final_arret);



#endif
