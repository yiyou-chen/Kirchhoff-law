#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int from[100005], to[100005], id[100005], num,  _vis[100005], current[100005], I, loop, inicof, m; 
double DDD, D[1005]; // 1 battery, 0 resistance
int tt[100005];
queue <int> q;
double val[1005][1005], b[1005][1005], vis[1005][1005];
void read(){
 int x, y;
 char ch;
 double z, real = 0.0, coff = 0.0;
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|
                       FOREGROUND_BLUE);
 printf("Number of loops: ");
 scanf("%d", &loop);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|
                       FOREGROUND_BLUE);
                       SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
 printf("Number of things in loop 1: ");
 scanf("%d", &m);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|
                        FOREGROUND_GREEN|FOREGROUND_BLUE);
 printf("Please type in the things in loop 1 (V (or v) represents battery, R (or r) represents resistance): \n");
 for(int i = 1; i <= m; i++){
  cin >> ch >> z;
  if(ch == 'V' || ch == 'v'){
   real += z;
  }
  else if(ch == 'R' || ch == 'r'){
   coff -= z;
  }
 }
 for(int i = 1; i <= loop - 1; i++){
  val[i][1] = coff;
  val[i][0] = real; 
 }
 for(int i = 1; i <= loop - 1; i++){
 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
 	printf("Number of things in Loop %d: ", i + 1);
  scanf("%d", &m);
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|
                        FOREGROUND_GREEN|FOREGROUND_BLUE);
  printf("Please type in the things in loop %d (V (or v) represents battery, R (or r) represents resistance): \n", i + 1);
  for(int j = 1; j <= m; j++){
   cin >> ch >> z;
   if(ch == 'V' || ch == 'v'){
    val[i][0] -= z;
   }
   else if(ch == 'R' || ch == 'r'){
    val[i][i + 1] -= z;
   }
  }
 }
 val[loop][1] = 1;
 for(int i = 2; i <= loop; i++){
  val[loop][i] = -1;
 }
}
void makematrix(int x){
 for(int i = 1; i <= loop; i++){
  for(int j = 1; j <= loop; j++){
   b[i][j] = val[i][j];
  }
 } 
 for(int i = 1; i <= loop; i++) {
  for(int j = loop + 1; j <= 2 * loop; j++){
   b[i][j] = b[i][j - loop];
  }
 }
 for(int i = 1; i <= loop; i++) {
  for(int j = 2 * loop + 1; j <= 3 * loop; j++){
   b[i][j] = b[i][j - loop];
  }
 }
 for(int i = 1; i <= loop; i++){
  b[i][x] = val[i][0];
 }
 for(int i = 1; i <= loop; i++){
  b[i][x + loop] = val[i][0];
 }
 for(int i = 1; i <= loop; i++){
  b[i][x + 2 * loop] = val[i][0];
 } 
}
void run(){
	if(loop == 2){
		DDD = val[1][1] * val[2][2] - val[2][1] * val[1][2];
		D[1] = val[1][0] * val[2][2] - val[2][0] * val[1][2];
		D[2] = val[1][1] * val[2][0] - val[2][1] * val[1][0];
		return ;
	}
 for(int i = 1; i <= loop; i++){
  for(int j = 1; j <= loop; j++){
   b[i][j] = val[i][j];
  }
 } 
 for(int i = 1; i <= loop; i++) {
  for(int j = loop + 1; j <=  2 * loop; j++){
   b[i][j] = b[i][j - loop];
  }
 }
 for(int i = 1; i <= loop; i++) {
  for(int j = 2 * loop + 1; j <= 3 * loop; j++){
   b[i][j] = b[i][j - loop];
  }
 }
 memset(vis, 0, sizeof(vis));
 for(int i = loop + 1; i <= 2 * loop; i++){
  double multi1 = 1.0, multi2 = 1.0;
  for(int j = i; j <= i + loop - 1;  j++){
   multi1 *= b[j - i + 1][j];
  }
  for(int j = 3 * loop + 1 - i; j >= 3 * loop + 1 - i - loop + 1; j--){
   multi2 *= b[3 * loop + 1 - i - j + 1][j];
  }
  //cout << multi1 << ' ' << multi2 << endl;
  DDD += multi1;
  DDD -= multi2;
 }
 for(int k = 1; k <= loop; k++){
 makematrix(k);
  /*	cout <<'/' << k << endl;
 	 for(int i = 1; i <= loop; i++) {
 	for(int j = 0; j <= loop; j++) cout << b[i][j] << ' ';
 	cout << endl;
 }*/
 memset(vis, 0, sizeof(vis));
 for(int i = loop + 1; i <= 2 * loop; i++){
  double multi1 = 1.0, multi2 = 1.0;
  for(int j = i; j <= i + loop - 1;  j++){
   multi1 *= b[j - i + 1][j];
  }
  for (int j = 3 * loop + 1 - i; j >= 3 * loop + 1 - i - loop + 1; j--){
   multi2 *= b[3 * loop + 1 - i - j + 1][j];
  }
   D[k] += multi1;
   D[k] -= multi2;
  }
 }
}
void print(){
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|
                       FOREGROUND_BLUE);
 	if(1.0 * D[1] / DDD < 0){
 		printf("I1: %.6lfA, Right!\n", -1.0 * D[1] / DDD);
	}
	else {
		printf("I1: %.6lfA, Left!\n", 1.0 * D[1] / DDD);
	}
  for(int i = 2; i <= loop; i++){
 		printf("I%d: %.6lfA, ", i, abs(1.0 * D[i] / DDD));
 		if(1.0 * D[i] / DDD < 0) printf("Left!\n");
 		else printf("Right!\n");
 	}
}
int main(){
	cout << "Gerry's Physics Project -- Kirchhoffs Circuit Law\n";
 read();
 /*for(int i = 1; i <= loop; i++) {
 	for(int j = 0; j <= loop; j++) cout << val[i][j] << ' ';
 	cout << endl;
 }*/
 run();
 //cout << DDD << endl;
 //for(int i = 1; i <= loop; i++) cout << D[i] << endl;
 print();
 system("pause");
}
/*
3 
1 V 10
1 R 3
1 R 2

2
1 V 5
1 r 1
*/
