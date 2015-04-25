/*Functia isCheck testeaza daca regele este in sah.
 Returneaza 1 daca este si 0 daca nu este in sah.*/
#include "goInCheck.h"

int findPiece(int *x, int *y, char piece);

int isCheck(int *coordx, int *coordy) {
	int x, y;
	int c, l;
	
	if (side) {
		findPiece(&x, &y, KingW); 
		
		if (board[x + 1][y - 1] == PawnB) {
			*coordx = x + 1;
			*coordy = y - 1;
			return 1;
		}
		if (board[x + 1][y + 1] == PawnB) {
			*coordx = x + 1;
			*coordy = y + 1;
			return 1;
		}
		if (board[x + 1][y - 2] == KnightB) {
			*coordx = x + 1;
			*coordy = y - 2;
			return 1;
		}
		if (board[x + 1][y + 2] == KnightB) {
			*coordx = x + 1;
			*coordy = y + 2;
			return 1;
		}
		if (board[x + 2][y - 1] == KnightB) {
			*coordx = x + 2;
			*coordy = y - 1;
			return 1;
		}
		if (board[x + 2][y + 1] == KnightB) {
			*coordx = x + 2;
			*coordy = y + 1;
			return 1;
		}
		if (board[x - 1][y - 2] == KnightB) {
			*coordx = x - 1;
			*coordy = y - 2;
			return 1;
		}
		if (board[x - 1][y + 2] == KnightB) {
			*coordx = x - 1;
			*coordy = y + 2;
			return 1;
		}
		if (board[x - 2][y - 1] == KnightB) {
			*coordx = x - 2;
			*coordy = y - 1;
			return 1;
		}
		if (board[x - 2][y + 1] == KnightB) {
			*coordx = x - 2;
			*coordy = y + 1;
			return 1;
		}
		
		l = x - 1;
		c = y - 1;
		while ((l > 1) && (c > 1)) {
			if (board[l][c] != (char)NULL) {
				break;
			}
			l--;
			c--;
		}
		if ((board[l][c] != (char)NULL) && (board[l][c] != '0')) {
			if ((board[l][c] == QueenB) || (board[l][c] == BishopB)) {
				*coordx = l;
				*coordy = c;
				return 1;
			}
		}
		l = x - 1;
		c = y + 1;
		while ((l > 1) && (c < 9)) {
			if (board[l][c] != (char)NULL) {
				break;
			}
			l--;
			c++;
		}
		if ((board[l][c] != (char)NULL) && (board[l][c] != '0')) {
			if ((board[l][c] == QueenB) || (board[l][c] == BishopB)) {
				*coordx = l;
				*coordy = c;
				return 1;
			}
		}
		l = x + 1;
		c = y - 1;
		while ((l < 9) && (c > 1)) {
			if (board[l][c] != (char)NULL) {
				break;
			}
			l++;
			c--;
		}
		if ((board[l][c] != (char)NULL) && (board[l][c] != '0')) {
			if ((board[l][c] == QueenB) || (board[l][c] == BishopB)) {
				*coordx = l;
				*coordy = c;
				return 1;
			}
		}
		l = x + 1;
		c = y + 1;
		while ((l < 9) && (c < 9)) {
			if (board[l][c] != (char)NULL) {
				break;
			}
			l++;
			c++;
		}
		if ((board[l][c] != (char)NULL) && (board[l][c] != '0')) {
			if ((board[l][c] == QueenB) || (board[l][c] == BishopB)) {
				*coordx = l;
				*coordy = c;
				return 1;
			}
		}
		l = x + 1;
		c = y;
		while ((l < 9)) {
			if (board[l][c] != (char)NULL) {
				break;
			}
			l++;
		}
		if ((board[l][c] != (char)NULL) && (board[l][c] != '0')) {
			if ((board[l][c] == QueenB) || (board[l][c] == RookB)) {
				*coordx = l;
				*coordy = c;
				return 1;
			}
		}
		l = x - 1;
		c = y;
		while ((l > 1)) {
			if (board[l][c] != (char)NULL) {
				break;
			}
			l--;
		}
		if ((board[l][c] != (char)NULL) && (board[l][c] != '0')) {
			if ((board[l][c] == QueenB) || (board[l][c] == RookB)) {
				*coordx = l;
				*coordy = c;
				return 1;
			}
		}
		l = x;
		c = y - 1;
		while ((c > 1)) {
			if (board[l][c] != (char)NULL) {
				break;
			}
			c--;
		}
		if ((board[l][c] != (char)NULL) && (board[l][c] != '0')) {
			if ((board[l][c] == QueenB) || (board[l][c] == RookB)) {
				*coordx = l;
				*coordy = c;
				return 1;
			}
		}
		l = x;
		c = y + 1;
		while ((c < 9)) {
			if (board[l][c] != (char)NULL) {
				break;
			}
			c++;
		}
		if ((board[l][c] != (char)NULL) && (board[l][c] != '0')) {
			if ((board[l][c] == QueenB) || (board[l][c] == RookB)) {
				*coordx = l;
				*coordy = c;
				return 1;
			}
		}
	}
	else {
		findPiece(&x, &y, KingB);
		if (board[x - 1][y - 1] == PawnW) {
			*coordx = x - 1;
			*coordy = y - 1;
			return 1;
		}
		if (board[x - 1][y + 1] == PawnW) {
			*coordx = x - 1;
			*coordy = y - 1;
			return 1;
		}
		
		if (board[x + 1][y - 2] == KnightW) {
			*coordx = x + 1;
			*coordy = y - 2;
			return 1;
		}
		if (board[x + 1][y + 2] == KnightW) {
			*coordx = x + 1;
			*coordy = y + 2;
			return 1;
		}
		if (board[x + 2][y - 1] == KnightW) {
			*coordx = x + 2;
			*coordy = y - 1;
			return 1;
		}
		if (board[x + 2][y + 1] == KnightW) {
			*coordx = x + 2;
			*coordy = y + 1;
			return 1;
		}
		if (board[x - 1][y - 2] == KnightW) {
			*coordx = x - 1;
			*coordy = y - 2;
			return 1;
		}
		if (board[x - 1][y + 2] == KnightW) {
			*coordx = x - 1;
			*coordy = y + 2;
			return 1;
		}
		if (board[x - 2][y - 1] == KnightW) {
			*coordx = x - 2;
			*coordy = y - 1;
			return 1;
		}
		if (board[x - 2][y + 1] == KnightW) {
			*coordx = x - 2;
			*coordy = y + 1;
			return 1;
		}
		l = x - 1;
		c = y - 1;
		while ((l > 1) && (c > 1)) {
			if (board[l][c] != (char)NULL) {
				break;
			}
			l--;
			c--;
		}
		if ((board[l][c] != (char)NULL) && (board[l][c] != '0')) {
			if ((board[l][c] == QueenW) || (board[l][c] == BishopW)) {
				*coordx = l;
				*coordy = c;
				return 1;
			}
		}
		l = x - 1;
		c = y + 1;
		while ((l > 1) && (c < 9)) {
			if (board[l][c] != (char)NULL) {
				break;
			}
			l--;
			c++;
		}
		if ((board[l][c] != (char)NULL) && (board[l][c] != '0')) {
			if ((board[l][c] == QueenW) || (board[l][c] == BishopW)) {
				*coordx = l;
				*coordy = c;
				return 1;
			}
		}
		l = x + 1;
		c = y - 1;
		while ((l < 9) && (c > 1)) {
			if (board[l][c] != (char)NULL) {
				break;
			}
			l++;
			c--;
		}
		if ((board[l][c] != (char)NULL) && (board[l][c] != '0')) {
			if ((board[l][c] == QueenW) || (board[l][c] == BishopW)) {
				*coordx = l;
				*coordy = c;
				return 1;
			}
		}
		l = x + 1;
		c = y + 1;
		while ((l < 9) && (c < 9)) {
			if (board[l][c] != (char)NULL) {
				break;
			}
			l++;
			c++;
		}
		if ((board[l][c] != (char)NULL) && (board[l][c] != '0')) {
			if ((board[l][c] == QueenW) || (board[l][c] == BishopW)) {
				*coordx = l;
				*coordy = c;
				return 1;
			}
		}
		l = x + 1;
		c = y;
		while ((l < 9)) {
			if (board[l][c] != (char)NULL) {
				break;
			}
			l++;
		}
		if ((board[l][c] != (char)NULL) && (board[l][c] != '0')) {
			if ((board[l][c] == QueenW) || (board[l][c] == RookW)) {
				*coordx = l;
				*coordy = c;
				return 1;
			}
		}
		l = x - 1;
		c = y;
		while ((l > 1)) {
			if (board[l][c] != (char)NULL) {
				break;
			}
			l--;
		}
		if ((board[l][c] != (char)NULL) && (board[l][c] != '0')) {
			if ((board[l][c] == QueenW) || (board[l][c] == RookW)) {
				*coordx = l;
				*coordy = c;
				return 1;
			}
		}
		l = x;
		c = y - 1;
		while ((c > 1)) {
			if (board[l][c] != (char)NULL) {
				break;
			}
			c--;
		}
		if ((board[l][c] != (char)NULL) && (board[l][c] != '0')) {
			if ((board[l][c] == QueenW) || (board[l][c] == RookW)) {
				*coordx = l;
				*coordy = c;
				return 1;
			}
		}
		l = x;
		c = y + 1;
		while ((c < 9)) {
			if (board[l][c] != (char)NULL) {
				break;
			}
			c++;
		}
		if ((board[l][c] != (char)NULL) && (board[l][c] != '0')) {
			if ((board[l][c] == QueenW) || (board[l][c] == RookW)) {
				*coordx = l;
				*coordy = c;
				return 1;
			}
		}
	}
	return 0;
}
