#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
using namespace std;

string next(int a1, int a2, int a3) {
    int delta = a2 - a1;

    if (a2 + delta == a3 && delta != 0) 
        return "AP " + to_string(a3 + delta);

    int radius = a2 / a1;
    return "GP " + to_string(a3 * radius);
}

int main() {

    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;

    while (a1 != 0 || a2 != 0 || a3 != 0) { 
        cout << next(a1, a2, a3) << endl;
        cin >> a1 >> a2 >> a3;
    }

    return 0;
}
