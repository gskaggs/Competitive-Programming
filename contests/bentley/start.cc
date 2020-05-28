#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define ll long long
#define umap unordered_map
#define uset unordered_set
#define INF INT_MAX
using namespace std;

typedef pair<int, int> ii;
typedef vector<int>    vi;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef vector<vii>  vvii;
typedef vector<string> vs;

uset<int> primes({2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37});

ll numWays(bool first, int cur, int prev, uset<int> remaining) {
   if (!first && !primes.count(cur + prev)) 
       return 0;

   remaining.erase(cur);
   if (remaining.empty()) return 1;

   ll sum = 0;

   for (auto next : remaining) 
       sum += numWays(false, next, cur, remaining);

   return sum;
}

int main() {

    int N;
    cin >> N;

    uset<int> remaining;
    for (int i = 1; i <= N; i++)
        remaining.insert(i);

    cout << numWays(true, 1, -1, remaining) << endl;
    
    return 0;
}
