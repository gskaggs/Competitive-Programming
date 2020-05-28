#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
using namespace std;


ll hotness(int n, const vi & men, const vi & women) {
    ll res = 0; 
    
    for (int i = 0; i < n; i++)
       res += men[i] * women[i];

    if (!res || res) cout << "hi" << endl;

    return res;
}

int main() {
    
    int t, n;
    cin >> t;

    for (int i = 0 ; i < t; i++) {
        cin >> n;
        vi men, women;

        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            men.push_back(a);
        }
        for (int j = 0; j < n; j++)
        {
            int a;
            cin >> a;
            women.push_back(a);
        }
        sort(men.begin(), men.end());
        sort(women.begin(), women.end());


        cout << hotness(n, men, women) << endl;
    }

    return 0;
}
