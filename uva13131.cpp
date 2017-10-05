//////////////////////////////////////////////////////////////////////

//Daniel Tomei : Divisors : 13131 : oaktrunks

//Data structure required : bitset, vector

//Tricks of the trade : Using sieve and sumDiv from green book.


/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>
#include <bitset>
#include <vector>

using namespace std;

//sieve function from green book
long long _sieve_size;
bitset<10000010> bs;
vector<int> primes;

void sieve(long long upperbound){
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (long long i = 2; i <= _sieve_size; i++) if (bs[i]){
		for (long long j = i*i; j <= _sieve_size; j += i) bs[j] = 0;
		primes.push_back((int)i);
	}
}

//sumDiv function from green book
long long sumDiv(long long N){
	long long PF_idx = 0, PF = primes[PF_idx], ans = 1;
	while (PF * PF <= N) {
		long long power = 0;
		while (N%PF == 0) { N /= PF; power++; }
		ans *= ((long long)pow((double)PF, power + 1.0) - 1) / (PF - 1);
		PF = primes[++PF_idx];
	}
	if (N != 1) ans *= ((long long)pow((double)N, 2.0) - 1) / (N - 1);
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long T, N, K; //test cases, two input ints
	sieve(500000); //creating list of primes needed for sumDiv
	cin >> T;
	for (int i = 0; i < T; i++){
		cin >> N >> K;
		if (N % K == 0) cout << sumDiv(N) - K * sumDiv(N / K) << '\n';
		else cout << sumDiv(N) << '\n';
	}
	return 0;
}