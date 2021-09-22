#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



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


bool Check_etud(char* code)
{
   FILE* fp = fopen("C:\\Gestion_biblio\\donnees\\etudiants.csv", "r");

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
    char cin[20];

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
            printf("success");
        }
    else{
            do{
        printf("veuillez saisir un CIN valide:");
        scanf("%s",cin);
            }
            while(Check_etud(cin)==false);
         printf("success");
    }
  }
}





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
