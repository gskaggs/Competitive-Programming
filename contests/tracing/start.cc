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
#define MAX_N 105
#define MAX_T 255 
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int>    vi;
typedef vector<pi>    vpi;

void setIO(string name) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int x, y, z, N, T;
pair<int, pi> s[MAX_T];
int og[MAX_N], in[MAX_N], k[MAX_N];

bool valid(int p, int K) {
    F0R(i, N) k[i] = K; 
    F0R(i, N) in[i] = 0;
    in[p] = 1;

    F0R(i, T) {
        int a = s[i].s.f, b = s[i].s.s;
        if (in[a]) k[a]--;
        if (in[b]) k[b]--;

        if (in[a] && k[a] >= 0 && !in[b]) in[b] = 1;
        if (in[b] && k[b] >= 0 && !in[a]) in[a] = 1;
    }

    F0R(i, N) if (og[i] != in[i]) return false;
    return true;
}

bool valid(int p) {
    bool res = false;
    F0R(i, MAX_T) if (valid(p, i)) {
        res = true;
        y = min(y, i);
        z = max(z, i);
    }

    return res;
}


int main() {
    setIO("tracing");
    
    cin >> N >> T;
    string str;
    cin >> str;
    F0R(i, N) 
        og[i] = (int)(str[i] - '0');
    
    F0R(i, T) {
        int t, a, b;
        cin >> t >> a >> b;
        s[i] = {t, {a-1, b-1}};
    }

    sort(s, s+T);

    y = INF;
    z = -INF;

    F0R(i, N) if(valid(i)) x++;

    cout << x << " " << y << " ";
    if (z == MAX_T-1) cout << "Infinity";
    else cout << z;
    cout << endl;

    return 0;
}
