
/*Testeaza daca un rege se apropie mai mult de o patratica de alt rege.*/
int KingToKing(int n, int m);

/*Verific daca o piesa este alba sau neagra:
2 pentru alba si 1 pentru neagra si 0 daca nu este o piesa*/
int pieceColor(char piece) {
	if(piece == PawnB)
		return 1;
	else
	if(piece== KnightB)
		return 1;
	else
	if(piece == BishopB)
		return 1;
	else
	if(piece == RookB)
		return 1;
	else
	if(piece == QueenB)
		return 1;
	else
	if(piece == KingB)
		return 1;
	else
	if(piece == PawnW)
		return 2;
	else
	if(piece == KnightW)
		return 2;
	else
	if(piece == BishopW)
		return 2;
	else
	if(piece == RookW)
		return 2;
	else
	if(piece == QueenW)
		return 2;
	else
	if(piece == KingW)
		return 2;
	return 0;	
}
