//////////////////////////////////////////////////////////////////////

//Daniel Tomei : Goldbach's Conjecture : 543 : oaktrunks

//Data structure required : bitset

//Tricks of the trade : Sieve of Eratosthenes taken from pg 211 of 
//							Competitive Programming 3
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll _sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound){
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= _sieve_size; i++) if (bs[i]){
		for (ll j = i*i; j <= _sieve_size; j += i) bs[j] = 0;
		primes.push_back((int)i);
	}
}

bool isPrime(ll N){
	return bs[N];
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; //input
	sieve(1000000); //max input defined in problem
	while (cin >> n && n > 0){
		for (int i = 3; i < n; i+=2){ //iterate through odd primes
			if (isPrime(i)){ 
				if (isPrime(n - i)){ //found the correct prime addition
					cout << n << " = " << i << " + " << n - i << '\n';
					break;
				}
			}
		}
	}
	return 0;
}