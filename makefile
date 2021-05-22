Prog: simu_enfer.o fonctions_damnes.o torture.o simulateur.o evenements.o 
	gcc -o Prog simu_enfer.o fonctions_damnes.o torture.o simulateur.o evenements.o -Wall

simu_enfer.o: simu_enfer.c simulateur.h torture.h evenements.h fonctions_damnes.h 
	gcc -o simu_enfer.o -c simu_enfer.c -Wall
	
simulateur.o: simulateur.c simulateur.h torture.h evenements.h fonctions_damnes.h 
	gcc -o simulateur.o -c simulateur.c -Wall

fonction_damnes.o: fonctions_damnes.c fonctions_damnes.h 
	gcc -o fonctions_damnes.o -c fonctions_damnes.c -Wall
    
torture.o: torture.c torture.h 
	gcc -o torture.o -c torture.c -Wall
	
evenements.o: evenements.c evenements.h
	gcc -o evenements.o -c evenements.c -Wall
	

clean:
	rm -rf *.o
    
deepclean:
	rm -rf *.o Prog

#Aucune mention des .h pour l'instant et ça marche
