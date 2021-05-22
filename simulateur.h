#ifndef SIMUL
#define SIMUL

struct cours_algo;
struct file_poste;
struct epilation_cheveux;
struct marseillais;
struct ech;
struct ppf;

void menu(struct ppf **, struct ppf *, struct cours_algo **, struct cours_algo *, struct ech*, struct file_poste **, struct file_poste *, struct epilation_cheveux **, struct epilation_cheveux *, struct marseillais **, struct marseillais *);
int moteurSimulation(struct ech *A,  struct cours_algo **pt_tete_cours_algo, struct file_poste **pt_tete_file_poste, struct epilation_cheveux **pt_tete_epilation_cheveux, struct marseillais **pt_tete_marseillais); //Essai FLORENT
void selectionTempsArret(int * tps);
void aiguillageDamnesArrivants( struct ech* echeancier, struct ppf* pt_tete,  int *identifiant, int aleatoire_bool, int t_final_arret);



#endif
