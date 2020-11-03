/*
ID: grant.s1
TASK: sprime
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
#define MAX_N (size_t) 1e7
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

int N, lo, hi;
vector<ll> primes;
bitset<MAX_N> p;

bool isPrime(ll n) {
	if (n < MAX_N) return p[n];
	trav(prime, primes) {
		if (n % prime == 0) 
			return false;
		if (prime*prime > n) break;
	}
	return true;
}

void sieve() {
	p.set();
	p[0] = p[1] = 0;

	for(ll i = 2; i < MAX_N; i++) {
		if(p[i]) {
			primes.pb(i);
			for(ll j = i*i; j < MAX_N; j += i) {
				p[j] = 0;
			}
		}
	}
}

void solve(ll n) {
	if (!isPrime(n) || n >= hi) return;
	if (n >= lo) cout << n << endl;
	n *= 10;
	F0R(i, 10) solve(n+i);
}

int main()
{
	setIO("sprime");
	cin >> N;
	sieve();
	hi = 1;
	F0R(i, N) hi *= 10;
	lo = hi / 10;
	F0R(i, 10) solve(i);
	return 0;
}
