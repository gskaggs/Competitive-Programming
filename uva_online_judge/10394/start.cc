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
    
    const int N = 20000000;
    bitset<N> prime;
    prime.set();
    vii twins;
    int prev = 2;

    for (ll i = 2; i < N; i++) {
        if (prime[i]) {
            if (i - prev == 2) 
                twins.push_back({prev, i});
            prev = i;

            for (ll j = i*i; j < N; j+= i) 
                prime[j] = 0;
            
        }
    }
    

    int S = 0;
    while (cin >> S) {
        printf("(%d, %d)\n", twins[S-1].first, twins[S-1].second);
    }
    return 0;
}
