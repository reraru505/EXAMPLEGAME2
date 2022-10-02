/*
 * display.h
 *
 *  Created on: 02-Oct-2022
 *      Author: fnln
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <raylib/raylib.h>

#include "glovals.h"
#include "game.h"

void beforedraw(  GAMEDATA *d);
void everyseven(  GAMEDATA *d);
void everythree(  GAMEDATA *d);
void afterdraw(  GAMEDATA *d);
void atdraw( GAMEDATA *d);

void execution(GAMEDATA* datainstance);

void exit_window();

#endif /* DISPLAY_H_ */
