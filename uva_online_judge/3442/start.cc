#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define umap unordered_map
using namespace std;

int lastDig(int a, int b) {
    if (b == 0) return 1;
    vi l;
    l.push_back(-1);
    
    int cur = a % 10, m = 1;
    l.push_back(cur);

    cur *= l[1];
    cur %= 10;

    while (cur != l[1]) {
        l.push_back(cur);
        cur *= l[1];
        cur %= 10;
        m++;
    }

    l[0] = l[m];
    return l[b % m];
}
    

int main() {
    int t, a, b;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        cout << lastDig(a, b) << endl;
    }

    return 0;
}
