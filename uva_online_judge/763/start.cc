#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define trav(a, x) for (auto& a : x)
#define sz(a) a.size()
#define all(a) a.begin(), a.end()
#define ll long long
#define umap unordered_map
#define uset unordered_set
#define INF 1000000000 
using namespace std;

typedef pair<int, int> ii;
typedef vector<int>    vi;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef vector<vii>  vvii;
typedef vector<string> vs;

int main() {
    string a, b, blank;

    vector<long long> fib(120);
    fib[0] = 1;
    fib[1] = 2;

    rep(i, 2, 100) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    while (cin >> a) {
       cin >> b;

       cout << a << " " <<  b << endl;

       ll n1 = 0, n2 = 0;

       reverse(all(a)); 
       reverse(all(b));

       rep(i, 0, sz(a)) {
           if (a[i] == '1') n1 += fib[i];
       }

       rep(i, 0, sz(b)) {
           if (b[i] == '1') n2 += fib[i]; }

       cout << n1 << " " << n2 << endl;

       ll sum = n1 + n2;

        
       string res;
       bool seen1 = false;
       for (int i = 99; i >= 0; i--) {
            
           printf("%d %lld %lld\n", i, fib[i], sum); 
           if (fib[i] < sum) {
               sum -= fib[i];
               res.push_back('1');
               seen1 = true;
           }

           else if (seen1) res.push_back('0');
       }

       cout << res << endl;
       


    }

    return 0;
}
