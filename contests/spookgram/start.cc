#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < (b); i++)
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

int main() {
    int N;
    cin >> N;

    vector<umap<char, int>> words (N);
    vi count (N);

    rep(i, 0, N) {
        string s;
        cin >> s;
        for (char c : s) {
            words[i][c]++;
        }
    }

    rep(i, 0, N) {
        rep(j, 0, N) {
            if (i == j) continue;
            bool gram = true;
            for (auto& c : words[i]) {
                if (words[j][c.first] < c.second) gram = false;
            }

            if (gram) {
                count[i]++;
            }
        }
    }

    rep(i, 0, N) {
        cout << count[i] << endl;
    }
    

    return 0;
}
