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


vi nums;

int main() {
    int n;
    cin >> n;
    nums.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    double avg = nums[0], res = INT_MIN;

    for (int i = 1; i < n; i++) {
        avg = avg * (1.0*i)/(i+1) + (1.0*nums[i]) / (i+1);
        res = max(res, avg);
    }

    reverse(nums.begin(), nums.end());
    avg = nums[0];
    for (int i = 1; i < n; i++) {
        avg = avg * (1.0*i)/(i+1) + (1.0*nums[i]) / (i+1);
        res = max(res, avg);
    }


    res = max(res, 0.0);
    cout << fixed << setprecision(14) << res << endl;


    return 0;
}
