bool comparePiece(const nod &first, const nod &second) {
	if(second.piesa == (char)NULL) {//daca cea de-a doua piesa nu elimina nici o piesa
			return true;//returneaza prima piesa
	}
	if(first.piesa == (char)NULL) {//daca prima piesa nu elimina o alta piesa o retuneaza pe a doua
		return false;
	}
		
	//daca ambele mutari elimina cate o piesa
		
	//daca ambele mutari elimina acelasi tip de piesa, aleg prima mutare
	if(first.piesa == second.piesa) {
		return true;
	}
		
	//daca una dintre mutari elimina un pion este aleasa cealalta mutare
	if(first.piesa == PawnW ||first.piesa == PawnB) {
		return false;
	}
	if(second.piesa == PawnW || second.piesa == PawnB) {
		return true;
	}
	
	//daca una din mutari elimina o regina, aleg mutarea
	if(first.piesa == QueenW ||first.piesa == QueenB) {
		return true;
	}
	if(second.piesa == QueenW || second.piesa == QueenB) {
		return false;
	}
	
	//raman de verificat posibilitatile: Knight - Bishop, Knight - Rook, Bishop - Rook
	//daca una din mutari elimina o tura, aleg mutarea
	if(first.piesa == RookW ||first.piesa == RookB) {
			return true;
	}
	if(second.piesa == RookW || second.piesa == RookB) {
		return false;
	}
		
	//daca una din mutari elimina un nebun, aleg mutarea
	if(first.piesa == BishopW ||first.piesa == BishopB) {
		return true;
	}
	if(second.piesa == BishopW || second.piesa == BishopB) {
		return false;
	}
	
	//daca una din mutari elimina un cal este aleasa piesa (cazuri pe care nu a trebui sa intre)
	if(first.piesa == KnightW ||first.piesa == KnightB) {
		return true;
	}
	
	if(second.piesa == KnightW || second.piesa == KnightB) {
		return false;
	}
	
	return true;
}


void afisare_lista(list<nod> mylist)
{
	cout<<mylist.size();
	mylist.sort(&comparePiece);
	
	for (list<nod>::iterator it=mylist.begin(); it != mylist.end(); ++it)
		cout <<"PIESA: "<<board[(int)((*it).x)][(int)((*it).y)]<<"\nx= "
			<< (int)(*it).x<<" y= "<<(int)(*it).y<<" X= "<<(int)(*it).X<<" Y= "<<(int)(*it).Y<<" piesa= "<<(*it).piesa<<"\n";
}
/*Functie care genereaza o lista cu toate posibilele mutari pe care
le poate face jucatorul la mutare (side). */
void generate_all(list<nod> *mylist,int side)
{
	int i,n,m,contor;
	//a[16][4] 0->tip, 1->X, 2->Y, 3->exita	

	if (side) //albul la mutare
	{
		for (i = 0; i <= 15; i++)
		{
			if (!initArrayW[i][3])
			{
				n = initArrayW[i][1];
				m = initArrayW[i][2]; 
					
				
				if(initArrayW[i][0] == PawnW) {
				
					//verific pozitia diagonala stanga
					if(pieceColor(board[n+1][m-1]) == 1){
						test_move(initArrayW[i][1],initArrayW[i][2],n+1,m-1,mylist);
					}
					//verific pozitia diagonala dreapta
					if(pieceColor(board[n+1][m+1]) == 1){
						test_move(initArrayW[i][1],initArrayW[i][2],n+1,m+1,mylist);
					}
					//verific pozitia din fata
					if(pieceColor(board[n+1][m]) == 0){
						test_move(initArrayW[i][1],initArrayW[i][2],n+1,m,mylist);
					}
					//daca se afla pe linia initiala, verific daca poate face doua pozitii
					if(n == 3) {
						//daca pe primele doua pozitii din fata este liber, testez mutarea
						if(pieceColor(board[n+1][m]) == 0 && pieceColor(board[n+2][m]) == 0) {
							test_move(n,m,n+2,m,mylist);
						}
					}
				}
				else if(initArrayW[i][0] == QueenW) {
				
				//comportarea ca a unui nebun
					contor = 1;
					//Mergem stanga sus
					while (board[n-contor][m-contor] !=  '0') //nu iese din tabla
					{
						if (pieceColor(board[n-contor][m-contor]) != 2) //nu e piesa de-a noastra
							test_move(initArrayW[i][1],initArrayW[i][2],n-contor,m-contor,mylist);
						if (pieceColor(board[n-contor][m-contor]) != 0) //nu e camp liber, te opresi
							break;
						contor ++;
					}
					
					contor = 1;
					//Mergem dreapta sus
					while (board[n-contor][m+contor] !=  '0') //nu iese din tabla
					{
						if (pieceColor(board[n-contor][m+contor]) != 2) //nu e piesa de-a noastra
							test_move(initArrayW[i][1],initArrayW[i][2],n-contor,m+contor,mylist);
						if (pieceColor(board[n-contor][m+contor]) != 0) //nu e camp liber, te opresi
							break;
						contor ++;
					}
					
					contor = 1;
					//Mergem dreapta jos
					while (board[n+contor][m+contor] !=  '0') //nu iese din tabla
					{
						if (pieceColor(board[n+contor][m+contor]) != 2) //nu e piesa de-a noastra
							test_move(initArrayW[i][1],initArrayW[i][2],n+contor,m+contor,mylist);
						if (pieceColor(board[n+contor][m+contor]) != 0) //nu e camp liber, te opresi
							break;
						contor ++;
					}
					
					contor = 1;
					//Mergem stanga sus
					while (board[n+contor][m-contor] !=  '0') //nu iese din tabla
					{
						if (pieceColor(board[n+contor][m-contor]) != 2) //nu e piesa de-a noastra
							test_move(initArrayW[i][1],initArrayW[i][2],n+contor,m-contor,mylist);
						if (pieceColor(board[n+contor][m-contor]) != 0) //nu e camp liber, te opresi
							break;
						contor ++;
					}
					
				//comportarea ca a unei ture
					int c, l;
					
					c = m;
					l = n - 1;
					while ((l > 1) && (pieceColor(board[l][c]) != 2)) {
						test_move(n, m, l, c, mylist);
						if (pieceColor(board[l][c]) == 1) {
							break;
						}
						l--;
					}
					
					c = m;
					l = n + 1;
					while ((l < 10) && (pieceColor(board[l][c]) != 2)) {
						test_move(n, m, l, c, mylist);
						if (pieceColor(board[l][c]) == 1) {
							break;
						}
						l++;
					}
					
					l = n;
					c = m + 1;
					while ((c < 10) && (pieceColor(board[l][c]) != 2)) {
						test_move(n, m, l, c, mylist);
						if (pieceColor(board[l][c]) == 1) {
							break;
						}
						c++;
					}
					
					l = n;
					c = m - 1;
					while ((c > 1) && (pieceColor(board[l][c]) != 2)) {
						test_move(n, m, l, c, mylist);
						if (pieceColor(board[l][c]) == 1) {
							break;
						}
						c--;
					}
				}
				
				else if (initArrayW[i][0] == KnightW)
				{
					//Verific campul in care ma duc sa fie diferit de piesa mea
					if(pieceColor(board[n-1][m-2]) != 2) {
						test_move(initArrayW[i][1],initArrayW[i][2],n-1,m-2,mylist);
					}
					if(pieceColor(board[n+1][m-2]) != 2) {
						test_move(initArrayW[i][1],initArrayW[i][2],n+1,m-2,mylist);
					}
					if(pieceColor(board[n-2][m-1]) != 2) {
						test_move(initArrayW[i][1],initArrayW[i][2],n-2,m-1,mylist);
					}
					if(pieceColor(board[n+2][m-1]) != 2) {
						test_move(initArrayW[i][1],initArrayW[i][2],n+2,m-1,mylist);
					}
					if(pieceColor(board[n-2][m+1]) != 2) {
						test_move(initArrayW[i][1],initArrayW[i][2],n-2,m+1,mylist);
					}
					if(pieceColor(board[n+2][m+1]) != 2) {
						test_move(initArrayW[i][1],initArrayW[i][2],n+2,m+1,mylist);
					}
					if(pieceColor(board[n-1][m+2]) != 2) {
						test_move(initArrayW[i][1],initArrayW[i][2],n-1,m+2,mylist);
					}
					if(pieceColor(board[n+1][m+2]) != 2) {
						test_move(initArrayW[i][1],initArrayW[i][2],n+1,m+2,mylist);
					}								
				}
				else if (initArrayW[i][0] == BishopW)
				{
					contor = 1;
					//Mergem stanga sus
					while (board[n-contor][m-contor] !=  '0') //nu iese din tabla
					{
						if (pieceColor(board[n-contor][m-contor]) != 2) //nu e piesa de-a noastra
							test_move(initArrayW[i][1],initArrayW[i][2],n-contor,m-contor,mylist);
						if (pieceColor(board[n-contor][m-contor]) != 0) //nu e camp liber, te opresi
							break;
						contor ++;
					}
					
					contor = 1;
					//Mergem dreapta sus
					while (board[n-contor][m+contor] !=  '0') //nu iese din tabla
					{
						if (pieceColor(board[n-contor][m+contor]) != 2) //nu e piesa de-a noastra
							test_move(initArrayW[i][1],initArrayW[i][2],n-contor,m+contor,mylist);
						if (pieceColor(board[n-contor][m+contor]) != 0) //nu e camp liber, te opresi
							break;
						contor ++;
					}
					
					contor = 1;
					//Mergem dreapta jos
					while (board[n+contor][m+contor] !=  '0') //nu iese din tabla
					{
						if (pieceColor(board[n+contor][m+contor]) != 2) //nu e piesa de-a noastra
							test_move(initArrayW[i][1],initArrayW[i][2],n+contor,m+contor,mylist);
						if (pieceColor(board[n+contor][m+contor]) != 0) //nu e camp liber, te opresi
							break;
						contor ++;
					}
					
					contor = 1;
					//Mergem stanga sus
					while (board[n+contor][m-contor] !=  '0') //nu iese din tabla
					{
						if (pieceColor(board[n+contor][m-contor]) != 2) //nu e piesa de-a noastra
							test_move(initArrayW[i][1],initArrayW[i][2],n+contor,m-contor,mylist);
						if (pieceColor(board[n+contor][m-contor]) != 0) //nu e camp liber, te opresi
							break;
						contor ++;
					}
				}
				
				else if (initArrayW[i][0] == KingW) {
					
					if ((n-1 > 1) && (m-1 > 1) && (pieceColor(board[n-1][m-1]) != 2) && KingToKing(n-1,m-1,side)) {
						test_move(n, m, n-1, m-1, mylist);
					}
					if ((n-1 > 1) && (pieceColor(board[n-1][m]) != 2) && KingToKing(n-1,m,side)) {
						test_move(n, m, n-1, m, mylist);
					}
					if ((n-1 > 1) && (m+1 < 10) && (pieceColor(board[n-1][m+1]) != 2) && KingToKing(n-1,m+1,side)) {
						test_move(n, m, n-1, m+1, mylist);
					}
					if ((m-1 > 1) && (pieceColor(board[n][m-1]) != 2) && KingToKing(n,m-1,side)) {
						test_move(n, m, n, m-1, mylist);
					}
					if ((m+1 < 10) && (pieceColor(board[n][m+1]) != 2) && KingToKing(n,m+1,side)) {
						test_move(n, m, n, m+1, mylist);
					}
					if ((n+1 < 10) && (m-1 > 1) && (pieceColor(board[n+1][m-1]) != 2) && KingToKing(n+1,m-1,side)) {
						test_move(n, m, n+1, m-1, mylist);
					}
					if ((n+1 < 10) && (pieceColor(board[n+1][m]) != 2) && KingToKing(n+1,m,side)) {
						test_move(n, m, n+1, m, mylist);
					}
					if ((n+1 < 10) && (m+1 < 10) && (pieceColor(board[n+1][m+1]) != 2) && KingToKing(n+1,m+1,side)) {
						test_move(n, m, n+1, m+1, mylist);
					}
				}
				
				else if (initArrayW[i][0] == RookW) {
					int c, l;
					
					c = m;
					l = n - 1;
					while ((l > 1) && (pieceColor(board[l][c]) != 2)) {
						test_move(n, m, l, c, mylist);
						if (pieceColor(board[l][c]) == 1) {
							break;
						}
						l--;
					}
					
					c = m;
					l = n + 1;
					while ((l < 10) && (pieceColor(board[l][c]) != 2)) {
						test_move(n, m, l, c, mylist);
						if (pieceColor(board[l][c]) == 1) {
							break;
						}
						l++;
					}
					
					l = n;
					c = m + 1;
					while ((c < 10) && (pieceColor(board[l][c]) != 2)) {
						test_move(n, m, l, c, mylist);
						if (pieceColor(board[l][c]) == 1) {
							break;
						}
						c++;
					}
					
					l = n;
					c = m - 1;
					while ((c > 1) && (pieceColor(board[l][c]) != 2)) {
						test_move(n, m, l, c, mylist);
						if (pieceColor(board[l][c]) == 1) {
							break;
						}
						c--;
					}
				}
				
				
			}
		
		}
	}
	else //negrul la mutare
	{
		for (i = 0; i <= 15; i++) {
			if (!initArrayB[i][3])
			{
				n = initArrayB[i][1];
				m = initArrayB[i][2];
					
				
				if(initArrayB[i][0] == PawnB) {
					
				//verific pozitia diagonala stanga
				if(pieceColor(board[n-1][m-1]) == 2){
					test_move(initArrayB[i][1],initArrayB[i][2],n-1,m-1,mylist);
				}
				//verific pozitia diagonala dreapta
				if(pieceColor(board[n-1][m+1]) == 2){
					test_move(initArrayB[i][1],initArrayB[i][2],n-1,m+1,mylist);
				}
				//verific pozitia din fata
				if(pieceColor(board[n-1][m]) == 0){
					test_move(initArrayB[i][1],initArrayB[i][2],n-1,m,mylist);
				}
				//daca se afla pe linia initiala, verific daca poate face doua pozitii
				if(n == 8) {
					//daca pe primele doua pozitii din fata este liber, testez mutarea
					if(pieceColor(board[n-1][m]) == 0 && pieceColor(board[n-2][m]) == 0) {
						test_move(n,m,n-2,m,mylist);
					}
				}
			}
				else if(initArrayB[i][0] == QueenB) {
				
				//comportarea ca a unui nebun
					contor = 1;
					//Mergem stanga sus
					while (board[n-contor][m-contor] !=  '0') //nu iese din tabla
					{
						if (pieceColor(board[n-contor][m-contor]) != 1) //nu e piesa de-a noastra
							test_move(initArrayB[i][1],initArrayB[i][2],n-contor,m-contor,mylist);
						if (pieceColor(board[n-contor][m-contor]) != 0) //nu e camp liber, te opresi
							break;
						contor ++;
					}
					
					contor = 1;
					//Mergem dreapta sus
					while (board[n-contor][m+contor] !=  '0') //nu iese din tabla
					{
						if (pieceColor(board[n-contor][m+contor]) != 1) //nu e piesa de-a noastra
							test_move(initArrayB[i][1],initArrayB[i][2],n-contor,m+contor,mylist);
						if (pieceColor(board[n-contor][m+contor]) != 0) //nu e camp liber, te opresi
							break;
						contor ++;
					}
					
					contor = 1;
					//Mergem dreapta jos
					while (board[n+contor][m+contor] !=  '0') //nu iese din tabla
					{
						if (pieceColor(board[n+contor][m+contor]) != 1) //nu e piesa de-a noastra
							test_move(initArrayB[i][1],initArrayB[i][2],n+contor,m+contor,mylist);
						if (pieceColor(board[n+contor][m+contor]) != 0) //nu e camp liber, te opresi
							break;
						contor ++;
					}
					
					contor = 1;
					//Mergem stanga sus
					while (board[n+contor][m-contor] !=  '0') //nu iese din tabla
					{
						if (pieceColor(board[n+contor][m-contor]) != 1) //nu e piesa de-a noastra
							test_move(initArrayB[i][1],initArrayB[i][2],n+contor,m-contor,mylist);
						if (pieceColor(board[n+contor][m-contor]) != 0) //nu e camp liber, te opresi
							break;
						contor ++;
					}
					
				//comportarea ca a unei ture
					int c, l;
					
					c = m;
					l = n - 1;
					while ((l > 1) && (pieceColor(board[l][c]) != 1)) {
						test_move(n, m, l, c, mylist);
						if (pieceColor(board[l][c]) == 2) {
							break;
						}
						l--;
					}
					
					c = m;
					l = n + 1;
					while ((l < 10) && (pieceColor(board[l][c]) != 1)) {
						test_move(n, m, l, c, mylist);
						if (pieceColor(board[l][c]) == 2) {
							break;
						}
						l++;
					}
					
					l = n;
					c = m + 1;
					while ((c < 10) && (pieceColor(board[l][c]) != 1)) {
						test_move(n, m, l, c, mylist);
						if (pieceColor(board[l][c]) == 2) {
							break;
						}
						c++;
					}
					
					l = n;
					c = m - 1;
					while ((c > 1) && (pieceColor(board[l][c]) != 1)) {
						test_move(n, m, l, c, mylist);
						if (pieceColor(board[l][c]) == 2) {
							break;
						}
						c--;
					}
				}
				
				else if (initArrayB[i][0] == KnightB)
				{
					//Verific campul in care ma duc sa fie diferit de piesa mea
					if(pieceColor(board[n-1][m-2]) != 1) {
						test_move(initArrayB[i][1],initArrayB[i][2],n-1,m-2,mylist);
					}
					if(pieceColor(board[n+1][m-2]) != 1) {
						test_move(initArrayB[i][1],initArrayB[i][2],n+1,m-2,mylist);
					}
					if(pieceColor(board[n-2][m-1]) != 1) {
						test_move(initArrayB[i][1],initArrayB[i][2],n-2,m-1,mylist);
					}
					if(pieceColor(board[n+2][m-1]) != 1) {
						test_move(initArrayB[i][1],initArrayB[i][2],n+2,m-1,mylist);
					}
					if(pieceColor(board[n-2][m+1]) != 1) {
						test_move(initArrayB[i][1],initArrayB[i][2],n-2,m+1,mylist);
					}
					if(pieceColor(board[n+2][m+1]) != 1) {
						test_move(initArrayB[i][1],initArrayB[i][2],n+2,m+1,mylist);
					}
					if(pieceColor(board[n-1][m+2]) != 1) {
						test_move(initArrayB[i][1],initArrayB[i][2],n-1,m+2,mylist);
					}
					if(pieceColor(board[n+1][m+2]) != 1) {
						test_move(initArrayB[i][1],initArrayB[i][2],n+1,m+2,mylist);
					}								
				}
				else if (initArrayB[i][0] == BishopB)
				{
					contor = 1;
					//Mergem stanga sus
					while (board[n-contor][m-contor] !=  '0') //nu iese din tabla
					{
						if (pieceColor(board[n-contor][m-contor]) != 1) //nu e piesa de-a noastra
							test_move(initArrayB[i][1],initArrayB[i][2],n-contor,m-contor,mylist);
						if (pieceColor(board[n-contor][m-contor]) != 0) //nu e camp liber, te opresi
							break;
						contor ++;
					}
					
					contor = 1;
					//Mergem dreapta sus
					while (board[n-contor][m+contor] !=  '0') //nu iese din tabla
					{
						if (pieceColor(board[n-contor][m+contor]) != 1) //nu e piesa de-a noastra
							test_move(initArrayB[i][1],initArrayB[i][2],n-contor,m+contor,mylist);
						if (pieceColor(board[n-contor][m+contor]) != 0) //nu e camp liber, te opresi
							break;
						contor ++;
					}
					
					contor = 1;
					//Mergem dreapta jos
					while (board[n+contor][m+contor] !=  '0') //nu iese din tabla
					{
						if (pieceColor(board[n+contor][m+contor]) != 1) //nu e piesa de-a noastra
							test_move(initArrayB[i][1],initArrayB[i][2],n+contor,m+contor,mylist);
						if (pieceColor(board[n+contor][m+contor]) != 0) //nu e camp liber, te opresi
							break;
						contor ++;
					}
					
					contor = 1;
					//Mergem stanga sus
					while (board[n+contor][m-contor] !=  '0') //nu iese din tabla
					{
						if (pieceColor(board[n+contor][m-contor]) != 1) //nu e piesa de-a noastra
							test_move(initArrayB[i][1],initArrayB[i][2],n+contor,m-contor,mylist);
						if (pieceColor(board[n+contor][m-contor]) != 0) //nu e camp liber, te opresi
							break;
						contor ++;
					}
				}
				
				else if (initArrayB[i][0] == KingB) {
					
					if ((n-1 > 1) && (m-1 > 1) && (pieceColor(board[n-1][m-1]) != 1) && KingToKing(n-1,m-1,side)) {
						test_move(n, m, n-1, m-1, mylist);
					}
					if ((n-1 > 1) && (pieceColor(board[n-1][m]) != 1) && KingToKing(n-1,m,side)) {
						test_move(n, m, n-1, m, mylist);
					}
					if ((n-1 > 1) && (m+1 < 10) && (pieceColor(board[n-1][m+1]) != 1) && KingToKing(n-1,m+1,side)) {
						test_move(n, m, n-1, m+1, mylist);
					}
					if ((m-1 > 1) && (pieceColor(board[n][m-1]) != 1) && KingToKing(n,m-1,side)) {
						test_move(n, m, n, m-1, mylist);
					}
					if ((m+1 < 10) && (pieceColor(board[n][m+1]) != 1) && KingToKing(n,m+1,side)) {
						test_move(n, m, n, m+1, mylist);
					}
					if ((n+1 < 10) && (m-1 > 1) && (pieceColor(board[n+1][m-1]) != 1) && KingToKing(n+1,m-1,side)) {
						test_move(n, m, n+1, m-1, mylist);
					}
					if ((n+1 < 10) && (pieceColor(board[n+1][m]) != 1) && KingToKing(n+1,m,side)) {
						test_move(n, m, n+1, m, mylist);
					}
					if ((n+1 < 10) && (m+1 < 10) && (pieceColor(board[n+1][m+1]) != 1) && KingToKing(n+1,m+1,side)) {
						test_move(n, m, n+1, m+1, mylist);
					}
				}
				
				else if (initArrayB[i][0] == RookB) {
					int c, l;
					
					c = m;
					l = n - 1;
					while ((l > 1) && (pieceColor(board[l][c]) != 1)) {
						test_move(n, m, l, c, mylist);
						if (pieceColor(board[l][c]) == 2) {
							break;
						}
						l--;
					}
					
					c = m;
					l = n + 1;
					while ((l < 10) && (pieceColor(board[l][c]) != 1)) {
						test_move(n, m, l, c, mylist);
						if (pieceColor(board[l][c]) == 2) {
							break;
						}
						l++;
					}
					
					l = n;
					c = m + 1;
					while ((c < 10) && (pieceColor(board[l][c]) != 1)) {
						test_move(n, m, l, c, mylist);
						if (pieceColor(board[l][c]) == 2) {
							break;
						}
						c++;
					}
					
					l = n;
					c = m - 1;
					while ((c > 1) && (pieceColor(board[l][c]) != 1)) {
						test_move(n, m, l, c, mylist);
						if (pieceColor(board[l][c]) == 2) {
							break;
						}
						c--;
					}
				}
				
				
			}			
		}
	}
}

