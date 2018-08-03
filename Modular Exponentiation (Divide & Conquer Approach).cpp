/// Modular Exponentiation / Big Mod Algorithm.cpp
/// Divide & Conquer Approach
/// Complexity: O(log(P))

#include<iostream>
#include<cstdio>
using namespace std;

int bigMod(int base, int P, int mod)
{
	/// Something to the power 0 equals to 1
	if(P == 0)
		return 1 % mod;	/// In case value of mod is 1

	/// If power is even
	if(P % 2 == 0)
	{
		int a = bigMod(base, P / 2, mod);
		return ((a % mod) * (a % mod) % mod);
	}
	/// If power is odd
	else
	{
		/// (a * b) % mod = ((a % mod) * (b % mod)) % mod
		int a = base % mod;
		int b = bigMod(base, P - 1, mod) % mod;	/// As the power is odd, so make it even for convenience
		return (a * b) % mod;
	}
}

int main()
{
	int B, P, mod;
	while (scanf("%d %d %d",&B,&P,&mod) != EOF)
	{
		printf("%d\n", bigMod(B, P, mod));
	}

	return 0;
}
