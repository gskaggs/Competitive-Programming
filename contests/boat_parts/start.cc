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

int main() {
    int N, P;
    cin >> P >> N;

    uset<string> parts;

    for (int i = 0; i < N; i++) {
        string cur;
        cin >> cur;
        parts.insert(cur);
        if (parts.size() == P) {
            cout << i+1 << endl;
            return 0;
        }
    }

    cout << "paradox avoided" << endl;

    return 0;
}
