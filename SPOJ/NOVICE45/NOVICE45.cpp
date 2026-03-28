#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MOD 1000000007
#define MAXN 10001
#define MAXK 101
int PF[MAXN][MAXK];

void pre_calc() {
	int i, j;
	memset(PF,0,sizeof(PF));
	for(i=0; i<MAXN; i++) {
		for(j=1; j<MAXK; j++) {
			if (j==i) PF[i][j]=1;
			else if(j<i) PF[i][j]=(PF[i-1][j-1]+PF[i-j][j]) %MOD;
		}
	}
}

int main() {
	
	int cases,n,k,l,hasil;
	pre_calc();
	scanf("%d", &cases);
	while(cases--){
		scanf("%d%d", &n, &k);
		if(n==1) printf("1\n");
		else {
			hasil=0;
			for(l=1;l<=k;l++) hasil=(hasil+PF[n][l]) %MOD;
			printf("%d\n", hasil);
		}
	}
	

	return 0;
}
