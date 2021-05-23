#ifndef TORTURE_H
#define TORTURE_H


struct cours_algo{
    int id;
    int cpt;
    struct cours_algo *suiv;

};

void InsererMaillonEnQueueTortureCoursAlgo(struct cours_algo **,struct cours_algo*); //envoi les damné dans la torture
void AfficherMaillonTortureCoursAlgo(struct cours_algo *);  //affiche les salles de tortures
void RechercherMaillonTortureCoursAlgo(struct cours_algo *,int);//recherche un damné par son id
void SupprimerMaillonTortureCoursAlgo(struct cours_algo **,int);//supprime un damné par son id
struct cours_algo* CreerMaillonTortureCoursAlgoSimulation(int id_ppf); //creer un maillon de torture



#endif
