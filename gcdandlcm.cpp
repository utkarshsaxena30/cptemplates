ll gcd(ll a, ll b) {
  return (b==0 ? a : gcd(b, a%b));
}

//take care of overflow
ll lcm(ll a, ll b) {
  return a*b/gcd(a, b);
}
