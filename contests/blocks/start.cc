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

    int N;
    cin >> N;

    vi nums(N);
    set <int> s;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
        s.insert(nums[i]);
    }

    int count = 0;

    while (!s.empty()) {
        count++;
        int cur = *s.begin();
        s.erase(cur);
        set <int> next;
        for (auto i = s.begin(); i != s.end(); i++) {
            if (*i % cur != 0) next.insert(*i);
        }

        swap(next, s);
    }

    cout << count << endl;
    return 0;
}
