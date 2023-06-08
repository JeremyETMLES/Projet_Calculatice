//-----------------------------------------------------------------------------------//
// Nom du projet 		: Projet calculatrice
// Nom du fichier 		: logs.c
// Date de cr�ation 	: 08.06.2023
// Date de modification : xx.xx.20xx
//
// Auteur 				: JAR et MBR (J�r�my Affolter et Mathieu Bucher)
// Modificateur			: -
//
// Description          : Fonctions d'enregistrement et de lecture de valeurs dans un fichier
//
// Remarques :          : 
// 						 
//----------------------------------------------------------------------------------//

//--- librairie standart ---//
#include <stdio.h>		// entr�e - sortie
#include <time.h>		// Gestion du temps r�el

//-- librairie personnelle --// 
#include "fonction.h"

// -- -
// Nom fonction : lectureCntIterations
// Param�tres entr�e / sortie / inout : -/-/cntBin, cntTrigo
// Description : Lit le nombre de fois que les fonctions de convertion et de trigo on �t� utilis�es
// Remarque : -
// Auteur : JAR et MBR
// Date de cr�ation	 : 08.06.2023
// Date modification : xx.xx.2023
//---
void lectureCntIterations(uint16_t* cntBin, uint16_t* cntTrigo)
{
	// Variables locales
	char ligne[128];

	// Ouverture du stream du fichier en mode lecture
	FILE* fichier = fopen("sauvlogs.txt", "r");

	while (fgets(ligne, sizeof(ligne), fichier))
	{
		sscanf(ligne, "La fonction de convertion bin�aire � �t� utilis�e %d fois", &cntBin);
		sscanf(ligne, "La fonction de calcul trigonom�trique � �t� utilis�e %d fois", &cntTrigo);
	}

	fclose(fichier);
}

// -- -
// Nom fonction : ecritureFichierLogs
// Param�tres entr�e / sortie / inout : cntBin, cntTrigo, valeurs/-/-
// Description : Lit le nombre de fois que les fonctions de convertion et de trigo on �t� utilis�es
// Remarque : -
// Auteur : JAR et MBR
// Date de cr�ation	 : 08.06.2023
// Date modification : xx.xx.2023
//---
void ecritureFichierLogs(uint16_t cntBin, uint16_t cntTrigo, str valeurs)
{
	// Variables locales
	struct tm* timeInfos = localtime(time(NULL));	// Structure sauvegardant la date actuelle

	// Ouverture du stream du fichier en mode �criture
	FILE* fichier = fopen("sauvlogs.txt", "a+");

	fseek(fichier, 0, SEEK_SET);

	fprintf(fichier, "La fonction de convertion bin�aire � �t� utilis�e %d fois", cntBin);
	fprintf(fichier, "La fonction de calcul trigonom�trique � �t� utilis�e %d fois", cntTrigo);

	fseek(fichier, 0, SEEK_END);

	// �criture de la date 
	fprintf(file, "%02d.%02d.%04d - %02d:%02d\n",
		timeInfos->tm_mday, timeInfos->tm_mon + 1, timeInfos->tm_year + 1900,
		timeInfos->tm_hour, timeInfos->tm_min);
	fprintf(fichier, "%s\n", valeurs);

	fclose(fichier);
}