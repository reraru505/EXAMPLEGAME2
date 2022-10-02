/*
 * resman.c
 *
 *  Created on: 02-Oct-2022
 *      Author: fnln
 */

#include "resman.h"

TNI Load_tni(char * path,int multiplier,bool isflipped){

	TNI buffer;

	buffer.i = LoadImage(path);
	ImageResizeNN(&buffer.i, buffer.i.width*multiplier,buffer.i.height*multiplier);
	if(isflipped == true){
		ImageFlipHorizontal(&buffer.i);
	}
	buffer.t = LoadTextureFromImage(buffer.i);
	return buffer;

}



