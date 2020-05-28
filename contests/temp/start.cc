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
typedef vector<int>      vi;
typedef vector<vi>      vvi;
typedef vector<ii>      vii;
typedef vector<vii>  vvii;
typedef vector<string> vs;

class SegmentTree {                 
    private: vi st, A;                          
    int n;
    int left (int p) { return p << 1; }         
    int right(int p) { return (p << 1) + 1; }

    void build(int p, int L, int R) {                                                       
        if (L == R)                                                      
            st[p] = A[L];                                                                               
        else {                                                              
            build(left(p) , L              , (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R          );
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = max(p1, p2);
    } }

    int rq(int p, int nL, int nR, int qL, int qR) {                                    
        if (qL >  nR || qR <  nL) return -INF; 
        if (nL >= qL && nR <= qR) return st[p];                          

        int p1 = rq(left(p) , nL             , (nL+nR) / 2, qL, qR);
        int p2 = rq(right(p), (nL+nR) / 2 + 1, nR        , qL, qR);

        return max(p1, p2); }                 

    int update_point(int p, int nL, int nR, int idx, int new_value) {
        
        int qL = idx, qR = idx;

        if (qL > nR || qR < nL)
            return st[p];

        if (nL == qL && nR == qR) {
            A[qL] = new_value; 
            return st[p] = A[qL]; 
        }

        int p1, p2;
        p1 = update_point(left(p) , nL,                (nL + nR) / 2, idx, new_value);
        p2 = update_point(right(p), (nL + nR) / 2 + 1, nR,            idx, new_value);

        return max(p1, p2);
    }

public:
    SegmentTree(const vi &_A) {
        A = _A; n = (int)A.size();                       
        st.assign(4 * n, 0);                        
        build(1, 0, n - 1);                                                                  
    }

    int rq(int i, int j) { return rq(1, 0, n - 1, i, j); }     

    int update_point(int idx, int new_value) {
        return update_point(1, 0, n - 1, idx, new_value); }
};
    
int main() {
    int arr[] = { 18, 17, 13, 19, 15, 11, 20 };                 
    vi A(arr, arr + 7);                                          
    SegmentTree st(A);

    return 0;
}
