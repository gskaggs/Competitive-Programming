/*
ID: grant.s1
TASK: pprime
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
#define MAX_N 10000000
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

int A, B;
vector<ll> primes, ans;
bitset<MAX_N> p;

void sieve() {
	p.set();
	p[0] = p[1] = 0;

	for(ll i = 2; i*i < MAX_N; i++) {
		if(p[i]) {
			primes.pb(i);
			for(ll j = i*i; j < MAX_N; j += i) {
				p[j] = 0;
			}
		}
	}
}

bool isPrime(ll n) {
	if (n < MAX_N) return p[n];
	trav(prime, primes) {
		if (n % prime == 0) 
			return false;
		if (prime*prime > n) break;
	}
	return true;
}

void solve(string s) {
	ll cur = stoll(s);
	if (cur >= A && cur <= B && isPrime(cur)) ans.pb(cur);
	if (cur > B || sz(s) > 8) return;
	F0R(i, 10) {
		char c = '0' + i;
		string s1 = c + s + c;
		solve(s1);
	}
}

int main()
{
	setIO("pprime");
	cin >> A >> B;
	sieve();
	string s;
	F0R(i, 10) { 
		char c = '0' + i;
		s = c;
		solve(s); 
		s.push_back(c);
		solve(s); 
	}
	sort(all(ans));
	trav(a, ans) cout << a << endl;
	return 0;
}
