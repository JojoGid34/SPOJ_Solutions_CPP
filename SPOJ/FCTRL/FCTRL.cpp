#include <iostream>
using namespace std;

int main() {
	
	//10 = 2x5 (nah kita butuh cari pasangan 2,5 ini ada berapa aja)
	//Karena faktornya 5 lbh dikit drpd faktor 2, jadi faktor 5 ini pembatasnya
	//Dan krn faktor 5 yg batasin, jadi banyaknya faktor 5 di N! itu bakal jadi banyaknya 0 juga
	
	int T, N, zero_sum;
	
	cin >> T;
	
	for (int i = 1; i <= T; i++) {
		cin >> N;
		
		zero_sum = 0;
		
		//Pakai floor(N/5) + floor(N/25) + floor(N/125) + ...
		//Buat ngitung brp banyak faktor 5 ya (mau 1x, 2x, 3x, dst...)
		
		while (N > 0) {
			N = N/5;
			zero_sum += N;
		} 
		
		cout << zero_sum << endl;
	}

	return 0;
}
