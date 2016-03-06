#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <iostream>

class ChessTable{

	const int up = -4;
	const int down = 4;
	const int left = -1;
	const int right = 1;


	int moved,a[16];

	int imerge(int posa,int posb){
		a[posb]++; a[posa] = 0;
		moved++;
		return 1;
	}

	int zeromerge(int posa,int posb){
		a[posb] = a[posa];
		a[posa] = 0;
		moved++;
		return -1;
	}

	int merge(int posa,int posb){
		int wstatus = 0;
		if (posa == posb) return wstatus;
		if (!a[posa]) return wstatus;
		if (a[posa] == a[posb]) return imerge(posa,posb);
		if (a[posb] == 0) return zeromerge(posa,posb);
	}

	int isEdge(int x,int dir){
		if (dir == up && x >= 1 && x <= 4) return 1;
		if (dir == down && x >= 13 && x<= 16) return 1;
		if (dir == left && x % 4 == 1) return 1;
		if (dir == right && x % 4 == 0) return 1;
		return 0;
	}

 	int movetile(int dir,int x){
 		int y = x;
 		while(!isEdge(x,dir)){
 			y = x + dir;
 			if (~merge(x,y)) x = y;
 			else break;
 		}
 	}

 	int MoveUp(){
 		for (int i = 1;i <= 16;i++)
 			movetile(up,i);
 	}

 	int MoveDown(){
 		for (int i = 16;i >= 1;i++)
 			movetile(down,i);
 	}

 	int MoveLeft(){
 		for (int i = 1;i <= 16;i++)
 			movetile(left,i);
 	}

 	int MoveRight(){
 		for (int i = 16;i >= 1;i--)
 			movetile(right,i);
 	}

 	const int _normstat = 1;

 	const int _unmoved = 0;

 	const int _over = -1;

 	int checkit(){
 		int cnt = 0;
 		if (moved) return _normstat;
 		for (int i = 1;i <= 16;i++) if (a[i]) cnt++;
 		if (cnt == 16) return _over;
 			else return _unmoved;
	}

 	int OperateMove(char oper){
 		moved = 0;
 		if (oper == 'A') MoveLeft();
 		if (oper == 'D') MoveRight();
 		if (oper == 'S') MoveDown();
 		if (oper == 'W') MoveUp();
 		return checkit();
 	}

    int add(){
        std::vector<int>v;
        for (int i = 1;i <= 16;i++) if (!a[i]) v.push_back(i);
        int pos = v[rand() % v.size()];
        a[pos] = 1;

    }

 	int init(){
 		memset(a,0,sizeof(a));
 		add();
 		add();
 	}

 	int show(){

 		for (int i = 1;i <= 4;i++){
 			for (int j = 1;j <= 4;j++)
 				std::cout << pow(2,a[(i - 1) * 4 + j]);
                std::cout << std::endl;
 		}

 		std::cout << std::endl;
 	}

};
