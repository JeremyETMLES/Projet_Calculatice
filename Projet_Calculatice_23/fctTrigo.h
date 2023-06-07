#ifndef FCT_TRIGO_H
#define FTC_TRIGO_H

#define PI 3.14159

typedef struct {
	union {
		float radian;
		short degre;
	}angle;

	short adjacent;
	short oppose;
	short hypothenuse;
	short sinus;
	short cosinus;
	short tangente;
}triangleRectangle;

// Prototype de fonction
unsigned char fonctionChoixCotes(triangleRectangle* cote);
void fonctionCalcul(triangleRectangle* cote);
void fonctionAffichage(triangleRectangle cote, unsigned char param3);
void calculTrigo(void);

#endif
