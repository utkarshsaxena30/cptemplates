//gives solution for ax+by=g, where g is gcd(a, b)
//If solution for above equation is x, y, solution for ax+by=c is (x*c)/g, (y*c)/g
void extendedEuclid(int a, int b, float &x, float &y)
{
    //base case, if b==0 then solution to ax+by=gcd(a,b) is x=1, y=0
    if(!b)
      x=1, y=0;

    else {
      float x1, y1;
      //find answer to bx+(a%b)y=gcd(b,a%b)
      extendedEuclid(b, a%b, x1, y1);
      //update x and y using results of recursive call
      x = y1;
      y = x1-y1*(a/b);
    }

}

// Solution for ax+by=c:

// int a, b, c;
// cin>>a>>b>>c;
// float x,y;
// extendedEuclid(a, b, x, y);
// int g=__gcd(a, b);
// cout<<(x*c)/g<<" "<<(y*c)/g;
