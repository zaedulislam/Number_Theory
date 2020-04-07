/*
Prime Factorization of an Integer Using Trial Division.cpp
Reference: SPOJ FACT0 - Integer Factorization (15 digits)
If the number of testcases is smaller and it is not feasible to generate primes up to N,
then this Trial Division will come in handy.
*/
#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>
using namespace std;
#define SF scanf
#define PF printf
typedef long long LL; //NOTES:"%lld"
map < LL, LL > MAP;
void PrimeFactorize(LL N)
{
	LL P, primePow, sqrtN = LL(sqrt((double)N));
	/*
	P * P <= N is almost 3 times faster than P <= sqrtN in some cases.
    for(P = 2; P * P <= N; P++) {}  	-> 0.21s
	for(P = 2; P <= N / P; P++) {} 		-> 0.37s
	for(P = 2; P <= sqrtN; P++) {}	-> 0.52s
	*/
	for(P = 2; P * P <= N; P++)
	{
		primePow = 0;
		// If P is a prime factor of N
		if(N % P == 0)
		{
			while(N % P == 0)
			{
				N /= P;
				primePow++;
			}
			MAP[P] = primePow;
		}
	}
	/*
	If N has a prime factor greater than sqrt(N) (There can be at-most one such prime factor).
	*/
	if(N > 1)
		MAP[N] = 1;
}
int main()
{
	LL tcases, I, J, K, N, n, m, cnt = 0, len;
	while(SF("%lld", &N), (N || 0))
	{
		MAP.clear();
        PrimeFactorize(N);
	}
	return 0;
}

