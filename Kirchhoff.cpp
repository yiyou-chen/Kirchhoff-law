#include <bits/stdc++.h>
using namespace std;
int n, m;
double mat[1002][1002];
unordered_map <int, int> now, pre;
char symbol;
double value;
void READ() {
	cout << "Please input the number of loops: ";
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cout << endl << "Please input the number of items in loop(top-down order)" << i << ":";
		cin >> m;
		cout << endl << "Please input all items in loop" << i << "(V for battery and R for resistor left-right order, :| is positive for battery, and |: is negative. Example: V -5 R 2):";
		for(int j = 1; j <= m; ++j) {
			cin >> symbol >> value;
			if(symbol == 'V') {
				mat[i][n + 1] += value;
			}
			else if (symbol == 'R') {
				mat[i][i] -= value;
			}
		}
	}
	for(int i = 1; i < n; ++i) {
		mat[i][n + 1] -= mat[n][n + 1];
		mat[i][n] += mat[n][n];
	}
	for(int i = 1; i < n; ++i) {
		mat[n][i] = 1;
	}
	mat[n][n] = -1; mat[n][n + 1] = 0;
	for(int i = 1; i <= n; ++i) {
		now[i] = i;
		pre[i] = i;
	}
}
void Gauss_Elimination() {
	for(int i = 1; i <= n; ++i) {
		double maxt = -1;
		int rowt = 0;
		for(int j = i; j <= n; ++j) {
			if(abs(mat[j][i]) > maxt) {
				maxt = abs(mat[j][i]);
				rowt = j;
			}
		}
		now[pre[i]] = rowt;
		now[pre[rowt]] = i;
		swap(pre[i], pre[rowt]);
		for(int j = 1; j <= n + 1; ++j) {
			swap(mat[i][j], mat[rowt][j]);
		}
		double scale = mat[i][i];
		for(int j = 1; j <= n + 1; ++j) {
			mat[i][j] /= scale;
		}
		for(int j = 1; j <= n; ++j) {
			if(j == i) continue;
			double time = mat[j][i];
			for(int k = i; k <= n + 1; ++k) {
				mat[j][k] -= time * mat[i][k]; 
			}
		}
	}
}
void PRINT() {
	cout << "Currents in each loop (- means current going from right to left))" << endl;
	for(int i = 1; i < n; ++i) {
		cout << "The current in loop" << i << ": " << -mat[now[i]][n + 1] << "A" << endl;
	}
	cout << "The current in loop" << n << ": " << mat[now[n]][n + 1] << "A" << endl;
}
int main() {
	READ();
	Gauss_Elimination();
	PRINT();
	exit(0);
}
