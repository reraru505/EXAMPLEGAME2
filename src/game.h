/*
 * game.h
 *
 *  Created on: 02-Oct-2022
 *      Author: fnln
 */

#ifndef GAME_H_
#define GAME_H_

#include "resman.h"
#include "glovals.h"

typedef struct{

	TNI player_up;
	TNI player_down;
	TNI player_left;
	TNI player_right;
	Rectangle anim_rec;
	Texture2D player_tex;
	int player_face;
	int player_speed_u;
	int player_speed_d;
	int player_speed_l;
	int player_speed_r;
	Vector2 playerpos;

	Vector2 worldpos;

	Rectangle pu;
	Rectangle pd;
	Rectangle pl;
	Rectangle pr;

	Vector2i player_pos_on_grid;

	TNI world;
	TNI world_up;
	Texture2D world_tex;
	Texture2D world_up_tex;
	Rectangle house;


} GAMEDATA;


void load_player(GAMEDATA *g);
void check_collision(GAMEDATA *g);
void loadworld(GAMEDATA *g);

void gameinstance();


#endif /* GAME_H_ */
