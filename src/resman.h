/*
 * resman.h
 *
 *  Created on: 02-Oct-2022
 *      Author: fnln
 */

#ifndef RESMAN_H_
#define RESMAN_H_

#include <raylib/raylib.h>
#include <stdlib.h>

typedef struct{
	Image i;
	Texture2D t;
}TNI;

TNI Load_tni(char * path,int multiplier,bool isflipped);

#endif /* RESMAN_H_ */
