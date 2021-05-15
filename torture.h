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

FILE_POSTE* CreerMaillonTortureFilePoste(FILE_POSTE *);
void InsererMaillonEnQueueTortureFilePoste(FILE_POSTE **,FILE_POSTE *);
void AfficherMaillonTortureFilePoste(FILE_POSTE *);
void RechercherMaillonTortureFilePoste(FILE_POSTE *,int);
void SupprimerMaillonTortureFilePoste(FILE_POSTE **,int);
void EcrireFichierFilePoste(FILE *,FILE_POSTE *);
FILE_POSTE* LireFichierFilePoste(FILE *);


EPILATION_CHEVEUX* CreerMaillonTortureEpilationCheveux();
void InsererMaillonEnQueueTortureEpilationCheveux(EPILATION_CHEVEUX **,EPILATION_CHEVEUX *);
void AfficherMaillonTortureEpilationCheveux(EPILATION_CHEVEUX *);
void RechercherMaillonTortureEpillationCheveux(EPILATION_CHEVEUX *,int);
void SupprimerMaillonTortureEpilationCheveux(EPILATION_CHEVEUX **,int);
void EcrireFichierEpilationCheveux(FILE *,EPILATION_CHEVEUX *);
EPILATION_CHEVEUX* LireFichierEpilationCheveux(FILE *);


MARSEILLAIS* CreerMaillonTortureMarseillais();
void InsererMaillonEnQueueTortureMarseillais(MARSEILLAIS **,MARSEILLAIS *);
void AfficherMaillonTortureMarseillais(MARSEILLAIS *);
void RechercherMaillonTortureMarseillais(MARSEILLAIS *,int);
void SupprimerMaillonTortureMarseillais(MARSEILLAIS **,int);
void EcrireFichierMarseillais(FILE *,MARSEILLAIS *);
MARSEILLAIS* LireFichierMarseillais(FILE *);

#endif
