#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions_damnes.h"

int main()
{
    FILE * database_PPF = NULL;
    PPF *nouveau = NULL;
    PPF *pt_tete = NULL;
    char nomrech[TCHAINE];

    menu(&pt_tete,nouveau,nomrech,database_PPF);
    fclose(database_PPF);
    return 0;
}

