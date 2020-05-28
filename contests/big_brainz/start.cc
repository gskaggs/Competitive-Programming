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
#define mod 1000000007
using namespace std;

typedef pair<int, int> ii;
typedef vector<int>    vi;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef vector<vii>  vvii;
typedef vector<string> vs;

class SegmentTree {         // the segment tree is stored like a heap array
private: 
  vi A;            
  vector<umap<int, int>> st_primes;

  int n;
  int left (int p) { return p << 1; }     // same as binary heap operations
  int right(int p) { return (p << 1) + 1;  }

  void rq(int p, int L, int R, int i, int j, umap<int, int>& primes) {                  
    if (i >  R || j <  L) return; // current segment outside query range
    if (L >= i && R <= j) {
        for (auto prime : st_primes[p]) {
            primes[prime.first] += prime.second;
        }
        return;
    }

    rq(left(p) , L              , (L+R) / 2, i, j, primes);
    rq(right(p), (L+R) / 2 + 1, R          , i, j, primes);

  }          

  bool update_point(int p, int L, int R, int idx, int mult) {
    int i = idx, j = idx;

    if (i > R || j < L)
      return false;

    st_primes[p][mult] += 1;

    if (L == i && R == j) {
      A[L] *= mult;
      if (A[L] > 100000) {
        st_primes[p].clear();
        return true;
      }
      return false; 
    }

    bool p1, p2;
    p1 = update_point(left(p) , L              , (L + R) / 2, idx, mult);
    p2 = update_point(right(p), (L + R) / 2 + 1, R          , idx, mult);

    if (p1 || p2) {
        st_primes[p].clear();
        for (auto prime : st_primes[left(p)]) {
            st_primes[p][prime.first] += prime.second;
        }
        for (auto prime : st_primes[right(p)]) {
            st_primes[p][prime.first] += prime.second;
        }
        return true;
    }

    return false;
  }

public:
  SegmentTree(int _n) {
    n = _n;
    A.assign(n, 1);            
    st_primes.resize(4*n);
  }

  // i, j are 1 indexed
  void rq(int i, int j, umap<int, int>& primes) { rq(1, 0, n - 1, i-1, j-1, primes); }   // overloading

  bool update_point(int idx, int mult) {
    return update_point(1, 0, n - 1, idx-1, mult); }
};
  
int main() {

  int N, Q;
  cin >> N >> Q;

  SegmentTree st(N);

  while (Q--) {
    int a, b ,c;
    cin >> a >> b >> c;

    // point update
    if (a) {
        int index = b, mult = c;
        st.update_point(index, mult);
    }
    else {
        umap<int, int> primes;
        ll prod = 1;
        st.rq(b, c, primes);

        // Euler phi
        for (auto prime : primes) {
            int p = prime.first;
            int pow = prime.second;
            rep(i, 0, pow-1) {
                prod *= p;
                prod %= mod;
            }
            prod *= p-1;
            prod %= mod;
        }

        cout << prod << endl;
    }
  }
  return 0;
}
