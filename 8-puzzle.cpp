#include <iostream>
#include <string>
#include <queue>
#include <stdlib.h>

using namespace std;
using std::cout;
using std::endl;

struct State{//Khai bao cau truc du lieu trang thai
	int giatri[3][3];
	int h,c;
};

void InitState(State &S){//Gan gia tri ban dau
	S.giatri[0][0] = 7;
	S.giatri[0][1] = 2;
	S.giatri[0][2] = 4;
	S.giatri[1][0] = 5;
	S.giatri[1][1] = 0;
	S.giatri[1][2] = 6;
	S.giatri[2][0] = 8;
	S.giatri[2][1] = 3;
	S.giatri[2][2] = 1;
	S.h = 1;
	S.c = 1;
}

void Show(State S){//In du lieu ra man hinh
	for(int i=0;i<=2;i++){
		for(int j=0;j<=2;j++){
			cout << S.giatri[i][j] << "|";		
		}		
		cout << endl;
	}
	cout << endl<<endl;
}
	
bool Move_Left(State S,State &S1)//Di chuyen o trong sang trai
{
	if(S.c <= 0) return false;// neu o trong dang tai cot dau tien thi tra ve false
	//gan gia tri S1 tai vi tri o trong ban dau bang gia tri tai vi tri ben trai
	S1.giatri[S.h][S.c] = S.giatri[S.h][S.c-1];
	//gan gia tri S1 tai vi tri ben trai bang gia tri tai vi tri o trong ban dau
	S1.giatri[S.h][S.c-1] = S.giatri[S.h][S.c];
	//Luu lai vi tri o trong
	S1.h = S.h;
	S1.c = S.c-1;	
	return true;
}

bool Move_Right(State S,State &S1)//Di chuyen o trong sang phai
{
	if(S.c >= 2) return false;
	//gan gia tri S1 tai vi tri o trong ban dau bang gia tri tai vi tri ben phai
	S1.giatri[S.h][S.c] = S.giatri[S.h][S.c+1];
	//gan gia tri S1 tai vi tri ben phai bang gia tri tai vi tri o trong ban dau
	S1.giatri[S.h][S.c+1] = S.giatri[S.h][S.c];
	//Luu lai vi tri o trong
	S1.h = S.h;
	S1.c = S.c+1;
	return true;
}

bool Move_Up(State S,State &S1)//Di chuyen o trong len tren
{
	if(S.h <= 0) return false;
	S1.giatri[S.h][S.c] = S.giatri[S.h-1][S.c];
	S1.giatri[S.h-1][S.c] = S.giatri[S.h][S.c];
	S1.h = S.h-1;
	S1.c = S.c;	
	return true;
}

bool Move_Down(State S,State &S1)//Di chuyen o trong xuong duoi
{
	if(S.h >= 2) return false;
	S1.giatri[S.h][S.c] = S.giatri[S.h+1][S.c];
	S1.giatri[S.h+1][S.c] = S.giatri[S.h][S.c];
	S1.h = S.h+1;
	S1.c = S.c;	
	return true;
}

void Chon(State S,State &S1,int act){
	switch(act){
		case 1:
			{
			Move_Left(S,S1);
			break;
		}
		case 2:{
			Move_Right(S,S1);
			break;
		}
		case 3:{
			Move_Up(S,S1);
			break;
		}
		case 4:	{
			Move_Down(S,S1);
			break;
		}
		default:{}
	}
}

int main(){
	State S,S1;
	int act;
	InitState(S);
	Show(S);
	S1=S;
	cout<< "Chon action: " << endl <<"Left 1"<<endl <<"Right 2"<<endl <<"Up 3"<<endl <<"Down 4"<<endl;
	cin >> act;
	
	Chon(S,S1,act);
	Show(S1);
	system("pause");
}
