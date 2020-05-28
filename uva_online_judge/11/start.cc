#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
using namespace std;

int Z(int n) {
    int d = n/5, res = 0;
    while (d) {
        res += d;
        d /= 5;
    }

    return res;
}

int main() {
    int t, n;
    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> n;
        cout << Z(n) << endl;
    }

    return 0;
}
