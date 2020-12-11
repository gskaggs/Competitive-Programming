#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <deque>
#include <iomanip>
#include <fstream>
#if __cplusplus > 201103L 
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

#define PB push_back
#define MP make_pair
#define AA first
#define BB second
#define SZ size()
#define BG begin()
#define OP begin()
#define ED end()
#define SQ(x) ((x)*(x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)

const int INF = 1000000007;

/*
	Implementation of highest-label push-relabel maximum flow
	with gap relabeling heuristic.

	Running time:
		O(|V|^2|E|^{1/2})

	Usage:
		- add edges by AddEdge()
		- GetMaxFlow(s, t) returns the maximum flow from s to t

	Input:
		- graph, constructed using AddEdge()
		- (s, t), (source, sink)

	Output:
		- maximum flow value

	Todo:
		- implement Phase II (flow network from preflow network)
		- implement GetMinCut()
*/

template <class T> struct Edge {
	int from, to, index;
	T cap, flow;

	Edge(int from, int to, T cap, T flow, int index) : from(from), to(to), cap(cap), flow(flow), index(index) {}
};

template <class T> struct PushRelabel {
	int n;
	vector <vector <Edge <T>>> adj;
	vector <T> excess;
	vector <int> dist, count;
	vector <bool> active;
	vector <vector <int>> B;
	int b;
	queue <int> Q;

	PushRelabel(int n) : n(n), adj(n) {}

	void AddEdge(int from, int to, int cap) {
		adj[from].push_back(Edge <T>(from, to, cap, 0, adj[to].size()));
		if (from == to) {
			adj[from].back().index++;
		}
		adj[to].push_back(Edge <T>(to, from, 0, 0, adj[from].size() - 1));

	}

	void Enqueue(int v) {
		if (!active[v] && excess[v] > 0 && dist[v] < n) {
			active[v] = true;
			B[dist[v]].push_back(v);
			b = max(b, dist[v]);
		}
	}

	void Push(Edge <T>& e) {
		T amt = min(excess[e.from], e.cap - e.flow);
		if (dist[e.from] == dist[e.to] + 1 && amt > T(0)) {
			e.flow += amt;
			adj[e.to][e.index].flow -= amt;
			excess[e.to] += amt;
			excess[e.from] -= amt;
			Enqueue(e.to);
		}
	}

	void Gap(int k) {
		for (int v = 0; v < n; v++) if (dist[v] >= k) {
			count[dist[v]]--;
			dist[v] = max(dist[v], n);
			count[dist[v]]++;
			Enqueue(v);
		}
	}

	void Relabel(int v) {
		count[dist[v]]--;
		dist[v] = n;
		for (auto e : adj[v]) if (e.cap - e.flow > 0) {
			dist[v] = min(dist[v], dist[e.to] + 1);
		}
		count[dist[v]]++;
		Enqueue(v);
	}

	void Discharge(int v) {
		for (auto& e : adj[v]) {
			if (excess[v] > 0) {
				Push(e);
			}
			else {
				break;
			}
		}

		if (excess[v] > 0) {
			if (count[dist[v]] == 1) {
				Gap(dist[v]);
			}
			else {
				Relabel(v);
			}
		}
	}

	T GetMaxFlow(int s, int t) {
		dist = vector <int>(n, 0), excess = vector<T>(n, 0), count = vector <int>(n + 1, 0), active = vector <bool>(n, false), B = vector <vector <int>>(n), b = 0;

		for (auto& e : adj[s]) {
			excess[s] += e.cap;
		}

		count[0] = n;
		Enqueue(s);
		active[t] = true;

		while (b >= 0) {
			if (!B[b].empty()) {
				int v = B[b].back();
				B[b].pop_back();
				active[v] = false;
				Discharge(v);
			}
			else {
				b--;
			}
		}
		return excess[t];
	}

	T GetMinCut(int s, int t, vector <int>& cut);
};

void solve()
{
	int i, j, k, u, v, w;

	int N, M;
	cin >> N >> M;
	int total = N + M + 2;

	const int SOURCE = 0;
	const int SINK = total - 1;
	const int BIG = 1000000;

	PushRelabel<int> g = PushRelabel<int>(total);
	for (i = 1; i <= N; ++i)
	{
		cin >> w;
		g.AddEdge(SOURCE, i, w);
	}
	
	for (i = 1; i <= M; ++i)
	{
		cin >> w;
		g.AddEdge(N + i, SINK, w);
	}

	for (i = 1; i <= N; ++i)
	{
		cin >> k;
		while (k--)
		{
			cin >> w;
			g.AddEdge(i, N + w + 1, BIG);
		}
	}

	cout << g.GetMaxFlow(SOURCE, SINK) << endl;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("", "w", stdout);

	solve();

	return 0;
}