#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define umap unordered_map
using namespace std;


bool isValid (const vi & x, int c, int d) {
    c--;
    int prev = 0;

    for (int i = 1; i < x.size() && c > 0; i++) { 
        if ( x[i] - x[prev] > d ) {
            prev = i;
            c--;
        }
    }
    retrun c == 0;
}
        
int main() {
    int t, n, c;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n >> c;
        vi x;
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            x.push_back(num);
        }
        
        sort(x.begin(), x.end());
        cout << binSearch(x, n, c) << endl;
    }
    return 0;
}
