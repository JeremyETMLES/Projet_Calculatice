//-----------------------------------------------------------------------------------//
// Nom du projet 		: Projet calculatrice
// Nom du fichier 		: main.c
// Date de cr�ation 	: 23.05.2023
// Date de modification : xx.xx.20xx
//
// Auteur 				: JAR et MBR (J�r�my Affolter et Mathieu Bucher
// Modificateur			: -
//
// Description          : programme principal du projet de fin de premi�re
//
// Remarques :          : 
// 						 
//----------------------------------------------------------------------------------//

//--- librairie standart ---//
#include <stdio.h>                  // entr�e - sortie
#include <stdlib.h>                 // pour les fonctions syst�mes
#include <stdint.h>

//-- librairie personnelle --// 
#include "fonction.h"

//-- d�claration de constantes --// 


//-- programme princiaple --// 
void main()
{
	//-- d�claration de variables --// 
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