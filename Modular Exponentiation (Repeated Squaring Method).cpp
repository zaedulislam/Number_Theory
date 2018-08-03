/// Modular Exponentiation / Big Mod Algorithm.cpp
/// Repeated Squaring Method (RSM)
/// Complexity: O(log(P))
#include<iostream>
#include<cstdio>
using namespace std;




LL BigMod(LL b, LL P, LL mod)
{
	LL res = 1 % mod, base = b % mod;
	while (P > 0)
	{
		if (P & 1)
			res = (res * base) % mod;

		base = (base * base) % mod;
		P = P >> 1;
	}
	return res;
}



int main()
{
	int B, P, mod;
	while (scanf("%d %d %d", &B, &P, &mod) != EOF)
	{
		printf("%lld\n", BigMod(B, P, mod));
	}

	return 0;
}
