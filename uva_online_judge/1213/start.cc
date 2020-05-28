#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define ll long long
#define umap unordered_map
#define uset unordered_set
#define INF INT_MAX
using namespace std;

typedef pair<int, int> ii;
typedef vector<int>    vi;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef vector<vii>  vvii;
typedef vector<string> vs;

vi primes;
int N, K, P;
vector<vvi> mem;

void sieve() {
    int N = 1120;
    vi nums(N+1, 1);

    for (int i = 2; i <= N; i++) {
        if (nums[i]) {
            primes.push_back(i);

            for (int j = i * i; j <= N; j += i) {
                nums[j] = 0;
            }
        }
    }

    P = primes.size();
}

int numWays(int p, int n, int k) {
    if (mem[p][n][k] != -1) 
        return mem[p][n][k];
    if (p == 0) 
        return 0;

    int res = numWays(p-1, n, k);
    if (n - primes[p] >= 0 && k > 0) res += numWays(p-1, n - primes[p], k-1);

    mem[p][n][k] = res;
    return res;
}


int main() {

    sieve();

    while (true) {
        
        cin >> N >> K;
        
        if (N == 0 && K == 0) break;

        mem.clear();
        mem.assign(P, vvi(N+1, vi(K+1, -1)));

        mem[0][0][0] = 1;
        mem[0][2][1] = 1;

        cout << numWays(P-1, N, K) << endl;

    }

    return 0;
}
