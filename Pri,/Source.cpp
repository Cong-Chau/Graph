#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct canh {
	int x, y, w;
};
// Danh sach ke cua ma tran co trong so
vector<pair<int, int>>adj[1001];
int n, m, s, t;
int parent[1001];
bool visited[1001];
void Input() {
	cout << "So dinh: "; cin >> n;
	cout << "So canh: "; cin >> m;
	cout << "Nhap dinh dau va dinh cuoi cua moi canh:\n";
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		adj[x].push_back({ y, w });
		adj[y].push_back({ x,w });
	}
	memset(visited, false, sizeof(visited));
}
void prim(int s) {
	visited[s] = 1;
	vector<canh>MST;
	int d = 0;
	while (MST.size() < n - 1) {
		int X = -1, Y = -1;
		int min = INT_MAX;
		for (int i = 0; i < n; i++) {
			if (visited[i] == 1) {
				for (pair<int, int>x : adj[i]) {
					if (!visited[x.first] && x.second < min) {
						X = x.first; Y = i;
						min = x.second;
					}
				}
			}
		}
		if (X != -1 && Y != -1) {
			MST.push_back({ X,Y,min });
			d += min;
			visited[X] = 1;
		}
	}
	cout << "trong so cua cay khung cuc tieu la:" << d << endl;
	for (auto x : MST) {
		cout << x.x << "  " << x.y << "   " << x.w << endl;
	}
}

void Prim(int s) {
	vector<canh>mst; // Cay khung
	int d = 0; // Chieu dai cay khung
	visited[s] = true; // dua dinh s vao tap dinh
	while (mst.size() < n - 1) {
		// Chon canh ngan nhat
		int min_w = INT_MAX; // Canh co trong so nho nhat
		int X, Y; // Luu 2 dinh cua canh dang xet
		for (int i = 0; i < n; i++) {
			if (visited[i]) {// neu i da thuoc tap dinh cua cay khung thi duyet danh sach ke
				for (pair<int, int>it : adj[i]) {// duyet qua tat ca dinh ke cua i
					int j = it.first; // dinh ke voi i
					int trongso = it.second; // trong so cua canh i-j
					if (!visited[j] && trongso < min_w) { // neu trong so nho hon min thi gan min lai bang trong so
						min_w = trongso;
						X = j;
						Y = i;
					}

				}

			}
		}
		// Them canh vao cay khung
		mst.push_back({ X,Y,min_w });
		d += min_w;
		visited[X] = true;
	}
	for (canh duyet : mst) {
		cout << "  " << duyet.x << " " << duyet.y << "  " << duyet.w << endl;
	}
}

int main() {
	Input();
	/*for (int i = 0; i < 6; i++) {
		for (pair<int, int>j : adj[i]) {
			if (i < j.first)
				cout << i << "  " << j.first << "  " << j.second << endl;
		}
	}*/
//	prim(0);
	Prim(0);
	cout << endl;
	return 0;
}