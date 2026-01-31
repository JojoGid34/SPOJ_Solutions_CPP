#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int cases;
  cin >> cases;

  while(cases--) {
	int n;
	cin >> n;

	printf("%.8f\n", 2 + (1.0 / n));

	//Hn = n2 Fn
	//Recursive Hn, pattern found --> 8(n2 - (n-1)2 + (n-2)2 - (n-3)2 + ...) --> a2-b2 --> Artihmetic sequence
	//Hn - H(n-1) = 4n2 + 4n
	//Gn simplified = sqrt((Hn - H(n-1) + 1) / n2) = sqrt((4n2 + 4n + 1) / n2) = sqrt((2n + 1)2 / n2) = (2n + 1) / n	
  }

  return 0;
}
