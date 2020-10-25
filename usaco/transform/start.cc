/*
ID: grant.s1
TASK: transform
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
#define MAX_N 10
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

int N, A[MAX_N][MAX_N], B[MAX_N][MAX_N];

pi rotate(pi cur)
{
	return {cur.s, N - 1 - cur.f};
}

void rotateA()
{
	F0R(i, N / 2)
	FOR(j, i, N-1-i)
	{
		pi cur = {i, j};
		F0R(k, 3)
		{
			cur = rotate(cur);
			swap(A[i][j], A[cur.f][cur.s]);
		}
	}
}

void reflectA() {
	F0R(i, N) F0R(j, N/2) {
		swap(A[i][j], A[i][N-1-j]);
	}
}

bool done()
{
	F0R(i, N) F0R(j, N)
		if (A[i][j] != B[i][j])
			return false;
	return true;
}

int solve()
{
	F0R(i, 3)
	{
		rotateA();
		if (done())
			return i + 1;
	}
	rotateA();
	reflectA();
	if (done())
		return 4;
	F0R(i, 3)
	{
		rotateA();
		if (done())
			return 5;
	}
	rotateA();
	reflectA();
	if (done())
		return 6;
	return 7;
}

int main()
{
	setIO("transform");
	cin >> N;
	F0R(i, N)
	{
		string s;
		cin >> s;
		F0R(j, N)
		A[i][j] = s[j];
	}

	F0R(i, N)
	{
		string s;
		cin >> s;
		F0R(j, N)
		B[i][j] = s[j];
	}

	cout << solve() << endl;

	return 0;
}
