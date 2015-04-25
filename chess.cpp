#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "define.h"
#include <list>
using namespace std;
#include "init_board.h"
#include "isCheck.h"
#include "moves.h"
#include "en_passant.h"
#include "mutari_identice.h"
#include "getMove.h"
#include "checkPown.h"
#include "castling.h" 
#include "generate_all.h"
#include "evaluate.h"
#include "minimax.h"


/*Functia afisareTabla printeaza la consola tabla de sah.*/
void afisareTabla()
{
	int i,j;
	for (i = 9; i >= 2; i--)
	{
		printf("%d ",i-1);
		for (j = 2; j <= 9; j++)
		{
			if (board[i][j] == 0)
				printf("_");
			else
				printf("%c",board[i][j]);
		}
		printf("\n");
	}
	printf("\n  ");
	for (i = 1; i <= 8; i++)
		printf("%c",'a'+i-1);
	printf("\n\n");
}

/*Functia validMove testeaza daca am primit o mutare de la Winboard*/
int validMove(char* string) {
	if (('a' <= string[0]) && (string[0] <= 'h') && (1 <= (string[1] - '0')) && ((string[1] - '0') <= 8) &&
		('a' <= string[2]) && (string[2] <= 'h') && (1 <= (string[3] - '0')) && ((string[3] - '0') <= 8)) {
		return 1;
	} else {
		return 0;
	}
}


int main(int argc, const char * argv[]){
	
	char command[10];
	side = Black; //implicit enginul joaca cu piesele negre
	turn = White; //albul incepe
	initializeBoard();
	setbuf(stdin, NULL);
	setbuf(stdout, NULL);
		
	write(1, "feature sigint=0\n", 17);

    while(1) {
		
		scanf("%s", command);
		
		if(!strcmp(command, "force")) {
			
			int user, turn = side;
			scanf("%s", command);

			//cat timp urmatoarele comenzi nu sunt go, new, quit sau resign
            while ((strcmp(command, "go") != 0) && (strcmp(command, "new") != 0)
				&& (strcmp(command, "quit") != 0) && (strcmp(command, "resign") != 0)
				&& (strcmp(command, "white") != 0) && (strcmp(command, "black") != 0)) {
				
				//verific daca comanda e valida si daca se poate realiza
				if (validMove(command)) {
					if (((char)(board[command[1] - '0' - 1][(char)command[0] - 97]) - 90) < 0) {
						user = White;
					} else {
						user = Black;
					}
					if (user != turn) {
						write(1, "not your turn\n", 14);
					} else {				
						
						makeMove();
						turn = !turn;
					}
                } else {
					write(1, "invalid move\n", 13);
                }
				scanf("%s", command);
			}
		}
		
		if(!strcmp(command, "quit")) {
			break;
		}
		
        if(!strcmp(command, "new")) { 
			side = Black; 
			initializeBoard();
			continue;
		}
	
        if(!strcmp(command, "xboard")) {
			continue;
		}
		
        if(!strcmp(command, "white")) {
			side = White;
			turn = Black;			
		}
		
        if(!strcmp(command, "black")) {
			side = Black;
			turn = White;
		}
        if(!strcmp(command, "resign")) { 
			write(1, "resign\n", 7);
		}
		
		if (!strcmp(command, "go")) { //comanda data in cazul schimbarii culorii
			makeMove();
		}
		if (validMove(command)) { //daca este o comanda valida, aceasta se executa
			
			//Verific en passant.
			en_passant(command); 

			//Punem mutarea pe placa.
			setMove(command);
			
			//Verific rocada.			
			castling(command);

			//Verific pown promotion.
			check_pown();

			//Fac o mutare.
			makeMove();
			
			//Verific pown promotion.
			check_pown();
			
			//Verific daca au fost facute 3 mutari identice.
			if (side)
				memcpy(currentB,command,sizeof(command));
			else 
				memcpy(currentW,command,sizeof(command));			
			if (remiza_3_mutari_identice())
			{
				write(1, "Draw\n", 5);
			}
		}		
		fflush(stdout);
		fflush(stdin);
	}
	return 0;
}
