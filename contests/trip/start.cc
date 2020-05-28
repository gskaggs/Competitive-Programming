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

    string s;
    cin >> s;

    vi t;

    for (int i = 0; i < s.size(); i++) {
        while (i < (int) (s.size()) - 1 && s[i] == s[i+1]) i++;
        t.push_back(s[i] - 'a');
    }



    vvi index (26);

    for (int i = 0; i < t.size(); i++) {
        index[t[i]].push_back(i);
    }

    long long res = 0;
    vi pos (26);

    for (int i = 0; i < t.size(); i++) {
        int cur = index [t[i]][pos[t[i]]];
        int next = pos[t[i]] == index[t[i]].size() - 1 ? t.size() : index[t[i]][pos[t[i]] + 1];
        
        for (int j = 0; j < 26; j++) {

            if (pos[j] < index[j].size()) {
                int other = index[j][pos[j]];
                if (other > cur && other < next)
                    res++;

            }

        }
        pos[t[i]]++;
    }

    cout << res << endl;


    return 0;
}
