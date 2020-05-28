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

int i;
umap <int, int> mem;

int rec(string s) {
    int res = 0;
    char cur = s[i];
    if (i == -1) return 0;
    i--;
    //cout << cur << endl;

    if (cur == '-') {
        res = rec(s) == 1 ? 0 : 1;
    }
    else if (cur == '+')
        res = rec(s) | rec(s);
    else if (cur == '*')
        res = rec(s) & rec(s);
    else {
        //cout << mem[i] << endl;
        res = mem[cur - 'A'];
    }

    return res;
}

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string cur;
        cin >> cur;

        mem[i] = cur == "T" ? 1 : 0;

    }

    string s;
    while (true) {
        string cur;
        cin >> cur;
        if (cin.eof()) break;
        s.push_back(cur[0]);
    }
    
    i = s.size() - 1;
    //cout << i << endl;
    //cout << s << endl;
    string res = rec(s) == 1 ? "T" : "F";

    cout << res << endl;

    return 0;
}
