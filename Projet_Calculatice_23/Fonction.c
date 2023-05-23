//-----------------------------------------------------------------------------------//
// Nom du projet 		: Projet calculatrice
// Nom du fichier 		: fonction.c
// Date de cr�ation 	: 23.05.2023
// Date de modification : xx.xx.20xx
//
// Auteur 				: JAR et MBR (J�r�my Affolter et Mathieu Bucher
// Modificateur			: -
//
// Description          : fonction du projet de fin de premi�re
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

//---
// Nom fonction : ConvBin
// Param�tres entr�e / sortie / inout : userVal/-/-
// Description : Converti une valeur en bin�aire
// Remarque : -
// Auteur : JAR et MBR
// Date de cr�ation	 : 23.05.2023
// Date modification : xx.xx.20xx
//---
void ConvBin(double userVal, uint8_t* tbBin[32])
{
	int32_t intUserVal = 0;
	float virgule = 0;
	uint8_t i = 0;

	intUserVal = (int)userVal;
	virgule = userVal - intUserVal;
	if (virgule != 0)
	{
		for (i = 0; i < 3; i++)
		{
			if ((virgule * 2) < 1)
			{
				tbBin[i] = 0;
			}
			else
			{
				tbBin[i] = 1;
			}
			virgule *= 2;

		}
		tbBin[i] = 0x2E;	// Ajoute le point
		i++;
	}
	while (intUserVal > 0)
	{
		tbBin[i] = intUserVal % 2;
		intUserVal = intUserVal / 2;
		i++;
	}
	if (i < sizeof(tbBin))
	{
		for (i; i < sizeof(tbBin); i++)
		{
			tbBin[i] = 0;
		}
	}
}