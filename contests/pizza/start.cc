#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define ll long long
#define umap unordered_map
#define uset unordered_set
#define INF 100000000000000
using namespace std;

typedef pair<int, int> ii;
typedef vector<int>    vi;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef vector<vii>  vvii;
typedef vector<string> vs;

struct Canidate {
    ll d;
    int u;
    vi missing;

    bool operator > (const Canidate c) const {
        return d > c.d;
    }
};

int main() {
    string t  = "a,b,c";
    stringstream sm;
    sm << t;
    while (getline(sm, t, ','))  cout << t << endl;
    int N, M, L, T;
    string s;
    getline(cin,s);
    stringstream ss(s);
    ss >> N >> M >> L >> T;
    cout << T << endl;

    umap <string, int> l;
    vector<string> temp (L);

    for (int i = 0; i < L; i++) {
        getline(cin, s);
        //cout << s <<endl;
        temp[i] = s;
        l[s] = i;
    }

    vvi ing (N+1);

    for (int i = 1; i < N+1; i++) {
        getline(cin, s);
        ss.clear();
        ss.str(s);
        
        string cur;

        while (ss >> cur) {
            if (l.count(cur) > 0) ing[i].push_back(l[cur]);

            //cout << cur << endl;
        }

        cout << ing[i].size() <<endl;
    }

    vector<vector<pair<ll, ll>>> adj (N+1);

    for (int i = 0; i<M; i++) {
        ll u, v, w;
        ss.clear();
        getline(cin, s);
        ss.str(s);
        ss >> u >> v >> w;
        cout <<s<<endl; 
    
        adj[u].push_back({v, w});
        //adj[v].push_back({u, w});
    
    }

    vector<ll> dist(N+1, INF);
    dist[1] = 0; 

    vi start (L, 1);
                for (int j = 0; j < ing[1].size(); j++) {
                    //cout << ing[1].size() <<endl;
                    start[ing[1][j]] = 0;
                }
    Canidate cur  = {0, 1, start};

    priority_queue<Canidate, vector<Canidate>, greater<Canidate>> pq;
    pq.push(cur);

    while (!pq.empty()) {
        cur = pq.top();
        pq.pop();
       
        int d = cur.d, u = cur.u;
        vi used = cur.missing;
        cout << d << " " << u << endl;
        if (d > dist[u]) continue;
        if (u == T) break;

        for (int i = 0; i < adj[u].size(); i++) {
            ll v = adj[u][i].first, w = adj[u][i].second;
            cout << "hello " <<endl;

            if (w + d < dist[v]) {
                dist[v] = w + d;
                vi used2 = used;

                for (int j = 0; j < ing[v].size(); j++) {
                    used2[ing[v][j]] = 0;
                    //cout << j << " : " << ing[v][j] << endl;
                }

                pq.push({w+d, (int)v, used2});
                

            }

        }

    }

    int count = 0;
    for (int i = 0; i < L; i++) {
        if (cur.missing[i])  {
            cout << temp[i] << endl;
            count++;
        }
    }

    if (count == 0)
        cout << "Delivery successful!" << endl;





    return 0;
}
