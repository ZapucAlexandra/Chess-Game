/*Verific daca vreun pion a ajuns pe prima/ultima linie si il transform in regina.
Imi actualizez vectorii de piese pentru a stii ce piese exista pe tabla.*/
void check_pown()
{
	int i, j;
	for (i = 2; i <= 9; i++)
	{
		if (board[2][i] == PawnB) {
			board[2][i] = QueenB;
			for (j = 0; j < 16; j++) {
				if ((initArrayB[j][1] == 2) && (initArrayB[j][2] == i)) {
					initArrayB[j][0] = 'Q';
				}
			}
		}
		if (board[9][i] == PawnW) {
			board[9][i] = QueenW;
			for (j = 0; j < 16; j++) {
				if ((initArrayW[j][1] == 9) && (initArrayW[j][2] == i)) {
					initArrayW[j][0] = 'q';
				}
			}
		}
	}
}
