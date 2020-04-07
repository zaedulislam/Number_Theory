// Sieve Of Eratosthenes && Prime Factorization.cpp
// Time Complexity: O(N log (log N))
#include<iostream>
#include<cmath>
using namespace std;

const int SIZE = 1e6 + 10;
int status[SIZE], prime[SIZE], factors[SIZE], primeSZ;

void Sieve()
{
	int I, K, sqrtN = int(sqrt((double)SIZE));
	for (I = 3; I <= sqrtN; I += 2)
	{
		if (status[I] == 0)
		{
			for (K = I * I; K <= SIZE; K += 2 * I)  // K += I + I
				status[K] = 1;
		}
	}

	K = 0;
	prime[K++] = 2;
	for (I = 3; I <= SIZE; I += 2)
	{
		if (status[I] == 0)
			prime[K++] = I;
	}
	primeSZ = K;
}

void PrimeFactorize(int N)
{
	int I, K = 0, sqrtN = int(sqrt((double)N));
	if (N <= 1)
		return;

	for (I = 0; I < primeSZ && prime[I] <= sqrtN; I++)
	{
		if (N % prime[I] == 0)
		{
			while (N %prime[I] == 0)
			{
				N /= prime[I];
				factors[K++] = prime[I];
			}
			sqrtN = int(sqrt((double)N));
		}
	}

	if (N > 1)
		factors[K++] = N;

	for (I = 0; I < K; I++) cout << factors[I] << " ";
	cout << endl;
}

int main()
{
	int N;
	cin >> N;
	Sieve();
	PrimeFactorize(N);

	return 0;
}
