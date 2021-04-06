Prog: simu_enfer.o fonctions_damnes.o torture.o simulateur.o
	gcc -o Prog simu_enfer.o fonctions_damnes.o torture.o simulateur.o -Wall

simu_enfer.o: simu_enfer.c fonctions_damnes.h torture.h simulateur.h
	gcc -o simu_enfer.o -c simu_enfer.c -Wall

fonction.o: fonctions_damnes.c fonctions_damnes.h
	gcc -o fonctions_damnes.o -c fonctions_damnes.c -Wall
    
torture.o: torture.c torture.h
	gcc -o torture.o -c torture.c -Wall
	
simulateur.o: simulateur.c simulateur.h
	gcc -o simulateur.o -c simulateur.c -Wall

clean:
	rm -rf *.o
    
deepclean:
	rm -rf *.o Prog

#Aucune mention des .h pour l'instant et ça marche
