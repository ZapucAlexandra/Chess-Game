/**Aici sunt definitiile,varibilele si vectorii globali.**/
#define PawnB 'P'
#define PawnW 'p'
#define KnightB 'N'
#define KnightW 'n'
#define BishopB 'B'
#define BishopW 'b'
#define RookB 'R'
#define RookW 'r'
#define QueenB 'Q'
#define QueenW 'q'
#define KingB 'K'
#define KingW 'k'

#define Black 0
#define White 1

#include <climits>
#define oo INT_MAX

//Adancimea arborelui MINIMAX!
#define adancime 3 

int side;
int turn;
int forceMode;
char board[12][12];
int initArrayW[16][4];
int initArrayB[16][4];

struct nod {
	char x,y,X,Y,piesa;
};

//Pentru 3 mutari identice:
char prevW[20], prevB[20],currentW[20],currentB[20];
int mutari_identice=0;

//Hardcodare mutare_noua.
char characterToRet;

//Contor folosit pentru statistici
int taieturi_alpha_beta;
