#include <list>

char* getMove(int n, int m, char* move); 
int findPawn(int side);
char* pawnNextMove(int line);
char* checkEscape(int ax, int ay, int x, int y);
void afisareTabla();
int maxi(int nivel, struct nod *move, int beta);

/*Cauta piesa piece pe tabla de sah. Returneaza 1 si coordonatele 
acesteaia daca exista si 0 altfel.*/
int findPiece(int *x, int *y, char piece) {
	int i ,j;
	
	for (i = 2; i < 10; i++) {
		for (j = 2; j < 10; j++) {
			if (board[i][j] == piece) {
				*x = i;
				*y = j;
				return 1;
			}
		}
	}
	return 0;
}	

/*Creeaza o mutare de tipul "move xYxY" cu ajutorul coordonatelor x1,x2,y1,y2*/ 
char *createMove(int x1, int y1, int x2, int y2) {
	char *move = strdup("aaaa");
	
	move[0] = y1 + 95;
	move[1] = x1 - 1 + '0';
	move[2] = y2 + 95;
	move[3] = x2 - 1 + '0';
	return move;
}


/*Functia setMove executa mutarea si actualizeaza vectorii de piese.*/
char setMove(char* string) {
	char character, characterToReturn;
	int i;
	
	characterToReturn = board[string[3] + 1 - '0'][(char)string[2] - 95];
	characterToRet = characterToReturn;
	if (characterToReturn != (char)NULL) {
		for (i = 0; i < 16; i++) {
			if ((characterToReturn - 97 < 0)) {
				if(	(initArrayB[i][1] == (string[3] + 1 - '0')) &&
					(initArrayB[i][2] == ((char)string[2] - 95))) {
						initArrayB[i][1] = 0; //stergem pozitia
						initArrayB[i][2] = 0; //stergem pozitia	
						initArrayB[i][3] = 1;
						break;
					}
			}
			else if ((initArrayW[i][1] == (string[3] + 1 - '0')) && (initArrayW[i][2] == ((char)string[2] - 95))) {
				initArrayW[i][1] = 0; //stergem pozitia
				initArrayW[i][2] = 0; //stergem pozitia
				initArrayW[i][3] = 1;
				
				break;
			}
		}
	}
	character = board[string[1] + 1 - '0'][(char)string[0] - 95];
	for (i = 0; i < 16; i++) {
		if (character - 97 < 0) {
			if ((initArrayB[i][1] == (string[1] + 1 - '0')) && (initArrayB[i][2] == ((char)string[0] - 95))) {
			initArrayB[i][1] = string[3] + 1 - '0';
			initArrayB[i][2] = (char)string[2] - 95;
			break;
			}
		}
		else if ((initArrayW[i][1] == (string[1] + 1 - '0')) && (initArrayW[i][2] == ((char)string[0] - 95))) {
			initArrayW[i][1] = string[3] + 1 - '0';
			initArrayW[i][2] = (char)string[2] - 95;
			break;
		}
	}

	board[string[3] + 1 - '0'][(char)string[2] - 95] = board[string[1] + 1 - '0'][(char)string[0] - 95];
	board[string[1] + 1 - '0'][(char)string[0] - 95] = (char)NULL;
	
	return characterToReturn;
}

/*Functia nextMove cauta cea mai buna mutare pentru engine, apeland
functia maxi (MINIMAX). Aceasta returneaza un cost si un nod in care
avem cea mai buna mutare. Daca maxi returneaza -infinit inseamna ca 
nu s-a gasit nicio mutare de efectuat, deci vom da resign in MakeMove.*/
char *nextMove() {
	char *move = strdup("aaaa");
	int cost;
	
	nod N;
	cost = maxi(adancime,&N, oo);
	
	if (cost == -oo)
		return NULL;
	
	move = createMove((int)N.x,(int)N.y,(int)N.X,(int)N.Y);
	setMove(move);
	return move;
}

/*Functia makeMove face o mutare.
Apeleaza nextMove pentru a genera cea mai buna mutare.*/
void makeMove() {
	char *str;
	char move[20];	
	
	if ((str = nextMove()) != NULL) {
		strcpy(move, "move ");
		strcat(move, str);
		free(str);
		strcat(move, "\n");
		write(1, move, 10);
		fflush(stdout);
	} else {
		write(1, "resign\n", 7);
		fflush(stdout);
	}
	
}

/*Functia takeBackMove da inapoi o mutare. 
Aceasta primeste coordonatele mutarii precedente
si piesa care se afla in locul destinatiei si NULL daca era liber.*/
void takeBackMove(int x1, int y1, int x2, int y2, char piece) {
	int i;
	char *move = createMove(x2, y2, x1, y1);
	
	setMove(move);
	board[x2][y2] = piece;
	
	if (piece != (char)NULL) 
		for (i = 0; i < 16; i++) 
			if (((char)initArrayB[i][1] == 0) && ((char)initArrayB[i][2] == 0) && ((char)initArrayB[i][0] == piece)) {
				initArrayB[i][1] = x2;
				initArrayB[i][2] = y2;
				initArrayB[i][3] = 0;
				break;
			}
			else if (((char)initArrayW[i][1] == 0) && ((char)initArrayW[i][2] == 0) && ((char)initArrayW[i][0] == piece)) {
				initArrayW[i][1] = x2;
				initArrayW[i][2] = y2;
				initArrayW[i][3] = 0;
				break;
			}
}

void test_move(int n1, int m1, int n2, int m2, list<nod> *mylist)
{
	//facem mutarea pe tabla pentru a verifica isCheck
	char ret = setMove(createMove(n1, m1, n2, m2)); 
	int n3, m3;
	if(!isCheck(&n3, &m3)) {
		
		nod node;
		node.x = (char)n1;
		node.y = (char)m1;
		node.X = (char)n2;
		node.Y = (char)m2;
		node.piesa = ret;
		
		if ( ret != '0' ) //verifica faptul ca nu iese din tabla
		{
			if (ret != (char)NULL) { //luam o piesa cu mutarea noastra
				(*mylist).push_front(node);
			} else {
				(*mylist).push_back(node);
			}
		}
	}
	takeBackMove(n1, m1, n2, m2, ret);
}
