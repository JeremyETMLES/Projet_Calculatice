//-----------------------------------------------------------------------------------//
// Nom du projet 		: Projet calculatrice
// Nom du fichier 		: fonction.c
// Date de création 	: 23.05.2023
// Date de modification : xx.xx.20xx
//
// Auteur 				: JAR et MBR (Jérémy Affolter et Mathieu Bucher
// Modificateur			: -
//
// Description          : fonction du projet de fin de première
//
// Remarques :          : 
// 						 
//----------------------------------------------------------------------------------//

//--- librairie standart ---//
#include <stdlib.h>                 // pour les fonctions systèmes
#include <stdio.h>                  // entrée - sortie
#include <stdint.h>

//-- librairie personnelle --// 
#include "fonction.h"

//---
// Nom fonction : ConvBin
// Paramètres entrée / sortie / inout : userVal/-/-
// Description : Converti une valeur en binéaire
// Remarque : -
// Auteur : JAR et MBR
// Date de création	 : 23.05.2023
// Date modification : 02.06.2023
//---
void ConvBin(double userVal, uint8_t* tbBin, uint8_t sizeTbBin)
{
	uint32_t intUserVal = 0;	// Variable de la partie entière
	float virgule = 0;		// Variable contenant la partie après la virgule
	uint8_t i = 0;		// Variable de comptage

	if (userVal < 0)
	{
		// Calcul du complément à 2
		userVal = 4294967295 + userVal + 1;		// (2^32) - 1 = 4294967295
	}
	intUserVal = (uint32_t)userVal;	// Récupération de la partie entière
	virgule = userVal - intUserVal;	// Récupération de la valeur après la virgule
	if (virgule != 0)	// Convertion de ce qui est après la vigule si il y en a
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
	while (intUserVal > 0)	// Convertion de la partie entière du nombre
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
// Paramètres entrée / sortie / inout : userVal, tbBin, sizeTbBin/-/-
// Description : Affiche une valeur binéaire
// Remarque : -
// Auteur : JAR et MBR
// Date de création	 : 02.06.2023
// Date modification : xx.xx.20xx
//---
void AfficheBin(double userVal, uint8_t* tbBin, uint8_t sizeTb, uint8_t mode)
{
	uint8_t i = 0;		// Variable de comptage
	uint8_t nbBits = 0;	// Variable du nombre de bits à afficher

	// Si le mode ne correspond à aucun des 4, passer en mode normal
	if (mode > 3)
	{
		mode = 0;
	}
	// Si on n'est pas en mode normal, enlever la virgule
	if (mode != 0)
	{
		userVal = (int)userVal;
	}
	// Appel de la fonction de convertion de la valeur en binéaire
	ConvBin(userVal, tbBin, sizeTb);
	// Machine d'état du mode
	switch (mode)
	{
		case 0:
			nbBits = 32;	// Nombre de bits à afficher: 8
			// Boucle permetant de ne pas afficher les 0 inutiles
			while (tbBin[nbBits - 1] == 0)
			{
				nbBits--;
			}
			break;
		case 1:
			nbBits = 8;		// Nombre de bits à afficher: 8
			break;
		case 2:
			nbBits = 16;	// Nombre de bits à afficher: 16
			break;
		case 3:
			nbBits = 32;	// Nombre de bits à afficher: 32
			break;
		default:
			break;
	}
	// Affichage de la valeur binéaire
	for (i = nbBits; i > 0; i--)
	{
		// Si la valeur est le code ASCII du point
		if (tbBin[i - 1] == 46)
		{
			// Afficher un point
			printf(".");
		}
		else
		{
			// Afficher la valeur du bit
			printf("%d", tbBin[i - 1]);
		}
	}
}

//---
// Nom fonction : ChoixConvBin
// Paramètres entrée / sortie / inout : -/-/-
// Description : Convertit et affiche une valeur en binéaire
// Remarque : -
// Auteur : JAR et MBR
// Date de création	 : 06.06.2023
// Date modification : xx.xx.20xx
//---
void ChoixConvBin(void)
{
	// Variables locales
	double userVal = 0;		// Variable de sauvegarde de la valeur à convertire
	uint8_t tbBin[32] = { 0 };	// Tableau de sauvegarde de la convertion
	uint8_t i = 0;		// Variable de comptage
	uint8_t mode = 0;	// Variable du mode choisit

	printf("Entrer la valeur a convertire: ");
	scanf_s("%lf%*C", &userVal, 1);
	while ((userVal < 0) && (((int)(userVal * 10)) % 10))
	{
		printf("Ce programe ne prend pas en compte les valeurs négative à virgule.\n Reentrer votre valeur:");
		scanf_s("%lf%*C", &userVal, 1);
	}
	printf("Choisiser un mode: \nMode normal (0) \nMode 8 bits (1) \nMode 16 bits (2) \nMode 32 bits (3) \n");
	scanf_s("%d%*C", &mode, 1);
	AfficheBin(userVal, tbBin, sizeof(tbBin), mode);
}