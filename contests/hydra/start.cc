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



int main() {
   
    while (true) {
        int x, y; 
        cin >> x >> y;

        if (x == 0 && y == 0)
            break;
        int h = x, t = y, res = 0;

        while (t & 1 || (h + t/2) & 1) {
            t++;
            res++;
        }

        res += t/2;
        h += t/2;
        res += h/2;
        cout << res << endl;
    }


    return 0;
}
