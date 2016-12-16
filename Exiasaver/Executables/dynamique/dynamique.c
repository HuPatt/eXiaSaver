#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "affichage.c"

int main()
{
    int n;

    int i;
    printf("Entrez le taux de rafraichissement de l'horloge\n");
    scanf("%d",&n);//on défini n étant le temps de rafraichissement et l'on enregistre la saisi de l'utilisateur.


while(1)//on rentre dans une boucle infini
{
char nbr[8], file[5];//On créer un tableau pour contenir les 8 caractères contenus dans l'heure.
int i, nb, cd;

   time_t heure_actuelle = time(NULL);//on place une heure abstraite dans heure_actuelle
   struct tm *temps_humain= localtime(&heure_actuelle);//pointeur dirigé vers une structure tm
							//cette structure permet de lire heure, minute, seconde
							//On initialise avec localtime() afin d'avoir l'heure actuelle
   int heures0, heures1, minutes0, minutes1, secondes0, secondes1;//on définit les différents composants de l'heure

  int heures= temps_humain->tm_hour;//cette instruction permet d'accéder à la partie tm_hour de la structure temps_humain
  int minutes= temps_humain->tm_min;//permet d'accéder à la partie tm_min de temps_humain
  int secondes= temps_humain->tm_sec; //permet d'accéder à la partie tm_sec de temps_humain

   if(heures<10)
        {
            heures0=0;
            heures1=heures;//si l'heure est <10 on affiche un 0 devant l'heure
        }
        else
        {
            heures0=heures%10;
            heures0=heures-heures0;
            heures0/=10;
            heures1=heures%10;//Sinon on affiche normalement
        }

        if(minutes<10)
        {
            minutes0=0;
            minutes1=minutes;//si les minutes <10 on affiche un 0 devant
        }
        else
        {
            minutes0=minutes%10;
            minutes0=minutes-minutes0;//sinon on affiche normalement
            minutes0/=10;
            minutes1=minutes%10;
        }

        if(secondes<10)
        {
            secondes0=0;
            secondes1=secondes;//si les secondes<10 on affiche un 0 devant
        }
        else
        {
            secondes0=secondes%10;
            secondes0=secondes-secondes0;//sinon on affiche normalement
            secondes0/=10;
            secondes1=secondes%10;
        }

sprintf(nbr, "%d%d:%d%d:%d%d", heures0, heures1, minutes0, minutes1, secondes0, secondes1);//on stocke les pbm dans une chaine de caractere

for(i=0;i<8;i++)//on parcourt les différents composants de l'heure
{
	if(nbr[i] == ':')
	{
	cd = nombre("2points.pbm");//Si on a ":" on ouvre le fichier "2points.pbm"
	}
	else
	{
	nb = nbr[i] - '0';
	sprintf(file, "%d.pbm", nb);//Si on a un chiffre on ouvre le fichier pbm correspondant "%d.pbm"
	cd = nombre(file);
	}
}




  printf("Cet ecran s'initialisera dans quelques secondes");


for (i =0; i < n; i++)
    {
        printf(".");
	fflush(stdout);
        sleep(1);//on afficher un point toutes les secondes jusqu'à ce que i=n
    }
system("clear");//On nettoye la console à chaque fin de boucle

}

return 0;
}





