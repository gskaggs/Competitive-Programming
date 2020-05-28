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
#define MAX_N 1000000
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int>    vi;
typedef vector<pi>    vpi;

int N, A[MAX_N];
vi next1;

void setIO(string name) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int nextone(int r) {
    FOR(i, r, N) {
        if (A[i]) return i;
    }
    return INF;
}

bool valid(int D) {
    int l = -INF, r = nextone(0), count = 0;
    F0R(i, N) {
        if (A[i]) { 
            if (i - l < D) return false;
            l = i;
            r = nextone(r+1);
            if (r - i < D) return false;
        }
        else if (i - l >= D && r - i >= D) {
            count++;
            l = i;
        }
    }

    return count >= 2;
}

int solve() {
   int lo = 0, hi = MAX_N;
   
   while(!valid(lo) || valid(hi));

   while (lo + 1 < hi) {
       int mid = (hi + lo) / 2;

       if (valid(mid)) lo = mid;
       else hi = mid;
   }

   return lo;
}

int main() {

    setIO("socdist1");

    cin >> N;
    string s;
    cin >> s;

    F0R(i, N) {
        A[i] = s[i] == '1';
    }

    cout << solve() << endl;

    return 0;
}
