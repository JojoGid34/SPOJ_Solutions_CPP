#include <iostream>
#include <vector>
using namespace std;

//Ga bisa long long, karena tetep aja overload 100! itu
//Triknya pakai array, yang isinya digit" dari nilai n! dalam posisi terbalik, BUKAN HISTORY ITUNGAN, TAPI CUMAN UTK BILANGAN ITU SAJA
//Misal 5! = 120 -> {0, 2, 1}

//Perkaliannya pakai teknik bersusun, karena ga bisa kalo langsung manual (overload juga)
//Per digit" ngitungnya

void multiply(vector<int>& result, int n) { //Pass by reference untuk ngubah yang aslinya juga
	int carry = 0; //Sisanya bakal ditambahin di digit berikutnya
	
	for(int i = 0; i < result.size(); i++) {
		int product = result[i] * n + carry; //Digit awal (1) * n + carry kalau ada 
		result[i] = product % 10; //Ambil angka satuannya
		carry = product / 10; //Sisa depannya jadi carry
	}
	
	while(carry) { //Kalo carrynya tetep ada meskipun perkaliannya udh selesai
		result.push_back(carry % 10); //Ambil angka satuannya juga, masukin
		carry /= 10; //Sisa depannya brti untuk posisi depannya lagi
		//Gitu terus sampai carrynya habis = 0
	}
}

void findfactorial(int n) {
	vector<int> result; //Reset vector tiap kali mau nyari nilai n! baru
	result.push_back(1); //Nilai awal
	
	for(int i = 2; i <= n; i++) {
		multiply(result, i); //Perkalian berulang dari 2, 3, dst, sampe n
	}
	
	for(int i = result.size() - 1; i >= 0; i--) {
		cout << result[i]; //Outputnya dari belakang ke depan, krn awalnya posisinya disimpan terbalik
	}
	cout << endl;
}

int main() {
	
	int t;
	
	if(!(cin >> t)) return 0; //Kalau t ga ada, ato = 0
	
	while (t--) { //Kalo t masih true, decrement tiap kali loop
		int n;
		cin >> n;
		
		if(n == 0 || n == 1) { //0! = 1! = 1 udh hukumnya
			cout << 1 << endl;
		} else {
			findfactorial(n); //Cari faktorialnya berapa
		}
	}

	return 0;
}

//O(N x D)
//N digit yg mau difaktorial
//D brp digit di resultnya
