CC = g++
CFLAGS = -Wall
SRC = chess.cpp
EXE = chess

build: define.h init_board.h goInCheck.h getMove.h isCheck.h moves.h checkPown.h en_passant.h mutari_identice.h castling.h generate_all.h evaluate.h minimax.h chess.cpp
	$(CC) -o $(EXE) $(SRC) $(CFLAGS)

.PHONY : clean
clean :
	rm -f $(EXE) *~
