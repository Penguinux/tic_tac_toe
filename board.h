/*
 * board.h
 *
 *  Created on: 13 cze 2018
 *      Author: Penguinux
 */

#ifndef BOARD_H_
#define BOARD_H_
#include <iostream>



class board
{
public:
	int size=0, howmany=0;
	char playersymb;
	char computersymb;
	char **b;
	int position[2]={0,0};
	int positionc[2]={0,0};
void make_b(int size);
void clear( int size,char **arr);
bool draw(int size, char **arr);
void write_b(char **arr, int size);
bool win(char **arr, int posx, int posy, int size, int howmany);
int minimax(char **arr,int size, int howmany,int posx,int posy,char cs,char ps,int level,int alpha,int beta,int *pos);
void move_p(char **arr,int *pos, char ps, int size);

};




#endif /* BOARD_H_ */
