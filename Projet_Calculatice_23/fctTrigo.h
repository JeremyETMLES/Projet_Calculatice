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
