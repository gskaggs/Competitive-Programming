#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define ll long long
#define umap unordered_map
#define uset unordered_set
using namespace std;

typedef pair<int, int> ii;
typedef vector<int>    vi;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef vector<vii>  vvii;

vvi adjList;
string res;

int main() {
   
    while (true) {
        string s;
        cin >> s;
        if (s == "#") break;

        adjList.resize(26);

        vi nums(s.size());
       
        nums[0] = s[0] - 'A';
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = s[i] - 'A';
            adjList[nums[i-1]].push_back(nums[i]);
        }

        for (int i = 0; i < 26; i++)
            dfs(i);

        reverse(res.begin(), res.end());
        cout << res << endl;
    }
    
    return 0;
}
