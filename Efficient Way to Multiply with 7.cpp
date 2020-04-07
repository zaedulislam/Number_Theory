// Efficient Way to Multiply with 7.cpp
// Note: Works only for positive integers.
// Same concept can be used for fast multiplication by 9 or other numbers.
// Time Complexity: O(1)
// Space Complexity: O(1)

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<cctype>
#include<cmath>
#include<stack>
#include<ctime>
#include<queue>
#include<algorithm>
#include<vector>
typedef unsigned long long llu;
using namespace std;
const double PI = 2 * acos(0.0);
const double EPS = 1e-9;


int multiplyBySeven(unsigned int n)
{
    return ((n << 3) - n);
}

int main()
{
    unsigned int n = 10;
    printf("%u\n",multiplyBySeven(n));
	return 0;
}

