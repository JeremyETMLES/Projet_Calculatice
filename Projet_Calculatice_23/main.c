//-----------------------------------------------------------------------------------//
// Nom du projet 		: Projet calculatrice
// Nom du fichier 		: main.c
// Date de création 	: 23.05.2023
// Date de modification : xx.xx.20xx
//
// Auteur 				: JAR et MBR (Jérémy Affolter et Mathieu Bucher
// Modificateur			: -
//
// Description          : programme principal du projet de fin de première
//
// Remarques :          : 
// 						 
//----------------------------------------------------------------------------------//

//--- librairie standart ---//
#include <stdio.h>                  // entrée - sortie
#include <stdlib.h>                 // pour les fonctions systèmes
#include <stdint.h>

//-- librairie personnelle --// 
#include "fonction.h"

//-- déclaration de constantes --// 


//-- programme princiaple --// 
void main()
{
	//-- déclaration de variables --// 
	uint8_t UserAnswer = 0;
	double userVal = 0;
	uint8_t tbBin[32] = { 0 };
	uint8_t i = 0;

	do {
		scanf_s("%lf%*C", &userVal, 1);
		ConvBin(userVal, &tbBin, sizeof(tbBin));
		for (i = sizeof(tbBin); i > 0; i--)
		{
			if (tbBin[i - 1] == 46)
			{
				printf(".");
			}
			else
			{
				printf("%d", tbBin[i - 1]);
			}
		}
		scanf_s("%c%*c", &UserAnswer, 2);
	} while (!(UserAnswer == 'Q' || UserAnswer == 'q'));
}