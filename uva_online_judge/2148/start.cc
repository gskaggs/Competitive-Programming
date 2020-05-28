#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t, n;
	cin >> t;
	
	for (int i = 0; i < t; i++) {
		cin >> n;
		long long sum = 0;
		
		for (int j = 0; j < n; j++) {
			long long num;
			cin >> num;
                        num %= n;
			sum += num;
                        sum %= n;
		}
		
		if (sum % n == 0) cout << "YES" << endl;
		else cout << "NO\n";
	}
	return 0;
}
