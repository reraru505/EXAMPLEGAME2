/*
 * collman.h
 *
 *  Created on: 02-Oct-2022
 *      Author: fnln
 */

#ifndef COLLMAN_H_
#define COLLMAN_H_

#include <stdbool.h>
#include <raylib/raylib.h>

#include "glovals.h"

bool array_xor(bool arr[],int len);
bool array_or(bool arr[],int len);
bool array_and(bool arr[],int len);

Vector2 find_player_pos_in_world(Vector2 playerpos,Vector2 worldpos);

Vector2i player_pos_on_grid(Vector2 v);


#endif /* COLLMAN_H_ */
