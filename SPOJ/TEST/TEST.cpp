#include <iostream>
using namespace std;

int main() {
	
	int n;
	
	while (true) {
		if(!(cin >> n)) { //Untuk mengecek apakah inputnya masih ada ato ga, meskipun blm 42
			break;
		}
		
		if(n == 42) { //Untuk mengecek apakah inputnya udah 42
			break;
		}
		
		cout << n << endl;
	}

	return 0;
}

//O(N)
