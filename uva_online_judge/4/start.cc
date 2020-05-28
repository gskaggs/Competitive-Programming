#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
using namespace std;


string RPN(string str) {
    stack<char> s;
    string res;

    for(int i = 0; i < str.size(); i++) {
        char c = str[i]; 
        
        if (c <= 'z' && c >= 'a')
            res.push_back(str[i]);
        else if (c == ')') {
            res.push_back(s.top());
            s.pop();
        }
        else if (c == '(') continue;
        else 
            s.push(c);
    }

    return res;
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        string str;
        cin >> str;

        string res = RPN(str);
        cout << res << endl;
    }

}
