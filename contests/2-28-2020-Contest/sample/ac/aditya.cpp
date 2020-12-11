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

const int MAXN = 800;
int N, M;

int arr[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool bfs(int r, int c, int endR, int endC, int lvl) {
	queue<pii> check;
	check.push({r, c});

	FOR0(i, N) {
		fill_n(vis[i], M, false);
	}

	vis[r][c] = true;

	while(sz(check) > 0) {
		pii curr = check.front();
		check.pop();

		r = curr.f;
		c = curr.s;

		if(r == endR && c == endC)
			return true;

		FOR0(i, 4) {
			int nxtR = r + dr[i];
			int nxtC = c + dc[i];

			if(nxtR >= 0 && nxtR < N && nxtC >= 0 && nxtC < M && !vis[nxtR][nxtC] && arr[nxtR][nxtC] <= lvl) {
				check.push({nxtR, nxtC});
				vis[nxtR][nxtC] = true;
			}
		}
	}

	return false;
}

int main() {
    cin.sync_with_stdio(0);
	cin.tie(0);

	read(N, M);
	int startR, startC, endR, endC;
	startR = startC = endR = endC = -1;

	FOR0(i, N) {
		FOR0(j, M) {
			read(arr[i][j]);
			if(arr[i][j] == 0) {
				if(startR == -1) {
					startR = i;
					startC = j;
				} else {
					endR = i;
					endC = j;
				}
			}
		}
	}

	int lo = 0;
	int hi = N * M + 1;

	while(lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if(bfs(startR, startC, endR, endC, mid)) {
			hi = mid;
		} else {
			lo = mid;
		}
	}

	println(hi);
}

