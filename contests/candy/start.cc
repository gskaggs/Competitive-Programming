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

    int N, C;
    cin >> N >> C;

    vi h (N);
    int sum = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> h[i];
        sum += h[i];
    }
    int cur = 0;
    for (int i = 0; i < N; i++) {
        if (sum - h[i] >= C - cur) cout << "Skip"<< endl;
        else {
            cout << "Candy" << endl;
            cur += h[i];
        }
        sum -= h[i];
    }
    /*vii h(N);

    for (int i = 0; i < N; i++) {
        cin >> h[i].first;
        h[i].second = i;
    }

    sort (h.begin(), h.end(), greater<ii>());

    vi use (N);
    int sum = 0;

    for (int i = 0; i < N && sum < C; i++) {
        sum += h[i].first;
        use[h[i].second] = 1;
    }
    for (int i = 0; i < N; i++) {
        if (use[i]) cout<< "Candy" << endl;
        else cout << "Skip" << endl;
    }*/

    return 0;
}
