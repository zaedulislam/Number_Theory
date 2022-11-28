// Sieve Of Eratosthenes && Prime Factorization.cpp
// Time Complexity: O(N log (log N))

#include<iostream>
#include<cmath>
using namespace std;

const int SIZE = 1e6 + 10;
bool status[SIZE];
int primes[SIZE], primeFactors[SIZE], primeCount;


void sieve()
{
    int i, k, sqrtN = int(sqrt((double)SIZE));
    for (i = 3; i <= sqrtN; i += 2){
        if (!status[i])
        {
            for (k = i * i; k <= SIZE; k += i + i) { // k += 2 * i
                status[k] = true;
            }
        }
    }
    
    
    k = 0;
    primes[k++] = 2;

    for (i = 3; i <= SIZE; i += 2){
        if (status[i] == 0) {
            primes[k++] = i;
        }
    }

    primeCount = k;
}


void primeFactorize(int N)
{
    if (N <= 1)
        return;

    int i, k = 0, sqrtN = int(sqrt((double)N));

    for (i = 0; i < primeCount && primes[i] <= sqrtN; i++){
        if (N % primes[i] == 0){
            while (N %primes[i] == 0){
                N /= primes[i];
                primeFactors[k++] = primes[i];
            }

            sqrtN = int(sqrt((double)N));
        }
    }

    if (N > 1){
        primeFactors[k++] = N;
    }


    for (i = 0; i < k; i++){
        cout << primeFactors[i] << " ";
    }

    cout << endl;
}


int main()
{
    int N;
    cin >> N;

    sieve();
    primeFactorize(N);

    return 0;
}
