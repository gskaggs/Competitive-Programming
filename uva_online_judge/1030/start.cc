#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define umap unordered_map
using namespace std;

int main() {
    
    vi ray;

    for (int i = 0; i < 1000; i++) 
        if ((i * i * i ) % 1000 == 888) {
            ray.push_back(i);
        }
    
    int t, n = 4;
    ll k;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> k;
        ll res = 0;
        res += 1000;
        res *= (k-1)/4;
        res += ray[(k-1) % n];
        cout << res << endl;
    }

    
    return 0;
}
