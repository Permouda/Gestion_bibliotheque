#include <stdio.h>
#include <stdlib.h>
#include "header.h"


int interface_une(){
    int reposnse;
    printf("\n\n\n");
printf("\t********************************************************\n");
printf("      \t\t\tGESTION DE BIBLIOTHEQUE\n");
printf("\t********************************************************\n");
printf("\n");
printf("vous etes?\n");
printf("1- un administrateur\t 2- un etudiant");
printf("\n\n");
scanf("%d",&reposnse);
return reposnse;
}

struct livre_classe* les_3_mieuxnotes()
{

   FILE* fp = fopen(".\\donnees\\livres.csv", "r");
   char buffer[200];
   double nt;
   char *eptr;
struct livre_classe *lv=(struct livre_classe*)malloc(sizeof(struct livre_classe) * 100);

    if (!fp)
        printf("Can't open file\n");

    else {
            printf("*********************************************\n");

            printf("     Les titres des livres Disponibles\n");

            printf("*********************************************\n");
            printf("\n\n");
        char buffer[1024];

        int row = 0;
        int column = 0;
        int i=0;
        while (fgets(buffer,
                     1024, fp)) {
            column = 0;
            row++;

            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
                continue;

            // Splitting the data
            char* value = strtok(buffer, ", ");
            while (value) {
                // Column 1
                if (column == 0) {
                  strcpy(lv[i].titre,value);
                }


                if(column==4)
                {
                    nt=strtod(value,&eptr);
                    lv[i].note=nt;
                }

                value = strtok(NULL, ", ");
                column++;

            }
            i++;
              printf("\n");
        }
        printf("\n\n");


   }
    return lv;

}

bool Check_etud(char* code)
{
   FILE* fp = fopen(".\\donnees\\etudiants.csv", "r");

    if (!fp)
        printf("Can't open file\n");

    else {
        // Here we have taken size of
        // array 1024 you can modify it
        char buffer[1024];

        int row = 0;
        int column = 0;

        while (fgets(buffer,
                     1024, fp)) {
            column = 0;
            row++;

            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
                continue;

            // Splitting the data
            char* value = strtok(buffer, ", ");

            while (value) {
                // Column 1
                if (column == 0) {
                    if(strcmp(value,code)==0)
                    {
                        return true;
                    }

                }
value = strtok(NULL, ", ");
                column++;

            }

                     }
                     return false;

}

}


void espace_etudiant()
{
    int resp;
    char cin[9],nom[20],prenom[20];
    int cin_v=0;



    system("cls");
    printf("\n\n*********************************************\n");
    printf("ECOLE MAROCAINE DES SCIENCES DE L'INGENIEUR\nESPACE ETUDIANT\n Gestion de bibliotheque\n");
    printf("*****************************************************\n\n");
    printf("\n\n");
    printf("1- s'identifier\t  2- s'inscrire\n\n");
    scanf("%d",&resp);
    if(resp==1){
            printf("entrez votre CIN:");
            scanf("%s",cin);
            if(Check_etud(cin))
        {
            int choix = menu_etud();

            switch(choix){
        case 1:
            afficher_livres();
            break;
        case 2:
            afficher_3_mieux_notee();
            break;
            }
        }
    }


    else{

        printf("veuillez saisir votre nom:");
        scanf("%s",nom);
        printf("veuillez saisir votre prenom:");
        scanf("%s",prenom);

        do{
        printf("veuillez saisir un CIN valide:");
        scanf("%s",cin);



// validation de cin

        while (cin[cin_v] != '\0'){
            cin_v++;

        }
         }while(cin_v!=8);


// hna khass fonction li ghatzid lina hada li t9iyd f'table dial li m9iydin

        printf("inscription validee \n nom: %s \n prenom: %s \n cin: %s \n",nom,prenom,cin);

 system("pause");


         int choix = menu_etud();

            switch(choix){
        case 1:
            afficher_livres();
            break;
        case 2:
            afficher_3_mieux_notee();
            break;
            }


}
}


int menu_etud()
{
    system("cls");
int choix;
    printf("***************************************\n***************************************\n");
    printf("\tECOLE MAROCAINE\n\tDE SCIENCES DE L'INGENIEUR\n");
    printf("***************************************\n***************************************\n");
    printf("\n\n\n");
    printf("\t*****************************************************\n");
    printf("\t\t                 Menu\n");
    printf("\t*****************************************************\n");
    printf("1- afficher tous les livres par classement\n2- voire les 3 livres les mieux notes pour chaque type\n3- voir les 3 livres les plus cherches pour chaque type\n");
    printf("4- chercher un livre\n5- demander un livre qui n'existe pas\n6- donner une note a un livre que vous avez lu\n7- Quitter");
    printf("\nsaisissez votre choix:");
    scanf("%d",&choix);
    return choix;
}

void afficher_livres(){
   FILE* fp = fopen("C:\\Gestion_biblio\\donnees\\livres.csv", "r");
   char buffer[200];

    if (!fp)
        printf("Can't open file\n");

    else {
            printf("*********************************************\n");

            printf("     Les titres des livres Disponibles\n");
            printf("*********************************************\n");
            printf("\n\n");
        char buffer[1024];

        int row = 0;
        int column = 0;

        while (fgets(buffer,
                     1024, fp)) {
            column = 0;
            row++;

            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
                continue;

            // Splitting the data
            char* value = strtok(buffer, ", ");
            while (value) {
                // Column 1
                if (column == 0) {
                   printf("\ttitre:");
                }
                if(column == 1)
                {
                    printf("\tauteur:");
                }
                 if(column == 2)
                {
                    printf("\ttype:");
                }
                printf("%s", value);
                value = strtok(NULL, ", ");
                column++;

            }
              printf("\n");
        }
        printf("\n\n");


   }
}
int compare (const void * a, const void * b)
{

  livre_classe *orderA = (livre_classe *)a;
  livre_classe *orderB = (livre_classe *)b;

  return ( orderB->note - orderA->note );
}
void trier(struct livre_classe* lv,int n)
{
  qsort(lv,n,sizeof(livre_classe),compare);
  printf("************************************************************\n");
  printf("               Les livres les plus Notes:\n");
  printf("************************************************************\n");
  printf("\n\n");
   for(int i=0;i<3;i++)
   {
       printf("\t%s\n\n",lv[i].titre,lv[i].note);

   }
}
void afficher_3_mieux_notee()
{
   struct livre_classe* lv = les_3_mieuxnotes();

    trier(lv,4);

}

