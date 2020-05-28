#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int> >
#define vii vector<pair<int, int> >
#define umap unordered_map

using namespace std;

bool canWin (int n, int& d, umap <int, bool> & mem) {
    if (n < 10) return true;
    if (mem.count(n)) return mem[n];
   
    int temp = n, dig;
    bool res = false;

    while (temp > 0) {
        dig = temp % 10;
        temp /= 10;
        
        int dummy;
        if (dig != 0 && !canWin(n - dig, dummy, mem)) {res = true; d = dig; mem[n] = res; return res; }
    }

    mem[n] = res;
    return res;
}



int main() {
    int t;
    cin >> t;

    int dig;
    umap <int, bool> mem;
    bool res = canWin(t, dig, mem);

    int temp = res ? 1 : 2;
    cout << temp << endl;

    if (res) cout << dig << endl;

    return 0;
}
