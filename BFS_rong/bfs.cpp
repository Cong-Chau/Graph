#include <iostream>
#include <vector>
#include <queue>
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
int parent[1001];
bool visited[1001]; // true neu da duyet qua, nguoc lai false

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

void BFS(int u) {
	queue<int> dinh;
	dinh.push(u);
	visited[u] = true;
	while (!dinh.empty()) {
		int temp = dinh.front();
		dinh.pop();
		for (int i : adj[temp]) {
			if (!visited[i]) {
				dinh.push(i);
				visited[i] = true;
				parent[i] = temp;
			}
		}
	}
}

void DuongDi(int s, int e) {
	BFS(s);
	for (int i = 0; i < 6; i++) {
		cout << "  " << parent[i];
	}
	cout << endl;
	if (!visited[e]) {
		cout << "Khong co duong di\n";
		return;
	}
	vector<int>duong;
	while (1) {
		duong.push_back(e);
		e = parent[e];
		if (e == s) {
			break;
		}
	}
	duong.push_back(s);
	reverse(duong.begin(), duong.end());
	for (int i : duong) {
		cout << "  " << i;
	}
}

int main() {
	Input();
	DuongDi(0, 4);
	return 0;
}