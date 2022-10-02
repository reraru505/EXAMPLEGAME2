/*
 * colman.c
 *
 *  Created on: 02-Oct-2022
 *      Author: fnln
 */

#include "collman.h"

bool array_xor(bool arr[],int len){

	int num = 0;

	for(int i = 0; i < len ; i++){

		if(arr[i] == true){
			num++;
		}
	}

	if(num == 1){
		return true;
	}else{
		return false;
	}

}

bool array_or(bool arr[],int len){

	int num = 0;

	for(int i = 0; i < len ; i++){

		if(arr[i] == true){
			num++;
		}
	}

	if(num > 0){
		return true;
	}else{
		return false;
	}

}

bool arrayxor(bool arr[],int len){

	int num = 0;

	for(int i = 0; i < len ; i++){

		if(arr[i] == true){
			num++;
		}
	}

	if(num == (len-1)){
		return true;
	}else{
		return false;
	}

}

Vector2 find_player_pos_in_world(Vector2 playerpos,Vector2 worldpos){

	Vector2 inworld;

	inworld.x = playerpos.x + (-1 * worldpos.x);
	inworld.y = playerpos.y + (-1 * worldpos.y);

	return inworld;
}

Vector2i player_pos_on_grid(Vector2 v){
	Vector2i buffer;

	buffer.x = (int) (v.x/32)/scale;
	buffer.y = (int) (v.y/32)/scale;

	return buffer;
}


