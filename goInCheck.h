
char setMove(char* string);
char *createMove(int x1, int y1, int x2, int y2);
void takeBackMove(int x1, int y1, int x2, int y2, char piece);
int isCheck(int *coordx, int *coordy);
void afisareTabla();


/*Verific daca pot sa mut regele in pozitia n,m
fara ca sa se apropie mai mult de o casuta de un celalalt rege
returneaza 1 daca mutarea se poate realiza
altfel returneaza 0.*/
int KingToKing(int n, int m, int side) {
	
	if (side)
	{
		if(board[n][m-1] == KingB)
			return 0;
		else if(board[n][m+1] == KingB)
			return 0;
		
		else if(board[n-1][m-1] == KingB)
			return 0;
		else if(board[n-1][m] == KingB)
			return 0;
		else if(board[n-1][m+1] == KingB)
			return 0;
		
		else if(board[n+1][m-1] == KingB)
			return 0;
		else if(board[n+1][m] == KingB)
			return 0;
		else if(board[n+1][m+1] == KingB)
			return 0;
	
	}
	else
	{
		if(board[n][m-1] == KingW)
			return 0;
		else if(board[n][m+1] == KingW)
			return 0;
		
		else if(board[n-1][m-1] == KingW)
			return 0;
		else if(board[n-1][m] == KingW)
			return 0;
		else if(board[n-1][m+1] == KingW)
			return 0;
		
		else if(board[n+1][m-1] == KingW)
			return 0;
		else if(board[n+1][m] == KingW)
			return 0;
		else if(board[n+1][m+1] == KingW)
			return 0;
	}
	
		
	return 1;
}

/*Functia goInCheck returneaza 1 daca mutarea nu ma baga in sah,
altfel, returneaza 0 */
int goInCheck(int n1, int m1, int n2, int m2) {

	char ret = setMove(createMove(n1, m1, n2, m2));
	int n3, m3;
	if(isCheck(&n3, &m3)) {
		takeBackMove(n1, m1, n2, m2, ret);
		return 0;
	}
	return 1;
}
