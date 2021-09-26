#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "fonctions.c"

struct Etudiant_classe Etud;
//fonction de recherche
bool rech(char*cin_n){
FILE *F;
F=fopen("Etudiant.txt","r");
do{
   fscanf(F,"%s ;%s ;%s \n",&Etud.cin,&Etud.nom,&Etud.prenom);
   fflush(stdin);
   if(Etud.cin == cin_n){
    fclose(F);
    return 1;
   }

}while(!feof(F));
fclose(F);
return 0;
}

// fonction d'ajouter etudiant
void ajouterEtudiant()
{
    FILE*F;
    char* cin_n;
    F=fopen("Etudiant.txt","a");
    printf("\n saisir le cin de l'etudian : ");
    scanf("%s",&cin_n);
    fflush(stdin);
    while(rech(cin_n)==1)
    {
        printf("\n ce Etudiant existe deja:");
        printf("\n Entrer un nouveau etudiant: ");
        scanf("%s",&cin_n);
    };
    Etud.cin<=cin_n;
    printf("\n Enter le nom :");
    gets(Etud.nom);
    fflush(stdin);
    printf("\n Enter le prenom :");
    gets(Etud.prenom);
    fflush(stdin);
    fprintf(F,"%s ;%s ;%s \n",Etud.cin,Etud.nom,Etud.prenom);
    close(F);
}

// recherche et affichage
void recherche(){
char* cin_search;
printf("Entrer le cin de l'etudiant a rechercher : ");
scanf("%s", &cin_search);
FILE*F;
F = fopen("Etudian.txt","r");
do{
        //lire une ligne et la metre dans une structure
    fscanf(F,"%s ;%s ;%s \n",&Etud.cin,&Etud.nom,&Etud.prenom);
    if (cin_search == Etud.cin){
        printf("CIN: %s \n",Etud.cin);
        printf("nom: %s \n",Etud.nom);
        printf("prenom: %s \n",Etud.prenom);
    }
}while(!feof(F));
fclose(F);
}

// supression de l'etudiant
void supprimer_etudiant(){
char rep;
int* cin_search;
printf("Entrer le cin de l'etudiant a supprimer :");
scanf("%s",&cin_search);
fflush(stdin);
if (rech(cin_search)==1){
    printf("\n voulez vous vraiment supprimer o/n ?");
    scanf("%c",&rep);
    fflush(stdin);
    if(rep=='o' || rep=='O'){
        FILE* Fich, *F;
        F = fopen("Etudiant.txt", "r");
        Fich = fopen("TempEtudiant.txt", "a");

        do{
        fscanf(F,"%s ;%s ;%s \n",&Etud.cin,&Etud.nom,&Etud.prenom);
        if(cin_search != Etud.cin)
        {
        fprintf(Fich,"%s ;%s ;%s \n",Etud.cin,Etud.nom,Etud.prenom);
        }
        }while(!feof(F));
    fclose(Fich);
    fclose(F);
    remove("Etudiant.txt");
    rename("TempEtudiant.txt", "Etudiant.txt");
    printf("Suppression Effectuee");
    }

}
else{
    printf("\n Ce CIN n'existe pas");
}
}

// Moddifier etudiant

void moddifier_etudiant(){
FILE*F, *Fich;
char* cin_search;
char rep='n';
printf("\n Entrer le CIN de l'etudiant a modifier");
scanf("%d", &cin_search);
fflush(stdin);
if(rech(cin_search)==1){
    printf("\n Voulez vraiment moddifier o/n ? ");
    scanf("%c",&rep);
    fflush(stdin);
    printf("%c",rep);

    if(rep=='o' || rep=='O'){
        F = fopen("Etudiant.txt","r");
        Fich = fopen("TempEtudiant.txt","a");

        do{
        fscanf(F,"%s ;%s ;%s \n",&Etud.cin,&Etud.nom,&Etud.prenom);
        if(cin_search == Etud.cin)
        {
        printf("\n Entrer le nouveau CIN : ");
        gets(Etud.cin);
        printf("\n Entrer le nouveau nom : ");
        gets(Etud.nom);
        printf("\n Entrer le nouveau prenom : ");
        gets(Etud.prenom);
        printf("\n la modification a reussi");
        }
        fprintf(Fich,"%s ;%s ;%s \n",Etud.cin,Etud.nom,Etud.prenom);

        }while(!feof(F));
    fclose(Fich);
    fclose(F);
    remove("Etudiant.txt");
    rename("TempEtudiant.txt", "Etudiant.txt");
    }
    else{
    printf("\n la modification a ete annule \n");
    }
}
else{
printf("\n ce CIN n'existe pas");
}
}

// afficher tout les etudiants
void afficher_tout(){
FILE*F;
F=fopen("Etudiant.txt","r");
printf("la liste des etudiants est: \n\n");
printf("CIN\t Nom\t Prenom \n");
do{
    fscanf(F,"%s ;%s ;%s \n",&Etud.cin,&Etud.nom,&Etud.prenom);
    fflush(stdin);
    printf("%s\t ",Etud.cin);
    printf("%s\t ",Etud.nom);
    printf("%s\n",Etud.prenom);
}while(!feof(F));
fclose(F);

}

