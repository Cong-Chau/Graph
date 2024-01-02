#include <iostream>
#include <vector>
using namespace std;
// n la dinh
// m la canh
/*
0 1
0 3
1 2
1 3
1 5
2 5
3 4
3 5
0  1  0  1  0  0
1  0  1  1  0  1
0  1  0  0  0  1
1  1  0  0  1  1
0  0  0  1  0  0
0  1  1  1  0  0
*/
vector<int>start = { 0,0,1,1,1,2,3,3 };
vector<int>_end   = { 1,3,2,3,5,5,4,5 };
int a[1001][1001];
vector<int> dsk[1001];// dsk[i]: danh sach ke cua dinh i
vector<vector<int>> dsc;

// Ma tran ke
void Matranke(int a[][1001], int m){
	int temp = 0;
	for (int i = 0; i < m; i++) {
		int x = start[temp];
		int y = _end[temp];
		a[x][y] = a[y][x] = 1;
		temp++;
	}
}
void outputMaTranKe(int a[][1001], int n) {
	cout << "    ";
	for (int i = 0; i < n; i++) {
		cout << i << "  ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << "" << i << " ";
		for (int j = 0; j < n; j++) {
			cout << "  " << a[i][j];
		}
		cout << endl;
	}
}

// Danh sach ke
void DanhSachKe(vector<int> dsk[], int m) {
	for (int i = 0; i < m; i++) {
		int x = start[i];
		int y = _end[i];
		dsk[x].push_back(y);
		dsk[y].push_back(x);
	}
}
void outputDanhSachKe(vector<int> dsk[], int n) {	
	for (int i = 0; i < n; i++) {
		cout << " " << i << ":";
		for (int j = 0; j < dsk[i].size(); j++) {
			cout << "  " << dsk[i][j];
		}
		cout << endl;
	}
}

// DFS: Chieu sau


int main() {
	/*cout << "n = "; cin >> n;
	cout << "m = "; cin >> m;*/
	int n = 6;
	int m = 8;
	
	// Ma tran ke
	cout << "Ma tran ke:\n";
	Matranke(a, m);
	outputMaTranKe(a, n);
	cout << endl;
	// Danh sach ke
	cout << "Danh sach ke:\n";
	DanhSachKe(dsk, m);
	outputDanhSachKe(dsk, n);
	cout << endl;

	return 0;
}