#include <iostream>
using namespace std;
typedef long long ll;

void solve() {
	ll n;
	cin >> n;
	
	ll k = 0;
	
	while (true) {
		ll max_n = (1LL << (k+1)) * k + ((1LL << (k+1)) - 1);
		
		if (max_n >= n) {
			cout << k << endl;
			break;
		}
		k++;
	}
	
	
}

int main() {
	
	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
