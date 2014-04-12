#include <stdio.h>
#include <stdlib.h>
const unsigned long long int MODE = 1e9 + 7;
int main()
{
	unsigned long long int N;
	unsigned long long int sum;
	unsigned long long int tempsum;
	unsigned long long int temp;
	unsigned long long int temp1;
	unsigned long long int temp2;
	unsigned int T;
	unsigned int i;

	scanf("%u", &T);
	for(i = 1; i <= T; i++){
		scanf("%llu", &N);

		if(N <= 3){
			sum = (N * N * (N+1) * (N+1) * ( N * N - 3 * N + 4)) / 8;
			printf("Case %d: %llu\n", i, sum);
		}
		else if(N % 2){
			temp1 = N + 1;
			temp = N + 1;
			temp1 /= 2;
			temp2 = N - 3;
			temp2 /= 2;
			temp1 %= MODE;
			N %= MODE;
			temp2 %= MODE;
			temp %= MODE;

			sum = N * N % MODE;
			sum = sum * temp1 % MODE;
			tempsum = sum;
			sum = sum * N % MODE;
			sum = sum * temp1 % MODE;
			sum = sum * temp2 % MODE;
			tempsum = tempsum * temp % MODE;
			sum = (sum + tempsum) % MODE;

			printf("Case %d: %llu\n", i, sum);
		}
		else{
			temp1 = N + 1;
			temp2 = N - 3;
			temp = N;
			N /= 2;
			N %= MODE;
			temp %= MODE;
			temp1 %= MODE;
			temp2 %= MODE;

			sum = temp1 * temp1 % MODE;
			sum = sum * N % MODE;
			tempsum = sum;
			sum = sum * temp2 % MODE;
			sum = sum * N % MODE;
			sum = sum * N % MODE;
			tempsum = tempsum * temp % MODE;
			sum = (sum + tempsum) % MODE;

			printf("Case %d: %llu\n", i, sum);
		}
	}
	exit(0);
}
