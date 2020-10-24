/*
ID: grant.s1
TASK: milk2
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

int main()
{
	setIO("milk2");

	int N;
	cin >> N;
	vpi A(N);

	F0R(i, N)
	{
		cin >> A[i].f >> A[i].s;
	}

	sort(A.begin(), A.end());

	pi res = {0, 0};
	pi cur = {-1, -1};

	for (auto farmer : A)
	{
		if (cur.f == -1)
		{
			cur = farmer;
		}
		else if (cur.s < farmer.f)
		{
			res.s = max(res.s, farmer.f - cur.s);
			cur = farmer;
		}
		else
		{
			cur.s = max(farmer.s, cur.s);
		}

		res.f = max(res.f, cur.s - cur.f);
	}

	cout << res.f << " " << res.s << endl;
	return 0;
}
