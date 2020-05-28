#include <iostream>
using namespace std;

bool prime(int n);

int main() {
    int t, n, m;

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> m >> n; 

        for (int num = m; num <= n; num++) 
            if (num != 1 && prime(num)) cout << num << endl;
        
        if (i != t-1) cout << endl; 
    }
    return 0;
}

bool prime(int n) {
    for (int i = 2; i * i <= n; i++) 
        if (n % i == 0) return false;
    return true;
}
