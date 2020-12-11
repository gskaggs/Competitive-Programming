#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    int q;
    cin >> n >> q;
    assert(1 <= n && n <= 200000);
    assert(1 <= q && q <= 200000);
    
    set<int> foodLocs;
    for(int i = 0; i <= n; i++) {
        foodLocs.insert(i);
    }
    while(q--) {
        int type;
        int l;
        cin >> type;
        cin >> l;
        assert(type == 1 || type == 2);
        assert(0 <= l && l <= n);
        if(type == 1) {
            assert(foodLocs.count(l) == 1);
            foodLocs.erase(l);
            assert(foodLocs.count(l) == 0);
        }
        else {
            auto val = foodLocs.lower_bound(l);
            int ans = abs(*val - l);
            if(val != foodLocs.begin()) {
                ans = min(ans, abs(*prev(val) - l));
            }
            if(val != foodLocs.end()) {
                ans = min(ans, abs(*next(val) - l));
            }
            cout << ans << endl;
        }
    }
    return 0;
}

