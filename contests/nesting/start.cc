#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
#define pb push_back
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second
#define umap unordered_map
#define uset unordered_set
#define INF 1000000007
#define MAX_N 100
using namespace std;

void setIO(string name) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int>    vi;
typedef vector<pi>    vpi;

int T, A[MAX_N];

int main() {

    cin >> T;
    F0R(t, T) {
        string s;
        cin >> s;
        int N = sz(s);
        F0R(i, N) A[i] = s[i] - '0';
        
        cout << "Case #" << t + 1 << ": ";

        int k = 0;
        F0R(i, N) {
            int cur = A[i];
            while (k > cur) { cout << ")"; k--; }
            while (k < cur) { cout << "("; k++; }
            cout << cur;
        }
        while (k > 0 ) { cout << ")"; k--; } 
        cout << endl; 
    }

    return 0;
}
