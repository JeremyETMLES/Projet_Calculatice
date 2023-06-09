//-----------------------------------------------------------------------------------//
// Nom du projet 		: Projet calculatrice
// Nom du fichier 		: logs.c
// Date de création 	: 08.06.2023
// Date de modification : xx.xx.20xx
//
// Auteur 				: JAR et MBR (Jérémy Affolter et Mathieu Bucher)
// Modificateur			: -
//
// Description          : Fonctions d'enregistrement et de lecture de valeurs dans un fichier
//
// Remarques :          : 
// 						 
//----------------------------------------------------------------------------------//

//--- librairie standart ---//
#include <stdlib.h>		// pour les fonctions systèmes
#include <stdio.h>		// entrée - sortie
#include <stdint.h>
#include <time.h>		// Gestion du temps réel

//-- librairie personnelle --// 
#include "fonction.h"

#define _CRT_SECURE_NO_WARNINGS



// -- -
// Nom fonction : lectureCntIterations
// Paramètres entrée / sortie / inout : -/-/cntBin, cntTrigo
// Description : Lit le nombre de fois que les fonctions de convertion et de trigo on été utilisées
// Remarque : -
// Auteur : JAR et MBR
// Date de création	 : 08.06.2023
// Date modification : xx.xx.2023
//---
void lectureCntIterations(uint16_t* cntBin, uint16_t* cntTrigo)
{
	// Variables locales
	uint8_t ligne[256];
	uint8_t i = 0;
	// Ouverture du stream du fichier en mode lecture
	FILE* fichier = fopen("sauvlogs.txt", "r+");

	while (fgets(ligne, sizeof(ligne), fichier))
	//for(i = 0; i < 2; i++)
	{
		//fgets(ligne, sizeof(ligne), fichier);
		if(sscanf(ligne, "La fonction de convertion binaire à été utilisée %d fois", &cntBin));
		if(sscanf(ligne, "La fonction de calcul trigonomètrique à été utilisée %d fois", &cntTrigo));
	}

	fclose(fichier);
}

// -- -
// Nom fonction : ecritureFichierLogs
// Paramètres entrée / sortie / inout : cntBin, cntTrigo, valeurs/-/-
// Description : Ajoute des lignes dans un fichier afin de sauvegarder les calculs effectués
// Remarque : -
// Auteur : JAR et MBR
// Date de création	 : 08.06.2023
// Date modification : xx.xx.2023
//---
void ecritureFichierLogs(uint16_t cntBin, uint16_t cntTrigo, stValues values)
{
	// Variables locales
	time_t now;
	time(&now);
	struct tm* timeInfos = localtime(&now);	// Structure sauvegardant la date actuelle
	uint8_t i = 0;	// Variable de comptage

	// Ouverture du stream du fichier en mode écriture
	FILE* fichier = fopen("sauvlogs.txt", "r+");

	fseek(fichier, 0, SEEK_SET);

	fprintf(fichier, "La fonction de convertion binaire à été utilisée %d fois\n", cntBin);
	fprintf(fichier, "La fonction de calcul trigonomètrique à été utilisée %d fois", cntTrigo);

	fseek(fichier, 0, SEEK_END);

	// Écriture de la date 
	fprintf(fichier, "\n%02d.%02d.%04d - %02d:%02d\n",
		timeInfos->tm_mday, timeInfos->tm_mon + 1, timeInfos->tm_year + 1900,
		timeInfos->tm_hour, timeInfos->tm_min);

	if (values.mode == 0)
	{
		fprintf(fichier, "%.02lf / 0b", values.userVal);
		for (i = values.nbBits - 1; i < values.nbBits; i--)
		{
			// Si la valeur est le code ASCII du point
			if (values.tbBin[i] == 46)
			{
				// Afficher un point
				fprintf(fichier, '.');
			}
			else
			{
				fprintf(fichier, "%d", values.tbBin[i]);
			}
		}
	}
	else
	{
		fprintf(fichier, "%.2f, %.2f / %.2f, %.3f, %.3f, %.3f, ", values.cote.oppose, values.cote.adjacent,
			values.cote.hypothenuse, values.cote.sinus, values.cote.cosinus, values.cote.tangente);
		if (values.modeAngle == 0)
		{
			fprintf(fichier, "%f", values.cote.angle.radian);
		}
		else
		{
			fprintf(fichier, "%d", values.cote.angle.degre);
		}
	}

	fclose(fichier);
}