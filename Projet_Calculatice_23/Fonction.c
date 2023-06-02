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
#include <stdlib.h>                 // pour les fonctions syst�mes
#include <stdio.h>                  // entr�e - sortie
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
// Date modification : 02.06.2023
//---
void ConvBin(double userVal, uint8_t* tbBin, uint8_t sizeTbBin)
{
	uint32_t intUserVal = 0;		// Variable de la partie enti�re
	float virgule = 0;	// Variable contenant la partie apr�s la virgule
	uint8_t i = 0;	// Variable de comptage

	if (userVal < 0)
	{
		userVal = 4294967295 + userVal + 1;	// Conpl�ment � 2
	}
	intUserVal = (uint32_t)userVal;	// R�cup�ration de la partie enti�re
	virgule = userVal - intUserVal;	// R�cup�ration de la valeur apr�s la virgule
	if (virgule != 0)	// Convertion de ce qui est apr�s la vigule si il y en a
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
				virgule -= 0.5;
			}
			virgule *= 2;
		}
		tbBin[i] = 0x2E;	// Ajoute le point
		i++;
	}
	while (intUserVal > 0)	// Convertion de la partie enti�re du nombre
	{
		tbBin[i] = intUserVal % 2;
		intUserVal = intUserVal / 2;
		i++;
	}
	if (i < sizeTbBin)	// Rempliasage du reste du tablesu par des 0
	{
		for (i; i < sizeTbBin; i++)
		{
			tbBin[i] = 0;
		}
	}
}

//---
// Nom fonction : AfficheBin
// Param�tres entr�e / sortie / inout : userVal, tbBin, sizeTbBin/-/-
// Description : Affiche une valeur bin�aire
// Remarque : -
// Auteur : JAR et MBR
// Date de cr�ation	 : 02.06.2023
// Date modification : xx.xx.20xx
//---
void AfficheBin(double userVal, uint8_t* tbBin, uint8_t sizeTb, uint8_t mode)
{
	uint8_t i = 0;
	uint8_t nbBits = 0;

	if (mode > 3)
	{
		mode = 0;
	}
	if (mode != 0)
	{
		userVal = (int)userVal;
	}
	nbBits = mode * 8;
	ConvBin(userVal, tbBin, sizeTb);
	switch (mode)
	{
		case 0:
			nbBits = 32;
			// boucle enlever les 0---------------------------------------------
			break;
		case 1:
			nbBits = 8;
			break;
		case 2:
			nbBits = 16;
			break;
		case 3:
			nbBits = 32;
			break;
		default:
			break;
	}
	for (i = nbBits; i > 0; i--)
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
}