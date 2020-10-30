/*
ID: grant.s1
TASK: crypt1
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

int N;
vi nums;

// all digits in n are valid
bool valid(int n) {
	while (n) {
		int cur = n % 10;
		if (!count(all(nums), cur)) 
			return false;
		n /= 10;
	}
	return true;
}

bool solve(int a, int b, int c, int d, int e) {
	int n1 = 100*a + 10*b + c; // top number
	int p1 = d * n1, p2 = e * n1; // partial sums
	if (p1 >= 1000 || p2 >= 1000) return false;
	if (!valid(p1) || !valid(p2)) return false;
	int fin = p1 + 10*p2; // final sum
	if (fin >= 10000 || !valid(fin)) return false;
	return true;
}

int main()
{
	setIO("crypt1");
	cin >> N;
	F0R(i, N) {
		int cur;
		cin >> cur;
		nums.pb(cur);
	}

	// complete search
	int res = 0;
	trav(a, nums) trav(b, nums) trav(c, nums) trav(d, nums) trav(e, nums) 
		if(solve(a, b, c, d, e)) res++;

	cout << res << endl;

	return 0;
}
