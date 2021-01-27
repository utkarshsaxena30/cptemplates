int mod=1e9+7;
template<typename T>
T madd(T a, T b) {
	a+=b;
	if(a>=mod)
		a-=mod;
	return a;
} //works when the numbers we are adding are both between 0 and m-1

template<typename T>
T msubtract(T a, T b) {
	a-=b;
	if(a<0)
		a+=mod;
	return a;
} //works when the numbers we are subtracting are both between 0 and m-1

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

ll mdiv(ll a, ll b) {
	ll b_inverse=mpow(b, mod-2);
	return (a*b_inverse)%mod;
} //(a/b)%m
