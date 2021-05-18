#ifndef SIMULATEUR
#define SIMULATEUR


//fonction aiguillage purgatoire
void AiguillagePurgatoire (PPF *,COURS_ALGO **,COURS_ALGO *,FILE_POSTE **,FILE_POSTE*,EPILATION_CHEVEUX **,EPILATION_CHEVEUX *,MARSEILLAIS **,MARSEILLAIS *, int, int, int, int, int, int, int, int);
void simulation(PPF **,COURS_ALGO **,FILE_POSTE **,EPILATION_CHEVEUX **,MARSEILLAIS **,PPF *,COURS_ALGO *,FILE_POSTE *,EPILATION_CHEVEUX *,MARSEILLAIS *,int, int, int, int, int, int, int, int);
void update(PPF **,COURS_ALGO **,FILE_POSTE **,EPILATION_CHEVEUX **,MARSEILLAIS **,PPF *,COURS_ALGO *,FILE_POSTE *,EPILATION_CHEVEUX *,MARSEILLAIS *, int, int, int, int);
void updatecompteur(COURS_ALGO *, FILE_POSTE *,EPILATION_CHEVEUX *,MARSEILLAIS *);
COURS_ALGO* copieListeFrag(COURS_ALGO *);
void Affichageapresupdate(COURS_ALGO *, FILE_POSTE *, EPILATION_CHEVEUX *, MARSEILLAIS *);


#endif
