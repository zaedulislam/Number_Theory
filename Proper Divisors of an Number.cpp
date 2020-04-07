// Proper Divisors of an Number.cpp
#include <iostream>
#include <cstdio>
#include <cmath>

int caseno = 1;
#define NL '\n'
#define FOR(I,J,K) for(I = J; I < K; I++)
using namespace std;
const int SIZE = 1000000;

// fflush(stdout);
int factor[SIZE], power[SIZE], actDiv[SIZE], factSZ = 0;

void GenProperDiv()
{
	int x, I, J, K, tempSZ, divSZ = 1;
	actDiv[0] = 1;
	for(I = 0; I < factSZ; I++){
		x = 1;
		tempSZ = divSZ;
		for(J = 1; J <= power[I]; J++){
			x = x * factor[I];
			//cout << x << NL;
			for(K = 0;  K < tempSZ; K++){
				actDiv[divSZ++] = actDiv[K] * x;
				//cout << "actDiv[K] * x = " << actDiv[K] * x << NL;
			}
		}
	}
	for(I = 0;  I < divSZ; I++) cout << actDiv[I] << " ";
	cout << NL;
}

void PrimeFactor(int n)
{
	int I, K, p, cnt; factSZ = 0;
	for(p = 2; p * p <= n; p++){
		if(n % p == 0){
			cnt = 0;
			while(n % p == 0){
				cnt++;
				n /= p;
			}
			factor[factSZ] = p;
			power[factSZ] = cnt;
			factSZ++;
		}
	}
	if(n > 1){
		factor[factSZ] = n;
		power[factSZ] = 1;
		factSZ++;
	}
}

int main()
{
	int tcases, I, J, K, N, n, m, cnt = 0, len;
	while(scanf("%d", &n) != EOF)
	{
		PrimeFactor(n);

		for(I = 0; I < factSZ; I++) cout << factor[I] << " ";
		cout << NL;
		for(I = 0; I < factSZ; I++) cout << power[I] << " ";
		cout << NL;
		GenProperDiv();
	}
	return 0;
}
