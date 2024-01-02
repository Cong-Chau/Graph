#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

/*
0 1 1
1 2 5
1 3 2
1 5 7
2 5 1
3 0 2
3 2 1
3 4 4
4 3 3
5 4 1
*/
int n, m;
vector<pair<int, int>> adj[1001];
int parent[10001];
// Chuyen tu danh sach canh sang danh sach ke
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
}

void Dijkstra(int s) {
	// Mang luu khoang cach duong di
	vector<long long>d(n + 1, INF);
	d[s] = 0;
	parent[s] = s;
	priority_queue<pair<int, int>, vector<pair<int, int>, greater<pair<int, int>>>>Q;
	// {khoang cach, dinh}
	// Khoi tao
	Q.push({ 0,s });
	while (!Q.empty()) {
		// Chon ra dinh co khoang cach den s nho nhat
		pair<int, int>min = Q.top();
		Q.pop();
		int kc = min.first;// khoang cach den s
		int u = min.second;// dinh dang xet
		if (d[u] < kc)// neu kc cu nho hon kc moi thi bo qua
			continue;
		// Cap nhat lai duong di ngan nhat
		// Duyet trong danh sach ke cua dinh u
		for (pair<int, int>it : adj[u]) {
			int v = it.first; // Dinh dich de xet
			int w = it.second;// Trong so
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				Q.push({ d[v], v });
				parent[v] = u;
			}
		}
	}
}
void DuongDi(int s, int v) {
	Dijkstra(s);
	vector<int>street;
	if (parent[v] == 0) {
		cout << "khong co duong di";
	}
	else {
		while (s != v) {
			street.push_back(v);
			v = parent[v];
		}
		street.push_back(s);
		reverse(street.begin(), street.end());
		for (auto it : street) {
			cout << it << "  ";
		}
	}
}
int main() {
	Input();
	Dijkstra(0);
	DuongDi(0, 4);
	cout << endl;
	return 0;
}