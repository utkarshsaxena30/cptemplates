ll mpow(ll a, ll b) {
	ll x=1;
	while(b) {
		if(b&1)
			x=(x*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return x;
} //a^b%m

//calculate nCr%mod. Define mod yourself
ll nCr(int n, int r) {
	if(r==0)
		return 1;

	ll fact[n + 1];
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = (fact[i - 1] * i) % mod;

    return (fact[n] * mpow(fact[r], mod-2) % mod
            * mpow(fact[n - r], mod-2) % mod)
           % mod;
}
