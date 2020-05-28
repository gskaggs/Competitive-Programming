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

int main() {
    int T;
    cin >> T;
    vi nums (T);

    for (int t = 0; t < T; t++) {
       cin >> nums[t]; 

    }
    
    int N = T, res = 0;

    int count = 1;
    for (int i = 1; i < N; i++) {
        if (nums[i] < nums[i-1]) {
            res += count * (count + 1) / 2;

            count = 1;
        }

        else 
            count++;


    }
    res += count * (count + 1) /2;
    cout << res << endl;

    return 0;
}
