#include <iostream>
using namespace std;
typedef long long ll;

//Pakai STARS AND BARS, tapi ubah dulu limitnya dari >=1 jadi >=0 untuk x1+x2+...+xk=n

ll combination(int n, int r) {
	if (r > n/2) r = n-r; //nCr = nC(n-r), ambil angka r yang lebih kecil
	
	ll hasil = 1;
	
	for(int i = 1; i <= r; i++) {
		hasil = hasil*(n-i+1)/i; //Pisah perkaliannya
	}
	
	return hasil;
}

int main() {
	int t;
	cin >> t;
	
	while (t--) {
		int n, k;
		cin >> n >> k;
		
		cout << combination(n-1, k-1) << endl;
	}

	return 0;
}
