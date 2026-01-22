#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	
	ll p, i;
	cin >> p;
	
	while(p > 1){
		if(p & 1){
			p = ((p << 1)^p)^1;
			i++;
		} else {
			p = p >> 1;
			i++;
		}
	}
	
	cout << i << endl;

	return 0;
}
