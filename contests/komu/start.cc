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


int closest(int num, vi& n) {
    int lo = 0, hi = n.size()-1;


    if (n[lo] >= num) return lo; 
    if (n[hi] <= num) return hi;

    while (lo + 1 < hi) {
        int mid = (lo + hi)/2;
        if (n[mid] <= num) lo = mid;
        else hi = mid;
    }

    return abs(n[lo] - num) > abs(n[hi] - num) ? hi : lo;
}



        
int main() {
    
    int N, K;
    cin >> N >> K;

    vi n(N);

    for (int i = 0; i < N; i++) {
        cin >> n[i];
    }

    sort(n.begin(), n.end());
   
    long long res = 0;
    for (int i = 0; i < K; i++) {
        long long k;
        cin >> k;

        long long close = n[closest(k, n)];

        long long best = abs(close - k);

        long long cur = 1000000000 - 2 * best;
        if (cur > 0)
            res += cur;

    }

    cout << res << endl;

    return 0;
}
