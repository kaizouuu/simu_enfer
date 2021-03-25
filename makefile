Prog: simu_enfer.o fonctions_damnes.o torture.o simulateur.o
	gcc -o Prog simu_enfer.o fonctions_damnes.o torture.o -Wall

simu_enfer.o: simu_enfer.c 
	gcc -o simu_enfer.o -c simu_enfer.c -Wall

fonction.o: fonctions_damnes.c 
	gcc -o fonctions_damnes.o -c fonctions_damnes.c -Wall
    
torture.o: torture.c 
	gcc -o torture.o -c torture.c -Wall
	
simulateur.o: simulateur.c 
	gcc -o simulateur.o -c simulateur.c -Wall

clean:
	rm -rf *.o
    
deepclean:
	rm -rf *.o Prog

#Aucune mention des .h pour l'instant et ça marche
