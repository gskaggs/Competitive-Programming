#include <bits/stdc++.h>
 
typedef unsigned long long LL;
using namespace std;
 
const LL MAXN = 100010;
 
LL n, m, c, a;
LL times[MAXN];
 
int main()
{
	cin >> n >> m >> c >> a;
	
	for(int i = 1; i <= c; i++) {
		cin >> times[i];
	}

	LL term = a / m + 1;
 
	LL nowt = 0;
 
	LL cnt = 1;
	LL ans = 0;
	
	while (true) {
		while (cnt <= c && times[cnt] <= nowt) {
			cnt++;
		}
 
		LL nxtM = (nowt / m + 1) * m;
 
		if (nowt / m >= n && cnt == c + 1) {
			break;
		}
 
		if ((nowt / m >= n || nxtM >= times[cnt]) && cnt != c + 1) {
			ans++; 
			nowt = times[cnt] + a;
			continue;
		}
		else {
			LL sum;
 
			if (cnt == c + 1) {
				sum = ((n * m - nxtM) / m) / term + 1;
				ans += sum;
				nowt = nxtM + term * (sum - 1) * m + a;
				break;
			}
			
			sum = ((std::min(times[cnt] - 1, n * m) - nxtM) / m) / term + 1;
			ans += sum;
			nowt = nxtM + term * (sum - 1) * m + a;
		}
	}
 
	printf("%lld\n", ans);
	
	return 0;
}
