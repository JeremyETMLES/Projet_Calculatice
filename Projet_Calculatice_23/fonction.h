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
//#include <stdlib.h>                 // pour les fonctions systèmes
//#include <stdio.h>                  // entrée - sortie
//#include <stdint.h>

#ifndef FCT_BIN_H
#define FCT_BIN_H


// Prototype de fonction
void ConvBin(double userVal, char* tbBin[32], uint8_t sizeTbBin);
void AfficheBin(double userVal, unsigned char* tbBin, uint8_t sizeTb, uint8_t mode);
void ChoixConvBin(void);

#endif

#ifndef FCT_TRIGO_H
#define FTC_TRIGO_H

#include <stdint.h>

#define PI 3.14159

typedef struct {
	union {
		float radian;
		int32_t degre;
	}angle;

	float adjacent;
	float oppose;
	float hypothenuse;
	float sinus;
	float cosinus;
	float tangente;
}triangleRectangle;

// Prototype de fonction
int fonctionChoixCotes(triangleRectangle* cote);
void fonctionCalcul(triangleRectangle* cote);
void fonctionAffichage(triangleRectangle cote, unsigned char param3);
void calculTrigo(void);

#endif

#ifndef FCT_LOGS_H
#define FCT_LOGS_H

typedef struct {
	triangleRectangle cote;
	uint8_t modeAngle;
	double userVal;
	uint8_t tbBin[32];
	uint8_t nbBits;
	uint8_t mode;
}stValues;

// Prototype de fonction
void lectureCntIterations(uint16_t* cntBin, uint16_t* cntTrigo);
void ecritureFichierLogs(uint16_t cntBin, uint16_t cntTrigo, stValues values);

#endif