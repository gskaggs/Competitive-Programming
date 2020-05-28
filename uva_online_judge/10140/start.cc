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


ii search(ll N, vi& primes) {
    int lo = 0, hi = primes.size()-1;
    if (N < primes[lo]) return {lo, -INF};
    if (N > primes[hi]) return {INF, hi};
    if (N == primes[hi]) return {hi, hi};
    if (N == primes[lo]) return {lo, lo};


    while (lo + 1 < hi) {
        int mid = lo + (mid - lo) / 2;
        if (primes[mid] >= N) lo = mid;
        else hi = mid;
    }

    return {hi, lo};
}


int main() {
    
    const size_t N = 2147483647ULL; 
    cout << N << endl;
    /*bitset<N> prime;
    prime.set();
    prime[0] = prime[1] = 0;
    vi primes;

    if (prime[N-1]) primes.push_back(N-1);

    for (ll i = 2; i < N; i++) {
        if (prime[i]) {
            primes.push_back(i);
            if (i < 1<<20) 
                for (ll j = i*i; j > 0 && j < N; j+=i)
                    prime[j] = 0;
        }
    }


    ll L, U;
    while (cin >> L >> U) {
        L = search(L, primes).first;
        U = search(U, primes).second;

        if (L == INF || U == -INF || L == U) {
            cout << "There are no adjacent primes." << endl;
            continue;
        }

        int c1 = primes[L], c2 = primes[L+1], d1 = c1, d2 = c2;
        for (int i = L ; i < U; i++) {
            if (primes[i+1] - primes[i] > d2 - d1) {
                d1 = primes[i]; d2 = primes[i+1];
            }
            if (primes[i+1] - primes[i] < c2 - c1) {
                c1 = primes[i]; c2 = primes[i+1];
            }

        }

        printf("%d,%d are closest, %d,%d are most distant.\n", c1, c2, d1, d2);
    }*/


    return 0;
}
