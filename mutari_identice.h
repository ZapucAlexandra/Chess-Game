/*Functia isReverse Inverseaza un string.*/
int isReverse(char a[20], char b[20])
{
	char aux;
	
	if (strlen(a) > 0)
	{
		aux = a[0];
		a[0] = a[2];
		a[2] = aux;
		
		aux = a[1];
		a[1] = a[3];
		a[3] = aux;
		
		if (!strcmp(a,b))
			return 1;
		}
	
	return 0;
}

/*Functia returneaza 1 pentru remiza in caz de 3 mutari identice*/
int remiza_3_mutari_identice()
{
	
	if (isReverse(prevW, currentW) && isReverse(prevB, currentB) )
	{
		mutari_identice++;
		
		if (mutari_identice==3)
		{
			return 1;
		}
	}
	else
	{
		mutari_identice = 0;
	}
	memcpy(prevW,currentW,strlen(currentW));
	memcpy(prevB,currentB,strlen(currentW));
		
	return 0;
}
