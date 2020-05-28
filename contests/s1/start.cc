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
    int N, K;
    cin >> N;
    vi nums(N);
    for (int i = 0; i < N; i++) 
        cin >> nums[i];

    cin >> K;
    if (any_of(nums.begin(), nums.end(), [K](int i) {
                return i == K;
                })) cout << "YES" << endl;
    else
        cout << "NO" << endl;


    return 0;
}
