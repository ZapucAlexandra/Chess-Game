/*Testez daca mutarea primita este o rocada si actualizez tabla,
 mutand tura la pozitia corespunzatoare.*/
void castling(char *command) {
	if (!strcmp(command, "e1g1")) {
		setMove(createMove(2, 9, 2, 7));
	}
	if (!strcmp(command, "e1c1")) {
		setMove(createMove(2, 2, 2, 5));
	}
	if (!strcmp(command, "e8g8")) {
		setMove(createMove(9, 9, 9, 7));
	}
	if (!strcmp(command, "e8c8")) {
		setMove(createMove(9, 2, 9, 5));
	}
}
