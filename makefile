Prog: simu_enfer.o fonctions_damnes.o
	gcc simu_enfer.o fonctions_damnes.o -o Prog -Wall

main.o: simu_enfer.c fonctions_damnes.h
	gcc -c simu_enfer.c -Wall

fonction.o: fonctions_damnes.c fonctions_damnes.h
	gcc -c fonctions_damnes.c -Wall
	
clean:
	rm -rf *.o
	
deepclean:
	rm -rf *.o simu_enfer
