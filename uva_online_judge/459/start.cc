#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define ll long long
#define umap unordered_map
#define uset unordered_set
using namespace std;

typedef pair<int, int> ii;
typedef vector<int>    vi;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef vector<vii>  vvii;

vi seen;
vvi adjList;

bool dfs(int u) {
    if (seen[u]) return false;
    seen[u] = true;

    for (int v : adjList[u])
        dfs(v);

    return true;
}

int main() {
    int t;
    cin >> t;

    for (int j = 0; j < t; j++) {
        char hi;
        cin >> hi;

        int N = hi - 'A';
        
        adjList.clear();
        adjList.resize(26);
        string s = "temp";
         
        while (true) {
            getline(cin, s);
            if (s.empty()) break;
            int v = s[0] - 'A';
            int u = s[1] - 'A';

            adjList[v].push_back(u);
            adjList[u].push_back(v);
        }

        seen.assign(26, false);
        int count = 0;

        for (int i = 0; i <= N; i++) {
            if (dfs(i)) count++;
        }

        cout << count << endl;

    }

    return 0;
}
