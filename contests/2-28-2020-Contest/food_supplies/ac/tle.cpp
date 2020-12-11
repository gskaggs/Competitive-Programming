#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    int q;
    cin >> n >> q;
    
    bool foodLocs[n+1];
    for(int i = 0; i <= n; i++) {
        foodLocs[i] = true;
    }
    
    while(q--) {
        int type;
        int l;
        cin >> type;
        cin >> l;

        if(type == 1) {
            foodLocs[l] = false;
        }
        else {
            int ans = 1e6;
            int i = l;
            while(i >= 0) {
                if(foodLocs[i]) {
                    ans = min(ans, abs(l - i));
                    break;
                }
                i--;
            }
            i = l;
            while(i <= n) {
                if(foodLocs[i]) {
                    ans = min(ans, abs(l - i));
                    break;
                }
                i++;
            }
            
            cout << ans << endl;
        }
    }
    return 0;
}

