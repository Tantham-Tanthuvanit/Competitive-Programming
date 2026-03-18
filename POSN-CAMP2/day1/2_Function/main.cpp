#include "prime_number.h"

int prime_number(vector <int> A)
{
	int sum = 0;

    for(int i = 0; i < A.size(); i++){
        int x = A[i];
        bool isPrime = true;

        if(x < 2) isPrime = false;

        for(int j = 2; j <= sqrt(x); j++){
            if(x % j == 0){
                isPrime = false;
                break;
            }
        }

        if(isPrime){
            sum += x;
        }
    }

    return sum;
}
