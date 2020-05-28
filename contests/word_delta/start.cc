#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define ll long long
#define umap unordered_map
#define uset unordered_set
#define INF 1000000000 
using namespace std;

typedef pair<int, int> ii;
typedef vector<int>    vi;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef vector<vii>  vvii;
typedef vector<string> vs;

void nextLine(stringstream & ss) {
    string s;
    getline(cin, s);
    ss.clear();
    ss << s;
}

bool edge(string a, string b) {
    int count = 0;
    if (a.size() != b.size()) return false;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i])
            count++;
    }

    return count == 1;
}

int main() {

    stringstream ss;
    string s;

    getline(cin, s);
    int N = stoi(s);

    getline(cin, s); // blank space

    for (int i = 0; i < N; i++) {
        uset<string> dict;
        umap<string, vs> adj;

        while (true) {
            getline(cin, s);
            if (s == "*") break;

            for (auto prev : dict) {
                if (edge(s, prev)) {
                    adj[prev].push_back(s);
                    adj[s].push_back(prev);
                }
            }

            dict.insert(s);
        }

        while (true) {
            nextLine(ss);
            string a, b;
            ss >> a;
            ss >> b;

            if (!a.size() || !b.size()) {
                cout << a << " " << b <<endl;
                break;
            }

            queue<pair<string, int>> q;
            q.push({a, 0});

            uset<string> seen;

            while (!q.empty()) {
                auto cur = q.front();
                q.pop();


                if (cur.first == b) {
                    printf("%s %s %d\n", a.c_str(), b.c_str(), cur.second);
                    break;
                }

                for (auto next : adj[cur.first]) {
                    if (!seen.count(next)) {
                        q.push({next, cur.second+1});
                    }
                }
                
                seen.insert(cur.first);

            }

        }
        if (i != N-1) cout << endl;

    }

    return 0;
}
