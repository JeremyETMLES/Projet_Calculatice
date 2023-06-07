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