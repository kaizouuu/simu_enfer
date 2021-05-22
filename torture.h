#ifndef TORTURE_H
#define TORTURE_H


struct cours_algo{
    int id;
    int cpt;
    struct cours_algo *suiv;

};

struct file_poste{
    int id;
    int cpt;
    struct file_poste *suiv;

};

struct epilation_cheveux{
    int id;
    int cpt;
    struct epilation_cheveux *suiv;
};

struct marseillais{
    int id;
    int cpt;
    struct marseillais *suiv;
};

void InsererMaillonEnQueueTortureCoursAlgo(struct cours_algo **,struct cours_algo*);
void AfficherMaillonTortureCoursAlgo(struct cours_algo *);
void RechercherMaillonTortureCoursAlgo(struct cours_algo *,int);
void SupprimerMaillonTortureCoursAlgo(struct cours_algo **,int);
struct cours_algo* CreerMaillonTortureCoursAlgoSimulation(int id_ppf);

void InsererMaillonEnQueueTortureFilePoste(struct file_poste **,struct file_poste*);
void AfficherMaillonTortureFilePoste(struct file_poste *);
void RechercherMaillonTortureFilePoste(struct file_poste *,int);
void SupprimerMaillonTortureFilePoste(struct file_poste **,int);
struct file_poste* CreerMaillonTortureFilePosteSimulation(int id_ppf);

void InsererMaillonEnQueueTortureEpilationCheveux(struct epilation_cheveux **,struct epilation_cheveux*);
void AfficherMaillonTortureEpilationCheveux(struct epilation_cheveux *);
void RechercherMaillonTortureEpilationCheveux(struct epilation_cheveux *,int);
void SupprimerMaillonTortureEpilationCheveux(struct epilation_cheveux **,int);
struct epilation_cheveux* CreerMaillonTortureEpilationCheveuxSimulation(int id_ppf);

void InsererMaillonEnQueueTortureMarseillais(struct marseillais **,struct marseillais*);
void AfficherMaillonTortureMarseillais(struct marseillais *);
void RechercherMaillonTortureMarseillais(struct marseillais *,int);
void SupprimerMaillonTortureMarseillais(struct marseillais **,int);
struct marseillais* CreerMaillonTortureMarseillaisSimulation(int id_ppf);

#endif
