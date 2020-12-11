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

const int MAXN = 200005;

int parent[MAXN];
int sz[MAXN];
int prv[MAXN];
int nxt[MAXN];
bool active[MAXN];

int find(int i) {
	if(parent[i] == i)
		return i;

	return parent[i] = find(parent[i]);
}

void join(int a, int b) {
	int pa = find(a);
	int pb = find(b);

	if(pa != pb) {
		if(sz[pa] > pb) {
			parent[pb] = pa;
			nxt[pa] = max(nxt[pa], nxt[pb]);
			prv[pa] = min(prv[pa], prv[pb]);
			sz[pa] += sz[pb];
		} else {
			parent[pa] = pb;
			nxt[pb] = max(nxt[pa], nxt[pb]);
			prv[pb] = min(prv[pa], prv[pb]);
			sz[pb] += sz[pa];
		}
	}
}

int main() {
    cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q;
	cin >> N >> Q;

	for(int i = 1; i < N; i++) {
		parent[i] = i;
		sz[i] = 1;
		prv[i] = i - 1;
		nxt[i] = i + 1;
	}

	for(int i = 0; i < Q; i++) {
		int t, ind;
		cin >> t >> ind;
		if(t == 1) {
			active[ind] = true;
			if(active[ind - 1]) {
				join(ind, ind - 1);
			}

			if(active[ind + 1]) {
				join(ind, ind + 1);
			}
		} else {
			int pi = find(ind);
			int start = prv[pi];
			int end = nxt[pi];
			if(active[ind])
				cout << min(ind - start, end - ind) << endl;
			else
				cout << 0 << endl;
		}
	}
}

