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
int n, m;
vector<int> adj[1001];
bool visited[1001]; // true neu da duyet qua, nguoc lai false
int parent[1001];
// Chuyen tu danh sach canh sang danh sach ke
void Input() {
	cout << "So dinh: "; cin >> n;
	cout << "So canh: "; cin >> m;
	cout << "Nhap dinh dau va dinh cuoi cua moi canh:\n";
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	// Thiet lap gia tri cua mang
	memset(visited, false, sizeof(visited));
}
//       Dinh u
void DFS(int u) {
	visited[u] = true;
	for (int i : adj[u]) {
		if (!visited[i]) {// neu dinh i chua duoc duyet thi de quy DFS vao i
			parent[i] = u;// Luu lai cha cua i la u
			DFS(i);
		}
	}
}

void DuongDi(int s, int e) {
	DFS(s);
	for (int i = 0; i < 6; i++) {
		cout << "  " << parent[i];
	}
	cout << endl;
	if (!visited[e]) {
		cout << "Khong co duong di\n";
		return;
	}
	vector<int>duong;// Luu lai duong di
	while (e != s) {
		duong.push_back(e);
		//Tim nguoc lai
		e = parent[e];
	}
	duong.push_back(s);
	reverse(duong.begin(), duong.end());
	for (int i : duong) {
		cout << "  " << i;
	}
}

int main() {
	Input();
	DuongDi(0, 5);
	return 0;
}