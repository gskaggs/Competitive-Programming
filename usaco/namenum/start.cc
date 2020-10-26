/*
ID: grant.s1
TASK: namenum
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

string valid[8] = {"ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"};

bool equiv(ll code, string s) {
	while(code > 0) {
		int cur = code % 10;
		code /= 10;

		if (s.empty() || valid[cur-2].find(s.back()) == string::npos) 
			return false;
		s.pop_back();
	}
	return s.empty();
}

int main()
{
	ifstream infile("dict.txt");
	setIO("namenum");

	ll code;
	cin >> code;

	int count = 0;

	string s;
	while (infile >> s) {
		if (equiv(code, s)) {
			cout << s << endl;
			count++;
		}
	}

	if (!count) cout << "NONE" << endl;

	return 0;
}
