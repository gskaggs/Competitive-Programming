/*
ID: grant.s1
TASK: palsquare
LANG: C++                 
*/

#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto &a : x)
#define pb push_back
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second
#define umap unordered_map
#define uset unordered_set
#define INF 1000000007
#define MAX_N 100005
using namespace std;

void setIO(string name)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen((name + ".in").c_str(), "r", stdin);
	freopen((name + ".out").c_str(), "w", stdout);
}

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

int N = 301;

char toBase(int n) {
	if (n < 10) return '0' + n;
	else return 'A' + n - 10;
}

bool isPal(string s) {
	int n = sz(s);
	F0R(i, n/2) {
		if(s[i] != s[n-1-i]) 
			return false;
	}
	return true;
}

string convert(int n, int b) {
	string res;
	while (n) {
		res.push_back(toBase(n % b));
		n /= b;
	}
	reverse(all(res));
	return res;
}

int main()
{
	setIO("palsquare");
	int B;
	cin >> B;

	FOR(i, 1, N) {
		if (isPal(convert(i*i, B))) {
			cout << convert(i, B) << " " << convert(i*i, B) << endl;
		}
	}
	return 0;
}
