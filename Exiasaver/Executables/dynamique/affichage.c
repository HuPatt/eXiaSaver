#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int nombre(char *pic)
{
   char caractere;
   int i =1000;

   // Reperage et Ouverture de l'image selectionne

   FILE * doc=NULL;
   doc = fopen(pic , "r");

    if (doc != NULL)
    {

            // Lecture du fichier jusqu'a la fin

            while ( caractere != EOF )
            {

                // Acquisition des caracteres, qui vont etre contenus dans le tableau

                caractere = fgetc(doc);

                // Conversion des valeurs par des caracteres de la norme ASCII

                if (caractere == '1')
                {
                    caractere = 88;
                   // printf("%c", caractere);
                }
                else if (caractere == '0')
                {
                    caractere = 32;
                   // printf("%c", caractere);
                }
			
                printf("%c", caractere);

                // Affichage de l'image


             }
            
    }
    int fclose(FILE*);

return 0;
}
