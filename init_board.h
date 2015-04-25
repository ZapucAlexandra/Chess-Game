/*hardcodat il setam pe 1 cand vrem sa citim dintr-un fisier o pozitie a tablei de sah.
S-a dovedit a fi utila pentru depanarea programului.*/
int hardcodat = 0;

/*Functie care citeste o tabla de sah din fisierul de intrare "hardcodat.txt".*/
void read_from_file()
{
	FILE *f=fopen("hardcodat.txt","r");
	int i,j, k1 = 0, k2 = 0;
	char x;
	
	for (i = 2; i < 10; i++) {
       for (j = 2; j < 10; j++) {
			board[i][j] = (char)NULL;
        } 
	}
	
	for (i = 2; i<10; i++)
	{
		for (j = 2; j<10; j++)
		{
			fscanf(f,"%c",&x);
			if (x != '0') {
				board[i][j] = x;
			if (board[i][j] - 90 > 0)
			{
				initArrayW[k1][0] = x;
				initArrayW[k1][1] = i;
				initArrayW[k1++][2] = j;
			}
			else
			{
				initArrayB[k2][0] = x;
				initArrayB[k2][1] = i;
				initArrayB[k2++][2] = j;
			}
			}
		}
		fscanf(f,"\n");
	}
	fclose(f);
}

//Initializarea tablei de sah.
void initializeBoard() {
	int i, j, k1 = 0, k2 = 0;
	
	
	for (i = 0; i < 12; i++) {
		for (j = 0; j < 12; j++) {
			board[i][j] = '0';	
		}
	}
	
	for (i = 4; i < 8; i++) {
       for (j = 2; j < 10; j++) {
			board[i][j] = (char)NULL;
        } 
	}
	
	//DE STERS LA FINAL
	if (hardcodat == 1)
	{
		read_from_file();
		
		return;
	}
	
	for (i = 2; i < 10; i++) {
      board[3][i] = PawnW;
	  initArrayW[k1][0] = PawnW;
	  initArrayW[k1][1] = 3;
	  initArrayW[k1++][2] = i;
      board[8][i] = PawnB;
	  initArrayB[k2][0] = PawnB;
	  initArrayB[k2][1] = 8;
	  initArrayB[k2++][2] = i;
	}
	
	board[2][2] = board[2][9] = RookW;
	initArrayW[k1][0] = RookW;
	initArrayW[k1][1] = 2;
	initArrayW[k1++][2] = 2;
	initArrayW[k1][0] = RookW;
	initArrayW[k1][1] = 2;
	initArrayW[k1++][2] = 9;
	board[9][2] = board[9][9] = RookB;
	initArrayB[k2][0] = RookB;
	initArrayB[k2][1] = 9;
	initArrayB[k2++][2] = 2;
	initArrayB[k2][0] = RookB;
	initArrayB[k2][1] = 9;
	initArrayB[k2++][2] = 9;
	
	board[2][3] = board[2][8] = KnightW;
	initArrayW[k1][0] = KnightW;
	initArrayW[k1][1] = 2;
	initArrayW[k1++][2] = 3;
	initArrayW[k1][0] = KnightW;
	initArrayW[k1][1] = 2;
	initArrayW[k1++][2] = 8;
    board[9][3] = board[9][8] = KnightB;
	initArrayB[k2][0] = KnightB;
	initArrayB[k2][1] = 9;
	initArrayB[k2++][2] = 3;
	initArrayB[k2][0] = KnightB;
	initArrayB[k2][1] = 9;
	initArrayB[k2++][2] = 8;
	
	board[2][4] = board[2][7] = BishopW;
	initArrayW[k1][0] = BishopW;
	initArrayW[k1][1] = 2;
	initArrayW[k1++][2] = 4;
	initArrayW[k1][0] = BishopW;
	initArrayW[k1][1] = 2;
	initArrayW[k1++][2] = 7;
	board[9][4] = board[9][7] = BishopB;
	initArrayB[k2][0] = BishopB;
	initArrayB[k2][1] = 9;
	initArrayB[k2++][2] = 4;
	initArrayB[k2][0] = BishopB;
	initArrayB[k2][1] = 9;
	initArrayB[k2++][2] = 7;

	board[2][5] = QueenW;
	initArrayW[k1][0] = QueenW;
	initArrayW[k1][1] = 2;
	initArrayW[k1++][2] = 5;
	board[9][5] = QueenB;
	initArrayB[k2][0] = QueenB;
	initArrayB[k2][1] = 9;
	initArrayB[k2++][2] = 5;

	board[2][6] = KingW;
	initArrayW[k1][0] = KingW;
	initArrayW[k1][1] = 2;
	initArrayW[k1++][2] = 6;
	board[9][6] = KingB;
	initArrayB[k2][0] = KingB;
	initArrayB[k2][1] = 9;
	initArrayB[k2++][2] = 6;
	
	//Setam vectorii de piese pe 0 pentru a stii ca exista pe placa.
	for (i = 0 ; i < 16; i++) {
		initArrayB[i][3] = 0;
		initArrayW[i][3] = 0;
	}	
	side = Black;
}

