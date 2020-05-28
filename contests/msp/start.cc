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

class UF {
    vi nums;
public:
    UF(int N) : nums(N) {
        for (int i = 0; i < N; i++) 
            nums[i] = i;
    }

    int root(int n) {
        while (nums[n] != n) 
            n = nums[n];

        return n;
    }

    bool sameSet(int a, int b) {
        return root(a) == root(b);
    }

    void makeUnion(int a, int b) {
        a = root(a);
        b = root(b);
        nums[a] = b;
    }

};

int main() {

    while(true) {
        string s;
        getline(cin, s);
        //if (s.size() == 0) break;
        int N = stoi(s);

        int orig = 0;
        for (int i = 0; i < N-1; i++) {
            getline(cin, s);
            stringstream ss;
            ss << s;
            int u, v, w;
            ss >> u >> v >> w;
            orig += w;
        }

        getline(cin, s);
        int K = stoi(s);

        vector<pair<int, ii>> E;

        for(int i = 0; i < K; i++) {
            getline(cin, s);
            stringstream ss;
            ss << s;
            int u, v, w;
            ss >> u >> v >> w;
            E.push_back({w, {u, v}});
        }

        getline(cin, s);
        int M = stoi(s);

        for (int i = 0; i < M; i++) {
            getline(cin, s);
            stringstream ss;
            ss << s;
            int u, v, w;
            ss >> u >> v >> w;
            E.push_back({w, {u, v}});
        }

        sort(E.begin(), E.end());

        UF uf(E.size());
        int cost = 0;

        for (int i = 0; i < E.size(); i++) {
            int u = E[i].second.first, v = E[i].second.second, w = E[i].first;

            if (!uf.sameSet(u, v)) {
                cost += w;
                uf.makeUnion(u, v);
            }
        }

        cout << orig << endl;
        cout << cost << endl;
        
        if (!getline(cin, s))
            break;
        cout << endl;
    }

    return 0;
}
