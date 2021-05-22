#ifndef TORTURE_H
#define TORTURE_H

//Mettre le code ici
//Creer maillon pour toute les sales de l'enfer



struct cours_algo{
    int id;
    int cpt;
    struct cours_algo *suiv;

};

void InsererMaillonEnQueueTortureCoursAlgo(struct cours_algo **,struct cours_algo*);
void AfficherMaillonTortureCoursAlgo(struct cours_algo *);
void RechercherMaillonTortureCoursAlgo(struct cours_algo *,int);
void SupprimerMaillonTortureCoursAlgo(struct cours_algo **,int);
struct cours_algo* CreerMaillonTortureCoursAlgoSimulation(int id_ppf);



#endif
