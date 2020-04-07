/*
The Usual Euclid's Method to Find GCD and LCM.cpp
Definition:
GCD: It the largest number ( let that be G ), that can divide both A and B. For example,
GCD(2,8)=2, GCD(3,4)=1, GCD(12,15)=3.
Two Trivial Case:
GCD(a,a)=a and GCD(a,0)=a.

Built-In Version:
There is also a builtin function in C++ for finding gcd. You can simply write __gcd(a,b) to find GCD(a,b).

Complexity: It's kind of tricky.The complexity of Eculidean Algorithm according to the answer
from StackOverflow is O(log10A+log10B).

Properties:
1. Every common divisor of a and b is a divisor of gcd(a,b).
2. The gcd is a commutative function: gcd(a,b)=gcd(b,a).
3. The gcd is an associative function: gcd(a,gcd(b,c))=gcd(gcd(a,b),c).
4. The gcd of three numbers can be computed as gcd(a,b,c)=gcd(gcd(a,b),c), or in some different
way by applying commutativity and associativity.This can be extended to any number of numbers.

Coding Pitfalls
Notice that the algorithm work correctly for non-negative inputs only. Try to find GCD(4,−2) with the above algorithm.
The correct answer should be 2. GCD will always be positive. But it returns -2. Even though the algorithm works
correctly only for a non-negative number, it can easily be extended to work with negative numbers. You need to either
send the absolute value of the inputs to the algorithm or use the absolute value of the return value.

Next, notice that GCD(0,0)=0. It should be infinity. Also, if you try to work with the return value of GCD(0,0), then you
 might get RTE due to division by zero.

Try to be careful in the two scenarios above.
*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

/// Non-recursive Method
int FindGCD(int a, int b)
{
	int divident = a, divisor = b, q, rem = -1;

	while (rem != 0)
	{
		q = divident / divisor;
		rem = divident % divisor;
		divident = divisor;
		divisor = rem;
	}
	return divident;
}

/// Bitwise Method
int FindGCD(int a, int b)
{
	int divident = a, divisor = b, q;
	while (divident)
		divident ^= divisor ^= divident ^= divisor %= divident;

	return divisor;
}

/// Recursive Method
int FindGCD(int a, int b)
{
	int divident = a, divisor = b, q;

	return !divident ? divisor : FindGCD(divident, divisor % divident);
}

int main()
{
	printf("GCD: %d\n", FindGCD(0, 34));
	return 0;
}
