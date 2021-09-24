#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "fonctions.c"
#include "header.h"



/*
 typedef struct livre{
 char titre[40];
 char auteur[20];
 char genre[15];

 };*/



int main()
{

int response=interface_une();
    switch(response){
case 1:
    printf("ba9ii");
    break;
case 2:
    espace_etudiant();
    break;
    }


    return 0;
}
