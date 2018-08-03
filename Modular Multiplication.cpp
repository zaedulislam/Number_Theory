/// Modular Multiplication.cpp
/// Complexity: O(log(b))

#include<iostream>
#include<cstdio>
using namespace std;

#define LL long long




LL ModularMul(LL a, LL b, LL mod)
{
    LL res = 0;
    a = a % mod;

    while(b > 0)
    {
        if(b & 1)
            res = (res + a) % mod;

        a = (a * 2) % mod;
        b >>= 1;
    }

    return res;
}



int main()
{
	LL a, b, mod;
	while (scanf("%lld%lld%lld", &a, &b, &mod) != EOF)
	{
		printf("%lld\n", ModularMul(a, b, mod));
	}

	return 0;
}


/*
Input:
9223372036854775807  9223372036854775807  100000000000

Output:
84232501249
*/
