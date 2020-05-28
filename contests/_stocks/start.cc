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

vector<string> stringFormattedWeeklyPrices(vector<int> dailyPrice) {
    int N = dailyPrice.size();
    vector<string> res;

    if (N < 7) return res;

    int sum = 0;
    for (int i = 0; i < 7; i++)
        sum += dailyPrice[i];

    stringstream ss;
    ss << fixed << setprecision(2) << sum / 7.0;
    string s;
    ss >> s;
    res.push_back(s);

    for (int i = 7; i < N; i++) {
        sum -= dailyPrice[i-7];
        sum += dailyPrice[i];
        ss.clear();
        ss << fixed << setprecision(2) << sum / 7.0;
        s.clear();
        ss >> s;
        res.push_back(s);
    }
    return res;
}

int main() {
 
    int N;
    cin >> N;
    vi nums (N); 

    for (int i = 0; i < N; i++) 
        cin >> nums[i];

    vector<string> res = stringFormattedWeeklyPrices(nums);
    for (auto s : res)
        cout << s << endl;

    return 0;
}
