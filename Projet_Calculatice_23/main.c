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

	do {
		printf("Que vouler vous faire:\n1.Convertion d'un nombre en bineaire\n2.Calcul d'un triangle rectangle\n");
		scanf_s("%c%*c", &UserAnswer, 2);
		if (UserAnswer == 1)
		{
			ChoixConvBin();
		}
		else
		{
			calculTrigo();
		}
		printf("\nVoulez-vous recommencer le programme? (q = quitter)");
		scanf_s("%c%*c", &UserAnswer, 2);
	} while (!(UserAnswer == 'Q' || UserAnswer == 'q'));
}