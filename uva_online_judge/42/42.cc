#include <iostream>
#include <string>
#include <algorithm>
#define ll long long

using namespace std;

string reverseAdd(string s1, string s2) {
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    ll l1, l2, l3;

    l1 = stoll(s1);
    l2 = stoll(s2);
    l3 = l1 + l2;

    while(l3 % 10 == 0 && l3) 
        l3 /= 10;

    string res = to_string(l3);
    reverse(res.begin(), res.end());
    return res;
}

int main() {	
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << reverseAdd(s1, s2) << endl;
    }

    return 0;
}
