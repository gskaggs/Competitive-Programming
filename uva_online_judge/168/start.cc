#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define ll long long
#define umap unordered_map
using namespace std;

typedef pair<int, int> ii;
typedef vector<int>    vi;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef vector<vii>  vvii;

void makeAdjList(string & s,  vvi & adjList) {
    for (int i = 0; i < s.size(); i++) {
        int cur = s[i] - 'A';
        i+=2;
        while (s[i] != ';' && s[i] != '.') {
            int n = s[i] - 'A';
            adjList[cur].push_back(n);
            i++;
        }
    }
}
int main() {

    while (true) {
        string str;
        cin >> str;

        if (str[0] == '#') break;

        vvi adjList(26);
        makeAdjList(str, adjList);

        int prev, cur, k, t = 0;
//        char p, c;
        cin >> prev >> cur >> k;
 //       prev = p - 'A';
 //       cur = c -'A';
        swap(prev, cur);

        unordered_set<int> s;
        vi res;

        while (true) {
            t++;

            int next = -1;

            for (int i : adjList[cur]) 
                if (i != prev && !s.count(i)) {next = i; break;}

            if (next == -1) break;

            prev = cur;
            cur = next;

            if (t % k == 0) {
                res.push_back(prev);
                s.insert(prev);
            }
        }

        for (int i : res) cout << (char) (i + 'A') << " ";
        cout << "/" << (char) (cur+'A') << endl;
    }
                

    return 0;
}
