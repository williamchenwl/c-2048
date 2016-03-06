#include <cstdio>
#include <string>
#include <iostream>
#include "chess.h"
#include <conio.h>
#include <cstdlib>

using namespace std;

ChessTable chess;

int hint(){
    puts("W for Up Move");
    puts("S for Down Move");
    puts("A for Left Move");
    puts("D for Right Move");
    puts("");
}

int Play(){
	chess.init();
	string oper;
	while(1){
        chess.show();
		oper[0] = _getch();
		int status = chess.OperateMove(oper[0]);
		if (status == chess._over){
            chess.show();
			printf("Restart Or Exit('r' for restart and 'e' for exit) : ");
			cin >> oper;
			if (oper[0] == 'r') return 1;
			if (oper[0] == 'e') return 0;
		}
		 system("CLS");
	}
}

int main(){
    hint();
	while (Play());
}

