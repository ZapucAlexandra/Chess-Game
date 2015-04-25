//Functiile maxi si mini impelmenteaza Algoritmul MINIMAX
//optimizat cu taieri Alpha-Beta.

int mini(int nivel, struct nod *move, int apha);
void afisare_lista(list<nod> mylist);
bool comparePiece(const nod &first, const nod &second);

/*Maxi primeste o adancime pana la care sa mearga,
returneaza un cost, si un nod cu prima mutare pe care 
trebuie s-o faca engine-ul pentru a obtine cea mai 
buna mutare calculata de el. Beta este folosita pentru
taieri Alpha-Beta. Daca gasim un cost mai mare la parinte
decat are beta, ne oprim.*/
int maxi(int nivel, struct nod *move,int beta)
{
	char *mutare = strdup("aaaa"), ret;
	nod maxN,aux, thismove;
	int maxC = -oo;
	int score;
		
	if (nivel == 0)
	{
		return evaluate();
	}
	list<nod> l;
	generate_all(&l,side);
	//l.sort(&comparePiece);
	while (!l.empty())
	{
		thismove = l.front();
		l.pop_front();
		
		//punem mutarea pe tabla
		mutare = createMove((int)thismove.x,(int)thismove.y,(int)thismove.X,(int)thismove.Y);
		ret = setMove(mutare);
		free(mutare);
		score = mini(nivel-1, &aux, maxC);

		//luam mutarea inapoi
		takeBackMove((int)thismove.x,(int)thismove.y,(int)thismove.X,(int)thismove.Y, ret);

		if (maxC < score)
		{
			maxC = score;
			maxN  = thismove;		
		}
		
		if (maxC > beta)
		{
			break;
		}
	}	
	
	*move  = maxN;
	return maxC;
}

/*mini primeste o adancime pana la care sa mearga,
returneaza un cost, si un nod cu prima mutare pe care 
trebuie s-o faca engine-ul pentru a obtine cea mai 
buna mutare calculata de el. Alpha este folosita pentru
taieri Alpha-Beta. Daca gasim un cost mai mic la parinte
decat are alpha, ne oprim.*/
int mini(int nivel, struct nod *move, int alpha)
{
	char *mutare = strdup("aaaa"), ret;
	nod minN,aux, thismove;
	int minC = oo;
	int score;
	
	if (nivel == 0)
	{
		return evaluate();
	}
	list<nod> l;
	generate_all(&l,(side+1)%2);
	//l.sort(&comparePiece);
	while (!l.empty())
	{
		thismove = l.front();
		
		//punem mutarea pe tabla
		mutare = createMove((int)thismove.x,(int)thismove.y,(int)thismove.X,(int)thismove.Y);
		ret = setMove(mutare);
		free(mutare);
		//afisareTabla();
		score = maxi(nivel-1, &aux, minC);
		//luam mutarea inapoi
		takeBackMove((int)thismove.x,(int)thismove.y,(int)thismove.X,(int)thismove.Y, ret);
		//afisareTabla();
		if (minC > score)
		{
			minC = score;
			minN  = thismove;		
		}
		
		if (minC < alpha)
		{
			break;
		}
		l.pop_front();
		
	}	
	
	*move  = minN;
	return minC;
}
