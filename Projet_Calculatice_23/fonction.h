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

#ifndef FCT_BIN_H
#define FCT_BIN_H


// Prototype de fonction
void ConvBin(double userVal, uint8_t* tbBin[32], uint8_t sizeTbBin);
void AfficheBin(double userVal, uint8_t* tbBin, uint8_t sizeTb, uint8_t mode);
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
uint8_t fonctionChoixCotes(triangleRectangle* cote);
void fonctionCalcul(triangleRectangle* cote);
void fonctionAffichage(triangleRectangle cote, unsigned char param3);
void calculTrigo(void);

#endif

#ifndef FCT_LOGS_H
#define FCT_LOGS_H


// Prototype de fonction
void lectureCntIterations(uint16_t* cntBin, uint16_t* cntTrigo);
void ecritureFichierLogs(uint16_t cntBin, uint16_t cntTrigo, uint32_t tbValeurs[], uint8_t sizeTbValeurs);

#endif