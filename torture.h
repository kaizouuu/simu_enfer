#ifndef TORTURE
#define TORTURE

//Mettre le code ici
//Creer maillon pour toute les sales de l'enfer
COURS_ALGO* CreerMaillonTortureCoursAlgo(COURS_ALGO *);
void InsererMaillonEnQueueTortureCoursAlgo(COURS_ALGO **,COURS_ALGO *);
void AfficherMaillonTortureCoursAlgo(COURS_ALGO *);
void RechercherMaillonTortureCoursAlgo(COURS_ALGO *,int);
void SupprimerMaillonTortureCoursAlgo(COURS_ALGO **,int);
void EcrireFichierCoursAlgo(FILE *,COURS_ALGO *);
COURS_ALGO* LireFichierCoursAlgo (FILE *);
int CompteurCoursAlgo (COURS_ALGO *);

COURS_ALGO* CreerMaillonTortureCoursAlgoSimulation(int id_ppf);



#endif
