#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define umap unordered_map
using namespace std;

ll B (ll n, umap <int, ll> & mem) {
    if (n == 0 || n == 1) return n;
    if (mem.count(n)) return mem[n];
    ll res = max(n, B(n/2, mem) + B(n/3, mem) + B(n/4, mem));
    mem[n] = res;
    return res;
}

int main() {
    int n;

    while(!cin.eof()) {
        cin >> n;
        if(cin.eof()) break;
        umap <int, ll> mem;
        cout << B(n, mem) << endl;
    }

    return 0;
}
