#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld; 
typedef double db; 
typedef string str; 

typedef pair<int, int> pii;
typedef pair<ll,ll> pll; 
typedef pair<ld,ld> pdd;  

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR0(i,a) FOR(i,0,a)
#define REV(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define REV0(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
#define SQ(x) ((x) * (x))
#define cmax(x, y) x = max(x, y)
#define cmin(x, y) x = min(x, y)

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define rsz resize
#define ins insert 

#define mp make_pair
#define pb push_back
#define eb emplace_back 
#define f first
#define s second
#define lb lower_bound 
#define ub upper_bound 

const int MOD = 1e9+7;
const ll INF = 1e18; 

namespace input {
    template<class T1, class T2> void read(pair<T1,T2>& p);
    template<class T> void read(vector<T>& a);

    template<class T> void read(T& x) { cin >> x; }
    void read(double& x) { string t; read(t); x = stod(t); }
    void read(ld& x) { string t; read(t); x = stold(t); }
    template<class T, class... Ts> void read(T& t, Ts&... ts) { 
        read(t); read(ts...); 
    }

    template<class T1, class T2> void read(pair<T1,T2>& p) { read(p.f,p.s); }
    template<class T> void read(vector<T>& a) { FOR0(i,sz(a)) read(a[i]); }
}

namespace output {
    void print(int x) { cout << x; }
    void print(long x) { cout << x; }
    void print(ll x) { cout << x; }
    void print(unsigned x) { cout << x; }
    void print(unsigned long x) { cout << x; }
    void print(unsigned long long x) { cout << x; }
    void print(float x) { cout << x; }
    void print(double x) { cout << x; }
    void print(ld x) { cout << x; }
    void print(char x) { cout << x; }
    void print(const char* x) { cout << x; }
    void print(const string& x) { cout << x; }
    void print(bool x) { print(x ? "true" : "false"); }
    
    template<class T1, class T2> void print(const pair<T1,T2>& x);
    template<class T> void print(const T& x);
    
    template<class T, class... Ts> void print(const T& t, const Ts&... ts) { 
        print(t); print(ts...); 
    }
    template<class T1, class T2> void print(const pair<T1,T2>& x) { 
        print("{",x.f,", ",x.s,"}"); 
    }
    template<class T> void print(const T& x) { 
        bool fst = true; 
		for (const auto& a: x) print(!fst?" ":"",a), fst = 0; 
    }

	template<class T> void print(T* x, int n) {
		print(x[0]);
		FOR(i, 1, n) {
			print(" ");
			print(x[i]);
		}
	}
    
    void println() { print("\n"); }
	
	template<class T> void println(T* t, int n) {
		print(t, n);
		println();
	}

    template<class T, class... Ts> void println(const T& t, const Ts&... ts) { 
        print(t); if (sizeof...(ts)) print(" "); println(ts...); 
    }
    
    void printdbg() { print("]\n"); }
    template<class T, class... Ts> void printdbg(const T& t, const Ts&... ts) { 
        print(t); if (sizeof...(ts)) print(", "); printdbg(ts...); 
    }
    #define dbg(x...) print("[",#x,"] = ["), printdbg(x);
}

using namespace input;
using namespace output;

struct Edge {
	int src;
	int dest;
	ll flow;
	ll cap;

	Edge(int s, int d, ll c) : src(s), dest(d), flow(0), cap(c) {}

	int other(int c) {
		return c == src ? dest : src;
	}

	ll left(int c) {
		return c == src ? cap - flow : flow;
	}

	void addFlow(int c, ll a) {
		if(c == src) {
			assert(flow + a <= cap);
			flow += a;
		} else {
			assert(flow - a >= 0);
			flow -= a;
		}
	}
};

struct FordFulkerson {
	vector<vector<Edge*>> graph;
	vector<Edge*> used;

	FordFulkerson(int n) : graph(n), used(n) {}
	
	void addEdge(int s, int d, ll c) {
		if(s == d) return;

		Edge* e = new Edge(s, d, c);
		graph[s].pb(e);
		graph[d].pb(e);
	}

	bool bfs(int s, int t) {
		used.assign(sz(used), 0);

		queue<int> cur;
		cur.push(s);

		while(sz(cur) > 0 && used[t] == 0) {
			int ind = cur.front();
			cur.pop();

			trav(e, graph[ind]) {
				if(used[e ->other(ind)] == 0 && e ->other(ind) != s && e ->left(ind) > 0) {
					used[e ->other(ind)] = e;
					cur.push(e ->other(ind));
				}
			}
		}

		return used[t] != 0;
	}

	ll flow(int s, int t) {
		ll ret = 0;

		while(bfs(s, t)) {
			ll add = INF;
			int cur = t;
			while(used[cur]) {
				cmin(add, used[cur] -> left(used[cur] -> other(cur)));
				cur = used[cur] -> other(cur);
			}


			cur = t;
			while(used[cur]) {
				used[cur] -> addFlow(used[cur] -> other(cur), add);
				cur = used[cur] -> other(cur);
			}

			ret += add;
		}

		return ret;
	}

};

int N, M;

int main() {
    cin.sync_with_stdio(0);
	cin.tie(0);
	read(N, M);
	vector<int> starts(N);
	read(starts);
	vector<int> ammos(M);
	read(ammos);

	FordFulkerson maxFlow(N + M + 2);
	int SOURCE = N + M;
	int SINK = N + M + 1;

	FOR0(i, N) {
		maxFlow.addEdge(i, SINK, starts[i]);
	}

	FOR0(i, M) {
		maxFlow.addEdge(SOURCE, N + i, ammos[i]);
	}

	FOR0(i, N) {
		int Ti;
		read(Ti);

		FOR0(j, Ti) {
			int nxt;
			read(nxt);
			maxFlow.addEdge(N + nxt, i, INF);
		}
	}

	ll flow = maxFlow.flow(SOURCE, SINK);
	println(flow);	
}

