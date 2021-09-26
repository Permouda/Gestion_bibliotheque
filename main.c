#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
// #include "fonctions.c"
#include "header.h"
#include "fonction_administrateur.c"


/*
 typedef struct livre{
 char titre[40];
 char auteur[20];
 char genre[15];

 };*/



int main()
{//iliass main
    int choix ;char rep;
    do{
      system("cls");
    printf("******* MENU******\n");
    printf("1- Ajouter un etudiant \n");
    printf("2- rechercher un etudiant \n");
    printf("3- Supprimer un etudiant \n");
    printf("4- modifier un etudiant \n");
    printf("5- Afficher tous les etudiants \n");
    printf("6- Quitter \n\n");
    do{
        printf("\n -Entrer votre choix :");
        scanf("%d",&choix);
    }while(choix<1 || choix>6);
    switch(choix){
    case 1:ajouterEtudiant();
    break;
    case 2:recherche();
    break;
    case 3:supprimer_etudiant();
    break;
    case 4:moddifier_etudiant();
    break;
    case 5:afficher_tout();
    break;
    case 6:break;
    }if(choix == 6)return 0;
    printf("\n Voulez-vous continuez o/n: ");
    scanf("%s",&rep);
    fflush(stdin);

    }while(rep=='o' || rep=='O');




    //Ayoub main

/*
int response=interface_une();
    switch(response){
case 1:
    printf("ba9ii");
    break;
case 2:
    espace_etudiant();
    break;
    }

*/
    return 0;
}
