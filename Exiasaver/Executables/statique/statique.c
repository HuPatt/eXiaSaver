#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include "getch.c"

int statique(char *nomImg)
{
	system("clear");
	char caractere[4000];
	char pic[100];
	int hauteur = 0, temp = 0, largeur = 0, i = 0, j, max = i;
	struct winsize console;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &console);

	// Selection d'une image

	//printf("L'image a ouvrir: ");
	//scanf("%s", pic);

	// Reperage et Ouverture de l'image selectionne

	FILE * doc = NULL;
	doc = fopen(nomImg, "r");

	if (doc != NULL)
	{

		// Lecture du fichier jusqu'a la fin

		while ( caractere[i] != EOF )
		{

                	// Acquisition des caracteres, qui vont etre contenus dans le tableau

                	caractere[i] = fgetc(doc);

             	   	// Conversion des valeurs du tableau par des caracteres de la norme ASCII
			// Incrémentation de variables, au fur et à mesure du nombre de caracteres lus

                	if (caractere[i] == '1')
                	{

				caractere[i] = 35;
				temp = temp + 1;

	                }
	               	else if (caractere[i] == '0')
	               	{

				caractere[i] = 32;
				temp = temp + 1;

		       	}
			else if(caractere[i] == '\n')
			{

				hauteur = hauteur + 1;
				largeur = temp + 1;
				temp = 0;

			}

			i++;

		}

		fclose(doc);

		//Initialisation de la valeur maximale, de la taille du tableau

		max = i;

		//Positionnement du curseur au centre de la console

		for (j = 0; j < ((console.ws_row - largeur) / 2); j++)
		{

			printf("\n");

		}

		for (j = 0; j < ((console.ws_col - hauteur) / 2); j++)
		{

			printf(" ");

		}

		//Affichage des caracteres

		for (i = 0; i < max; i++)
		{

			if (caractere[i] == 35)
                	{

				printf("%c", (char)caractere[i]);

	                }

                	else if (caractere[i] == 32)
	                {

	          		printf("%c", (char)caractere[i]);

			}

			else if(caractere[i] == '\n')
			{

				printf("%c", (char)caractere[i]);

				//Re-positionnement du curseur au centre de la console

				for (j = 0; j < ((console.ws_col - hauteur) / 2); j++)
				{

					printf(" ");

				}

			}

		}

	}

	//Positionnement du curseur à l'état inital

	printf("\n");

	//Pression d'une quelconque touche du clavier, permettant ensuite de fermer le programme

	getch();

	return 0;
}
