#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define umap unordered_map
using namespace std;

string message(const string & s, int c) {
    string res;
    int first = 2*c - 1, second = 1;
    
    for (int start = 0; start < c; start++) {
        int cur = start;

        while (cur < s.size()) {
            res.push_back(s[cur]);
            cur += first;

            if (cur >= s.size()) break;
            res.push_back(s[cur]);
            cur += second;
        }

        first -= 2;
        second += 2;
    }

    return res;
}

int main() {
    int c;
    string s;

    cin >> c;
    cin >> s;

    while (c != 0) {
        cout << message(s, c) << endl;

        cin >> c;
        cin >> s;
    }
    
    return 0;
}
