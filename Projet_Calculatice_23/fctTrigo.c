#include <stdio.h>
#include <math.h>
#include "fctTrigo.h"



unsigned char fonctionChoixCotes(triangleRectangle* cote)
{
	unsigned char param1 = 0;
	unsigned char param2 = 0;
	unsigned char param3 = 0;

	//choix paramètre 1 avec cote et valeur du cote
	printf("quelle est le coté du triangle choisi ?\n");
	printf("1.Opposé\n2.Adjacent\n3.Hypoténuse\n");
	scanf("%d%*c", &param1, 1);
	
	while(param1 == 0)
	{
		printf("Cela ne correspond pas a un cote reentrer votre choix\n");
		scanf("%d%*c", &param1, 1);
	}

	printf("Quelle est la longueur de ce coté ?\n");
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
	printf("quelle est le coté du triangle choisi ?\n");
	printf("1.Opposé\n2.Adjacent\n3.Hypoténuse\n");
	scanf("%d%*c", &param2,1);

	while ((param2 == 0) || (param1 == param2))
	{
		printf("Cela ne correspond pas a un cote ou ce cote a deja ete enregistre, reentrer votre choix\n");
		scanf("%d%*c", &param2, 1);
	}

	printf("Quelle est la longueur de ce coté ?\n");
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
	printf("Dans quelle unite l'angle doit il etre donne?\n1.En degré\n2.En radian\n");
	scanf("%d%*c", &param3,1);

	return param3;
}

void fonctionCalcul(triangleRectangle* cote)
{
	if (cote->oppose != 0 && cote->adjacent != 0)
	{
		cote->hypothenuse = sqrt(cote->oppose ^ 2 + cote->adjacent ^ 2);
		cote->angle.radian = atan(cote->oppose / cote->adjacent);
		cote->angle.degre = cote->angle.radian * (180.0 / PI);

	}
	if (cote->oppose != 0 && cote->hypothenuse != 0)
	{
		cote->adjacent = sqrt(cote->hypothenuse ^ 2 - cote->oppose ^ 2);
		cote->angle.radian = asin(cote->oppose / cote->hypothenuse);
		cote->angle.degre = cote->angle.radian * (180.0 / PI);
	}
	if (cote->hypothenuse != 0 && cote->adjacent != 0)
	{
		cote->oppose = sqrt(cote->hypothenuse ^ 2 - cote->adjacent ^ 2);
		cote->angle.radian = acos(cote->adjacent / cote->hypothenuse);
		cote->angle.degre = cote->angle.radian * (180.0 / PI);
	}

	


}


void fonctionAffichage(triangleRectangle cote, unsigned char param3)
{
	printf("\nValeurs du triangle :\n");
	printf("Opposé : %.2f\n", cote.oppose);
	printf("Adjacent : %.2f\n", cote.adjacent);
	printf("Hypoténuse : %.2f\n", cote.hypothenuse);
	printf("Sinus : %.2f\n", sin(cote.angle.radian));
	printf("Cosinus : %.2f\n", cos(cote.angle.radian));
	printf("Tangente : %.2f\n", tan(cote.angle.radian));

	if(param3 ==1)
	{
		printf("Angle : %d degré\n", cote.angle.degre);
	}
	if(param3 == 2)
	{
		printf("Angle : %.2f radian\n", cote.angle.radian);
	}
}

void calculTrigo(void)
{
	triangleRectangle cote = {0, 0, 0, 0, 0, 0, 0};
	unsigned char param3 = 0;

	param3 = fonctionChoixCotes(&cote);
	fonctionCalcul(&cote);
	fonctionAffichage(cote, param3);
}