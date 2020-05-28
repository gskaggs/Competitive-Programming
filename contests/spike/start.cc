#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define trav(a, x) for (auto& a : x)
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
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

    int M = 0, W = 0;
    char team;
    int player;

    char res = 0;

    rep(i, 0, N) {
        
        string s;
        cin >> s;

        int next_player = s[1] - '0';
        char next_team = s[0];

        if (i == 0) {
            team = next_team;
            player = next_player + 1;
        }

        if (team == next_team) {
            
            if (player == next_player) {
                res = team;
                break;
            }

        }

        else {
            if (M + W > 3) {
                res = team;
                break;
            }

            if ((W == 0 && M > 1) || (M == 0 && W > 1)) {
                res = team;
                break;
            }

            M = 0;
            W = 0;
        }

        if (s[2] == 'M') 
            M++;
        else
            W++;

        team = next_team;
        player = next_player;

    }

    if ((M + W > 3) || (W == 0 && M > 1) || (M == 0 && W > 1)) {
        res = team;
    }

    if (res == 0) {
        cout << "No violation" << endl;
    }

    else 
        cout << res << endl;

    return 0;
}
