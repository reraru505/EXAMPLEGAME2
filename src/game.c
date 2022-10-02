/*
 * game.c
 *
 *  Created on: 02-Oct-2022
 *      Author: fnln
 */


#include "game.h"
#include "display.h"
#include "collman.h"
#include "stdio.h"



void beforedraw(GAMEDATA *d){

	d->player_speed_u = 5;
	d->player_speed_d = 5;
	d->player_speed_l = 5;
	d->player_speed_r = 5;


	check_collision(d);


	if(IsKeyPressed(KEY_F11)){
		int display = GetCurrentMonitor();

			if (IsWindowFullscreen())
		            {
		                // if we are full screen, then go back to the windowed size
		                SetWindowSize(screenwidth, screenheight);
		      }
			else
		      {
		                // if we are not full screen, set the window size to match the monitor we are on
		                SetWindowSize(GetMonitorWidth(display), GetMonitorHeight(display));
		       }
			ToggleFullscreen();

	}

	if(IsKeyDown(KEY_W)){

		if(d->playerpos.y < (180)){

			d->player_face = 1;
			d->worldpos.y += d->player_speed_u;

		}else{
			d->player_face = 1;
			d->playerpos.y -= d->player_speed_u;

		}
	}else if(IsKeyDown(KEY_A)){

		if(d->playerpos.x < (320)){
			d->player_face = 2;
			d->worldpos.x += d->player_speed_l;
		}else{
			d->player_face = 2;
			d->playerpos.x -= d->player_speed_l;
		}
	}else if(IsKeyDown(KEY_S)){

		if(d->playerpos.y > (440)){
			d->player_face = 3;
			d->worldpos.y -= d->player_speed_d;
		}else{
			d->player_face = 3;
			d->playerpos.y += d->player_speed_d;
		}

	}else if(IsKeyDown(KEY_D)){

		if(d->playerpos.x > (860)){
			d->player_face = 4;
			d->worldpos.x -= d->player_speed_r;
		}else{
			d->player_face = 4;
			d->playerpos.x += d->player_speed_r;
		}
	}

	if(d->player_face == 1){
		d->player_tex = d->player_up.t;
	}else if(d->player_face == 2){
		d->player_tex = d->player_left.t;
	}else if(d->player_face == 3){
		d->player_tex = d->player_down.t;
	}else if(d->player_face == 4){
		d->player_tex = d->player_right.t;
	}

}
void everyseven(GAMEDATA *d){
	d->anim_rec.x += d->anim_rec.width; //player animation
}
void everythree(GAMEDATA *d){


}
void afterdraw(GAMEDATA *d){

}

void atdraw(GAMEDATA *d){

	DrawTexture(d->world_tex, d->worldpos.x, d->worldpos.y, WHITE);
	DrawTextureRec(d->player_tex, d->anim_rec,d->playerpos,WHITE);
	DrawTexture(d->world_up_tex, d->worldpos.x, d->worldpos.y, WHITE);

}

void load_player(GAMEDATA *g){


	g->player_down = Load_tni("res/Player_facing_down.png",scale,false);
	g->player_up = Load_tni("res/Player_facing_up.png",scale,false);
	g->player_left = Load_tni("res/Player_facing_left.png",scale,false);
	g->player_right = Load_tni("res/Player_facing_right.png",scale,false);
	g->anim_rec = (Rectangle){0,0,32*scale,32*scale};
	g->player_face = 1;
	g->playerpos = (Vector2){screenwidth/2-96,screenheight/2};

}



void check_collision(GAMEDATA *d){

	d->pu = (Rectangle){d->playerpos.x,d->playerpos.y-(32),(32*2),(32*2)};
	d->pd = (Rectangle){d->playerpos.x,d->playerpos.y+(32),(32*2),(32*2)};
	d->pl = (Rectangle){d->playerpos.x-(32),d->playerpos.y,(32*2),(32*2)};
	d->pr = (Rectangle){d->playerpos.x+(32),d->playerpos.y,(32*2),(32*2)};
	d->house = (Rectangle){d->worldpos.x+(16*32*4),d->worldpos.y+(3*32*4),(7*32*4),(2*32*2)};

	if(CheckCollisionRecs(d->pu, d->house))d->player_speed_u = 0;
	if(CheckCollisionRecs(d->pd, d->house))d->player_speed_d = 0;
	if(CheckCollisionRecs(d->pl, d->house))d->player_speed_l = 0;
	if(CheckCollisionRecs(d->pr, d->house))d->player_speed_r = 0;



}

void loadworld(GAMEDATA *g){

	g->worldpos = (Vector2){0,0};

	//map_coll_array_init(g);

	g->world = Load_tni("res/map.png",4,false);
	g->world_up = Load_tni("res/houseup.png",4,false);

	g->world_tex = g->world.t;
	g->world_up_tex = g->world_up.t;
}



void gameinstance(){

	InitWindow(screenwidth,screenheight,"agame");


	GAMEDATA datainstance;

	load_player(&datainstance);

	loadworld(&datainstance);

	execution(&datainstance);

	exit_window();

}


