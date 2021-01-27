//upper limit for n is 1e6-1.
vector<int> isPrime(1e6, 1);
vector<int> primes;
void sieve(int n) {
	primes.clear();
  for(int i=2; i<=n; i++) {
    if(isPrime[i]) {
      primes.push_back(i);
      int x=2, a=i*x;
      while(a<=n) {
        isPrime[a]=0;
        x++;
        a=i*x;
      }
    }
  }
}
