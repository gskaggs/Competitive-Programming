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

bool works(vi& nums, int K , int L) {
    int sum = 0;
    for (int i = 0; i < nums.size() && sum <= K; i++) {
        if (nums[i] <= L) sum += nums[i]; 
    }
    return sum <= K;
}

int main() {
    
    int N, K;
    cin >> N >> K;

    vi nums(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];

    int lo = 0, hi = 1000;
    if (works(nums, K, hi)) {
        cout << "eat away!" << endl;
        return 0;
    }

    while (lo + 1 < hi) {
        int mid = lo + (hi -lo)/2;
        if (works(nums, K, mid)) lo = mid;
        else hi = mid;
    }

    cout << lo << endl;


    return 0;
}
