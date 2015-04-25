/*Testez daca exista situatie de en passant si sterg pionul care trebuie.*/

void en_passant(char command[10])
{
	if (side)
	{
		if ( board[command[1] + 1 - '0'][(char)command[0] - 95] == PawnB )
		{
			if (board[command[3] + 1 - '0'][(char)command[2] - 95] == (char)NULL)
			{
				if ((char)command[0] - 95 != (char)command[2] - 95)
				{
					//caz de en passant => sterg pionul meu alb
					board[command[3] + 1 - '0' + 1][(char)command[2] - 95] =  (char)NULL;
					
					int i = 0;
					for (i  = 0; i < 16; i++) {
						if ((initArrayW[i][1] == (command[3] + 1 - '0' - 1)) && (initArrayW[i][2] == ((char)command[2] - 95))) {
							initArrayW[i][1] = 0;
							initArrayW[i][2] = 0;
							initArrayW[i][3] = 1;
							break;
						}
					}
				}
			}
		}
	}
	else
	{
		if ( board[command[1] + 1 - '0'][(char)command[0] - 95] == PawnW ) 
		{
			if (board[command[3] + 1 - '0'][(char)command[2] - 95] == (char)NULL)
			{
				if ((char)command[0] - 95 != (char)command[2] - 95)
				{
					//caz de en passant => sterg pionul
					board[command[3] + 1 - '0' - 1][(char)command[2] - 95] =  (char)NULL;
					
					int i = 0;
					for (i  = 0; i < 16; i++) {
						if ((initArrayB[i][1] == (command[3] + 1 - '0' - 1)) && (initArrayB[i][2] == ((char)command[2] - 95))) {
							initArrayB[i][1] = 0;
							initArrayB[i][2] = 0;
							initArrayB[i][3] = 1;
							break;
						}
					}
				}
			}
		}	
	}
}
