#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define ll long long
#define umap unordered_map
#define uset unordered_set
#define INF INT_MAX
using namespace std;

typedef pair<int, int> ii;
typedef vector<int>    vi;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef vector<vii>  vvii;
typedef vector<string> vs;

umap<int, umap<int, double>> dist;

struct Node {
    int x, y;
    double d;

    bool operator > (const Node & n) const {
        return d > n.d; 
    }
};

struct Edge {
    int x, y;
    double d;
};

double makeDist(int a, int b, int c, int d) {
    double s1 = (c - a) * (c - a);
    double s2 = (d - b) * (d - b);
    return pow(s1 + s2, 0.5);
}

int main() {

    string s;
    stringstream ss;
    getline(cin, s);

    int t;
    t = stoi(s);
    getline(cin, s);

    for (int i = 0; i < t; i++) {
        if (i != 0) cout << endl;
        int S1, S2, E1, E2;
        getline(cin, s);
        ss << s; 
        ss >> S1 >> S2 >> E1 >> E2;
        ss.clear();

        dist.clear();
        dist[S1][S2] = 0; 

        umap<int, umap<int, vector<Edge>>> adj;
        vii prev;

        prev.push_back({S1, S2});

        while (true) {
            getline(cin, s);
            if (s.empty()) break;
            ss << s;
            //cout << s << endl;
            
            ii last = {-1, -1};
            while (true) {
                int x, y;
                ss >> x >> y;
                if (x == -1 && y == -1) 
                    break;
                
                if (last.first != -1) {
                    //cout << last.first << " " << last.second << " " << x << " " << y << endl;
                    double d = makeDist(last.first, last.second, x, y)/40;
                    //cout << d << endl;
                    adj[x][y].push_back({last.first, last.second, d});
                    adj[last.first][last.second].push_back({x, y, d});
                } 

                for (auto n : prev) {
                    double d = makeDist(n.first, n.second, x, y)/10;
                    adj[x][y].push_back({n.first, n.second, d});
                    adj[n.first][n.second].push_back({x, y, d});
                }

                last = {x, y};
                prev.push_back(last);
                if (!dist[x].count(y)) dist[x][y] = INF;
            }
            
            ss.clear();
        }

        int x = E1, y = E2;
        for (auto n : prev) {
                double d = makeDist(n.first, n.second, x, y)/10;
                adj[x][y].push_back({n.first, n.second, d});
                adj[n.first][n.second].push_back({x, y, d});
        }

        if (!dist[E1].count(E2)) dist[E1][E2] = INF;

        priority_queue<Node, vector<Node>, greater<Node>> pq;
        pq.push({S1, S2, 0});

        while (!pq.empty()) {
            int x = pq.top().x, y = pq.top().y;
            double d = pq.top().d;
            pq.pop();
            if (d > dist[x][y]) continue;

            if (x == E1 && y == E2) break;

            for (const Edge & e : adj[x][y]) {
                double cur = dist[x][y] + e.d;
                if (cur < dist[e.x][e.y]) {
                    pq.push({e.x, e.y, cur});
                    dist[e.x][e.y] = cur;
                }       
            }
        }

        cout << fixed << setprecision(0) << (dist[E1][E2]*60)/1000 << endl; 

    }

    return 0;
}
