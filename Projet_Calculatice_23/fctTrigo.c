#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include "fonction.h"




unsigned char fonctionChoixCotes(triangleRectangle* cote)
{
	uint8_t param1 = 0;
	uint8_t param2 = 0;
	uint8_t param3 = 0;

	//choix paramètre 1 avec cote et valeur du cote
	printf("Quelle est le cote du triangle choisi ?\n");
	printf("1.Oppose\n2.Adjacent\n3.Hypotenuse\n");
	scanf("%d%*c", &param1, 1);
	
	while(param1 == 0)
	{
		printf("Cela ne correspond pas a un cote reentrer votre choix\n");
		scanf("%d%*c", &param1, 1);
	}

	printf("Quelle est la longueur de ce cote ?\n");
	if (param1 == 1)
	{
		scanf("%f", &cote->oppose);
	}

	if (param1 == 2)
	{
		scanf("%f", &cote->adjacent);
	}

	if (param1 == 3)
	{
		scanf("%f", &cote->hypothenuse);
	}


	//choix parametre 2 avec cote choisi et valeur du cote
	printf("Quelle est le cote du triangle choisi ?\n");
	printf("1.Oppose\n2.Adjacent\n3.Hypotenuse\n");
	scanf("%d%*c", &param2,1);

	while ((param2 == 0) || (param1 == param2))
	{
		printf("Cela ne correspond pas a un cote ou ce cote a deja ete enregistre, reentrer votre choix\n");
		scanf("%d%*c", &param2, 1);
	}

	printf("Quelle est la longueur de ce cote ?\n");
	if (param2 == 1)
	{
		scanf("%f", &cote->oppose);
	}

	if (param2 == 2)
	{
		scanf("%f", &cote->adjacent);
	}

	if (param2 == 3)
	{
		scanf("%f", &cote->hypothenuse);
	}


	//choix de l'unite de l'angle
	printf("Dans quelle unite l'angle doit il etre donne?\n1.En degre\n2.En radian\n");
	scanf("%d%*c", &param3,1);

	return param3;
}

void fonctionCalcul(triangleRectangle* cote)
{
	if (cote->adjacent == 0) {
		if ((cote->oppose * cote->oppose) >= (cote->hypothenuse * cote->hypothenuse)) {
			printf("Erreur : Les valeurs des cotes ne permettent pas de calculer l'abscisse.\n");
			return;
		}
		cote->adjacent = sqrt((cote->hypothenuse * cote->hypothenuse) - (cote->oppose * cote->oppose));
	}
	else if (cote->oppose == 0) {
		if ((cote->adjacent * cote->adjacent) >= (cote->hypothenuse * cote->hypothenuse)) {
			printf("Erreur : Les valeurs des cotes ne permettent pas de calculer le cote oppose.\n");
			return;
		}
		cote->oppose = sqrt((cote->hypothenuse * cote->hypothenuse) - (cote->adjacent * cote->adjacent));
	}
	else if (cote->hypothenuse == 0) {
		cote->hypothenuse = sqrt((cote->oppose * cote->oppose) + (cote->adjacent * cote->adjacent));
	}
	cote->angle.radian = acos(cote->adjacent / cote->hypothenuse);
}


void fonctionAffichage(triangleRectangle cote, unsigned char param3)
{
	printf("\nValeurs du triangle :\n");
	printf("Oppose : %.2f\n", cote.oppose);
	printf("Adjacent : %.2f\n", cote.adjacent);
	printf("Hypotenuse : %.2f\n", cote.hypothenuse);
	printf("Sinus : %.2f\n", sin(cote.angle.radian));
	printf("Cosinus : %.2f\n", cos(cote.angle.radian));
	printf("Tangente : %.2f\n", tan(cote.angle.radian));

	if(param3 ==1)
	{
		cote.angle.degre = cote.angle.radian * (180.0 / PI);
		printf("Angle : %d degre\n", cote.angle.degre);
	}
	else
	{
		printf("Angle : %.2f radian\n", cote.angle.radian);
	}
}

void calculTrigo(void)
{
	triangleRectangle cote = {0, 0, 0, 0, 0, 0, 0};
	uint8_t param3 = 0;

	param3 = fonctionChoixCotes(&cote);
	fonctionCalcul(&cote);
	fonctionAffichage(cote, param3);
}