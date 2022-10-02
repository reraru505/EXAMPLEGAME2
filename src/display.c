/*
 * display.c
 *
 *  Created on: 02-Oct-2022
 *      Author: fnln
 */

#include "display.h"


void execution(GAMEDATA* datainstance){


	SetTargetFPS(60);

	int a = 0;
	int b = 0;

	while(!WindowShouldClose()){
		if(a == 12){
			a=0;
			everyseven(datainstance);
		}
		if(b == 3){
			b = 0;
			everythree(datainstance);
		}
		beforedraw(datainstance);
		BeginDrawing();

		ClearBackground(GREEN);
		atdraw(datainstance);

		EndDrawing();
		afterdraw(datainstance);
		a++;
		b++;

	}
}

void exit_window(){

	CloseWindow();

}


